#include "products.h"
# include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Function Declaration

//Function to display all the products-Kris Ly
void viewProducts() {
	//open file "product.txt" to display all items carried
	fstream myFile;
	myFile.open("products.txt", ios::in);
	cout << "\tThis is the product that we carry\n";
	cout << "======================================\n";
	cout << "|Design no|          Name            |\n";
	cout << "======================================\n";

	//Iterate through the "products.txt" file and display on screen
	if (myFile.is_open()) {
		string designID, designName;
		while (myFile >> designID&& myFile >> designName) {
			cout <<"   "<<designID<<"\t\t"<<designName << endl;
		}
		myFile.close();
	}
		
}