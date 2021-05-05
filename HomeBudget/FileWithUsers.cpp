#include "FileWithUsers.h"

vector <User> FileWithUsers::loadUsersFromFile() {
    CMarkup xml;
    User user;
    vector <User> users;
    bool fileExists = xml.Load( getFilename().c_str() );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.ResetPos();
    xml.FindElem();
    xml.IntoElem();

    while ( xml.FindElem("User") )
    {
        User user;
        xml.IntoElem();
        xml.FindElem( "UserID" );
        int userID = atoi(xml.GetData().c_str());
        xml.FindElem( "Login" );
        string login = xml.GetData();
        xml.FindElem( "Password" );
        string password = xml.GetData();
        xml.FindElem( "Name" );
        string name = xml.GetData();
        xml.FindElem( "Surname" );
        string surname = xml.GetData();
        xml.OutOfElem();

        user.setUserID(userID);
        user.setLogin(login);
        user.setPassword(password);
        user.setName(name);
        user.setSurname(surname);
        users.push_back(user);
    }

    return users;
}
