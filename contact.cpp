
#include "contact.h"
#include <iostream>
#include <string>
#include <algorithm> // For std::remove
using namespace std;

Email::Email(string type, string email_addr){
    this->type = type;
    this->email_addr = email_addr;
}

void Email::set_contact(){
    cout << "Enter the type of email address: ";
    cin >> type;
    cout << "Enter email address: ";
    cin >> email_addr;
}

string Email::get_contact(string style){
    
    if (style=="full")
	    return "(" + type + ") " + email_addr;
    else 
        return email_addr;
}

void Email::print(){
    
	cout << get_contact() << endl;
}

Phone::Phone(string type, string num){

    this->type = type;

    for (char &c : num) {
        if (c == '-') {
            num.erase(std::remove(num.begin(), num.end(), '-'), num.end());
            break;
        }
    }
    this->num = num;
}