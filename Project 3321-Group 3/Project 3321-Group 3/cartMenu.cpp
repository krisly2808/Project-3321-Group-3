//Function related to Cart menu
#include "cartMenu.h"
#include "checkOut.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>  

using namespace std;

//RATIO to exchange USD to CAD and EUR
const double USDCAD = 1.27;
const double USDEUR = 0.93;


//Function to print cart menu-Kris Ly
void printCartMenu() {
	cout << "Please select you option from the list below:\n ";
	cout << "\t1. View Cart.\n ";
	cout << "\t2. Modify Cart.\n ";
	cout << "\t3. Check-out\n ";
	cout << "\t4. Back to previous Menu.\n ";
}

//Function to print detail menu based on input-Kris Ly
void printDetailCartMenu(int option) {
	system("CLS");
	cin.ignore();
	switch (option)
	{ 
	case 1:
		viewCart();
		break;
	case 2:
		modifyCart();
		break;
	case 3:
		checkOut();
		break;
	case 4:
		int choice;
		printGuestMenu();
		cin >> choice;
		printDetailGuestMenu(choice);
		break;
	default:
		cout << "INVALID CHOICE. Please only input option from 1 or 2. Thank you\n";
		break;
	}
}

//Function to display items in cart-Kris Ly
void viewCart() {
	
	//open "cart.txt" to display all items in cart
	fstream myFile;
	myFile.open("cart.txt", ios::in);
	cout << "\t\tThis is the product currently in your cart\n";
	cout << "=====================================================================\n";
	cout << "|Design no|          Name            |     Quantity  |     Price     |\n";
	cout << "=====================================================================\n";

	//Iterate throught "cart.txt" to display items on screen
	if (myFile.is_open()) {
		string designID, designName;
		int quantity;
		double price;
		double total = 0.0;
		while (myFile >> designID&& myFile >> designName&& myFile >> quantity &&myFile >> price) {
			total += price;
			cout << "   " << designID << "\t"<<setw(20) << designName <<"\t\t"<< quantity<<"\t\t" << price << endl;
		}
		cout << "\tTotal price is: " << total <<" in USD." << endl;
		myFile.close();
	}
}

//Function to modify items in cart-Kris Ly
void modifyCart() {
	viewCart();				//Display all items in cart
	int option;
	char deleteMore, updateMore, addMore;

	//Display option to update or remove cart
	cout << " \nPlease pick the following option:\n";
	cout << " 1. Update the quantity of item(s)\n";
	cout << " 2. Remove item(s)\n";
	cout << " 3. Add item(s)\n";
	cout << " 4. Back to previous Menu\n";

	cin >> option;

	switch (option)
	{
	//Option 1-Updating the quantity of item in cart
	case 1:
		do{cin.clear();
		cin.ignore();
		updateQuantity();
		cout << "\nPLease input y/Y to update another item\n";
		cin >> updateMore;
		} while (updateMore == 'y' || updateMore == 'Y');
		system("CLS");
		modifyCart();
		break;

	//Option 2-Delete item in cart
	case 2:
		do {cin.clear();
			cin.ignore();
			deleteItem();
			cout << "\nPLease input y/Y to delete another item\n";
			cin >> deleteMore;
		} while (deleteMore == 'y' || deleteMore == 'Y');
		system("CLS");
		modifyCart();
		break;

	//Option 3-Add item to cart
	case 3:
		do {
			cin.clear();
			cin.ignore();
			addItem();
			cout << "\nPLease input y/Y to add  another item\n";
			cin >> addMore;
		} while (addMore == 'y' || addMore == 'Y');
		system("CLS");
		modifyCart();
		break;
	case 4:
		system("CLS");
		int choice4;
		printCartMenu();
		cin >> choice4;
		printDetailCartMenu(choice4);
		break;

	//Default case
	default:
		cin.clear();
		cin.ignore();
		cout << "INVALID CHOICE. Please only input option from 1 and 2.Thank you\n";
		break;
	}
}

//Function to delete item in cart-Kris Ly
void deleteItem() {
	string designID, designName, itemID;
	int quantity;
	double price;
	bool isValidID=false;	//variable to check if input item ID is valid

	cout << "Enter the Design ID of item you want to delete \n";
	cin >> itemID;

	//Checking if input item ID is in the file -"cart.txt". Return true if valid
	ifstream checkItemID;
	checkItemID.open("cart.txt");
	while (checkItemID >> designID && checkItemID >> designName && checkItemID >> quantity && checkItemID >> price) {
		if (itemID == designID) isValidID = true;
	}
	checkItemID.close();

	//If the Item ID is valid, process the delete function
	if(isValidID){
		ifstream inFile;
		inFile.open("cart.txt");		//open "cart.txt" in read mode
		ofstream outFile;
		outFile.open("newCart.txt");	//create and open "newcart.txt" in write mode to hold the temp values of cart
		
		//Copy the items that not need to be deleted to "newcart.txt"
		while (inFile >> designID && inFile >> designName && inFile >> quantity && inFile >> price) {
			if (designID != itemID) {
				outFile << designID << "\t";
				outFile << designName << "\t";
				outFile << quantity <<"\t";
				outFile << price << endl;
			}
		}
		inFile.close();
		outFile.close();

		//remove old cart file named "cart.txt" and replace by "newcart.txt". Then rename "newcart.txt"
		remove("cart.txt");
		if (rename("newCart.txt", "cart.txt") != 0) {
			cout << "Cart has not been updated\n";
		}
		else {
			cin.clear();
			cin.ignore();
			system("CLS");
			cout << "*************Cart has been UPDATED***************\n";
			viewCart();
		}
	}
	//Prompt the error if input item ID not match
	else { cout << "Your input itemID is not match with any items in cart.\n"; }
}

//Function to update the quantity of items in cart-Kris Ly
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
	checkItemID.open("cart.txt");
	while (checkItemID >> designID && checkItemID >> designName && checkItemID >> quantity && checkItemID >> price) {
		if (itemID == designID) isValidID = true;
	}
	checkItemID.close();

	//If the Item ID is valid, process the update function
	if (isValidID) {ifstream inFile;
	inFile.open("cart.txt");		//open "cart.txt" in read mode
	ofstream outFile;
	outFile.open("newCart.txt");	//create and open "newcart.txt" in write mode to hold the temp values of cart

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
	remove("cart.txt");
	if (rename("newCart.txt", "cart.txt") != 0) {
			cout << "Cart has not been updated\n";}
	else {
			cin.clear();
			cin.ignore();
			system("CLS");
			cout << "*************Cart has been UPDATED***************\n";
			viewCart();}
	}

	//Prompt the error if input item ID not match
	else { cout << "Your input itemID is not match with any items in cart.\n"; }
}

//Function to add items in cart-Kris Ly
void addItem() {
	string designID, designName, itemID;
	double quantity, addedQuantity;
	double price;
	bool isValidID = false;			//variable to check if input item ID is valid
	bool isInCart = false;			//variable to check if the item added has been in cart
	viewProducts();
	cout << "Enter the Design ID of item you want to add: \n";
	cin >> itemID;
	cout << "Enter new quantity for the item please: \n";
	cin >> addedQuantity;

	//Checking if input item ID is in the file of items carried -"product.txt". Return true if valid
	ifstream checkItemID;
	checkItemID.open("products.txt");
	while (checkItemID >> designID && checkItemID >> designName && checkItemID >> price) {
		if (itemID == designID) isValidID = true;
	}
	checkItemID.close();

	//Checking if input item ID is in the cart -"cart.txt". Return true if valid
	ifstream checkInCart;
	checkInCart.open("cart.txt");
	while (checkInCart >> designID && checkInCart >> designName&& checkInCart>>quantity&&checkInCart >> price) {
		if (itemID == designID) isInCart = true;
	}
	checkInCart.close();

	//If the Item ID is valid, process the update function
	if (isValidID) {
		ifstream inFile;
		inFile.open("cart.txt");		//open "cart.txt" in read mode
		ofstream outFile;
		outFile.open("newCart.txt");	//create and open "newcart.txt" in write mode to hold the temp values of cart

		//Copy and update the info of items to "newcart.txt"
		if (isInCart) {
			//Update quantity if item is already in cart
			while (inFile >> designID && inFile >> designName && inFile >> quantity && inFile >> price) {
				if (designID == itemID) {
					outFile << designID << "\t";
					outFile << designName << "\t";
					outFile << (addedQuantity + quantity)*price/quantity << endl;
				}
				else {
					outFile << designID << "\t";
					outFile << designName << "\t";
					outFile << quantity << "\t";
					outFile << price << endl;
				}
			}
		}
		else {
			//Adding new item to the cart
			ifstream inFileProduct;
			inFileProduct.open("products.txt");
			while (inFile >> designID && inFile >> designName && inFile >> quantity && inFile >> price) {
				outFile << designID << "\t";
				outFile << designName << "\t";
				outFile << quantity << "\t";
				outFile << price << endl;
			}
			while (inFileProduct>>designID&& inFileProduct>>designName && inFileProduct >> price) {
				if (designID==itemID) {
					outFile << designID << "\t";
					outFile << designName << "\t";
					outFile << addedQuantity << "\t";
					outFile << price * addedQuantity << endl;
				}
			}
			inFileProduct.close();
		}
		inFile.close();
		outFile.close();

		//remove old cart file named "cart.txt" and replace by "newcart.txt". Then rename "newcart.txt"
		remove("cart.txt");
		if (rename("newCart.txt", "cart.txt") != 0) {
			cout << "Cart has not been updated\n";
		}
		else {
			cin.clear();
			cin.ignore();
			system("CLS");
			cout << "*************Cart has been UPDATED***************\n";
			viewCart();
		}
	}

	//Prompt the error if input item ID not match
	else { cout << "Your input itemID is not match with any items that we carry.\n"; }
}

//Function to check total price of item in cart in USD-Kris Ly
double checkTotalUSD() {
	//open "cart.txt" to display all items in cart
	fstream myFile;
	myFile.open("cart.txt", ios::in);

	//Iterate throught "cart.txt" to display items on screen
	if (myFile.is_open()) {
		string designID, designName;
		int quantity;
		double price;
		double total = 0.0;
		while (myFile >> designID && myFile >> designName && myFile >> quantity && myFile >> price) {
			total += price;
		}
		myFile.close();
		return total;
	}
}

//Function to check total price of item in cart-Kris Ly
double checkTotalCAD() {
	return checkTotalUSD()*USDCAD;
};

//Function to check total price of item in cart-Kris Ly
double checkTotalEUR() {
	return checkTotalUSD() * USDEUR;
}