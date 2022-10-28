#include <iostream>
#include <fstream> 
#include <string.h>
#include "authlib.h"
#include <sstream>


void register_user();
void login_user();

using namespace std;

#include <openssl/sha.h>
#include <openssl/evp.h>

//modified version of https://stackoverflow.com/questions/3969047/is-there-a-standard-way-of-representing-an-sha1-hash-as-a-c-string-and-how-do-i
string GetHexRepresentation(const unsigned char *Bytes) {
    string ret;
    ret.reserve(SHA256_DIGEST_LENGTH * 2);
    for(const unsigned char *ptr = Bytes; ptr < Bytes+SHA256_DIGEST_LENGTH; ++ptr) {
        char buf[3];
        sprintf(buf, "%02x", (*ptr)&0xff);
        ret += buf;
    }
    return ret;
}

string HashFunction(string password1){
    unsigned char pass_arr[sizeof(password1)]; 

    for (int i = 0; i < sizeof(password1); i++) {
        pass_arr[i] = password1[i];
    }

    unsigned int len = strlen ((const char*) pass_arr);
    unsigned char hash [SHA256_DIGEST_LENGTH];

    SHA256(pass_arr, len, hash);

    string ret = GetHexRepresentation(hash); 

    return ret; 
  
}



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

    string hashed_pass = HashFunction(password1);

    ofstream f_out;

    f_out.open("passwords.txt", ios::app);
    f_out << username << ":" << hashed_pass << endl;
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

    string hashed_pass = HashFunction(password);

    ifstream f_in;
    f_in.open("passwords.txt");
    string user, pass;
    while (!f_in.eof())
    {
        getline(f_in, user, ':'); 

        getline(f_in, pass);

        
        if (user == username && pass == hashed_pass)
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
