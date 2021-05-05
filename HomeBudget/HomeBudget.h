#ifndef HOMEBUDGET_H
#define HOMEBUDGET_H

#include <iostream>

#include "UserManager.h"
//#include "IncomeManager.h"
//#include "ExpenseManager.h"

using namespace std;

class HomeBudget
{
    UserManager userManager;
    //IncomeManager *incomeManager;
    //ExpenseManager *expenseManager;
    //const string FILENAME_WITH_INCOMES;
    //const string FILENAME_WITH_EXPENSES;

public:
    HomeBudget(string filenameWithUsers)
        : userManager(filenameWithUsers){};

    void listAllUsers();
    int getIDOfLoggedUser();
    char chooseOptionOfMainMenu();
    int logonUser();
};

/*
public:
    HomeBudget(string filenameWithUsers, string filenameWithIncomes, string filenameWithExpenses)
        : userManager(filenameWithUsers), FILENAME_WITH_INCOMES(filenameWithIncomes),
        FILENAME_WITH_EXPENSES(filenameWithExpenses)
    {
        incomeManager = NULL;
        expenseManager = NULL;
    };
    ~HomeBudget()
    {
        delete incomeManager;
        incomeManager = NULL;
        delete expenseManager;
        expenseManager = NULL;
    }
    int getIDOfLoggedUser();
    char chooseOptionOfMainMenu();
    void registerUser();
    void logonUser();
    char chooseOptionOfUserMenu();
    void addIncome();
    void addExpense();
    void displayBalanceOfCurrentMonth();
    void displayBalanceOfPreviousMonth();
    void displayBalanceOfChosenFrame();
    void changePassword();
    void logoutUser();
};
*/
#endif
