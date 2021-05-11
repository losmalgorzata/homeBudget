#include "FileWithExpenses.h"

vector <Expense> FileWithExpenses::loadExpensesFromFile(int loggedUserID){
    CMarkup xml;
    Expense expense;
    vector <Expense> expenses;
    bool fileExists = xml.Load( getFilename().c_str() );

    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("Expense") ){
        Expense expense;
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
        xml.FindElem( "DateInt" );
        int dateInt = atoi(xml.GetData().c_str());
        xml.OutOfElem();

        if (userID == loggedUserID) {
            expense.setID(ID);
            expense.setUserID(userID);
            expense.setDate(date);
            expense.setItem(item);
            expense.setAmount(amount);
            expense.setDateInt(dateInt);
            expenses.push_back(expense);
        }
    }

    return expenses;
}

bool FileWithExpenses::addExpenseToFile(Expense expense){
    CMarkup xml;
    bool fileExists = xml.Load( getFilename().c_str() );
    if (!fileExists){
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expenses");
    }
    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expense");
    xml.IntoElem();
    xml.AddElem("ID", AuxiliaryMethods::intToStringConversion(expense.getID()));
    xml.AddElem("UserID", AuxiliaryMethods::intToStringConversion(expense.getUserID()));
    xml.AddElem("Date", expense.getDate());
    xml.AddElem("Item", expense.getItem());
    xml.AddElem("Amount", AuxiliaryMethods::doubleToStringConversion(expense.getAmount()));
    xml.AddElem("DateInt", AuxiliaryMethods::intToStringConversion(expense.getDateInt()));
    xml.OutOfElem();
    xml.OutOfElem();

    xml.Save(getFilename().c_str());
}
