#include "UserManager.h"

void UserManager::listAllUsers() {
    for (int i=0; i < users.size(); i++) {
        cout << (users[i].getUserID()) << endl;
        cout << (users[i].getLogin()) << endl;
        cout << (users[i].getPassword()) << endl;
        cout << (users[i].getName()) << endl;
        cout << (users[i].getSurname()) << endl;
    }
}

int UserManager::getIDOfLoggedUser(){
    return loggedUserID;
}

int UserManager::logonUser(){
    string login="", password="";
    cout << "Provide login: ";
    login = AuxiliaryMethods::getLine();

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login){
            for (int p = 0; p < 3; p++)
            {
                cout << "Provide password. " << 3-p << " trials left.";
                password = AuxiliaryMethods::getLine();
                if (users[i].getPassword() == password)
                {
                    cout << "User logged in" << endl;
                    Sleep(1000);
                    loggedUserID = users[i].getUserID();
                    return loggedUserID;
                }
            }
            cout << "The password is incorrect for the third time" << endl;
            Sleep(1500);
        }
    }
    cout << "No such a login" << endl;
    Sleep(1500);
    return 0;
}



