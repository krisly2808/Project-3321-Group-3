#include "mainMenu.h"

# include <iostream>
using namespace std;

void printMenu() {
	cout << "Please select you option from the list below:\n ";
	cout << "\t1. Login.\n ";
	cout << "\t2. Sign-up as User.\n ";
	cout << "\t3. Continue as Guest.\n ";
	cout << "\t4. Forgot Passwords.\n ";
	cout << "\t5. Exit Program.\n ";
}

void printDetailMenu(int option) {
	system("CLS");
	switch (option)
	{
	case 1:
		cout << "Printing the login menu\n";
		break;
	case 2:
		cout << "Printing the sign-up menu\n";
		break;
	case 3:
		cout << "Printing the Guest menu\n";
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