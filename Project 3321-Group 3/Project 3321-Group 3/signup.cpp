//Francisco Alfaro
#include "signup.h"
#include <iostream>
#include<iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
// Francisco Alfaro -> I worked on all the functions in this file and signup.h 
// all the comments are made by me so that the code can be understood 

using namespace std;
void forgotPassword(); //this is the function that allows the user to get their password back 
void getInfo(); // gets the information from a new user 
void changePersonalInfo(string fName, string lName, string phoneNumber);
void getPassword(); //function called in getInfo() that gets the password from the user, it is called within itself if password dont match while 
//asking to re-enter 

//global variables used along with temporal variables to pass data onto a txt file 
string USERNAME;
string PASSWORD;
string PHONENUMBER;
string ADDRESS;
string CREDITCARD;
int PIN;

const int NUM_LENGTH = 10;

void menuDesign(){
	//reused from the internet 
	const char TB = '\xCD';
	const char LR = '\xBA';
	const char TL = '\xC9';
	const char TR = '\xBB';
	const char BL = '\xC8';
	const char BR = '\xBC';
	cout << "\n";
	string title = "WE SELL T-SHIRTS";
	string margin = "  ";
	string line(title.length() + 2 * margin.length(), TB);
	cout << setw(11) << TL << line << TR << endl;
	cout << setw(11) << LR << margin << title << margin << LR << endl;
	cout << setw(11) << BL << line << BR << endl;
	cout << endl;
	/*
	cout << "\n\n <WE SELL T-SHIRTS>\n";

	cout << " --------------------\n";
	cout << setw(23) << "\\  ^__^\n";
	cout << setw(30) << "	\\ (oo)\_______\n";
	cout << setw(34) << "(__)\       )\ / \ " << "\n";
	cout << setw(32) << "    ||----m |  " << "\n";
	cout << setw(32) << "  ||     ||`\n";


	*/
}

//separated everything into different functions for simplicity 

void signUp() //this is the function called from mainMenu.cpp to display everything in this file 
{
	system("cls");
	getInfo();
}

void forgotPassword()
{
	string inputPhoneNo, inputUserName;
	cout << "\n\n <HI! I remember you!>\n";
	//just a design for the specific part of the menu 
	cout << " --------------------\n";
	cout << setw(23) << "\\  ^__^\n";
	cout << setw(30) << "	\\ (oo)\_______\n";
	cout << setw(34) << "(__)\       )\ / \ " << "\n";
	cout << setw(32) << "    ||----m |  " << "\n";
	cout << setw(32) << "  ||     ||`\n";

	cout << "We need to verify your PHONE NO and USER NAME to recover your password.\n";
	cout << "\nPlease input your phone number: \n";
	cin >> inputPhoneNo;
	cout << "\nPLease input your user name: \n";
	cin >> inputUserName;
	fstream myFile;
	myFile.open("user.txt", ios::in);
	bool isUser = false;
	string userNameInFile, passwordInFile, firstNameInFile, lastNameInFile,
		creditCardInFile, addressInFile, phoneNoInFile, recoverPassword;

	//verifying the user identity
	while (getline(myFile, userNameInFile) && getline(myFile, passwordInFile) && getline(myFile, firstNameInFile)
		&& getline(myFile, lastNameInFile) && getline(myFile, creditCardInFile)
		&& getline(myFile, addressInFile) && getline(myFile, phoneNoInFile)) {
		if (inputUserName == userNameInFile && inputPhoneNo == phoneNoInFile) {
			isUser = true;
			recoverPassword = passwordInFile;
		}
	}
	if (isUser == false) {
		char choice;
		cout << "Sorry, the combination does not exist in our database.\n"
			<< "Would you like to register as an user now? y/Y\n";
		cin >> choice;
		if (choice == 'y' || choice == 'Y') signUp();
	}
	else {
		cout << "\nYour combination is matched with our database.\n"
			<< "This is your password: " << recoverPassword << endl;
	}
}


void changePersonalInfo(string fName, string lName, string phoneNumber) //this function is just in case the user makes a mistake and wants to change 
// a part of their recent inputs 
{
	cout << "\nThis is your current information:\n";
	cout << "1. First name: " << fName << endl;
	cout << "2. Last Name: " << lName << endl;
	cout << "3. Phone number: " << phoneNumber << endl;

	cout << "Which one would you like to change? (1-3): ";
	int option;
	cin >> option;


	while (option <= 0 || option > 3)
	{
		cout << "Enter a number 1-3: ";
		cin >> option;
	}

	switch (option)
	{
	case 1:
		cout << "Enter the new desired first name: ";
		cin >> fName;
		cout << "\nGreat, " << fName << "! Let's now move forward on getting the rest of your information.\n";
		getPassword();
		break;
	case 2: cout << "Enter the new desired last name: ";
		cin >> lName;
		cout << "\nGreat, " << fName << "! Let's now move forward on getting the rest of your information.\n";
		getPassword();
				break;
	case 3: cout << "Enter the new desired phone number: ";
		cin >> phoneNumber;
		cout << "\nGreat, " << fName << "! Let's now move forward on getting the rest of your information.\n";
		getPassword();
		break;
	}
}

void getPassword() //this function gets the password from the user, it is called within it just in case passwords asked for don't match 
{
	
	cout << "Enter your desired password: ";
	string password;
	cin >> password;
	cin.ignore();

	cout << "Please confirm your password: ";
	string cPassword; // confirmed password variable
	cin >> cPassword;
	cin.ignore();

	if (password == cPassword)
	{	cout << "\nWelcome " << USERNAME << "!\n" << "Your account has been created. Thank you! \nHowever, we need your credit card"
			<< " information and address so you can safely shop in our store!\n\n";
		}
	if (password != cPassword)
	{
		cout << "The passwords don't match!\n\n";
		return getPassword();

	}

	string address;
	string creditCardNumber;

	cout << "Enter your credit card number: ";
	cin >> creditCardNumber;
	cin.ignore();
	string tempccn = creditCardNumber; //temp variable to store the credit card number to be accessed by the fuction that will read the infomation 
	CREDITCARD = tempccn;
	cin.clear();

	cout << "Enter your address: ";
	getline(cin, address);

	string tempAdress = address; //temp variable to store the address to be accessed by the fuction that will read the infomation 
	ADDRESS = address;
	string PASS = password;
	PASSWORD = PASS;

}


void getInfo() //this function is to obtain the details from the new user 
{	cout << "\n\n <WELCOME! Thanks for deciding to sign up!>\n";
	cout << " -----------------------------------------------\n";
	cout << setw(23) << "\\  ^__^\n";
	cout << setw(30) << "	\\ (oo)\_______\n";
	cout << setw(34) << "(__)\       )\ / \ " << "\n";
	cout << setw(32) << "    ||----m |  " << "\n";
	cout << setw(32) << "  ||     ||`\n";
	cout << "\nPlease enter your first name: ";

	string fName;
	cin >> fName;
	while (fName.size() > NUM_LENGTH)
	{
		cout << "Please re-enter your first name: ";
		cin >> fName;
	}

	cout << "Enter your last name: ";
	string lName;
	cin >> lName;

	while (lName.size() > NUM_LENGTH)
	{
		cin.clear();
		cout << "Please re-enter your last name: ";
		cin >> lName;
	}

	cin.ignore();
	cout << "Enter your phone number: ";

	string phoneNumber;
	getline(cin, phoneNumber);
	string temp2 = phoneNumber;
	PHONENUMBER = temp2;


	cout << "Enter your desired permanent username: ";
	string username;

	cin >> username;
	string temp = username;

	USERNAME = temp; //TEMPORAL VARIABLES FOR THE WINNNNN
	cin.clear();

	cout << "\nBefore we ask for your password, would you like to change any of the recent information?(y/n or any other character)\n";
	char c;
	cout << "Enter your answer: ";
	cin >> c;

	if (c == 'y' || c == 'Y')
	{
		changePersonalInfo(fName, lName, phoneNumber);
	}
	else 
	{
		getPassword();
	}
	


	fstream myUser, myNewUser;
	myUser.open("user.txt", ios::in);
	myNewUser.open("user2.txt", ios::out);
	string oldUserName, oldPassword, oldFirstName, oldLastName, oldCard, oldAddress, oldPhoneNo;
	while (getline(myUser, oldUserName) &&
		getline(myUser, oldPassword) &&
		getline(myUser, oldFirstName) &&
		getline(myUser, oldLastName) &&
		getline(myUser, oldCard) &&
		getline(myUser, oldAddress) &&
		getline(myUser, oldPhoneNo)) {
			myNewUser << oldUserName << endl;
			myNewUser << oldPassword << endl;
			myNewUser << oldFirstName << endl;
			myNewUser << oldLastName << endl;
			myNewUser << oldCard << endl;
			myNewUser << oldAddress << endl;
			myNewUser << oldPhoneNo << endl;
		}
		myNewUser<< username << "\n" << PASSWORD << "\n" << fName << "\n" << lName << "\n" << CREDITCARD << "\n" << ADDRESS << "\n" << PHONENUMBER;
	myNewUser.close();
	myUser.close();
	remove("user.txt");
	if (rename("user2.txt", "user.txt") != 0) {
		cout << "Info has not been updated\n";
	}
	else {
		cout << "*************Info has been UPDATED***************\n";
	}


}
