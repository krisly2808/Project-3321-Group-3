#include "ordersMenu.h"
#include <string>
#include <iostream>
#include <fstream>
//Amani
using namespace std;

void viewGuestOrders() {
	system("cls");
	fstream myFile;
	myFile.open("GuestOrder.txt", ios::in);
	string line;
	while (!myFile.eof()) {
		getline(myFile, line);
		cout << line << endl;
	}
	myFile.close();
}		
void viewUserOrders() {
	system("cls");
	fstream myFile;
	myFile.open("UserOrder.txt", ios::in);
	string line;
	while (!myFile.eof()) {
		getline(myFile, line);
		cout << line << endl;
	}
	myFile.close();
}
