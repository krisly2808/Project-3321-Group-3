#include "AM.h"
#include "LoginMenu.h"
#include "UserMenu.h"

string userName;
string passWord;
bool validate;


void getLogin(){
    validateLogin();
}


void validateLogin(){
    string s1;
    string s2;
    string line;
    bool validate;
    ifstream inFile;

    while (true){

    cout << "Welcome Back! \n\n";
    cout << "Please Enter your Username: ";
    cin >> userName;
    cout << "Please Enter your Password: ";
    cin >> passWord;

    
    inFile.open("c//user.txt");
    
    if (inFile.fail()){
        cout << "File Open Error";
    }

    inFile >> s1 >> s2;

    inFile.close();

    if ((s1 == userName) && (s2 == passWord)){
        validate = true;
    }
    else {
        validate = false;
    }
    //return validate;
    if (validate == true){
        char c;
        cout << "Please type 'a' if you are an Admin and 'u' if you are a User";
        cin >> c;
        
        if (c == 'a' || c == 'A'){
        //printAdminMenu();
        }
        else if (c == 'u' || c == 'U'){
        //printUserMenu();
        }
        else {
            cout << "Invalid Choice";
        }
    }
    else {
        cout << "You have entered the wrong combinatation of username and password!";   
    }
    
}
}
