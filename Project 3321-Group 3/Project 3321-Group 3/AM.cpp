#include "AM.h"
#include "cartMenu.h"
#include "products.h"
#include <iostream>
#include <fstream>

using namespace std;

extern double USDCAD, USDEUR;


void printAdminMenu(){


//Would eventually like to replace "Admin" with actual admin username
    system("cls");
    cout << "Welcome Admin!\n" ;
    cout << "\t 1. View and Your Orders \n" ;
    cout << "\t 2. View and Manage Your Word and Art Bank \n";
    cout << "\t 3. View and Manage Your Inventory \n";
    cout << "\t 4. Update Currency ratio \n";
    cout << "\t 5. Return to Main Menu \n";
}

void printDetailsAdminMenu(){
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

        case 3: 
        //Update Inventory-Kris Ly
        {viewProducts();
        string designID, name, price, number;
        fstream oldInventory, newInventory;
        oldInventory.open("products.txt", ios::in);
        newInventory.open("newproducts.txt", ios::out);
        char option;
        cout << "Would you like to update the inventory for any product? Y/y\n";
        cin >> option;
        if (option == 'y' || option == 'Y') {
            string updateDesignID, updateQuantity;
            cout << "What is the design ID to update? \n";
            cin >> updateDesignID;
            cout << "How many item of this design " << updateDesignID << " for new inventory?\n";
            cin >> updateQuantity;
            while (oldInventory >> designID >> name >> price >> number) {
                if (updateDesignID == designID) {
                    newInventory << designID << "\t" << name << "\t" << price << "\t" << updateQuantity << endl;
                }
                else newInventory << designID << "\t" << name << "\t" << price << "\t" << number << endl;
            }

        }
        while (oldInventory >> designID >> name >> price >> number) {
            newInventory << designID << "\t" << name << "\t" << price << "\t" << number << endl;
        }
        oldInventory.close();
        newInventory.close();
        system("cls");
        remove("products.txt");
        if (rename("newproducts.txt", "products.txt") != 0) {
            cout << "Inventory has not been updated\n";
        }
        else {
            cin.clear();
            cin.ignore();
            cout << "Inventory is UPDATED\n";
            viewProducts();
        }
        }
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
        break;

    }
}
