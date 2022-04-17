#include "signup.h"
#include <iostream>
#include<iomanip>
#include <ctime>
#include <string>
using namespace std;

void forgotPassword(string);
void getInfo();
void changePersonalInfo(string fName, string lName, string phoneNumber);
void getPassword();



string userName;
string PASSWORD;
string PHONENUMBER;
const int NUM_LENGTH = 10;

void signUp()
{
	getInfo();

}

void forgotPassword(string phoneNumber) //this new way of getting the password is based on constants instead of storing it in an array ... 
//im thinking of getting creating an array to hold the information (all string based) but get all of that information into one function to separate it if needed to

{

	cout << "\n\nWe all tend to forget our password from time to time, and that's okay!\n";
	cout << "Please enter your phone number: ";
	string phoneNo;
	
	if (phoneNo == PHONENUMBER)
	{
		cout << "Enter your new password: ";
		string password;
		cin >> password;
		cout << "Re-enter your password: ";
		cin >> password;
		cout << "Congrats! Your new password has been saved.\n";
	}
	



}

void changePersonalInfo(string fName, string lName, string phoneNumber)
{
	cout << "\nThis is your current information:\n";
	cout << "1. First name: " << fName << endl;
	cout << "2. Last Name: " << lName << endl;
	cout << "3. Phone number: " << phoneNumber << endl;

	cout << "Which one would you like to change? (1-3): ";
	int option;
	cin >> option;


	while (option <= 0 | option > 3)
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
	case 2:	cout << "Enter the new desired last name: ";
		cin >> lName;
		cout << "\nGreat, " << fName << "! Let's now move forward on getting the rest of your information.\n";
		getPassword();

		break;
	case 3:	cout << "Enter the new desired phone number: ";
		cin >> phoneNumber;
		cout << "\nGreat, " << fName << "! Let's now move forward on getting the rest of your information.\n";
		getPassword();


		break;
	}





}
void getPassword()
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
	{
		
		cout << "\nWelcome " << userName << "!\n" << "Your account has been created. Thank you! \n\n";
		password == PASSWORD;
	}
	if (password != cPassword)
	{
		cout << "The passwords don't match!\n\n";
		return getPassword();

	}


}


void getInfo()
{



	cout << "Welcome!\n";
	cout << "Thank you for deciding to sign up!\n\n";
	cout << "Please enter your first name: ";
	string fName;
	cin >> fName;

	while (fName.size() > NUM_LENGTH) // may take it off 

	{
		cout << "Please re-enter your first name: ";
		cin >> fName;
	}

	cout << "Enter your last name: ";
	string lName;
	cin >> lName;
	

	while (lName.size() > NUM_LENGTH) // may take it off 

	{
		cin.clear();

		cout << "Please re-enter your last name: ";
		cin >> lName;

	}
	
	cin.ignore();
	cout << "Enter your phone number: ";
	string phoneNumber;
	cin >> phoneNumber;
	phoneNumber == PHONENUMBER;
	while (phoneNumber.size() > NUM_LENGTH) // may take it off 

	{
		cin.clear();

		cout << "Please re-enter your phone number: ";
		cin >> phoneNumber;

	}

	cout << "Enter your desired permanent username: ";
	string username;
	cin >> userName;
	//thinking of having a restriction of max characters in a username 

	username = userName; // this is going to be a valauble way of using certain code such as changing passwords... 


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
	

}
