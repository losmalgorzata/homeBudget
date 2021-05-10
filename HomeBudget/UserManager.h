#ifndef USERMANAGER_H
#define USERMANAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "User.h"
#include "FileWithUsers.h"

using namespace std;

class UserManager
{
    int loggedUserID;
    vector <User> users;

    bool doesLoginExist(string login);
    FileWithUsers fileWithUsers;
    User giveNewUserData();

public:
    UserManager(string filenameWithUsers) : fileWithUsers(filenameWithUsers){
        loggedUserID = 0;
        users = fileWithUsers.loadUsersFromFile();
    }

    void listAllUsers();
    int getLoggedUserID();
    int getNewUserID();
    int logonUser();
    void registerUser();
    void logoutUser();
    void changePassword();
    void saveAllUsersToFile();
    bool isUserLoggedIn();
};

#endif
