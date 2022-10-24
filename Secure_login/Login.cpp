#include<iostream>
#include<fstream>
#include<stdio.h>
#include<string.h>
using namespace std;

#include "login.h"


int main()
{
    main_menu();
    return 0;
}

void main_menu()
{
    int choice;
    cout << "Welcome to the Secure Login System" << endl;
    cout << "Please select from the menu options below" << endl;
    cout << "*******************************************"<< endl;
    cout << "1. Register\n2. Login\n3. Forgot Credentials\n4. Exit\n  => ";
    cin >> choice;
    while(choice != 4)
    {     
        switch (choice)
        {
            case 1: 
                register_user();
                break;
        
            case 2: 
                login_user();
                break;
                
            case 3:
                forgot_credentials();
                break;

            case 4:
                cout << "\nSystem Exiting..!\n";
                exit(0);
                break;    

            default:
                cout << "\nInvalid Choice\n" << endl;
        } 
        cout << "1. Register\n2. Login\n3. Forgot Credentials\n4. Exit\n  => ";
        cin >> choice; 
    }
}


//register a user using a while loop until the user enters the same password twice
void register_user()
{
    char username[20], password1[20], password2[20];
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password1;
    cout << "Re-enter Password: ";
    cin >> password2;

    
    while (strcmp(password1, password2) != 0)
    {
        cout << "\nPasswords do not match" << endl;
        cout << "enter password:";
        cin.getline(password1,20);

        cout<< "Enter Password again:";
        cin.getline(password2,20);
    }
    ofstream f_out;
    f_out.open("user.txt", ios::app);
    f_out << username << " " << password1 << endl;
    f_out.close();
    cout << "\nRegistration Successful\n" << endl;
}
void login_user()
{
    char username[20], password[20];
    cout << "enter username: ";
    cin >> username;
    cout << "enter password: ";
    cin >> password;


    ifstream f_in;
    f_in.open("user.txt");
    char user[20], pass[20];
    while (!f_in.eof())
    {
        f_in >> user >> pass;
        if (strcmp(user, username) == 0 && strcmp(pass, password) == 0)
        {
            cout << "\nLogin Successful\n" << endl;
            break;
        }
    }
    if (f_in.eof())
    {
        cout << "\nInvalid Credentials\n" << endl;
    }
    f_in.close();
}
//when user selects forgot credentials, the user is asked to enter the username or password to reset
void forgot_credentials()
{
    int choice;
    cout << "1. Forgot Username\n2. Forgot Password\nKindly make a Choice to proceed: ";
    cin >> choice;

    switch (choice)
    {
        case 1: 
            forgot_username();
            break;
    
        case 2: 
            forgot_password();
            break;

        default:
            cout << "\nInvalid Choice\n" << endl;
       
    }
}
void forgot_username()
{
    char password[20];
    cout << "enter password: ";
    cin >> password;
    //search for the password in the file
    ifstream f_in;
    f_in.open("user.txt");
    char user[20], pass[20];
    while (!f_in.eof())
    {
        f_in >> user >> pass;
        if (strcmp(pass, password) == 0)
        {
            cout << "\nYour username is: " << user << endl;
            break;
        }
    }
    if (f_in.eof())
    {
        cout << "\nInvalid Credentials\n" << endl;
    }
}

void forgot_password()
{
    char username[20];
    cout << "enter username: ";
    cin >> username;
    //search for the username in the file
    ifstream f_in;
    f_in.open("user.txt");
    char user[20], pass[20];
    while (!f_in.eof())
    {
        f_in >> user >> pass;
        if (strcmp(user, username) == 0)
        {
            cout << "\nYour password is: " << pass << endl;
            break;
        }
    }
    if (f_in.eof())
    {
        cout << "\nInvalid Credentials\n" << endl;
    }
}
