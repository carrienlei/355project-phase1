
#include "contact.h"
// TODO: Add needed libraries! Done
#include <iostream>
#include <string>
#include <algorithm> // For std::remove
using namespace std;


Email::Email(string type, string email_addr): type(type), email_addr(email_addr) {
    // TODO: Complete me! Done 
}


void Email::set_contact(){
    // TODO: Do not change the prompts!
	
    cout << "Enter the type of email address: ";
    cin >> type;
    cout << "Enter email address: ";
    cin >> email_addr;
}



string Email::get_contact(string style){
    // Note: We have default argument in declaration and not in definition!
    if (style=="full")
	    return "(" + type + ") " + email_addr;
    else 
        return email_addr;
}


void Email::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}


Phone::Phone(string type, string num): type(type) {
    // Remove '-' from num done 
    num.erase(remove(num.begin(), num.end(), '-'), num.end());
    this->num = num;
}


void Phone::set_contact(){
    // TODO: Complete this method done
    // Use the same prompts as given!
	cout <<"Enter the type of phone number: ";
	cin >> type;
	cout << "Enter the phone number: ";
	cin >> num;
	// Remove '-' from num
	num.erase(remove(num.begin(), num.end(), '-'), num.end());
}


string Phone::get_contact(string style){
    // TODO: Complete this method, get hint from Email  done
    if (style == "full")
        return "(" + type + ") " + num;
    else
        return num;
}


void Phone::print(){
    // Note: get_contact is called with default argument
	cout << get_contact() << endl;
}
