#include "AM.h"


void printAdminMenu(){


//Would eventually like to replace "Admin" with actual admin username
    system("cls");
    cout << "Welcome Admin!" ;
    cout << "\t 1. View and Your Orders \n" ;
    cout << "\t 2. View and Manage Your Word and Art Bank \n";
    cout << "\t 3. View and Manage Your Inventory \n";
    cout << "\t 4. Change Currency \n";
    cout << "\t 5. Return to Main Menu \n";
}

void printDetailsAdminMenu(){
    system("CLS");
    cin.clear();
    int option;
    cout << "Please input your choice";
    cin >> option;

    switch(option){

        case 1: 
        viewOrders();
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
