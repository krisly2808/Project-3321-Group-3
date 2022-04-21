#include "checkOut.h"
#include "cartMenu.h"

void checkOut() {
	viewCart();
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
			userCheckout();
		}
		else guestCheckout();
		break;
	default:
		int option;
		printGuestMenu();
		cin >> option;
		printDetailGuestMenu(option);
		break;
	}

}


void userCheckout() {
	cout << "\nUser checkout menu\n";
}


void guestCheckout() {
	cout << "\nGuest checkout menu\n";
}