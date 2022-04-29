#include "AM.h"
#include "cartMenu.h"
#include "products.h"
#include <iostream>
#include <fstream>
#include "inventoryMenu.h"
#include "ordersMenu.h";

using namespace std;

extern double USDCAD, USDEUR;

void printAdminMenu(){


//Would eventually like to replace "Admin" with actual admin username
    system("cls");
    cout << "Welcome Admin!\n" ;
    cout << "\t 1. View Orders \n" ;
    cout << "\t 2. View or Add new design \n";
    cout << "\t 3. View and Manage Your Inventory \n";
    cout << "\t 4. Update Currency ratio \n";
    cout << "\t 5. Return to Main Menu \n";
}

void printDetailsAdminMenu(){
    cin.clear();
    int option;
    cout << "Please input your choice:\n";
    cin >> option;

    switch(option){

        case 1: 
            cin.clear();
            int choice;
            cout << "Welcome Admin!\n";
            cout << "\t 1. View All Guest orders \n";
            cout << "\t 2. View All User orders \n";
            cin >> choice;
            switch (choice)
            {
            case 1:
                viewGuestOrders();
                break;
            case 2:
                viewUserOrders();
                break;
            default:
                cout << "Invalid choice\n";
                break;
            }
        break;

        case 2: 
            cin.clear();
            int choice1;
            cout << "Welcome Admin!\n";
            cout << "\t 1. View Design \n";
            cout << "\t 2.  Add new design \n";
            cin >> choice1;
            switch (choice1)
            {case 1:
                viewInventory();
                break;
            case 2:
                addNewDesign();
                break;
            default:
                cout << "Invalid choice\n";
                break;
            }
        break;

        case 3: 
            cin.clear();
            int choice2;
            viewInventory();
            printInventoryMenu();
            cout << "Pleasse input your choice: \n";
            cin >> choice2;
            printDetailsInventoryMenu(choice2);

         break;

        //Update currency exchange ratio-Kris Ly
        case 4: {
            cout << "Here is the default currency exchange ratio for USD-CAD: " << USDCAD <<
                ".\n Here is the default currency exchange ratiofor USD-EUR:" << USDEUR << endl;
            cout << "Please enter new value for USD-CAD ratio: \n";
            cin >> USDCAD;
            cout << "Please enter new value for USD-EUR ratio: \n";
            cin >> USDEUR;
            cout << "Here is the new currency exchange ratio for USD-CAD: " << USDCAD <<
                ".\n Here is the new currency exchange ratiofor USD-EUR:" << USDEUR << endl;

        }
        case 5: 
            system("cls");
            int option1;
            printMainMenu();
            cin >> option1;
            //Print detail menu based on input-Kris Ly
            printDetailMainMenu(option1);

        break;

    }
}
