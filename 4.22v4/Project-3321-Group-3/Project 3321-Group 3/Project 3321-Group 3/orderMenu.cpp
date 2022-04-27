#include "ordersMenu.h"


void viewOrders() {
	
	fstream myFile;
	myFile.open("orders.txt", ios::in);
	cout << "\t\t\tHere are your current orders:\n";
	cout << "===================================================================\n";
	cout << "   |Order no||  Order Date  ||  Order Total  ||  Customer Name |\n";
	cout << "===================================================================\n";

	
	if (myFile.is_open()) {

        int orderNo, orderDate;
        double orderTotal;
        string customerName;
      
		while (myFile >> orderNo&& myFile >> orderDate && myFile>> orderTotal && myFile >>customerName) {
			cout <<"   "<<setw(5)<<orderNo <<setw(15)<<orderDate<<setw(20)<< orderTotal <<setw(25)<< customerName << endl;
		}
		myFile.close();
	}
		
}