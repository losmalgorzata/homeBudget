#include "DateOperation.h"

int DateOperation::getYear(string date){
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    return year;
}

int DateOperation::getMonth(string date){
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    return month;
}

int DateOperation::getDay(string date){
    int year, month, day;
    sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
    return day;
}

bool DateOperation::isLeapYear(int year){
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

int DateOperation::numberOfDaysInMonth(int year, int month){
    bool leapYear = isLeapYear(year);
    int days;

    switch (month){
        case 1:
            {
                days = 31;
                break;
            }
        case 2:
            {
                if(leapYear)
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

string DateOperation::getMaxDate(){
    string maxDate, year_str, month_str, day_str;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = numberOfDaysInMonth(year, month);

    year_str = AuxiliaryMethods::intToStringConversion(year);

    if (month < 10)
        month_str = "0" + AuxiliaryMethods::intToStringConversion(month);
    else
        month_str = AuxiliaryMethods::intToStringConversion(month);

    if (day < 10)
        day_str = "0" + AuxiliaryMethods::intToStringConversion(day);
    else
        day_str = AuxiliaryMethods::intToStringConversion(day);

    maxDate = year_str + "-" + month_str + "-" + day_str;

    return maxDate;
}

bool DateOperation::checkMinCriterion(string date){
    string minDate = "2000-01-01";
    int minYear = getYear(minDate);
    int minMonth = getMonth(minDate);
    int minDay = getDay(minDate);

    int year = getYear(date);
    int month = getMonth(date);
    int day = getDay(date);

    bool yearCriterion;
    if (year >= minYear)
        yearCriterion = true;
    else
        yearCriterion = false;

    bool monthCriterion;
    if (month >= minMonth)
        monthCriterion = true;
    else
        monthCriterion = false;

    bool dayCriterion;
    if (day >= minDay)
        dayCriterion = true;
    else
        dayCriterion = false;

    int exam = yearCriterion + monthCriterion + dayCriterion;
    if (exam == 3) {
        return true;
    } else {
        return false;
    }
}

bool DateOperation::checkMaxCriterion(string date){
    string maxDate = getMaxDate();
    int maxYear = getYear(maxDate);
    int maxMonth = getMonth(maxDate);
    int maxDay = getDay(maxDate);

    int year = getYear(date);
    int month = getMonth(date);
    int day = getDay(date);

    if (year > maxYear)
        return false;
    else if (year < maxYear){
        if (month <= 12 && day <= numberOfDaysInMonth(year, month))
            return true;
        else
            return false;
    } else if (year == maxYear){
        if (month > maxMonth)
            return false;
        else if (month <= maxMonth) {
            if (day <= numberOfDaysInMonth(year, month))
                return true;
            else
                return false;
        }
    }
}

string DateOperation::getTodayDate(){
    string date, year_str, month_str, day_str;
    time_t now = time(0);
    tm *ltm = localtime(&now);

    int year = 1900 + ltm->tm_year;
    int month = 1 + ltm->tm_mon;
    int day = ltm->tm_mday;

    year_str = AuxiliaryMethods::intToStringConversion(year);

    if (month < 10)
        month_str = "0" + AuxiliaryMethods::intToStringConversion(month);
    else
        month_str = AuxiliaryMethods::intToStringConversion(month);

    if (day < 10)
        day_str = "0" + AuxiliaryMethods::intToStringConversion(day);
    else
        day_str = AuxiliaryMethods::intToStringConversion(day);

    date = year_str + "-" + month_str + "-" + day_str;

    return date;
}

bool DateOperation::checkDate(string date){
    bool minCriterion = checkMinCriterion(date);
    bool maxCriterion = checkMaxCriterion(date);

    int exam = minCriterion + maxCriterion;
    if (exam == 2)
        return true;
    else
        return false;
}

int DateOperation::changeDateFromStringToInt(string date){
    int dateInt;
    string dateStr;
    int year = getYear(date);
    int month = getMonth(date);
    int day = getDay(date);

    string yearStr, monthStr, dayStr;
    yearStr = AuxiliaryMethods::intToStringConversion(year);

    if (month < 10)
        monthStr = "0" + AuxiliaryMethods::intToStringConversion(month);
    else
        monthStr = AuxiliaryMethods::intToStringConversion(month);

    if (day < 10)
        dayStr = "0" + AuxiliaryMethods::intToStringConversion(day);
    else
        dayStr = AuxiliaryMethods::intToStringConversion(day);

    dateStr = yearStr + monthStr + dayStr;
    dateInt = AuxiliaryMethods::stringToIntConversion(dateStr);

    return dateInt;
}

string DateOperation::giveDateStart(){
    string dateStart;
    cout << "Provide start date [yyyy-mm-dd]: ";
    dateStart = AuxiliaryMethods::getLine();
    bool examStart = checkDate(dateStart);

    while (examStart == 0){
        cout << endl << "Incorrect date" << endl << endl;
        system("pause");
        cout << "Provide start date [yyyy-mm-dd]: ";
        dateStart = AuxiliaryMethods::getLine();
        examStart = checkDate(dateStart);
    }
    return dateStart;
}

string DateOperation::giveDateEnd(){
    string dateEnd;
    cout << "Provide end date [yyyy-mm-dd]: ";
    dateEnd = AuxiliaryMethods::getLine();
    bool examEnd = checkDate(dateEnd);

    while (examEnd == 0){
        cout << endl << "Incorrect date" << endl << endl;
        system("pause");
        cout << "Provide end date [yyyy-mm-dd]: ";
        dateEnd = AuxiliaryMethods::getLine();
        examEnd = checkDate(dateEnd);
    }
    return dateEnd;
}
