#include <iostream>
#include "contact.h"
// TODO: Add needed libraries! <- In contact.h

Email::Email(){
    set_contact();
}

Email::Email(string type, string email_addr){
    // TODO: Complete me!
    this->type = type;
    this->email_addr = email_addr;
}

void Email::set_contact(){
    // TODO: Do not change the prompts!

    cout << "Enter the type of email address: ";
    // some code here
    std::getline(std::cin, type);
    cout << "Enter email address: ";
    // some code here
    std::getline(std::cin, email_addr);
}

string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "Email (" + type + "): " + email_addr;
    else
        return email_addr;
}

void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact("full") << endl;
}

Phone::Phone(){
    set_contact();
}

Phone::Phone(string type, string num){
    // TODO: It is possible that num includes "-" or not, manage it!
    // TODO: Complete this method!
    // Note: We don't want to use C++11! stol is not valid!
    // The code has been covered in the discussion session

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

//Prompts the user to enter the information, like phone number or email address
void Phone::set_contact(){
    // TODO: Complete this method
    // Use the same prompts as given!
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
    // TODO: Complete this method, get hint from Email
    // The code has been covered in discussion session

	if (style=="full")
		return "Phone (" + type + "): " + phone_num;
    else
        return phone_num;

    /* Note: Understand your own TA's bug!
     * This code has a bug, can you understand it!
    int x1 = (phone_num/10000000);
	int x2 = ((phone_num)/10000)%1000;
	int x3 = phone_num%10000;
    */
}

void Phone::print(){
    // Note: get_contact is called with default argument << changed
	cout << get_contact("full") << endl;
}
