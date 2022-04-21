//          University of Houston-Downtown
//          CS 3321-Software Engineering
//          Professor. Emre Yilmaz  
// Project 3321-Group 3.cpp created by Group 3:
//      +Kris Ly
//      +Amani Harrison
//      +Francisco Alfaro
//

#include <iostream>
#include "mainMenu.h"

using namespace std;

int main()
{
    char rerun;
    int option;
    //Do-while loop to repeat the program-Kris Ly
    do {
        cin.clear();
        cin.ignore();
        system("CLS");
        //Print out the main menu prompt-Kris Ly
        printMainMenu();
        cin >> option;

        //Print detail menu based on input-Kris Ly
        printDetailMainMenu(option);

        //Option to re-run the program
        cin.clear();
        cout << "\nPLease input y/Y to re-run the program or press any key to quit.\n";
        cin >> rerun;

    } while (rerun == 'y' || rerun == 'Y');
}

