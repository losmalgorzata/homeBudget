#ifndef FINANCIALITEM_H
#define FINANCIALITEM_H

#include <iostream>
#include <cmath>

using namespace std;

class FinancialItem {
    int ID;
    int userID;
    string date;
    string item;
    double amount;
    int dateInt;

public:
    int getID();
    int getUserID();
    string getDate();
    string getItem();
    double getAmount();
    int getDateInt();

    void setID(int newID);
    void setUserID(int newUserID);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);
    void setDateInt(int newDateInt);
};

#endif
