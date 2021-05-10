#include "FileWithIncomes.h"

vector <Income> FileWithIncomes::loadIncomesFromFile(int loggedUserID){
    CMarkup xml;
    Income income;
    vector <Income> incomes;
    bool fileExists = xml.Load( getFilename().c_str() );

    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Income") ){
        Income income;
        xml.IntoElem();
        xml.FindElem( "ID" );
        int ID = atoi(xml.GetData().c_str());
        xml.FindElem( "UserID" );
        int userID = atoi(xml.GetData().c_str());
        xml.FindElem( "Date" );
        string date = xml.GetData();
        xml.FindElem( "Item" );
        string item = xml.GetData();
        xml.FindElem( "Amount" );
        double amount = atof(xml.GetData().c_str());
        xml.OutOfElem();

        if (userID == loggedUserID) {
            income.setID(ID);
            income.setUserID(userID);
            income.setDate(date);
            income.setItem(item);
            income.setAmount(amount);
            incomes.push_back(income);
        }
    }

    return incomes;
}

bool FileWithIncomes::addIncomeToFile(Income income){
    CMarkup xml;
    bool fileExists = xml.Load( getFilename().c_str() );
    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("ID", AuxiliaryMethods::intToStringConversion(income.getID()));
    xml.AddElem("UserID", AuxiliaryMethods::intToStringConversion(income.getUserID()));
    xml.AddElem("Date", income.getDate());
    xml.AddElem("Item", income.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::doubleToStringConversion(income.getAmount()));
    xml.OutOfElem();
    xml.OutOfElem();

    xml.Save(getFilename().c_str());
}
