#ifndef AUXILIARYMETHODS_H
#define AUXILIARYMETHODS_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class AuxiliaryMethods
{
public:
    static char getChar();
    static string getLine();
    static string intToStringConversion(int number);
    static string doubleToStringConversion(double number);
    static string changeCommaToDot(string input);
};

#endif
