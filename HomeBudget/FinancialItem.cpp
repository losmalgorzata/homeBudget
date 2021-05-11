#include "FinancialItem.h"

void FinancialItem::setID(int newID) {
    if (newID > 0)
        ID = newID;
}

void FinancialItem::setUserID(int newUserID) {
    userID = newUserID;
}

void FinancialItem::setDate(string newDate) {
    date = newDate;
}

void FinancialItem::setItem(string newItem) {
    item = newItem;
}

void FinancialItem::setAmount(double newAmount) {
    amount = newAmount;
}

void FinancialItem::setDateInt(int newDateInt){
    dateInt = newDateInt;
}

int FinancialItem::getID() {
    return ID;
}

int FinancialItem::getUserID() {
    return userID;
}

string FinancialItem::getDate() {
    return date;
}

string FinancialItem::getItem() {
    return item;
}

double FinancialItem::getAmount() {
    return amount;
}

int FinancialItem::getDateInt(){
    return dateInt;
}
