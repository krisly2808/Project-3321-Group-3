#include "inventoryMenu.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Amani - print Inventory menu

void printInventoryMenu(){

    cout << "Manage your inventory";
    cout << "\n1. Modify Current Inventory";
    cout << "\n2. Update Currency";
    cout << "\n3. Return To Admin Menu";
}

void printDetailsInventoryMenu(int option){
    system("CLS");
    cin.ignore();

    switch(option){
        case 1: 
       modifyInventory;
        break;
        case 2:
        //updateCurrency
        default:
        cout << "That is not a valid choice";

    }

}
void viewInventory() {
	
	//open "inventory.txt" to display all items in cart
	fstream myFile;
	myFile.open("inventory.txt", ios::in);
	cout << "\t\tThis is your current inventory\n";
	cout << "=====================================================================\n";
	cout << "|Design no|          Name            |     Quantity  |     Price     |\n";
	cout << "=====================================================================\n";


if (myFile.is_open()) {
		string designID, designName;
		int quantity;
		double price;
		
		while (myFile >> designID&& myFile >> designName&& myFile >> quantity &&myFile >> price) {
			
			cout << "   " << designID << "\t"<<setw(20) << designName <<"\t\t"<< quantity<<"\t\t" << price << endl;
		}
		
		myFile.close();
    
}
    char r;    
    cout << "Would you like to modify your cart? y/n";
    cin >> r;
    if(r == 'y' || r == 'Y'){
        modifyInventory();
    }else{
        cout << "Returning to Inventory Menu";
        printInventoryMenu();
    }
    

}


void modifyInventory(){

    viewInventory();
    int option;
    char deleteI;
    char addI;
    char updateI;

    cout << " \nPlease pick the following option:\n";
	cout << " 1. Update the quantity of item(s)\n";
	cout << " 2. Add new item(s)\n";
    cout << " 3. Update Currecny\n";
	cout << " 4. Back to previous Menu\n";

    cin >> option;

    switch(option){

        case 1:
        updateQuantity();
        break;

        case 2:
        addNewItem();
        break;

        case 3:
        //updateCurrency();
        break;

        default:
        cout << "Please enter a valid number";
        break;
    }
}

void updateQuantity() {
	string designID, designName, itemID;
	int quantity, updateQuantity;
	double price;
	bool isValidID = false;			//variable to check if input item ID is valid

	cout << "Enter the Design ID of item you want to update: \n";
	cin >> itemID;
	cout << "Enter new quantity for the item please: \n";
	cin >> updateQuantity;

	//Checking if input item ID is in the file -"cart.txt". Return true if valid
	ifstream checkItemID;
	checkItemID.open("inventory.txt");
	while (checkItemID >> designID && checkItemID >> designName && checkItemID >> quantity && checkItemID >> price) {
		if (itemID == designID) isValidID = true;
	}
	checkItemID.close();

	//If the Item ID is valid, process the update function
	if (isValidID) {ifstream inFile;
	inFile.open("inventory.txt");		//open "cart.txt" in read mode
	ofstream outFile;
	outFile.open("newInventory.txt");	//create and open "newcart.txt" in write mode to hold the temp values of cart

	//Copy and update the info of items to "newcart.txt"
	while (inFile >> designID && inFile >> designName && inFile >> quantity && inFile >> price) {
		if (designID == itemID) {
			outFile << designID << "\t";
			outFile << designName << "\t";
			outFile << updateQuantity << "\t";
			outFile << price / quantity * updateQuantity << endl;
		}
		else {
			outFile << designID << "\t";
			outFile << designName << "\t";
			outFile << quantity << "\t";
			outFile << price << endl;
		}
	}
	inFile.close();
	outFile.close();

	//remove old cart file named "cart.txt" and replace by "newcart.txt". Then rename "newcart.txt"
	remove("inventory.txt");
	if (rename("newInventory.txt", "inventory.txt") != 0) {
			cout << "Cart has not been updated\n";}
	else {
			cin.clear();
			cin.ignore();
			system("CLS");
			cout << "*************Inventory has been UPDATED***************\n";
			viewInventory();}
	}

	//Prompt the error if input item ID not match
	else { cout << "Your input itemID is not match with any items in cart.\n"; }
}

void addNewItem() {
	string designID, designName, itemID;
	double quantity;
	double price;
	//bool isValidID = false;			//variable to check if input item ID is valid
	viewInventory();
	cout << "Enter the Design ID of item you want to add: \n";
	cin >> designID;
	cout << "Enter the Design Name of the item: \n";
	cin >> designName;
    cout << "Enter Initial Quantity: \n";
    cin >> quantity;
    cout << "Enter the Price of the item: \n";
    cin >> price;
    

	//Add new item to inventory
	fstream newInventory;
	newInventory.open("inventory.txt", newInventory.out | newInventory.app);
    if(newInventory.is_open()){
	newInventory << designID + " ";
    newInventory << designName + " ";
    newInventory << quantity;
    newInventory << " ";
    newInventory << price;
	newInventory.close();
}
	
	
			cin.clear();
			cin.ignore();
			system("CLS");
			cout << "*************Inventory has been UPDATED***************\n";
			viewInventory();
		
	}

    void updateCurrency(double price){


    }