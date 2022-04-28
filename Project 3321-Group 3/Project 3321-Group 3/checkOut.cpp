#include "checkOut.h"
#include "cartMenu.h"
#include "signup.h"
#include <fstream>
#include <iostream>
#include <string>
//RATIO to exchange USD to CAD and EUR
const double USDCAD = 1.27;
const double USDEUR = 0.93;

string SAVEDUSERNAME, SAVEDPASSWORD;

using namespace std;
void checkOut() {
	viewCartInUSD();
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
		else {
			char signup;
			cout << "Do you want to sign-up? y/y\n";
			cin >> signup;
			if (signup == 'y' || signup == 'Y') {
				system("cls");
				signUp();
			}
			else guestCheckout();
		}
		break;
	default:
		int option;
		printGuestMenu();
		cin >> option;
		printDetailGuestMenu(option);
		break;
	}

}

//Function to checkout as User-Kris Ly
void userCheckout() {
	bool isUser = false;
	string userName, password;
	cout << "\nUser checkout menu\n";
	cout << "\t Welcome back to our shop\n"
		<< "Please input your user name:\n";
	cin >> userName;
	cout << "Please input you password:\n";
	cin >> password;
	fstream myFile;
	myFile.open("user.txt",ios::in);
	string userNameInFile, passwordInFile, firstNameInFile, lastNameInFile,
		creditCardInFile, addressInFile, phoneNoInFile;
	//verifying the user identity
	while (getline(myFile,userNameInFile)&& getline(myFile, passwordInFile) && getline(myFile, firstNameInFile)
		&& getline(myFile, lastNameInFile) && getline(myFile,creditCardInFile)
		&& getline(myFile,addressInFile) && getline(myFile, phoneNoInFile)) {
		if (userName == userNameInFile && password == passwordInFile) {
			isUser = true;
			SAVEDUSERNAME = userName;
			SAVEDPASSWORD = password;
		}
	}
	if (isUser==true) {
		system("cls");
		int choice;
		cout << "Welcome back Loyal Customer\n";
		viewCartInUSD();
		cout << "1. Check-out in USD\n";
		cout << "2. Check-out in CAD\n";
		cout << "3. Check-out in EUR\n";
		cin >> choice;
		switch (choice) {
		case 1:
			checkoutinUSD();
			break;
		case 2:
			checkoutinCAD();
			break;
		case 3:
			checkoutinEUR();
			break;
		default:
			cout << "INVALID choice.\n";
				break;
		}

	}
	else {
		char signup;
		cout << "Information not found\n";
		cout << "Do you want to sign-up? y/y\n";
		cin >> signup;
		if (signup == 'y' || signup == 'Y') { 
			system("cls");
			signUp();}
			else guestCheckout();
	}

}

//Function for guest checkout-Kris Ly
void guestCheckout() {
	system("CLS");
	char choice;
	string name, address, designID, designName, cardNo,phoneNo;
	double quantity, price;
	double total = 0.0;
	fstream myFile;
	myFile.open("GuestOrder.txt", ios::out);
	
	viewCartInUSD();

	cin.ignore();
	cout << "Please input customer name: \n";
	getline(cin, name);
	myFile <<"Name: "<< name << "\n";
	
	cout << "Please input customer address: \n";
	getline(cin, address);
	myFile <<"Address: "<< address << "\n";

	do {
		cout << "Please input 16 VALID credit card number: \n";
		getline(cin, cardNo);
	} while (cardNo.length() != 16);
	myFile <<"Credit Card: "<< cardNo << "\n";

	cout << "Please input customer phone no: \n";
	getline(cin, phoneNo);
	myFile << "Phone No: " << phoneNo << "\n";


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

		cout << "Please input customer phone no: \n";
		getline(cin, phoneNo);
		myFile << "Phone No: " << phoneNo << "\n";

		cout << "Do you want to update any information: Type Y/y \n";
		cin >> choice;
	}

	fstream myCart;
	myCart.open("cart.txt", ios::in);
	myFile << "=====================================================================\n";
	myFile << "|Design no|          Name            |     Quantity  |     Price     |\n";
	myFile << "=====================================================================\n";
	while (myCart >> designID >> designName >> quantity >> price) {
		total += price;
		myFile << "   " << designID << "\t" << setw(20) << designName << "\t\t" << quantity << "\t\t" << price << endl;
	}
	myFile << "\tTotal price is: " << total << " in USD." << endl;
	system("cls");
	cout << "All information has been saved and exported as txt for processing.\n\t\tTHANK YOU FOR PURCHASING\n";
	viewCartInUSD();
	myCart.close();
	myFile.close();

}

void checkoutinUSD() {
	system("CLS");
	viewCartInUSD();
	char choice;
	string designID, designName, quantity;
	double price;
	double total = 0.0;
	string userNameInFile, passwordInFile, firstNameInFile, lastNameInFile,
		creditCardInFile, addressInFile, phoneNoInFile;
	cout << "Would you want to check-out by using your saved info? Y/y\n";
	cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		fstream myFile, myOrderFile;
		myFile.open("user.txt", ios::in);
		myOrderFile.open("userOrder.txt", ios::out);
		//verifying the user identity
		while (getline(myFile, userNameInFile) && getline(myFile, passwordInFile) && getline(myFile, firstNameInFile)
			&& getline(myFile, lastNameInFile) && getline(myFile, creditCardInFile)
			&& getline(myFile, addressInFile) && getline(myFile, phoneNoInFile))  {
			if (SAVEDUSERNAME == userNameInFile && SAVEDPASSWORD == passwordInFile) {
				myOrderFile << "Name:" << firstNameInFile << " " << lastNameInFile << "\n"
					<< "Address:" << addressInFile << "\n"
					<< "Credit card info: " << creditCardInFile << "\n"
					<< "Phone no: " << phoneNoInFile << endl;
				break;
			}
		}
		fstream myCart;
		myCart.open("cart.txt", ios::in);
		myOrderFile << "=====================================================================\n";
		myOrderFile << "|Design no|          Name            |     Quantity  |     Price     |\n";
		myOrderFile << "=====================================================================\n";
		while (myCart >> designID  >> designName  >> quantity >> price) {
			total += price;
			myOrderFile << "   " << designID << "\t" << setw(20) << designName << "\t\t" << quantity << "\t\t" << price << endl;
		}
		myOrderFile << "\tTotal price is: " << total << " in USD." << endl;
		
		system("cls");
		viewCartInUSD();
		cout << "All information has been saved and exported as txt for processing.\n\t\tTHANK YOU FOR PURCHASING\n";

		myCart.close();
		myFile.close();
		myOrderFile.close();
	}
	
};

void checkoutinCAD() {
	system("CLS");
	viewCartInCAD();
	char choice;
	string designID, designName, quantity;
	double price;
	double total = 0.0;
	string userNameInFile, passwordInFile, firstNameInFile, lastNameInFile,
		creditCardInFile, addressInFile, phoneNoInFile;
	cout << "Would you want to check-out by using your saved info? Y/y\n";
	cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		fstream myFile, myOrderFile;
		myFile.open("user.txt", ios::in);
		myOrderFile.open("userOrder.txt", ios::out);
		//verifying the user identity
		while (getline(myFile, userNameInFile) && getline(myFile, passwordInFile) && getline(myFile, firstNameInFile)
			&& getline(myFile, lastNameInFile) && getline(myFile, creditCardInFile)
			&& getline(myFile, addressInFile) && getline(myFile, phoneNoInFile)) {
			if (SAVEDUSERNAME == userNameInFile && SAVEDPASSWORD == passwordInFile) {
				myOrderFile << "Name:" << firstNameInFile << " " << lastNameInFile << "\n"
					<< "Address:" << addressInFile << "\n"
					<< "Credit card info: " << creditCardInFile << "\n"
					<< "Phone no: " << phoneNoInFile << endl;
				break;
			}
		}
		fstream myCart;
		myCart.open("cart.txt", ios::in);
		myOrderFile << "=====================================================================\n";
		myOrderFile << "|Design no|          Name            |     Quantity  |     Price     |\n";
		myOrderFile << "=====================================================================\n";
		while (myCart >> designID >> designName >> quantity >> price) {
			price = price * USDCAD;
			total += price;
			myOrderFile << "   " << designID << "\t" << setw(20) << designName << "\t\t" << quantity << "\t\t" << price << endl;
		}
		myOrderFile << "\tTotal price is: " << total << " in CAD." << endl;

		system("cls");
		viewCartInCAD();
		cout << "All information has been saved and exported as txt for processing.\n\t\tTHANK YOU FOR PURCHASING\n";

		myCart.close();
		myFile.close();
		myOrderFile.close();
	}

}

void checkoutinEUR() {
	system("CLS");
	viewCartInEUR();
	char choice;
	string designID, designName, quantity;
	double price;
	double total = 0.0;
	string userNameInFile, passwordInFile, firstNameInFile, lastNameInFile,
		creditCardInFile, addressInFile, phoneNoInFile;
	cout << "Would you want to check-out by using your saved info? Y/y\n";
	cin >> choice;
	if (choice == 'Y' || choice == 'y') {
		fstream myFile, myOrderFile;
		myFile.open("user.txt", ios::in);
		myOrderFile.open("userOrder.txt", ios::out);
		//verifying the user identity
		while (getline(myFile, userNameInFile) && getline(myFile, passwordInFile) && getline(myFile, firstNameInFile)
			&& getline(myFile, lastNameInFile) && getline(myFile, creditCardInFile)
			&& getline(myFile, addressInFile) && getline(myFile, phoneNoInFile)) {
			if (SAVEDUSERNAME == userNameInFile && SAVEDPASSWORD == passwordInFile) {
				myOrderFile << "Name:" << firstNameInFile << " " << lastNameInFile << "\n"
					<< "Address:" << addressInFile << "\n"
					<< "Credit card info: " << creditCardInFile << "\n"
					<< "Phone no: " << phoneNoInFile << endl;
				break;
			}
		}
		fstream myCart;
		myCart.open("cart.txt", ios::in);
		myOrderFile << "=====================================================================\n";
		myOrderFile << "|Design no|          Name            |     Quantity  |     Price     |\n";
		myOrderFile << "=====================================================================\n";
		while (myCart >> designID >> designName >> quantity >> price) {
			price = price * USDEUR;
			total += price;
			myOrderFile << "   " << designID << "\t" << setw(20) << designName << "\t\t" << quantity << "\t\t" << price << endl;
		}
		myOrderFile << "\tTotal price is: " << total << " in EUR." << endl;

		system("cls");
		viewCartInEUR();
		cout << "All information has been saved and exported as txt for processing.\n\t\tTHANK YOU FOR PURCHASING\n";

		myCart.close();
		myFile.close();
		myOrderFile.close();
	}

}