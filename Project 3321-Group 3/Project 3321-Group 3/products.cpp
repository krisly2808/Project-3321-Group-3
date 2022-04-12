#include "products.h"
# include <iostream>
#include <fstream>
#include <string>
using namespace std;

//Function Declaration
//Function to display all the products-Kris Ly
void viewProducts() {
	fstream myFile;
	myFile.open("products.txt", ios::in);
	cout << "\tThis is the product that we carry\n";
	cout << "======================================\n";
	cout << "|Design no|          Name            |\n";
	cout << "======================================\n";
	if (myFile.is_open()) {
		string designID, designName;
		myFile >> designID;
		myFile >> designName;
		while (!myFile.eof()) {
			cout <<"   "<<designID<<"\t\t"<<designName << endl;
			myFile >> designID;
			myFile >> designName;
			if(myFile.eof()) cout << "   " << designID << "\t\t" << designName << endl;
		}
		myFile.close();
	}
		
}