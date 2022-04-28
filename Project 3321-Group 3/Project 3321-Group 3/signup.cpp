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
void passPassword(); //this function is to pass the password so it can be used as a global variable and be passed onto the file 
void securityCode(); //this function is to obtain a security pin from the user just in case the password is forgotten. It is called
// in forgotPassword() 

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
	getInfo();
}

void forgotPassword()
{
	//cout << "Enter your phone number: ";
	//string phoneNumber;
	//getline(cin, phoneNumber);

	//if (phoneNumber == PHONENUMBER)
	//{
		cout << "\n\n <HI! I remember you!>\n";
	//just a design for the specific part of the menu 
	cout << " --------------------\n";
	cout << setw(23) << "\\  ^__^\n";
	cout << setw(30) << "	\\ (oo)\_______\n";
	cout << setw(34) << "(__)\       )\ / \ " << "\n";
	cout << setw(32) << "    ||----m |  " << "\n";
	cout << setw(32) << "  ||     ||`\n";
	cout << "\nPlease input your pin: "; //takes the pin from the user who just created their account just in case they forgot it 

	int pin;
	cin >> pin;
	if (pin == PIN)
	{
		passPassword();
			}
	else cout << "\nWrong pin...\n";
}

void passPassword() //this function is used to read and pass the password to the passedPassword.txt and so that the user can 
//obtain their password ...It basically reveals their password after asking the user for specific details . 
{
	{
		string line;
		ifstream file("passedPassword.txt");
		if (file.is_open())
		{
			cout << "\n\nWe all tend to forget our password from time to time, and that's okay!\n";
			cout << "Please enter your phone number: ";///switch to re-enter if other function works 
			string phoneNo;
			cin >> phoneNo;
			for (int lineno = 1; getline(file, line) && lineno <= 1; lineno++)
				if (lineno == 1 && file)
					cout << "\nThis is your password: ";
			cout << line << endl;
			cout << "Please login now...\n";
			file.close();
		}
		else cout << "Can not open the file";
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
	fstream myFile;
	myFile.open("passedPassword.txt", ios::out);
	if (myFile.is_open()) {
		myFile << password;
		myFile.close();
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
	cin.clear();



	cout << "\nHi, you will be asked to enter a pin.(any length)\nThe pin is just in case you forget your password...\n ";
	securityCode();

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

	cout << "\nBefore we ask for your password, would you like to change any of the recent information?(y/n or any other character)\n";
	char c;
	cout << "Enter your answer: ";
	cin >> c;

	if (c == 'y' || c == 'Y')
	{
		changePersonalInfo(fName, lName, phoneNumber);
	}
	else if (c == 'n' || c == 'N')
	{
		getPassword();
	}
	else getPassword();

	/*fstream myFile;
	myFile.open("user.txt", ios::app);
	if (myFile.is_open()) {

		myFile << username << "\n" << PASSWORD << "\n" << fName << "\n" << lName << "\n" << CREDITCARD << "\n" << ADDRESS << "\n" << PHONENUMBER;
		myFile.close();
	}*/
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
		cin.clear();
		cin.ignore();
		system("CLS");
		cout << "*************Info has been UPDATED***************\n";
	}


}


void securityCode() // gets security pin from user just in case password is forgotten . 
{
	cout << "\n\nPlease enter your pin: ";
	int pin;
	cin >> pin;
	cout << "Re-enter your pin: ";
	int pin2;
	cin >> pin2;
	if (pin2 != pin)
	{
		cout << "The pins don't match!\n";
		return securityCode();
	}
	int temp = pin;
	PIN = temp;

}
