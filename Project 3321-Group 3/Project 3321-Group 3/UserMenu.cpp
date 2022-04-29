#include "UserMenu.h"
#include "reviews.h"
#include "checkOut.h"


void printUserMenu(){

//Would eventually like to replace "User" with actual username - Amani
    cout << "Welcome User!\n" ;
    cout << "\t 1. View Products \n" ;
    cout << "\t 2. View/Modify Your Cart\n";
    cout << "\t 3. View or Add a Review \n";
    cout << "\t 4. Checkout.\n";
    cout << "\t 5. Return to Main Menu \n";
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
            updateReviews();
        break;
        
        case 4:
            userCheckoutFromUserMenu();
            break;


        case 5:
            cin.clear();
            cin.ignore();
            system("CLS");
            int choice;
            printMainMenu();
            cin >> choice;
            printDetailMainMenu(choice);
        break;

        default:
        cout << "INVALID CHOICE";
        break;

    }

}