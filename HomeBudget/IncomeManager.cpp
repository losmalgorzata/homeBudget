#include "IncomeManager.h"

void IncomeManager::listIncomes(vector <Income> incomes){
    for (int i=0; i < incomes.size(); i++) {
        //cout << (incomes[i].getID()) << endl;
        //cout << (incomes[i].getUserID()) << endl;
        cout << endl << (incomes[i].getDate()) << endl;
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
    int dateInt;

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

    dateInt = DateOperation::changeDateFromStringToInt(date);
    income.setDateInt(dateInt);

    return income;
}

Income IncomeManager::giveNewIncomeDataOfChosenDay(){
    Income income;
    string date, item;
    double amount;
    int dateInt;

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

    dateInt = DateOperation::changeDateFromStringToInt(date);
    income.setDateInt(dateInt);

    return income;
}

Income IncomeManager::giveNewIncomeData(){
    char answer;
    do {
        cout << "Is the income of today? [y/n]" << endl;
        answer = AuxiliaryMethods::getChar();
    } while (answer != 'y' && answer != 'n');

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
    return(allIncomes.empty() == true ? 1 : (allIncomes.back().getID() + 1));
}

vector <Income> IncomeManager::chooseIncomesFromMonth(int year, int month){
    vector <Income> chosenIncomes;
    string incomeDate;
    int incomeYear, incomeMonth;

    for (int i=0; i < incomes.size(); i++) {
        incomeDate = incomes[i].getDate();
        incomeYear = DateOperation::getYear(incomeDate);
        incomeMonth = DateOperation::getMonth(incomeDate);
        if ((incomeYear == year) && (incomeMonth == month)){
            chosenIncomes.push_back(incomes[i]);
        }
    }
    return chosenIncomes;
}

void IncomeManager::displayBalanceOfCurrentMonth(){
    vector <Income> chosenIncomes;
    string today = DateOperation::getTodayDate();
    int currentYear = DateOperation::getYear(today);
    int currentMonth = DateOperation::getMonth(today);
    chosenIncomes = chooseIncomesFromMonth(currentYear, currentMonth);
    listIncomes(sortIncomes(chosenIncomes));
}

double IncomeManager::calculateSumOfIncomesOfCurrentMonth(){
    double sumOfIncomes=0.0;
    double amount;
    string today = DateOperation::getTodayDate();
    int currentYear = DateOperation::getYear(today);
    int currentMonth = DateOperation::getMonth(today);
    vector <Income> chosenIncomes = chooseIncomesFromMonth(currentYear, currentMonth);
    for (int i=0; i < chosenIncomes.size(); i++) {
        amount = chosenIncomes[i].getAmount();
        sumOfIncomes = sumOfIncomes + amount;
    }
    return sumOfIncomes;
}

vector <Income> IncomeManager::sortIncomes(vector <Income> chosenIncomes){
    struct less_than_key
    {
        inline bool operator() (Income& struct1, Income& struct2)
        {
            return (struct1.getDateInt() < struct2.getDateInt());
        }
    };
    sort(chosenIncomes.begin(), chosenIncomes.end(), less_than_key());
    return chosenIncomes;
}

void IncomeManager::displayBalanceOfPreviousMonth(){
    vector <Income> chosenIncomes;
    string today = DateOperation::getTodayDate();
    int currentYear = DateOperation::getYear(today);
    int currentMonth = DateOperation::getMonth(today);

    int previousMonth, previousYear;

    if (currentMonth==1){
        previousMonth = 12;
        previousYear = currentYear - 1;
    } else {
        previousMonth = currentMonth - 1;
        previousYear = currentYear;
    }

    chosenIncomes = chooseIncomesFromMonth(previousYear, previousMonth);
    listIncomes(sortIncomes(chosenIncomes));
}

double IncomeManager::calculateSumOfIncomesOfPreviousMonth(){
    double sumOfIncomes=0.0;
    double amount;
    string today = DateOperation::getTodayDate();
    int currentYear = DateOperation::getYear(today);
    int currentMonth = DateOperation::getMonth(today);

    int previousMonth, previousYear;

    if (currentMonth==1){
        previousMonth = 12;
        previousYear = currentYear - 1;
    } else {
        previousMonth = currentMonth - 1;
        previousYear = currentYear;
    }

    vector <Income> chosenIncomes = chooseIncomesFromMonth(previousYear, previousMonth);
    for (int i=0; i < chosenIncomes.size(); i++) {
        amount = chosenIncomes[i].getAmount();
        sumOfIncomes = sumOfIncomes + amount;
    }
    return sumOfIncomes;
}

void IncomeManager::displayBalanceOfChosenFrame(string dateStart, string dateEnd){
    vector <Income> chosenIncomes;
    chosenIncomes = chooseIncomesFromChosenFrame(dateStart, dateEnd);
    listIncomes(sortIncomes(chosenIncomes));
}

double IncomeManager::calculateSumOfIncomesOfChosenFrame(string dateStart, string dateEnd){
    double sumOfIncomes=0.0;
    double amount;
    vector <Income> chosenIncomes = chooseIncomesFromChosenFrame(dateStart, dateEnd);
    for (int i=0; i < chosenIncomes.size(); i++) {
        amount = chosenIncomes[i].getAmount();
        sumOfIncomes = sumOfIncomes + amount;
    }
    return sumOfIncomes;
}

vector <Income> IncomeManager::chooseIncomesFromChosenFrame(string dateStart, string dateEnd){
    vector <Income> chosenIncomes;
    int startYear = DateOperation::getYear(dateStart);
    int startMonth = DateOperation::getMonth(dateStart);
    int startDay = DateOperation::getDay(dateStart);
    int endYear = DateOperation::getYear(dateEnd);
    int endMonth = DateOperation::getMonth(dateEnd);
    int endDay = DateOperation::getDay(dateEnd);

    string incomeDate;
    int incomeYear, incomeMonth, incomeDay;

    for (int i=0; i < incomes.size(); i++) {
        incomeDate = incomes[i].getDate();
        incomeYear = DateOperation::getYear(incomeDate);
        incomeMonth = DateOperation::getMonth(incomeDate);
        incomeDay = DateOperation::getDay(incomeDate);
        if ((incomeYear >= startYear) && (incomeMonth >= startMonth) && (incomeDay >= startDay)
            && (incomeYear <= endYear) && (incomeMonth <= endMonth) && (incomeDay <= endDay)){
            chosenIncomes.push_back(incomes[i]);
        }
    }
    return chosenIncomes;
}
