#include "artMenu.h"

void viewArtMenu(){

    cout << "========= Art and Word Bank =========";
    cout << "\t 1. View Designs \n";
    cout << "\t 2. Upload New Design \n";
    cout << "\t 3. Go Back \n";
    
}

void viewUploads(){
    string adminUploads;
    ifstream openfile ("Uploads.txt");
    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            getline(openfile, adminUploads);
            cout << adminUploads << endl;
        }
    }
}

void viewNewUploadsMenu(){
    ofstream adminUpload;
    adminUpload.open("New_Uploads.txt");

    string design;
    getline(cin, design);
    adminUpload << "Your Design has been Uploaded";

    adminUpload.close();

}

void viewDetailArtMenu(int option){
  

    system("CLS");
    cin.ignore();
    switch (option){
        case 1: 
        cout << "Here are Your Current Uploaded Designs";
        viewUploads();
        break;
        
        case 2: 
        cout << "Please Upload New Designs Here:"; 
        viewNewUploadsMenu();
        break;

        case 3: 
        break;

        default:
        cout << "INVALID CHOICE\n";
        break;
    }
}
   


