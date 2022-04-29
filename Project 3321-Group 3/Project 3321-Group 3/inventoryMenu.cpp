#include "inventoryMenu.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "AM.h"

using namespace std;

//Amani - print Inventory menu

void printInventoryMenu(){

    cout << "Manage your inventory";
    cout << "\n1. View Current Inventory";
    cout << "\n2. Update the Inventory";
    cout << "\n3. Return To Admin Menu";
}

void printDetailsInventoryMenu(int option){
    system("CLS");
    cin.ignore();

    switch(option){
        case 1: 
			viewInventory();
        break;
        case 2:
			updateInventory();
		break;
		case 3:
			printAdminMenu();
			printDetailsAdminMenu();
		break;
        default:
        cout << "That is not a valid choice";
    }

}

void viewInventory() {
	//open file "product.txt" to display all items carried
	fstream myFile;
	myFile.open("products.txt", ios::in);
	cout << "\t\t\tThis is the product in INVENTORY\n";
	cout << "======================================================================================\n";
	cout << "|Design no|          Name            ||          Price            ||  Number of items ||\n";
	cout << "======================================================================================\n";

	//Iterate through the "products.txt" file and display on screen
	if (myFile.is_open()) {
		string designID, designName;
		double price, number;
		while (myFile >> designID >> designName >> price >> number) {
			cout << "   " << setw(5) << designID << setw(20) << designName << setw(25) << price << setw(25) << number << endl;
		}
		myFile.close();
	}

}

void modifyInventory(){

    viewInventory();
    int option;
   	cout << " \nPlease pick the following option:\n";
	cout << " 1. Update the quantity of item(s)\n";
	cout << " 2. Back to admin Menu\n";

    cin >> option;

    switch(option){

        case 1:
			updateInventory();
        break;

        case 2:
			printAdminMenu();
			printDetailsAdminMenu();
        break;

        default:
        cout << "Please enter a valid number\n";
        break;
    }
}

void updateInventory() {
	string designID, designName, itemID;
	double quantity, updateQuantity;
	double price;
	bool isValidID = false;			//variable to check if input item ID is valid
	viewInventory();
	cout << "Enter the Design ID of item you want to update: \n";
	cin >> itemID;
	cout << "Enter number of this item please: \n";
	cin >> updateQuantity;

	//Checking if input item ID is in the file -"cart.txt". Return true if valid
	ifstream checkItemID;
	checkItemID.open("products.txt");
	while (checkItemID >> designID >> designName  >> price >> quantity) {
		if (itemID == designID) isValidID = true;
	}
	checkItemID.close();

	//If the Item ID is valid, process the update function
	if (isValidID) {
		ifstream inFile;
		inFile.open("products.txt");		//open "inventory.txt" in read mode
		ofstream outFile;
		outFile.open("newProducts.txt");	//create and open "newinventory.txt" in write mode to hold the temp values of cart

	//Copy and update the info of items to "newinventory.txt"
	while (inFile >> designID && inFile >> designName && inFile >> price && inFile >> quantity) {
		if (designID == itemID) {
			outFile << designID << "\t";
			outFile << designName << "\t";
			outFile << price << "\t";
			quantity = quantity + updateQuantity;
			outFile <<  quantity << endl;
		}
		else {
			outFile << designID << "\t";
			outFile << designName << "\t";
			outFile << price << "\t";
			outFile << quantity << endl;
		}
	}
	inFile.close();
	outFile.close();

	//remove old cart file named "inventory.txt" and replace by "newinventory.txt". Then rename "newinventory.txt"
	remove("products.txt");
	if (rename("newProducts.txt", "products.txt") != 0) {
			cout << "Inventory has not been updated\n";}
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

void addNewDesign() {
	string designID, designName, itemID,updateDesignName ;
	double quantity,updateQuantity;
	double price, updatePrice;
	bool isValidID = false;
	viewInventory();
	cout << "Enter the Design ID of item you want to add: \n";
	cin >> itemID;
	//Add new item to inventory
	ifstream checkItemID;
	checkItemID.open("products.txt");
	while (checkItemID >> designID >> designName >> price >> quantity) {
		if (itemID == designID) isValidID = true;
	}
	checkItemID.close();
	if (isValidID) {
		cout << "This design is currently in our Inventory. The update process for inventory is activated.\n";
		cout << "Enter the Price of the item: \n";
		cin >> updatePrice;
		cout << "Enter Number of item for this inventory: \n";
		cin >> updateQuantity;
		ifstream inFile;
		inFile.open("products.txt");		//open "inventory.txt" in read mode
		ofstream outFile;
		outFile.open("newProducts.txt");	//create and open "newinventory.txt" in write mode to hold the temp values of cart

	//Copy and update the info of items to "newinventory.txt"
		while (inFile >> designID && inFile >> designName && inFile >> price && inFile >> quantity) {
			if (designID == itemID) {
				outFile << designID << "\t";
				outFile << designName << "\t";
				outFile << updatePrice << "\t";
				quantity = quantity + updateQuantity;
				outFile << quantity << endl;
			}
			else {
				outFile << designID << "\t";
				outFile << designName << "\t";
				outFile << price << "\t";
				outFile << quantity << endl;
			}
		}
		inFile.close();
		outFile.close();

		//remove old cart file named "inventory.txt" and replace by "newinventory.txt". Then rename "newinventory.txt"
		remove("products.txt");
		if (rename("newProducts.txt", "products.txt") != 0) {
			cout << "Inventory has not been updated\n";
		}
		else {
			cin.clear();
			cin.ignore();
			system("CLS");
			cout << " Number of item and Price have been update\n";
			viewInventory();
		}
	}
	else {
		cin.clear();
		cout << "Enter the Design Name of the item: \n";
		cin >> updateDesignName;
		cout << "Enter the Price of the item: \n";
		cin >> updatePrice;
		cout << "Enter Number of item for this inventory: \n";
		cin >> updateQuantity;
		ifstream inFile;
		inFile.open("products.txt");		//open "inventory.txt" in read mode
		ofstream outFile;
		outFile.open("newProducts.txt");	//create and open "newinventory.txt" in write mode to hold the temp values of cart

	//Copy and update the info of items to "newinventory.txt"
		while (inFile >> designID && inFile >> designName && inFile >> price && inFile >> quantity) {
			if (designID != itemID) {
				outFile << designID << "\t";
				outFile << designName << "\t";
				outFile << price << "\t";
				outFile << quantity << endl;
			}
		}
		outFile << itemID << "\t";
		outFile << updateDesignName << "\t";
		outFile << updatePrice << "\t";
		outFile << updateQuantity << endl;

		inFile.close();
		outFile.close();

		//remove old cart file named "inventory.txt" and replace by "newinventory.txt". Then rename "newinventory.txt"
		remove("products.txt");
		if (rename("newProducts.txt", "products.txt") != 0) {
			cout << "Inventory has not been updated\n";
		}
		else {
			cin.clear();
			cin.ignore();
			system("CLS");
			cout << "New Item has been added to Inventory\n";
			viewInventory();
		}
	}
}

	

	
	


