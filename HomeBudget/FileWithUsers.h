#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "User.h"
#include "AuxiliaryMethods.h"
#include "XMLFile.h"

using namespace std;

class FileWithUsers : public XMLFile
{
    const string FILENAME_WITH_USERS;

public:
    FileWithUsers(string FILENAMEWITHUSERS) : XMLFile(FILENAMEWITHUSERS){};
    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
};

#endif

