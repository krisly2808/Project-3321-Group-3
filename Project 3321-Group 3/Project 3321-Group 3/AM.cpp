#include "AM.h"


void printAdminMenu(){


//Would eventually like to replace "Admin" with actual admin username
    cout << "Welcome Admin!" ;
    cout << "\t 1. View and Your Orders \n" ;
    cout << "\t 2. View and Manage Your Word and Art Bank \n";
    cout << "\t 3. View and Manage Your Inventory \n";
    cout << "\t 4. Change Currency \n";
    cout << "\t 5. Return to Main Menu \n";
}

void detailsAdminMenu(int option){
    system("CLS");
    cin.clear();
    cin.ignore();

    switch(option){

        case 1: 
        viewOrders();
        break;

        case 2: 
        viewArtMenu();
        break;

        case 3: 
        printInventoryMenu();
        break;

        case 4: //changeCurrency();
        break;

    }
}
