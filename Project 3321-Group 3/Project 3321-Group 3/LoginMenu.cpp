#include "AM.h"
#include "LoginMenu.h"
#include "UserMenu.h"


bool isAdmin = false;
string userName;
string passWord;
int cardNum;
string address;
bool isMember = false;
bool validate = false;
ifstream inFile;
//Amani - Login menu



void getLogin(){
    validateLogin();
    
}

void printUserMenu() {};
void printAdminMenu() {};

void validateLogin(){
    
    bool admin;
    string s1;
    string s2;
    int userCard;
    int addressNum;
    string line;
    bool member;
    

    while (validate == false){

    cout << "Welcome Back! \n\n";
    cout << "Please Enter your Username: ";
    cin >> userName;
    cout << "Please Enter your Password: ";
    cin >> passWord;

    
    inFile.open("c//user.txt");
    
    if (inFile.fail()){
        cout << "File Open Error";
    }

    inFile >> admin >> s1 >> s2 >> userCard >> addressNum >> line >> member;
    isAdmin = admin;
    cardNum = userCard;
    address = std::to_string(addressNum) + " " + line;
    isMember = member;
    

    inFile.close();

    if ((s1 == userName) && (s2 == passWord)){
        validate = true;
    }
    else {
        validate = false;
    }
   
}
 while (validate == true && isAdmin == false){
        char r;
        cout << "Hello " + userName;
        cout << "Would you like to update your saved information? y/n";
        cin >> r;

        if(r == 'y' || r =='Y'){
           updatePaymentInfo(cardNum, address, isMember);
        }
        else if (r == 'n' || r == 'N'){
            printUserMenu();
        }
    }
  while (validate == true && isAdmin == true){
      printAdminMenu();
  } 

}
void updatePaymentInfo(int c, string a, bool m){

    int choice;
    
    cout << "Here is your current personal information:";
    cout << "1. Card number: " << c << endl;
    cout << "2. Current address: " << a <<endl;
    cout << "3. Member status: " << m << endl;
    cout << "What would you like to update? (1, 2, or 3)";
    cin >> choice;

    while ( choice <= 0 || choice > 3){
        char r;
        switch(choice){
            case 1:
            cout << "Please enter your updated credit card number: ";
            cin >> c;
            cout << "Your credit card number has been saved! Would you like to update anymore information? y/n";
            cardNum = c;
            cin >> r;
            if (r == 'y' || r == 'Y'){
                updatePaymentInfo(c,a,m);
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
                updatePaymentInfo(c,a,m);
            }else {
                printUserMenu();
                break;
            }

            case 3:
            cout << "Are you sure you would like to change your member status from " << m << " to " << !m << "? y/n" << endl;
            cin >> r;
            if (r == 'y' || r == 'Y'){
                bool temp;
                temp = !m;
                m = temp;
                cout << "Okay! Your member status has been changed to " << m << endl;
            }else {
                cout << "Okay! Your member status will remain " << m << endl;
            }
            isMember = m;
            cout << "Your member status has been saved! Would you like to update anymore information? y/n";
            if (r == 'y' || r == 'Y'){
                updatePaymentInfo(c,a,m);
            }else {
                printUserMenu();
                break;
            }
        }
    }
   
    fstream newFile;
    newFile.open("user.txt", ios::out);
    if (newFile.is_open()){
    newFile << isAdmin << userName << passWord << cardNum << address << isMember;
    newFile.close();
}

}
