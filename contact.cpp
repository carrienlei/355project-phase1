
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


Phone::Phone(string type, string phone_num){
    this->type = type;
    this->phone_num = phone_num;
}

void Phone::set_contact(){
    cout <<"Enter the type of phone number: ";
    cin >> type;
    cout << "Enter the phone number: ";
    cin >> phone_num;
}


string Phone::get_contact(string style){
    if (style == "full")
        return "(" + type + "): " + phone_num;
    else
        return phone_num;
}


void Phone::print(){
    cout << get_contact() << endl;
}