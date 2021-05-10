#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"

using namespace std;

class FileWithIncomes : public XMLFile
{
    const string FILENAME_WITH_INCOMES;
    int lastIncomeID;

public:
    FileWithIncomes(string FILENAMEWITHINCOMES) : XMLFile(FILENAMEWITHINCOMES){
        lastIncomeID = 0;
    };
    bool addIncomeToFile(Income income);
    vector <Income> loadIncomesFromFile(int loggedUserID);
};

#endif

