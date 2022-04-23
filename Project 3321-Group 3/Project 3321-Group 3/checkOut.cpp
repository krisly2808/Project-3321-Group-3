#include "checkOut.h"
#include "cartMenu.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
void checkOut() {
	viewCart();
	char choice;
	cout << "\t Do you wanna to checkout? Y/y to continue\n";
	cin >> choice;
	switch (choice)
	{case 'Y':
	case 'y':
		char answer;
		cout << "\t Are you member? Y/y\n";
		cin >> answer;
		if (answer == 'y' || answer == 'Y') {
			userCheckout();
		}
		else guestCheckout();
		break;
	default:
		int option;
		printGuestMenu();
		cin >> option;
		printDetailGuestMenu(option);
		break;
	}

}


void userCheckout() {
	cout << "\nUser checkout menu\n";
}

//Function for guest checkout-Kris Ly
void guestCheckout() {
	
	char choice;
	string name, address, designID, designName, cardNo;
	double quantity, price;
	
	fstream myFile;
	myFile.open("GuestOrder.txt", ios::out);
	
	viewCart();

	cin.ignore();
	cout << "Please input customer name: \n";
	getline(cin, name);
	myFile << name << "\n";
	
	cout << "Please input customer address: \n";
	getline(cin, address);
	myFile << address << "\n";
	do {
		cout << "Please input 16 VALID credit card number: \n";
		getline(cin, cardNo);
	} while (cardNo.length() != 16);
	myFile << cardNo << "\n";

	cout << "Do you want to update any information: Type Y/y \n";
	cin >> choice;
	
	while (choice == 'y' || choice == 'Y') {
		myFile.close();
		myFile.open("GuestOrder.txt", ios::out);
		cin.ignore();
		cout << "Please input customer name: \n";
		getline(cin, name);
		myFile << name << "\n";
		
		cout << "Please input customer address: \n";
		getline(cin, address);
		myFile << address <<"\n";

		do {
			cout << "Please input VALID credit card number: \n";
			getline(cin, cardNo);
		} while (cardNo.length() != 16);
		myFile << cardNo << "\n";

		cout << "Do you want to update any information: Type Y/y \n";
		cin >> choice;
	}

	fstream myCart;
	myCart.open("cart.txt", ios::in);

	while (myCart >> designID && myCart >> designName && myCart >> quantity && myCart >> price) {
		myFile << designID << "\t";
		myFile << designName << "\t";
		myFile << quantity << "\t";
		myFile << price << endl;
	}

	cout << "All information has been saved and exported as txt for processing.\n\t\tTHANK YOU FOR PURCHASING\n";

	myCart.close();
	myFile.close();

}