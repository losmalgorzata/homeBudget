#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Income.h"
#include "FileWithIncomes.h"
#include "DateOperation.h"

using namespace std;

class IncomeManager
{
    const int LOGGED_USER_ID;
    vector <Income> incomes;
    FileWithIncomes fileWithIncomes;

    Income giveNewIncomeData();

public:
    IncomeManager(string filenameWithIncomes, int loggedUserID)
        : fileWithIncomes(filenameWithIncomes), LOGGED_USER_ID(loggedUserID){
        incomes = fileWithIncomes.loadIncomesFromFile(LOGGED_USER_ID);
    };

    void addIncome();
    void listIncomes(vector <Income> incomes);
    int getNewIncomeID();
    Income giveNewIncomeDataOfChosenDay();
    Income giveNewIncomeDataOfToday();
    void displayBalanceOfCurrentMonth();
    double calculateSumOfIncomesOfCurrentMonth();
    vector <Income> chooseIncomesFromMonth(int year, int month);
    vector <Income> sortIncomes(vector <Income> chosenIncomes);
};

#endif
