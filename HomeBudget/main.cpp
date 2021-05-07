#include <iostream>

#include "HomeBudget.h"

using namespace std;

int main()
{
    //HomeBudget homeBudget("users.xml", "incomes.xml", "expenses.xml");
    HomeBudget homeBudget("users.xml");
    //homeBudget.listAllUsers();

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
                //homeBudget.addIncome();
                break;
            case '2':
                //homeBudget.addExpense();
                break;
            case '3':
                //homeBudget.displayBalanceOfCurrentMonth();
                break;
            case '4':
                //homeBudget.displayBalanceOfPreviousMonth();
                break;
            case '5':
                //homeBudget.displayBalanceOfChosenFrame();
                break;
            case '6':
                homeBudget.changePassword();
                homeBudget.listAllUsers();
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


/*
int get_year(string date)
{
    int tm_year, tm_mon, tm_mday;
    sscanf(date.c_str(), "%d-%d-%d", &tm_year, &tm_mon, &tm_mday);
    return tm_year;
};

int get_month(string date)
{
    int tm_year, tm_mon, tm_mday;
    sscanf(date.c_str(), "%d-%d-%d", &tm_year, &tm_mon, &tm_mday);
    return tm_mon;
};

int get_days(string date)
{
    int tm_year, tm_mon, tm_mday;
    sscanf(date.c_str(), "%d-%d-%d", &tm_year, &tm_mon, &tm_mday);
    return tm_mday;
};

void compare_dates(string date1, string date2)
{
    int year1 = get_year(date1);
    int month1 = get_month(date1);
    int days1 = get_days(date1);
    int year2 = get_year(date2);
    int month2 = get_month(date2);
    int days2 = get_days(date2);

    if (year1 > year2) {
        cout << date1 << " is later than " << date2 << endl;
    } else if (year1 < year2) {
        cout << date2 << " is later than " << date1 << endl;
    } else {
        if (month1 > month2) {
            cout << date1 << " is later than " << date2 << endl;
        } else if (month1 < month2) {
            cout << date2 << " is later than " << date1 << endl;
        } else {
            if (days1 > days2) {
                cout << date1 << " is later than " << date2 << endl;
            } else if (days1 < days2) {
                cout << date2 << " is later than " << date1 << endl;
            } else {
                cout << "Dates are equal" << endl;
            }
        }
    }
}

string format_date(string date)
{
    char buf[11];
    int tm_year, tm_mon, tm_mday;
    sscanf(date.c_str(), "%d-%d-%d", &tm_year, &tm_mon, &tm_mday);
    sprintf(buf, "%d-%02d-%02d", tm_year, tm_mon, tm_mday);
    return buf;
}

bool is_leap_year(int year)
{
    if (year%4 == 0){
        if (year%400 == 0){
            return true;
        } else if (year%100 == 0) {
            return false;
        } else {
            return true;
        }
    } else {
        return false;
    }
}

int number_of_days(string date)
{
    int days;

    char buf[11];
    int a, b, c;
    sscanf(date.c_str(), "%d-%d-%d", &a, &b, &c);

    switch (b)
        {
        case 1:
            {
                days = 31;
                break;
            }
        case 2:
            {
                if(is_leap_year(a))
                    days = 29;
                else
                    days = 28;
                break;
            }
        case 3:
            {
                days = 31;
                break;
            }
        case 4:
            {
                days = 30;
                break;
            }
        case 5:
            {
                days = 31;
                break;
            }
        case 6:
            {
                days = 30;
                break;
            }
        case 7:
            {
                days = 31;
                break;
            }
        case 8:
            {
                days = 31;
                break;
            }
        case 9:
            {
                days = 30;
                break;
            }
        case 10:
            {
                days = 31;
                break;
            }
        case 11:
            {
                days = 30;
                break;
            }
        case 12:
            {
                days = 31;
                break;
            }
        default:
            cout << endl << "Incorrect month" << endl << endl;
            break;
        }

    return days;
}
*/



/*  while ( xml.FindElem("User") )
    {
        xml.IntoElem();
        xml.FindElem( "Login" );
        MCD_STR strLogin = xml.GetData();
        xml.FindElem( "Amount" );
        double amount = atof( MCD_2PCSZ(xml.GetData()) );
        xml.FindElem( "Date" );
        MCD_STR strDate = xml.GetData();
        xml.OutOfElem();

        cout << "Login: " << strLogin << endl;
        cout << "Amount: " << amount << endl;
        cout << "Date: " << format_date(strDate) << endl;
        cout << "Leap year (2000) " << is_leap_year(2000) << endl;
        cout << "Leap year (1999) " << is_leap_year(1999) << endl;
        cout << "Leap year (2004) " << is_leap_year(2004) << endl;
        cout << "Leap year (2010) " << is_leap_year(2010) << endl;
        cout << "Leap year (2400) " << is_leap_year(2400) << endl;
        cout << "number of days " << number_of_days(strDate) << endl;

    }

    time_t now = time(0);
    char* dt = ctime(&now);
    cout << "Current date: " << dt << endl;

    time_t now2 = time(0);
    tm *ltm = localtime(&now2);
    // print various components of tm structure.
    cout << "Year:" << 1900 + ltm->tm_year<<endl;
    cout << "Month: "<< 1 + ltm->tm_mon<< endl;
    cout << "Day: "<< ltm->tm_mday << endl;
    compare_dates("2000-01-01", "2000-01-02");
    compare_dates("2000-01-01", "2000-02-01");
    compare_dates("2000-01-01", "2001-01-02");
    compare_dates("2000-01-10", "2000-01-02");
    compare_dates("2000-01-01", "2000-01-01");

    return 0;
}
*/
