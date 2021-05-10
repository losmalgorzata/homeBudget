#include "IncomeManager.h"

void IncomeManager::listIncomes(){
    for (int i=0; i < incomes.size(); i++) {
        cout << (incomes[i].getID()) << endl;
        cout << (incomes[i].getUserID()) << endl;
        cout << (incomes[i].getDate()) << endl;
        cout << (incomes[i].getItem()) << endl;
        cout << (incomes[i].getAmount()) << endl;
    }
}

void IncomeManager::addIncome(){
    Income income;

    system("cls");
    cout << " >>> NEW INCOME ADDITION <<<" << endl << endl;
    income = giveNewIncomeData();

    incomes.push_back(income);
    if(fileWithIncomes.addIncomeToFile(income))
        cout << "New income has been added." << endl;
    else
        cout << "Error. The income has not been added." << endl;
    system("pause");
}

Income IncomeManager::giveNewIncomeDataOfToday(){
    Income income;
    string date, item;
    double amount;

    date = DateOperation::getTodayDate();
    income.setDate(date);
    income.setID(getNewIncomeID());
    income.setUserID(LOGGED_USER_ID);

    cout << "Provide the item of income: ";
    item = AuxiliaryMethods::getLine();
    income.setItem(item);

    cout << "Provide how much the income is: ";
    string amount_str = AuxiliaryMethods::getLine();
    amount_str = AuxiliaryMethods::changeCommaToDot(amount_str);
    amount = atof(amount_str.c_str());
    income.setAmount(amount);

    return income;
}

Income IncomeManager::giveNewIncomeDataOfChosenDay(){
    Income income;
    string date, item;
    double amount;

    cout << "Provide the date of income (yyyy-mm-dd): ";
    date = AuxiliaryMethods::getLine();
    bool exam = DateOperation::checkDate(date);

    while (exam == 0){
        cout << endl << "Incorrect date" << endl << endl;
        system("pause");
        cout << "Provide the date of income (yyyy-mm-dd): ";
        date = AuxiliaryMethods::getLine();
        exam = DateOperation::checkDate(date);
    }

    income.setDate(date);

    income.setID(getNewIncomeID());
    income.setUserID(LOGGED_USER_ID);

    cout << "Provide the item of income: ";
    item = AuxiliaryMethods::getLine();
    income.setItem(item);

    cout << "Provide how much the income is: ";
    string amount_str = AuxiliaryMethods::getLine();
    amount_str = AuxiliaryMethods::changeCommaToDot(amount_str);
    amount = atof(amount_str.c_str());
    income.setAmount(amount);

    return income;
}

Income IncomeManager::giveNewIncomeData(){
    char answer;
    cout << "Is the income of today? [y/n]" << endl;
    answer = AuxiliaryMethods::getChar();

    Income income;

    switch(answer){
            case 'y':
                {
                    income = giveNewIncomeDataOfToday();
                    break;
                }
            case 'n':
                {
                    income = giveNewIncomeDataOfChosenDay();
                    break;
                }
            default:
                cout << endl << "Incorrect answer" << endl << endl;
                system("pause");
                break;
            }

    return income;
}

int IncomeManager::getNewIncomeID()
{
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getID() + 1;
}
/*
Income IncomeManager::giveNewIncomeData(){
    Income income;
    string date, item;
    double amount;

    income.setID(getNewIncomeID());
    income.setUserID(LOGGED_USER_ID);

    cout << "Provide the date of income (yyyy-mm-dd): ";
    date = AuxiliaryMethods::getLine();
    income.setDate(date);

    cout << "Provide the item of income: ";
    item = AuxiliaryMethods::getLine();
    income.setItem(item);

    cout << "Provide how much the income is: ";
    amount = atof(AuxiliaryMethods::getLine().c_str());
    income.setAmount(amount);

    return income;
}

*/
