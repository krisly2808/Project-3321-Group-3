//Kris Ly
#include "guestMenu.h"
#include "reviews.h"
#include "checkOut.h"

//Function Definitions
// 
//Function to print menu for Guest-Kris Ly
void printGuestMenu() {
	cout << "Please select you option from the list below:\n ";
	cout << "\t1. View products.\n ";
	cout << "\t2. View/Modify Cart.\n ";
	cout << "\t3. View reviews.\n ";
	cout << "\t4. Checkout.\n ";
	cout << "\t5. Exit to main menu.\n ";
}

//Function to print menu for Guest-Kris Ly
void printDetailGuestMenu(int option) {
	system("CLS");
	cin.clear();
	cin.ignore();
	switch (option)
	{case 1:
		viewProducts();
		break;
	case 2:
		int choice2;
		printCartMenu();
		cin >> choice2;
		printDetailCartMenu(choice2);
		break;
	case 3:
		printReviews();
		break;
	case 4:
		checkOut();
		break;
	case 5:
		int choice4;
		printMainMenu();
		cin >> choice4;
		printDetailMainMenu(choice4);
		break;
	default:
		cout << "INVALID CHOICE. Please only input option from 1 to 4.Thank you\n";
		break;
	}
}
