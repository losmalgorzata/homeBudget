#include "HomeBudget.h"

void HomeBudget::listAllUsers(){
    userManager.listAllUsers();
}

int HomeBudget::getLoggedUserID(){
    userManager.getLoggedUserID();
}

char HomeBudget::chooseOptionOfMainMenu(){
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register new user" << endl;
    cout << "2. Log in" << endl;
    cout << "3. Exit program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}

int HomeBudget::logonUser(){
    userManager.logonUser();

    if (userManager.isUserLoggedIn()){
        incomeManager = new IncomeManager(FILENAME_WITH_INCOMES, userManager.getLoggedUserID());
        expenseManager = new ExpenseManager(FILENAME_WITH_EXPENSES, userManager.getLoggedUserID());
    }

}

void HomeBudget::registerUser()
{
    userManager.registerUser();
}

char HomeBudget::chooseOptionOfUserMenu() {
    char choice;
    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Display balance of the current month" << endl;
    cout << "4. Display balance of the previous month" << endl;
    cout << "5. Display balance of the chosen time frame" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}

void HomeBudget::logoutUser()
{
    userManager.logoutUser();
    delete incomeManager;
    incomeManager = NULL;
    delete expenseManager;
    expenseManager = NULL;
}

void HomeBudget::changePassword()
{
    userManager.changePassword();
}

void HomeBudget::addIncome(){
    if(userManager.isUserLoggedIn())
    {
        incomeManager->addIncome();
    }
    else
    {
        cout << "Please log in before adding an income" << endl;
        system("pause");
    }
}

void HomeBudget::addExpense(){
    if(userManager.isUserLoggedIn())
    {
        expenseManager->addExpense();
    }
    else
    {
        cout << "Please log in before adding an expense" << endl;
        system("pause");
    }
}

void HomeBudget::listIncomes(vector <Income> incomes){
    incomeManager->listIncomes(incomes);
}

void HomeBudget::listExpenses(vector <Expense> expenses){
    expenseManager->listExpenses(expenses);
}

void HomeBudget::displayBalanceOfCurrentMonth(){
    cout << endl << "    >>> INCOMES <<<" << endl;
    cout << "---------------------------" << endl;
    incomeManager->displayBalanceOfCurrentMonth();
    cout << endl << "    >>> EXPENSES <<<" << endl;
    cout << "---------------------------" << endl;
    expenseManager->displayBalanceOfCurrentMonth();
    double sumOfIncomes = incomeManager->calculateSumOfIncomesOfCurrentMonth();
    double sumOfExpenses = expenseManager->calculateSumOfExpensesOfCurrentMonth();
    cout << endl << "    >>> SUMMARY <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Sum of the incomes: " << sumOfIncomes << endl;
    cout << "Sum of the expenses: " << sumOfExpenses << endl;
    double difference = sumOfIncomes - sumOfExpenses;
    cout << "Difference between incomes and expenses: " << difference << endl;
    system("pause");
}

void HomeBudget::displayBalanceOfPreviousMonth(){
    cout << endl << "    >>> INCOMES <<<" << endl;
    cout << "---------------------------" << endl;
    incomeManager->displayBalanceOfPreviousMonth();
    cout << endl << "    >>> EXPENSES <<<" << endl;
    cout << "---------------------------" << endl;
    expenseManager->displayBalanceOfPreviousMonth();
    double sumOfIncomes = incomeManager->calculateSumOfIncomesOfPreviousMonth();
    double sumOfExpenses = expenseManager->calculateSumOfExpensesOfPreviousMonth();
    cout << endl << "    >>> SUMMARY <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Sum of the incomes: " << sumOfIncomes << endl;
    cout << "Sum of the expenses: " << sumOfExpenses << endl;
    double difference = sumOfIncomes - sumOfExpenses;
    cout << "Difference between incomes and expenses: " << difference << endl;
    system("pause");
}

void HomeBudget::displayBalanceOfChosenFrame(){
    string dateStart = DateOperation::giveDateStart();
    string dateEnd = DateOperation::giveDateEnd();
    cout << endl << "    >>> INCOMES <<<" << endl;
    cout << "---------------------------" << endl;
    incomeManager->displayBalanceOfChosenFrame(dateStart, dateEnd);
    cout << endl << "    >>> EXPENSES <<<" << endl;
    cout << "---------------------------" << endl;
    expenseManager->displayBalanceOfChosenFrame(dateStart, dateEnd);
    double sumOfIncomes = incomeManager->calculateSumOfIncomesOfChosenFrame(dateStart, dateEnd);
    double sumOfExpenses = expenseManager->calculateSumOfExpensesOfChosenFrame(dateStart, dateEnd);
    cout << endl << "    >>> SUMMARY <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Sum of the incomes: " << sumOfIncomes << endl;
    cout << "Sum of the expenses: " << sumOfExpenses << endl;
    double difference = sumOfIncomes - sumOfExpenses;
    cout << "Difference between incomes and expenses: " << difference << endl;
    system("pause");
}
