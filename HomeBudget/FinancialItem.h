#ifndef FINANCIALITEM_H
#define FINANCIALITEM_H

#include <iostream>

using namespace std;

class FinancialItem {
    int ID;
    int userID;
    string date;
    string item;
    double amount;

public:
    int getID();
    int getUserID();
    string getDate();
    string getItem();
    double getAmount();

    void setID(int newID);
    void setUserID(int newUserID);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
};

#endif
