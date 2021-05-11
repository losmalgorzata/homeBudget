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

void HomeBudget::listIncomes(vector <Income> incomes){
    incomeManager->listIncomes(incomes);
}

void HomeBudget::displayBalanceOfCurrentMonth(){
    incomeManager->displayBalanceOfCurrentMonth();
    double sumOfIncomes = incomeManager->calculateSumOfIncomesOfCurrentMonth();
    cout << "Sum of the incomes: " << sumOfIncomes << endl;
    system("pause");
}

void HomeBudget::displayBalanceOfPreviousMonth(){
    incomeManager->displayBalanceOfPreviousMonth();
    double sumOfIncomes = incomeManager->calculateSumOfIncomesOfPreviousMonth();
    cout << "Sum of the incomes: " << sumOfIncomes << endl;
    system("pause");
}

void HomeBudget::displayBalanceOfChosenFrame(){
    string dateStart = DateOperation::giveDateStart();
    string dateEnd = DateOperation::giveDateEnd();
    incomeManager->displayBalanceOfChosenFrame(dateStart, dateEnd);
    double sumOfIncomes = incomeManager->calculateSumOfIncomesOfChosenFrame(dateStart, dateEnd);
    cout << "Sum of the incomes: " << sumOfIncomes << endl;
    system("pause");
}
