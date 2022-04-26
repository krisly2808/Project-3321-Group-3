#include "reviews.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
//FUnction to display review -Kris Ly
void printReviews() {
	//open file "review.txt" to display all items carried
	fstream myFile;
	myFile.open("review.txt", ios::in);
	cout << "\t**********************REVIEW**********************\n";
	cout << "===================================================================\n";
	cout << "|Design no|          Name            ||          Review           |\n";
	cout << "===================================================================\n";

	//Iterate through the "review.txt" file and display on screen
	if (myFile.is_open()) {
		string designID, designName, review;
		double price;
		while (myFile >> designID && myFile >> designName && myFile >> price && myFile >> review) {
			cout << "   " << setw(5) << designID << setw(20) << designName << setw(25) << review << endl;
		}
		myFile.close();
	}

}