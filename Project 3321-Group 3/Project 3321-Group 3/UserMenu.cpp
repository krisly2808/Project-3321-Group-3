#include "UserMenu.h"


void printUserMenu(){

//Would eventually like to replace "User" with actual username
    cout << "Welcome User!\n" ;
    cout << "\t 1. View Products \n" ;
    cout << "\t 2. View/Modify Your Cart\n";
    cout << "\t 3. View or Add a Review \n";
    cout << "\t 4. Return to Main Menu \n";
}

void printDetailsUserMenu(){
    cin.clear();
    int option;
    cout << "Please input your choice";
    cin >> option;

    switch(option){
        case 1: 
        viewProducts();
        break;

        case 2:
            int choice2;
            printCartMenu();
            cin >> choice2;
            printDetailCartMenu(choice2);
        break;

        case 3:
        printReviews();
        break;
        
        case 4:
            cin.clear();
            cin.ignore();
            system("CLS");
            int choice;
            //Print out the main menu prompt-Kris Ly
            printMainMenu();
            cin >> choice;

            //Print detail menu based on input-Kris Ly
            printDetailMainMenu(choice);
        break;

        default:
        cout << "INVALID CHOICE";
        break;

    }

}