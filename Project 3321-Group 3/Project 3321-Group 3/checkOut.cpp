#include "checkOut.h"
#include "cartMenu.h"
#include "signup.h"
#include <fstream>
#include <iostream>
#include <string>
//RATIO to exchange USD to CAD and EUR
extern double USDCAD;
extern double USDEUR;

string SAVEDUSERNAME, SAVEDPASSWORD;

using namespace std;
//General checkout-Kris Ly
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
			userCheckoutFromGuestMenu();
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

//General function to checkout as User from Guest menu-Kris Ly
void userCheckoutFromGuestMenu() {
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
	myFile.close();
}

////General function to checkout as User from User menu-Kris Ly
void userCheckoutFromUserMenu() {
		system("cls");
		int choice;
		string userName;
		cout<< "Please verify your user name so we can process the member checkout:\n";
		cin >> userName;
		fstream myFile;
		myFile.open("user.txt", ios::in);
		string userNameInFile, passwordInFile, firstNameInFile, lastNameInFile,
			creditCardInFile, addressInFile, phoneNoInFile;
		//verifying the user identity
		while (getline(myFile, userNameInFile) && getline(myFile, passwordInFile) && getline(myFile, firstNameInFile)
			&& getline(myFile, lastNameInFile) && getline(myFile, creditCardInFile)
			&& getline(myFile, addressInFile) && getline(myFile, phoneNoInFile)) {
			if (userName == userNameInFile ) {
				SAVEDUSERNAME = userName;
				SAVEDPASSWORD = passwordInFile;
			}
		}
		cout << "Welcome back Loyal Customer: "<<SAVEDUSERNAME<<" \n";
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
		myFile.close();
}

//Function for guest checkout ONLy in USD-Kris Ly
void guestCheckout() {
	system("CLS");
	string line;
	char choice;
	string name, address, designID, designName, cardNo,phoneNo;
	double quantity, price;
	double total = 0.0;
	fstream myFile,myOldFile;
	myFile.open("NewGuestOrder.txt", ios::out);
	myOldFile.open("GuestOrder.txt", ios::in);
	while (!myOldFile.eof()) { 
		getline(myOldFile,line);
		myFile << line << endl;
	}
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
		myFile.open("NewGuestOrder.txt", ios::out);
		while (!myOldFile.eof()) {
			getline(myOldFile, line);
			myFile << line << endl;
		}
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

	myCart.close();
	myFile.close();
	myOldFile.close();
	remove("GuestOrder.txt");
	if (rename("NewGuestOrder.txt", "GuestOrder.txt") != 0) {
		cout << "Order has not been updated\n";
	}
	else {
		cin.clear();
		cin.ignore();
		viewCartInUSD();
		cout << "All information has been saved and exported as txt for processing.\n\t\tTHANK YOU FOR PURCHASING\n";
		
	}
}

//Function to checkout as User in USD-Kris Ly
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
		fstream myFile, myOrderFile,myOldFile;
		myFile.open("user.txt", ios::in);

		myOrderFile.open("NewUserOrder.txt", ios::out);
		myOldFile.open("UserOrder.txt", ios::in);
		string line;
		while (!myOldFile.eof()) {
			getline(myOldFile, line);
			myOrderFile << line << endl;
		}

		//Update user info from user.txt
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

		myOldFile.close();
		myCart.close();
		myFile.close();
		myOrderFile.close();
		remove("UserOrder.txt");
		if (rename("NewUserOrder.txt", "UserOrder.txt") != 0) {
			cout << "Cart has not been updated\n";
		}
		else {
			cin.clear();
			cin.ignore();
			cout << "All information has been saved and exported as txt for processing.\n\t\tTHANK YOU FOR PURCHASING\n";
			viewCartInUSD();
		}
	}
	
};

//Function to checkout as User in CAD-Kris Ly
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
		fstream myFile, myOrderFile, myOldFile;
		myFile.open("user.txt", ios::in);

		myOrderFile.open("NewUserOrder.txt", ios::out);
		myOldFile.open("UserOrder.txt", ios::in);
		string line;
		while (!myOldFile.eof()) {
			getline(myOldFile, line);
			myOrderFile << line << endl;
		}

		//Update user info from user.txt
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

		myOldFile.close();
		myCart.close();
		myFile.close();
		myOrderFile.close();
		remove("UserOrder.txt");
		if (rename("NewUserOrder.txt", "UserOrder.txt") != 0) {
			cout << "Cart has not been updated\n";
		}
		else {
			cin.clear();
			cin.ignore();
			cout << "All information has been saved and exported as txt for processing.\n\t\tTHANK YOU FOR PURCHASING\n";
			viewCartInCAD();
		}
	}
}

//Function to checkout as User in EUR-Kris Ly
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
		fstream myFile, myOrderFile, myOldFile;
		myFile.open("user.txt", ios::in);

		myOrderFile.open("NewUserOrder.txt", ios::out);
		myOldFile.open("UserOrder.txt", ios::in);
		string line;
		while (!myOldFile.eof()) {
			getline(myOldFile, line);
			myOrderFile << line << endl;
		}

		//Update user info from user.txt
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

		myOldFile.close();
		myCart.close();
		myFile.close();
		myOrderFile.close();
		remove("UserOrder.txt");
		if (rename("NewUserOrder.txt", "UserOrder.txt") != 0) {
			cout << "Cart has not been updated\n";
		}
		else {
			cin.clear();
			cin.ignore();
			cout << "All information has been saved and exported as txt for processing.\n\t\tTHANK YOU FOR PURCHASING\n";
			viewCartInEUR();
		}
	}

}