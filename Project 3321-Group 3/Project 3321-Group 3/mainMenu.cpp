#include "mainMenu.h"
#include "guestMenu.h"
#include "signup.h"
#include "LoginMenu.h"
# include <iostream>
#include <iomanip>

using namespace std;

//Function Definitions
//
//Function to print the main menu for all users to input choice-Kris Ly

void printMainMenu() {

	menuDesign();
	cout << "\n\nPlease select you option from the list below:\n ";
	cout << "\t1. Login.\n ";
	cout << "\t2. Sign-up as User.\n ";
	cout << "\t3. Continue as Guest.\n ";
	cout << "\t4. Forgot Passwords.\n ";
	cout << "\t5. Exit Program.\n ";
}

//Function to print detail menu based on input-Kris Ly
void printDetailMainMenu(int option) {
	system("CLS");
	cin.clear();
	cin.ignore();
	switch (option)
	{
	case 1:
		getLogin();

		break;
	case 2:
		signUp();
		break;
	case 3: {
		char repeat;
		do {
			system("cls");
			int choice;
			printGuestMenu();
			cin >> choice;
			printDetailGuestMenu(choice);
			cin.clear();
			cout << "Back to Guest Menu? Y/y\n";
			cin >> repeat;
		} while (repeat =='y'||repeat=='Y');
	}
		break;
	case 4:
		forgotPassword();
		break;
	case 5:
		exit(0);
		break;
	default:
		cout << "INVALID CHOICE. Please only input option from 1 to 5.Thank you\n";
		break;
	}
}



