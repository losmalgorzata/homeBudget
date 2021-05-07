#include "AuxiliaryMethods.h"

char AuxiliaryMethods::getChar(){
    string entry = "";
    char input  = {0};

    while (true){
        getline(cin, entry);

        if (entry.length() == 1){
            input = entry[0];
            break;
        }
        cout << "Incorrect char. Try again." << endl;
    }
    return input;
}

string AuxiliaryMethods::getLine() {
    string entry = "";
    getline(cin, entry);
    return entry;
}

string AuxiliaryMethods::intToStringConversion(int number){
    ostringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
