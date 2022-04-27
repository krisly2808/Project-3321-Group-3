#include "UserMenu.h"


void printUserMenu(){

//Would eventually like to replace "User" with actual username
    cout << "Welcome User!" ;
    cout << "\t 1. View Products \n" ;
    cout << "\t 2. View Your Cart\n";
    cout << "\t 3. View or Add a Review \n";
    cout << "\t 4. Return to Main Menu \n";
}

void printDetailsUserMenu(int option){

    system("CLS");
    cin.clear();

    switch(option){
        case 1: 
        viewProducts();
        break;

        case 2:
        printCartMenu();
        break;

        case 3:
        printReviews();
        break;

        case 4:
        printMainMenu();
        break;

        default:
        cout << "INVALID CHOICE";
        break;



    }

}