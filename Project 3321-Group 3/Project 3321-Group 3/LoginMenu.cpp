#include "AM.h"
#include "LoginMenu.h"
#include "UserMenu.h"
#include <iostream>
#include <string>

using namespace std;


string userName;
string passWord;
string cardNum;
string fname;
string lname;
string address;
string phone;
bool isAdmin = false;
bool validate = false;
ifstream userFile;
ifstream adminFile;
//Amani - Login menu



void getLogin(){
    validateLogin(); 
}

void validateLogin(){
    
    
    string s1;
    string s2;
    string userCard;
    string first;
    string last;
    string addressLine;
    string phoneNum;
  
    

    while (validate == false){

    cout << "Welcome Back! \n\n";
    cout << "Please Enter your Username: ";
    cin >> userName;
    cout << "Please Enter your Password: ";
    cin >> passWord;

    userFile.open("user.txt", ios::in);
    if (userFile.is_open()){
    
    string s;
         while (getline(userFile, s1)&&
                getline(userFile, s2)&&
                getline(userFile, first)&&
                getline(userFile, last)&&
                getline(userFile, userCard)&&
                getline(userFile, addressLine)&&
                getline(userFile, phoneNum)){
         cardNum = userCard;
         address = addressLine;
         phone = phoneNum; 
         if ((s1 == userName) && (s2 == passWord)) {
             validate = true;
             isAdmin = false;
         }
         }
        userFile.close();
     if (validate == false){

        adminFile.open("admin.txt", ios::in);
        while(isAdmin == false&&adminFile >> s1 >> s2){
            if ((s1 == userName) && (s2 == passWord)) {
                validate = true;
                isAdmin = true;
                printAdminMenu();
                printDetailsAdminMenu();
            }
            adminFile.close();
        }

    } else  cout << "This information is not valid";
    
  }
}

    if (validate == true && isAdmin == false){
        system("cls");
        char r;
        cout << "Hello " + userName;
        cout << "\nWould you like to update your saved information? y/n\n";
        cin >> r;

        if(r == 'y' || r =='Y'){
           updatePaymentInfo();
        }
        else if (r == 'n' || r == 'N'){
           
            system("cls");
            printUserMenu();
            printDetailsUserMenu();
        }
    }


}

void updatePaymentInfo(){

    int choice;
    string oldUserName, oldPassword, oldFirstName, oldLastName, oldCard, oldAddress, oldPhoneNo;
    string newCard, newAddress, newPhoneNo;
    fstream myUser, myNewUser;
    myUser.open("user.txt", ios::in);
    myNewUser.open("user2.txt", ios::out);

    cout << "\nHere is your current personal information:";
    cout << "\n1. Card number: " << cardNum << endl;
    cout << "\n2. Current address: " << address <<endl;
    cout << "\n3. Phone number: " << phone << endl;
    cout << "\nWhat would you like to update? (1 to 3)\n";
    cin >> choice;

    switch (choice){ 
    case 1:
        cin.ignore();
        cout << "Please enter your updated credit card number: ";
        getline(cin, newCard);
        while (getline(myUser, oldUserName) &&
            getline(myUser, oldPassword) &&
            getline(myUser, oldFirstName) &&
            getline(myUser, oldLastName) &&
            getline(myUser, oldCard) &&
            getline(myUser, oldAddress) &&
            getline(myUser, oldPhoneNo)) {
            if(oldUserName==userName && oldPassword==passWord){
                myNewUser << oldUserName << endl;
                myNewUser << oldPassword << endl;
                myNewUser << oldFirstName << endl;
                myNewUser << oldLastName << endl;
                myNewUser << newCard << endl;
                myNewUser << oldAddress << endl;
                myNewUser << oldPhoneNo << endl;
            }
            else {
                myNewUser << oldUserName << endl;
                myNewUser << oldPassword << endl;
                myNewUser << oldFirstName << endl;
                myNewUser << oldLastName << endl;
                myNewUser << oldCard << endl;
                myNewUser << oldAddress << endl;
                myNewUser << oldPhoneNo << endl;
            }
        }
        

        break;
    case 2:
        cin.ignore();
        cout << "Please enter your updated address: ";
        getline(cin, newAddress);
        while (getline(myUser, oldUserName) &&
            getline(myUser, oldPassword) &&
            getline(myUser, oldFirstName) &&
            getline(myUser, oldLastName) &&
            getline(myUser, oldCard) &&
            getline(myUser, oldAddress) &&
            getline(myUser, oldPhoneNo)) {
            if (oldUserName == userName && oldPassword == passWord) {
                myNewUser << oldUserName<<endl;
                myNewUser << oldPassword << endl;
                myNewUser << oldFirstName << endl;
                myNewUser << oldLastName << endl;
                myNewUser << oldCard << endl;
                myNewUser << newAddress << endl;
                myNewUser << oldPhoneNo << endl;
            }
            else {
                myNewUser << oldUserName << endl;
                myNewUser << oldPassword << endl;
                myNewUser << oldFirstName << endl;
                myNewUser << oldLastName << endl;
                myNewUser << oldCard << endl;
                myNewUser << oldAddress << endl;
                myNewUser << oldPhoneNo << endl;
            }
        }

        break;
    case 3:
        cin.ignore();
        cout << "Please enter your updated phone number: ";
        getline(cin, newPhoneNo);
        while (getline(myUser, oldUserName) &&
            getline(myUser, oldPassword) &&
            getline(myUser, oldFirstName) &&
            getline(myUser, oldLastName) &&
            getline(myUser, oldCard) &&
            getline(myUser, oldAddress) &&
            getline(myUser, oldPhoneNo)) {
            if (oldUserName == userName && oldPassword == passWord) {
                myNewUser << oldUserName << endl;
                myNewUser << oldPassword << endl;
                myNewUser << oldFirstName << endl;
                myNewUser << oldLastName << endl;
                myNewUser << oldCard << endl;
                myNewUser << oldAddress << endl;
                myNewUser << newPhoneNo << endl;
            }
            else {
                myNewUser << oldUserName << endl;
                myNewUser << oldPassword << endl;
                myNewUser << oldFirstName << endl;
                myNewUser << oldLastName << endl;
                myNewUser << oldCard << endl;
                myNewUser << oldAddress << endl;
                myNewUser << oldPhoneNo << endl;
            }
        }
        break;
    default:
        cout << "Your Input is INVALID.\n";
        break;
    }
    myNewUser.close();
    myUser.close();
    remove("user.txt");
    if (rename("user2.txt", "user.txt") != 0) {
        cout << "Info has not been updated\n";
    }
    else {
        cin.clear();
        cin.ignore();
        system("CLS");
        cout << "*************Info has been UPDATED***************\n";
    }
}
   /* while ( choice <= 0 || choice > 2){
        char r;
        switch(choice){
            case 1:
            cout << "Please enter your updated credit card number: ";
            cin >> c;
            cout << "Your credit card number has been saved! Would you like to update anymore information? y/n\n";
            cardNum = c;
            cin >> r;
            if (r == 'y' || r == 'Y'){
                updatePaymentInfo(cardNum,address);
            }else {
                system("cls");
                printUserMenu();
                printDetailsUserMenu();
                break;
            }

            case 2:
            cout<< "Please enter your updated address: ";
            cin >> a;
            cout << "Your current address has been saved! Would you like to update anymore information? y/n\n";
            address = a;
            cin >> r;
            if (r == 'y' || r == 'Y'){
                updatePaymentInfo(cardNum,address);
            }else {
                system("cls");
                printUserMenu();
                printDetailsUserMenu();
                break;
            }

            default:
                cout << "Please choose a valid number.\n";
                break;
            }
        }
    
    fstream newFile;
    newFile.open("user.txt", ios::in);
    if (newFile.is_open()){
    newFile << userName << passWord << cardNum << address;
    newFile.close();
    }*/


