#include "ExpenseManager.h"

void ExpenseManager::listExpenses(vector <Expense> expenses){
    for (int i=0; i < expenses.size(); i++) {
        //cout << (expenses[i].getID()) << endl;
        //cout << (expenses[i].getUserID()) << endl;
        cout << endl << (expenses[i].getDate()) << endl;
        cout << (expenses[i].getItem()) << endl;
        cout << (expenses[i].getAmount()) << endl;
    }
}

void ExpenseManager::addExpense(){
    Expense expense;

    system("cls");
    cout << " >>> NEW EXPENSE ADDITION <<<" << endl << endl;
    expense = giveNewExpenseData();

    expenses.push_back(expense);
    if(fileWithExpenses.addExpenseToFile(expense))
        cout << "New expense has been added." << endl;
    else
        cout << "Error. The expense has not been added." << endl;
    system("pause");
}

Expense ExpenseManager::giveNewExpenseDataOfToday(){
    Expense expense;
    string date, item;
    double amount;
    int dateInt;

    date = DateOperation::getTodayDate();
    expense.setDate(date);
    expense.setID(getNewExpenseID());
    expense.setUserID(LOGGED_USER_ID);

    cout << "Provide the item of expense: ";
    item = AuxiliaryMethods::getLine();
    expense.setItem(item);

    cout << "Provide how much the expense is: ";
    string amount_str = AuxiliaryMethods::getLine();
    amount_str = AuxiliaryMethods::changeCommaToDot(amount_str);
    amount = atof(amount_str.c_str());
    expense.setAmount(amount);

    dateInt = DateOperation::changeDateFromStringToInt(date);
    expense.setDateInt(dateInt);

    return expense;
}

Expense ExpenseManager::giveNewExpenseDataOfChosenDay(){
    Expense expense;
    string date, item;
    double amount;
    int dateInt;

    cout << "Provide the date of expense (yyyy-mm-dd): ";
    date = AuxiliaryMethods::getLine();
    bool exam = DateOperation::checkDate(date);

    while (exam == 0){
        cout << endl << "Incorrect date" << endl << endl;
        system("pause");
        cout << "Provide the date of expense (yyyy-mm-dd): ";
        date = AuxiliaryMethods::getLine();
        exam = DateOperation::checkDate(date);
    }

    expense.setDate(date);

    expense.setID(getNewExpenseID());
    expense.setUserID(LOGGED_USER_ID);

    cout << "Provide the item of expense: ";
    item = AuxiliaryMethods::getLine();
    expense.setItem(item);

    cout << "Provide how much the expense is: ";
    string amount_str = AuxiliaryMethods::getLine();
    amount_str = AuxiliaryMethods::changeCommaToDot(amount_str);
    amount = atof(amount_str.c_str());
    expense.setAmount(amount);

    dateInt = DateOperation::changeDateFromStringToInt(date);
    expense.setDateInt(dateInt);

    return expense;
}

Expense ExpenseManager::giveNewExpenseData(){
    char answer;
    cout << "Is the expense of today? [y/n]" << endl;
    answer = AuxiliaryMethods::getChar();

    Expense expense;

    switch(answer){
            case 'y':
                {
                    expense = giveNewExpenseDataOfToday();
                    break;
                }
            case 'n':
                {
                    expense = giveNewExpenseDataOfChosenDay();
                    break;
                }
            default:
                cout << endl << "Incorrect answer" << endl << endl;
                system("pause");
                break;
            }

    return expense;
}

int ExpenseManager::getNewExpenseID()
{
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getID() + 1;
}

vector <Expense> ExpenseManager::chooseExpensesFromMonth(int year, int month){
    vector <Expense> chosenExpenses;
    string expenseDate;
    int expenseYear, expenseMonth;

    for (int i=0; i < expenses.size(); i++) {
        expenseDate = expenses[i].getDate();
        expenseYear = DateOperation::getYear(expenseDate);
        expenseMonth = DateOperation::getMonth(expenseDate);
        if ((expenseYear == year) && (expenseMonth == month)){
            chosenExpenses.push_back(expenses[i]);
        }
    }
    return chosenExpenses;
}

void ExpenseManager::displayBalanceOfCurrentMonth(){
    vector <Expense> chosenExpenses;
    string today = DateOperation::getTodayDate();
    int currentYear = DateOperation::getYear(today);
    int currentMonth = DateOperation::getMonth(today);
    chosenExpenses = chooseExpensesFromMonth(currentYear, currentMonth);
    listExpenses(sortExpenses(chosenExpenses));
}

double ExpenseManager::calculateSumOfExpensesOfCurrentMonth(){
    double sumOfExpenses=0.0;
    double amount;
    string today = DateOperation::getTodayDate();
    int currentYear = DateOperation::getYear(today);
    int currentMonth = DateOperation::getMonth(today);
    vector <Expense> chosenExpenses = chooseExpensesFromMonth(currentYear, currentMonth);
    for (int i=0; i < chosenExpenses.size(); i++) {
        amount = chosenExpenses[i].getAmount();
        sumOfExpenses = sumOfExpenses + amount;
    }
    return sumOfExpenses;
}

vector <Expense> ExpenseManager::sortExpenses(vector <Expense> chosenExpenses){
    struct less_than_key
    {
        inline bool operator() (Expense& struct1, Expense& struct2)
        {
            return (struct1.getDateInt() < struct2.getDateInt());
        }
    };
    sort(chosenExpenses.begin(), chosenExpenses.end(), less_than_key());
    return chosenExpenses;
}

void ExpenseManager::displayBalanceOfPreviousMonth(){
    vector <Expense> chosenExpenses;
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

    chosenExpenses = chooseExpensesFromMonth(previousYear, previousMonth);
    listExpenses(sortExpenses(chosenExpenses));
}

double ExpenseManager::calculateSumOfExpensesOfPreviousMonth(){
    double sumOfExpenses=0.0;
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

    vector <Expense> chosenExpenses = chooseExpensesFromMonth(previousYear, previousMonth);
    for (int i=0; i < chosenExpenses.size(); i++) {
        amount = chosenExpenses[i].getAmount();
        sumOfExpenses = sumOfExpenses + amount;
    }
    return sumOfExpenses;
}

void ExpenseManager::displayBalanceOfChosenFrame(string dateStart, string dateEnd){
    vector <Expense> chosenExpenses;
    chosenExpenses = chooseExpensesFromChosenFrame(dateStart, dateEnd);
    listExpenses(sortExpenses(chosenExpenses));
}

double ExpenseManager::calculateSumOfExpensesOfChosenFrame(string dateStart, string dateEnd){
    double sumOfExpenses=0.0;
    double amount;
    vector <Expense> chosenExpenses = chooseExpensesFromChosenFrame(dateStart, dateEnd);
    for (int i=0; i < chosenExpenses.size(); i++) {
        amount = chosenExpenses[i].getAmount();
        sumOfExpenses = sumOfExpenses + amount;
    }
    return sumOfExpenses;
}

vector <Expense> ExpenseManager::chooseExpensesFromChosenFrame(string dateStart, string dateEnd){
    vector <Expense> chosenExpenses;
    int startYear = DateOperation::getYear(dateStart);
    int startMonth = DateOperation::getMonth(dateStart);
    int startDay = DateOperation::getDay(dateStart);
    int endYear = DateOperation::getYear(dateEnd);
    int endMonth = DateOperation::getMonth(dateEnd);
    int endDay = DateOperation::getDay(dateEnd);

    string expenseDate;
    int expenseYear, expenseMonth, expenseDay;

    for (int i=0; i < expenses.size(); i++) {
        expenseDate = expenses[i].getDate();
        expenseYear = DateOperation::getYear(expenseDate);
        expenseMonth = DateOperation::getMonth(expenseDate);
        expenseDay = DateOperation::getDay(expenseDate);
        if ((expenseYear >= startYear) && (expenseMonth >= startMonth) && (expenseDay >= startDay)
            && (expenseYear <= endYear) && (expenseMonth <= endMonth) && (expenseDay <= endDay)){
            chosenExpenses.push_back(expenses[i]);
        }
    }
    return chosenExpenses;
}
