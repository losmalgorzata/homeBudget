#include "UserManager.h"

void UserManager::listAllUsers()
{
    for (int i=0; i < users.size(); i++)
    {
        cout << (users[i].getUserID()) << endl;
        cout << (users[i].getLogin()) << endl;
        cout << (users[i].getPassword()) << endl;
        cout << (users[i].getName()) << endl;
        cout << (users[i].getSurname()) << endl;
    }
}
