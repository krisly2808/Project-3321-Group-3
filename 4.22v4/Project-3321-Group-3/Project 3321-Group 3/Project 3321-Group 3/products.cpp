#include "products.h"
# include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//Function Declaration

//Function to display all the products-Kris Ly
void viewProducts() {
	//open file "product.txt" to display all items carried
	fstream myFile;
	myFile.open("products.txt", ios::in);
	cout << "\t\t\tThis is the product that we carry\n";
	cout << "===================================================================\n";
	cout << "|Design no|          Name            ||          Price            |\n";
	cout << "===================================================================\n";

	//Iterate through the "products.txt" file and display on screen
	if (myFile.is_open()) {
		string designID, designName;
		double price;
		while (myFile >> designID&& myFile >> designName&&myFile>>price) {
			cout <<"   "<<setw(5)<<designID<<setw(20)<<designName<<setw(25)<<price << endl;
		}
		myFile.close();
	}
		
}