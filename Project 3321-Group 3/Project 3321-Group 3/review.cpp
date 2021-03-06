// Kris Ly
#include "reviews.h"
#include "products.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

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

//Function to update the review-Kris Ly
void updateReviews() {
    printReviews();
    string designID, name, price, review;
    fstream oldReview, newReview,myProduct;
    double quantity;
    bool inTheList = false;
    newReview.open("newreview.txt", ios::out);
    myProduct.open("products.txt", ios::in);
    char option;
    cout << "Would you like to update the review for any product? Y/y\n";
    cin >> option;
    if (option == 'y' || option == 'Y') {
        system("cls");
        printReviews();
        string updateDesignID, updatedReview;
        viewProducts();
        cout << "What is the design ID to review? \n";
        cin >> updateDesignID;
        cin.ignore();
        cin.clear();
        cout << "How many star you want to put for this review " << updateDesignID << "?\n";
        getline(cin, updatedReview);

        //check if the item to review is in the reviews.txt
        oldReview.open("review.txt", ios::in);
        while (oldReview >> designID >> name >> price >> review) {
            if (designID == updateDesignID) inTheList = true;
        }
        oldReview.close();

        if (inTheList==false) {
            oldReview.open("review.txt", ios::in);
            while (oldReview >> designID >> name >> price >> review) {
                newReview << designID << "\t" << name << "\t" << price << "\t" << review << endl;
            }
            oldReview.close();
            while (myProduct >> designID >> name >> price >> quantity) {
                if (designID == updateDesignID) {
                    newReview << designID << "\t" << name << "\t" << price << "\t" << updatedReview << endl;
                }
            }
        }
        else {
            oldReview.open("review.txt", ios::in);
        while (oldReview >> designID >> name >> price >> review) {
            if (updateDesignID == designID) {
                newReview << designID << "\t" << name << "\t" << price << "\t" << review << endl;
                newReview << designID << "\t" << name << "\t" << price << "\t" << updatedReview << endl;
            }
            else { newReview << designID << "\t" << name << "\t" << price << "\t" << review << endl; }
        }}
    }
    else {
        oldReview.open("review.txt", ios::in);
        while (oldReview >> designID >> name >> price >> review) {
            newReview << designID << "\t" << name << "\t" << price << "\t" << review << endl;
        }
    }
    myProduct.close();
    oldReview.close();
    newReview.close();
    system("cls");
    remove("review.txt");
    if (rename("newreview.txt", "review.txt") != 0) {
        cout << "review has not been updated\n";
    }
    else {
        cin.clear();
        cout << "Here is the reviews\n";
        printReviews();
    }
}