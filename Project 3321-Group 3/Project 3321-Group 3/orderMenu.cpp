#include "ordersMenu.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;


//Amani

void viewOrders() {
	
	fstream myFile;
	myFile.open("orders.txt", ios::in);

	cout << "\t\t\tHere are your current orders:\n";
	cout << "===================================================================\n";
	cout << "   |Order no||  Order Date  ||  Order Total  ||  Customer Name |\n";
	cout << "===================================================================\n";

	//Iterate through the "orders.txt" file and display on screen
	if (myFile.is_open()) {

        int orderNo;
        string orderDate, orderTotal, customerName;
      
		while (myFile >> orderNo && myFile >> orderDate && myFile>> orderTotal && myFile >>customerName) {
			cout <<"   "<<orderNo << "\t" <<orderDate<< "\t" << orderTotal << "\t" << customerName << endl;
		}
		myFile.close();
	}
}		
