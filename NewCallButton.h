private void NewCRMCall_Btn_Click(object sender, System.EventArgs args)
{
    // ** Place Event Handling Code Here **
 
    string launchType = "AddNew";       
 
    string custID = string.Empty;
    string key1 = string.Empty;
    string key2 = string.Empty;
    string key3 = string.Empty;
    string relToFile = string.Empty;
    int callSeqNum = 0;
    int custNum = 0;
    string shipToNum = string.Empty;
    bool LaunchOK = true;
 
    EpiDataView CustomerList = (EpiDataView)oTrans.EpiDataViews["V_UD_SalesDB_Customers_1View1"];
     
    try
    {
        if(CustomerList.Row > -1)
        {
            custNum = Convert.ToInt32(CustomerList.dataView[CustomerList.Row]["Customer_CustNum"].ToString());              
            custID = custNum.ToString();
            //shipToNum = CustomerList.dataView[CustomerList.Row]["ShipTo_ShipToNum"].ToString();
            relToFile = "customer";
            key1 = custNum.ToString();
            key2 = custNum.ToString();
        }
        else
        {
            LaunchOK = false;
        }
         
    }
    catch
    {
        LaunchOK = false;
    }
    if (LaunchOK)
    {
        XmlDocument xDoc = new XmlDocument();
        XmlNode xDocElem = xDoc.CreateElement("Test");
        XmlNode xNodeMode = xDoc.CreateElement("Mode");
        xNodeMode.InnerText = launchType;
        xDocElem.AppendChild(xNodeMode);
        xDoc.AppendChild(xDocElem); 
        CRMCallArgs crmArgs = new CRMCallArgs(relToFile, key1, key2, key3, callSeqNum.ToString(), custID);
        crmArgs.ValueIn = xDoc;
        ProcessCaller.LaunchForm(this.oTrans , "Erp.UI.CRMCallEntry.dll", crmArgs);
    }
 
     
}
 
private void EditCall_Btn_Click(object sender, System.EventArgs args)
{
    // ** Place Event Handling Code Here **
 
    string launchType = "Update";
 
    string custID = string.Empty;
    string key1 = string.Empty;
    string key2 = string.Empty;
    string key3 = string.Empty;
    string relToFile = string.Empty;
    int callSeqNum = 0;
    int custNum = 0;
    string shipToNum = string.Empty;
    bool LaunchOK = true;
 
    EpiDataView CustomerList = (EpiDataView)oTrans.EpiDataViews["V_UD_SalesDB_Customers_1View1"];
    EpiDataView CallList = (EpiDataView)oTrans.EpiDataViews["V_UD_SalesDB_Calls_1View"];
     
    try
    {
        if (CustomerList.Row > -1  || CallList.Row > -1)
        {
            custID = CustomerList.dataView[CustomerList.Row]["Customer_CustID"].ToString();
            custNum = custNum = Convert.ToInt32(CustomerList.dataView[CustomerList.Row]["Customer_CustNum"].ToString());
            relToFile = CallList.dataView[CallList.Row]["CRMCall_RelatedToFile"].ToString();
            key1 = CallList.dataView[CallList.Row]["CRMCall_Key1"].ToString();
            key2 = CallList.dataView[CallList.Row]["CRMCall_Key2"].ToString();
            key3 = CallList.dataView[CallList.Row]["CRMCall_Key3"].ToString();
            callSeqNum = Convert.ToInt32(CallList.dataView[CallList.Row]["CRMCall_CallSeqNum"].ToString());
        }
    }
    catch
    {
       LaunchOK = false;
    }
    if (LaunchOK)
    {
        XmlDocument xDoc = new XmlDocument();
        XmlNode xDocElem = xDoc.CreateElement("Test");
        XmlNode xNodeMode = xDoc.CreateElement("Mode");
        xNodeMode.InnerText = launchType;
        xDocElem.AppendChild(xNodeMode);
        xDoc.AppendChild(xDocElem); 
        CRMCallArgs crmArgs = new CRMCallArgs(relToFile, key1, key2, key3, callSeqNum.ToString(), custID);
        crmArgs.ValueIn = xDoc;
        ProcessCaller.LaunchForm(this.oTrans , "Erp.UI.CRMCallEntry.dll", crmArgs);
    }
 
     
}
