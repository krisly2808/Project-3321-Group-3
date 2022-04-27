#include "AM.h"
#include "LoginMenu.h"
#include "UserMenu.h"
#include <iostream>
using namespace std;


string userName;
string passWord;
int cardNum;
string fname;
string lname;
string address;
bool isAdmin = false;
bool validate = false;
ifstream userFile;
ifstream adminFile ("admin.txt", ios::in);
//Amani - Login menu



void getLogin(){
    validateLogin();
    
}



void validateLogin(){
    
    
    string s1;
    string s2;
    int userCard;
    string first;
    string last;
    int addressNum;
    string addressLine;
  
    

    while (validate == false){

    cout << "Welcome Back! \n\n";
    cout << "Please Enter your Username: ";
    cin >> userName;
    cout << "Please Enter your Password: ";
    cin >> passWord;

    userFile.open("user.txt", ios::in);
    if (userFile.is_open()){
    
    string s;
    while (std::getline(userFile, s, '\n')){

    userFile >> s1 >> s2 >> userCard >> addressNum >> addressLine ;
    cardNum = userCard;
    address = std::to_string(addressNum) + " " + addressLine;
   
    

    userFile.close();
    }
    if ((s1 == userName) && (s2 == passWord)){
        validate = true;
        isAdmin = false;
    }
    else if (validate == false){
        adminFile.open("admin.txt", ios::in);
        while(std::getline(adminFile, s, '\n')){
            adminFile >> s1 >> s2;

        }
        if((s1 == userName) && (s2 == passWord)){
            validate = true;
            isAdmin = true;
            printAdminMenu();
        }


    } else {
        validate = false;
    }
  }
}

 while (validate == true){
        char r;
        cout << "Hello " + userName;
        cout << "\nWould you like to update your saved information? y/n";
        cin >> r;

        if(r == 'y' || r =='Y'){
           updatePaymentInfo(cardNum, address);
        }
        else if (r == 'n' || r == 'N'){
            printUserMenu();
        }
    }


}
void updatePaymentInfo(int c, string a){

    int choice;
    
    cout << "\nHere is your current personal information:";
    cout << "\n1. Card number: " << c << endl;
    cout << "\n2. Current address: " << a <<endl;
    cout << "\nWhat would you like to update? (1 or 2)";
    cin >> choice;

    while ( choice <= 0 || choice > 2){
        char r;
        switch(choice){
            case 1:
            cout << "Please enter your updated credit card number: ";
            cin >> c;
            cout << "Your credit card number has been saved! Would you like to update anymore information? y/n";
            cardNum = c;
            cin >> r;
            if (r == 'y' || r == 'Y'){
                updatePaymentInfo(cardNum,address);
            }else {
                printUserMenu();
                break;
            }

            case 2:
            cout<< "Please enter your updated address: ";
            cin >> a;
            cout << "Your current address has been saved! Would you like to update anymore information? y/n";
            address = a;
            cin >> r;
            if (r == 'y' || r == 'Y'){
                updatePaymentInfo(cardNum,address);
            }else {
                printUserMenu();
                break;
            }

            default:
                cout << "Please choose a valid number";
                break;
            }
        }
    
    fstream newFile;
    newFile.open("user.txt", ios::out);
    if (newFile.is_open()){
    newFile << userName << passWord << cardNum << address;
    newFile.close();
}

}
