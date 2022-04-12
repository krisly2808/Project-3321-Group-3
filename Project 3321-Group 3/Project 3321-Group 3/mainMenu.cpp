#include "mainMenu.h"

//Function Definitions
// 
//Function to print the main menu for all users to input choice-Kris Ly
void printMenu() {
	cout << "Please select you option from the list below:\n ";
	cout << "\t1. Login.\n ";
	cout << "\t2. Sign-up as User.\n ";
	cout << "\t3. Continue as Guest.\n ";
	cout << "\t4. Forgot Passwords.\n ";
	cout << "\t5. Exit Program.\n ";
}

//Function to print detail menu based on input-Kris Ly
void printDetailMenu(int);
void printDetailMenu(int option) {
	system("CLS");
	cin.clear();
	cin.ignore();
	switch (option)
	{
	case 1:
		cout << "Printing the login menu\n";
		break;
	case 2:
		cout << "Printing the sign-up menu\n";
		break;
	case 3:
		int choice;
		printGuestMenu();
		cin >> choice;
		printDetailGuestMenu(choice);
		break;
	case 4:
		cout << "Printing the Forgot-passwords menu\n";
		break;
	case 5:
		exit(0);
		break;
	default:
		cout << "INVALID CHOICE. Please only input option from 1 to 5.Thank you\n";
		break;
	}
}