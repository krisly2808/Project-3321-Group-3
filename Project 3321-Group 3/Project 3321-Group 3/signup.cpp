#include "signup.h"
#include <iostream>
#include<iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
//FA 
using namespace std;

void forgotPassword();
void getInfo();
void changePersonalInfo(string fName, string lName, string phoneNumber);
void getPassword();
void passPassword();
void securityCode();
void getPin();




string USERNAME;
string PASSWORD;
string PHONENUMBER;
int PIN;

const int NUM_LENGTH = 10;


void menuDesign()



{
	cout << "\n\n <WE SELL T-SHIRTS>\n";

	cout << " --------------------\n";
	cout << setw(23) << "\\  ^__^\n";
	cout << setw(30) << "	\\ (oo)\_______\n";
	cout << setw(34) << "(__)\       )\ / \ " << "\n";
	cout << setw(32) << "    ||----m |  " << "\n";
	cout << setw(32) << "  ||     ||`\n";
}


/* cute box design
const char TB = '\xCD'; // 205
	const char LR = '\xBA'; // 186
	const char TL = '\xC9'; // 201
	const char TR = '\xBB'; // 187
	const char BL = '\xC8'; // 200
	const char BR = '\xBC'; // 188

	string hello = "Hello World!";
	string margin = "  ";
	string line(hello.length() + 2 * margin.length(), TB);

	cout << TL << line << TR << endl;
	cout << LR << margin << hello << margin << LR << endl;
	cout << BL << line << BR << endl;
	cout << endl;


*/
void signUp()
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

	\
		cout << "\n\n <HI! I remember you!>\n";

	cout << " --------------------\n";
	cout << setw(23) << "\\  ^__^\n";
	cout << setw(30) << "	\\ (oo)\_______\n";
	cout << setw(34) << "(__)\       )\ / \ " << "\n";
	cout << setw(32) << "    ||----m |  " << "\n";
	cout << setw(32) << "  ||     ||`\n";







	cout << "\nPlease input your pin: ";

	int pin;
	cin >> pin;
	if (pin == PIN)
	{
		passPassword();

	}
	else cout << "\nWrong pin...\n";

	//}
	//else cout << "Invalid number...\n";




}


void passPassword()
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

void changePersonalInfo(string fName, string lName, string phoneNumber)
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

		cout << "\nWelcome " << USERNAME << "!\n" << "Your account has been created. Thank you! \n\n";

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


	securityCode();


	string PASS = password;
	PASSWORD = PASS;

}


void getInfo()
{





	cout << "\n\n <WELCOME! Thanks for deciding to sign up!>\n";
	cout << " -----------------------------------------------\n";
	cout << setw(23) << "\\  ^__^\n";
	cout << setw(30) << "	\\ (oo)\_______\n";
	cout << setw(34) << "(__)\       )\ / \ " << "\n";
	cout << setw(32) << "    ||----m |  " << "\n";
	cout << setw(32) << "  ||     ||`\n";
	cout << "\nPlease enter your first name: ";

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
	getline(cin, phoneNumber);
	string temp2 = phoneNumber;
	PHONENUMBER == temp2;

	/*while (phoneNumber.lenght() > NUM_LENGTH) // may take it off


	{
		cin.clear();

		cout << "Please re-enter your phone number: ";
		cin >> phoneNumber;

	}

	*/

	cout << "Enter your desired permanent username: ";
	string username;

	cin >> username;
	string temp = username;

	USERNAME = temp; //TEMPORAL VARIABLES FOR THE WINNNNN

	//thinking of having a restriction of max characters in a username -FA





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










	fstream myFile;
	myFile.open("user.txt", ios::out);
	if (myFile.is_open()) {

		myFile << fName << "\n" << lName << "\n" << phoneNumber << "\n" << username;




		myFile.close();
	}




}


void securityCode()
{
	cout << "\nHi, you will be asked to enter a 4-digit pin.\nThe pin is just in case you forget your password...\n ";
	cout << "\n\nPlease enter your pin: ";
	int pin;
	cin >> pin;
	cout << "Re-enter your pin: ";
	int pin2;
	cin >> pin2;



	while (pin2 != pin)
	{
		cout << "The pins don't match!\n";
		return getPin();
	}
	int temp = pin;
	PIN = temp;

}


void getPin()
{
	cout << "\n\nPlease enter your pin: ";
	int pin;
	cin >> pin;
	cout << "Re-enter your pin: ";
	int pin2;
	cin >> pin2;

}