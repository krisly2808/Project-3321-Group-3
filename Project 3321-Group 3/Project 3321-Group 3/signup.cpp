#include "signup.h"
#include <iostream>
#include<iomanip>
#include <ctime>
#include <string>
using namespace std;

void signUp()
{

	cout << "Welcome!\n";
	cout << "Thank you for deciding to sign up!\n\n";
	cout << "Please enter your first name: ";
	string fName;
	cin >> fName;

	while (fName.size() > 9) // may take it off 

	{
		cin.clear();
		cout << "Please re-enter your first name: ";
		cin >> fName;
	}

	cout << "Enter your last name: ";
	string lName;
	cin >> lName;

	while (lName.size() > 9) // may take it off 

	{
		cin.clear();
		cout << "Please re-enter your last name: ";
		cin >> fName;
	}

	cout << "Enter your phone number: ";
	string phoneNumber;
	cin >> phoneNumber;

	while (phoneNumber.size() > 9) // may take it off 

	{
		cin.clear();
		cout << "Please re-enter your phone number: ";
		cin >> fName;
	}

	cout << "Enter your desired username: ";
	string userName;
	cin >> userName;
	//thinking of having a restriction of max characters in a username 

	cin.ignore();

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
	}

}