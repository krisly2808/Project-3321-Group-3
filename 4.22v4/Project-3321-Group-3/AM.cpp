#include "AM.h"


void printAdminMenu(){


//Would eventually like to replace "Admin" with actual admin username
    cout << "Welcome Admin!" ;
    cout << "\t 1. View and Manage Your Orders \n" ;
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

        case 1: //viewOrdersMenu();
        break;

        case 2: 
        int choice;
        viewArtMenu();
        cin >> choice;
        viewDetailArtMenu(choice);
        break;

        case 3: //inventoryMenu();
        break;

        case 4: //changeCurrency();
        break;

    }
}
