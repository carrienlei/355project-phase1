#include <iostream>
#include "contact.h"

Email::Email(){
    set_contact();
}

Email::Email(string type, string email_addr){
    this->type = type;
    this->email_addr = email_addr;
}

//Getting the email type and email address
void Email::set_contact(){
    cout << "Enter the type of email address: ";
    std::getline(std::cin, type);
    cout << "Enter email address: ";
    std::getline(std::cin, email_addr);
}

string Email::get_contact(string style){
    if (style=="full")
	    return "Email (" + type + "): " + email_addr;
    else
        return email_addr;
}

void Email::print(){
	cout << get_contact("full") << endl;
}

Phone::Phone(){
    set_contact();
}

Phone::Phone(string type, string num){
    if (num.length() < 10){
        cout << "Error! Phone number won't be saved. Please enter a 10-digit phone number" << endl;
        return;
    }

    this->type = type;
    if(!(num.find("-") != std::string::npos))
    {
        num = num.substr(0, 3) + "-" + num.substr(3, 3) + "-" + num.substr(6);
    }
    this->phone_num = num;
}

//Getting the type of phone number and the phone number
void Phone::set_contact(){
	cout <<"Enter the type of phone number: ";
	std::getline(std::cin, type);
	string num;
	cout << "Enter the phone number: ";
	std::getline(std::cin, num);
	if(!(num.find("-") != std::string::npos))
    	{
        	num = num.substr(0, 3) + "-" + num.substr(3, 3) + "-" + num.substr(6);
    	}
	this->phone_num = num;
}

string Phone::get_contact(string style){
	if (style=="full")
		return "Phone (" + type + "): " + phone_num;
    else
        return phone_num;
}

void Phone::print(){
	cout << get_contact("full") << endl;
}
