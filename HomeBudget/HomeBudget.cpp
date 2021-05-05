#include "HomeBudget.h"

void HomeBudget::listAllUsers(){
    userManager.listAllUsers();
}

int HomeBudget::getIDOfLoggedUser(){
    userManager.getIDOfLoggedUser();
}

char HomeBudget::chooseOptionOfMainMenu(){
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Register new user" << endl;
    cout << "2. Log in" << endl;
    cout << "3. Exit program" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    choice = AuxiliaryMethods::getChar();

    return choice;
}

int HomeBudget::logonUser(){
    userManager.logonUser();
    /*
    if (uzytkownikMenedzer.czyUzytkownikJestZalogowany()){
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI, uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
    }
    */
}
