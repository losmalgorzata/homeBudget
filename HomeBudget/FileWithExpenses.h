#ifndef FILEWITHEXPENSES_H
#define FILEWITHEXPENSES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"
#include <cmath>

using namespace std;

class FileWithExpenses : public XMLFile
{
    const string FILENAME_WITH_EXPENSES;
    int lastExpenseID;

public:
    FileWithExpenses(string FILENAMEWITHEXPENSES) : XMLFile(FILENAMEWITHEXPENSES){
        lastExpenseID = 0;
    };
    bool addExpenseToFile(Expense expense);
    vector <Expense> loadExpensesFromFile(int loggedUserID);
    vector <Expense> loadAllExpensesFromFile();
};

#endif

