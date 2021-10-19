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

int UserManager::getLoggedUserID(){
    return loggedUserID;
}

int UserManager::logonUser(){
    string login="", password="";
    cout << "Provide login: ";
    login = AuxiliaryMethods::getLine();

    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login){
            for (int p = 0; p < 3; p++){
                cout << "Provide password. " << 3-p << " trials left: ";
                password = AuxiliaryMethods::getLine();
                if (users[i].getPassword() == password){
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

void UserManager::registerUser(){
    User user = giveNewUserData();

    users.push_back(user);
    fileWithUsers.addUserToFile(user);

    cout << endl << "Registration successful" << endl << endl;
    system("pause");
}

User UserManager::giveNewUserData(){
    User user;
    user.setUserID(getNewUserID());
    string login;

    do{
        cout << "Provide login: ";
        cin >> login;
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()) == true);

    string password;
    cout << "Provide password: ";
    cin >> password;
    user.setPassword(password);

    string name;
    cout << "Provide name: ";
    cin >> name;
    user.setName(name);

    string surname;
    cout << "Provide surname: ";
    cin >> surname;
    user.setSurname(surname);

    return user;
}

int UserManager::getNewUserID(){
    return(users.empty() == true ? 1 : (users.back().getUserID() + 1));
}

bool UserManager::doesLoginExist(string login){
    for (int i=0; i < users.size(); i++)
    {
        if (users[i].getLogin() == login)
        {
            cout << endl << "There is such a login already" << endl;
            return true;
        }
    }
    return false;
}

void UserManager::logoutUser(){
    loggedUserID = 0;
}

void UserManager::changePassword(){
    string newPasword = "";
    cout << "Provide a new password: ";
    newPasword = AuxiliaryMethods::getLine();

    for (int i=0; i < users.size(); i++)
    {
        if (users[i].getUserID() == loggedUserID)
        {
            users[i].setPassword(newPasword);
            cout << "The password has been changed" << endl;
            Sleep(1500);
        }
    }

    saveAllUsersToFile();
}

void UserManager::saveAllUsersToFile(){
    CMarkup xml;
    xml.Load( fileWithUsers.getFilename().c_str() );
    xml.ResetPos();
    xml.FindElem("Users");
    xml.RemoveElem();

    xml.AddElem("Users");
    for (int i=0; i < users.size(); i++){
        xml.ResetPos();
        xml.FindElem();
        xml.IntoElem();
        xml.AddElem("User");
        xml.IntoElem();
        xml.AddElem("UserID", AuxiliaryMethods::intToStringConversion(users[i].getUserID()));
        xml.AddElem("Login", users[i].getLogin());
        xml.AddElem("Password", users[i].getPassword());
        xml.AddElem("Name", users[i].getName());
        xml.AddElem("Surname", users[i].getSurname());
        xml.OutOfElem();
        xml.OutOfElem();
    }
    xml.Save(fileWithUsers.getFilename().c_str());
}

bool UserManager::isUserLoggedIn()
{
    return(loggedUserID > 0 ? true : false);
}
