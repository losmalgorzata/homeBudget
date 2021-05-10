#ifndef DATEOPERATION_H
#define DATEOPERATION_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <string.h>
#include <ctime>

#include "AuxiliaryMethods.h"

using namespace std;

class DateOperation
{
public:
    static string getTodayDate();
    static bool checkDate(string date);
    static int getYear(string date);
    static int getMonth(string date);
    static int getDay(string date);
    static bool isLeapYear(int year);
    static int numberOfDaysInMonth(int year, int month);
    static string getMaxDate();
    static bool checkMinCriterion(string date);
    static bool checkMaxCriterion(string date);
};

#endif
