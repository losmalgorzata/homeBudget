#ifndef EXPENSEMANAGER_H
#define EXPENSEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Expense.h"
#include "FileWithExpenses.h"
#include "DateOperation.h"

using namespace std;

class ExpenseManager
{
    const int LOGGED_USER_ID;
    vector <Expense> expenses;
    FileWithExpenses fileWithExpenses;

    Expense giveNewExpenseData();

public:
    ExpenseManager(string filenameWithExpenses, int loggedUserID)
        : fileWithExpenses(filenameWithExpenses), LOGGED_USER_ID(loggedUserID){
        expenses = fileWithExpenses.loadExpensesFromFile(LOGGED_USER_ID);
    };

    void addExpense();
    void listExpenses(vector <Expense> expenses);
    int getNewExpenseID();
    Expense giveNewExpenseDataOfChosenDay();
    Expense giveNewExpenseDataOfToday();
    void displayBalanceOfCurrentMonth();
    double calculateSumOfExpensesOfCurrentMonth();
    void displayBalanceOfPreviousMonth();
    double calculateSumOfExpensesOfPreviousMonth();
    void displayBalanceOfChosenFrame(string dateStart, string dateEnd);
    double calculateSumOfExpensesOfChosenFrame(string dateStart, string dateEnd);
    vector <Expense> chooseExpensesFromMonth(int year, int month);
    vector <Expense> sortExpenses(vector <Expense> chosenExpenses);
    vector <Expense> chooseExpensesFromChosenFrame(string dateStart, string dateEnd);
};

#endif
