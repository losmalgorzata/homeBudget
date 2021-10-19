#include <iostream>

#include "HomeBudget.h"

using namespace std;

int main()
{
    HomeBudget homeBudget("users.xml", "incomes.xml", "expenses.xml");

    char choice;

    while(true){
        if (homeBudget.getLoggedUserID() == 0){
            choice = homeBudget.chooseOptionOfMainMenu();
            switch(choice){
            case '1':
                homeBudget.registerUser();
                break;
            case '2':
                homeBudget.logonUser();
                //homeBudget.listIncomes(incomes);
                system("pause");
                break;
            case '3':
                exit(0);
                break;
            default:
                cout << endl << "Incorrect choice" << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = homeBudget.chooseOptionOfUserMenu();
            switch(choice){
            case '1':
                homeBudget.addIncome();
                system("pause");
                break;
            case '2':
                homeBudget.addExpense();
                break;
            case '3':
                homeBudget.displayBalanceOfCurrentMonth();
                break;
            case '4':
                homeBudget.displayBalanceOfPreviousMonth();
                break;
            case '5':
                homeBudget.displayBalanceOfChosenFrame();
                break;
            case '6':
                homeBudget.changePassword();
                //homeBudget.listAllUsers();
                system("pause");
                break;
            case '7':
                homeBudget.logoutUser();
                break;
            default:
                cout << endl << "Incorrect choice" << endl << endl;
                system("pause");
                break;
            }
        }
    }
    return 0;
}

