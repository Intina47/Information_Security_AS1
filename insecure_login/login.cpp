#include <iostream>
#include <fstream> 
#include <string.h>
#include <openssl/sha.h>
#include "authlib.h"


void register_user();
void login_user();
void forgot_credentials();
void forgot_password();
void forgot_username();


using namespace std;


int main() {
  
  int choice;
  cout << "Welcome to the Subverted Login System!" << endl << "Please select a choice from the following options" << endl << "*******************************************" << endl << "1. Register\n2. Login\n3. Exit\n  => " << endl;
  cin >> choice;

  switch (choice)
  {
  case 1:
    register_user();
    break;

  case 2: 
    login_user();
    break; 

  case 3: 
    exit(0);
    break;
  
  default:
    cout << "Please enter a valid choice!" << endl;
    break;
  }

  return 0;
}

//register a user using a while loop until the user enters the same password twice
void register_user()
{
    string username, password1, password2;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password1;
    cout << "Re-enter Password: ";
    cin >> password2;

    
    while (password1 != password2)
    {
        cout << "\nPasswords do not match" << endl;
        cout << "enter password:";

        cin >> password1;

        cout<< "Enter Password again:";

        cin >> password2;
    }
    ofstream f_out;
    f_out.open("passwords.txt", ios::app);
    f_out << username << ":" << password1 << endl;
    f_out.close();
    cout << "\nRegistration Successful\n" << endl;
}
void login_user()
{
    string username, password;
    cout << "enter username: ";
    cin >> username;
    cout << "enter password: ";
    cin >> password;

    ifstream f_in;
    f_in.open("passwords.txt");
    string user, pass;
    while (!f_in.eof())
    {
        getline(f_in, user, ':'); 

        getline(f_in, pass);
        
        if (user == username && pass == password)
        {
            cout << "\nLogin Successful\n" << endl;
            
            f_in.close();

            authenticated(user);
            
            break;
        }
    }

        if (f_in.eof())
        {
            cout << "\nInvalid Credentials\n" << endl;

            rejected(user);
        }

    f_in.close();
}
