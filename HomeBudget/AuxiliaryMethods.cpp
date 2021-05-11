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

string AuxiliaryMethods::doubleToStringConversion(double number){
    string str = to_string(number);
    return str;
}

string AuxiliaryMethods::changeCommaToDot(string input){
    string output;
    string toReplace = ",";
    size_t pos = input.find(toReplace);
    if (input.find(toReplace) != string::npos)
        output = input.replace(pos, toReplace.length(), ".");
    else
        output =input;
    return output;
}

int AuxiliaryMethods::stringToIntConversion(string input){
    int inputInt;
    istringstream iss(input);
    iss >> inputInt;
    return inputInt;
}
