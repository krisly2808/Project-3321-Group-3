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

//Amani - Login menu
void getLogin(){
    validateLogin();
    
}



void validateLogin(){
    
    bool admin;
    string s1;
    string s2;
    int userCard;
    string line;
    bool member;
    ifstream inFile;

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

    inFile >> admin >> s1 >> s2 >> userCard >> line >> member;
    admin = isAdmin;

    

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
void updatePaymentInfo(int card, string address, bool member){
    


   


    
   



}
