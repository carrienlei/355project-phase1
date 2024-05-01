#include "person.h"
#include <iostream>
#include <fstream>
#include <sstream>
// Assuming Date, Email, and Phone classes are fully defined elsewhere

Person::Person() {
    // Assume this initializes a Person with interactive input
    set_person();
}

Person::Person(string f_name, string l_name, string b_date, string email_addr, string phone_num) {
    this->f_name = f_name;
    this->l_name = l_name;
    this->birthdate = new Date(b_date); // Assuming Date has a constructor accepting a string
    this->email = new Email("email", email_addr); // Simplified; actual implementation may vary
    this->phone = new Phone("phone", phone_num); // Simplified; actual implementation may vary
}

Person::Person(string filename) {
    set_person(filename);
}

Person::~Person() {
    delete birthdate;
    delete email;
    delete phone;
}

void Person::set_person() {
    cout << "First Name: ";
    std::getline(std::cin, this->f_name);
    cout << "Last Name: ";
    std::getline(std::cin, this->l_name);
    cout << "Birthdate (M/D/YYYY): ";
    string tempDate;
    std::getline(std::cin, tempDate);
    this->birthdate = new Date(tempDate);

    cout << "Type of email address (assuming only one type for simplicity): ";
    string emailType;
    std::getline(std::cin, emailType);
    cout << "Email address: ";
    string emailAddress;
    std::getline(std::cin, emailAddress);
    this->email = new Email(emailType, emailAddress); 

    cout << "Type of phone number (assuming only one type for simplicity): ";
    string phoneType;
    std::getline(std::cin, phoneType);
    cout << "Phone number: ";
    string phoneNumber;
    std::getline(std::cin, phoneNumber);
    this->phone = new Phone(phoneType, phoneNumber); // Simplified constructor call
}

void Person::set_person(string filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Cannot open file: " << filename << std::endl;
        return;
    }
    std::getline(file, this->f_name);
    std::getline(file, this->l_name);
    string tempDate;
    std::getline(file, tempDate);
    this->birthdate = new Date(tempDate); // Assuming proper format

    // Assuming file contains email and phone in a specific format
    string emailType, emailAddress;
    std::getline(file, emailType);
    std::getline(file, emailAddress);
    this->email = new Email(emailType, emailAddress);

    string phoneType, phoneNumber;
    std::getline(file, phoneType);
    std::getline(file, phoneNumber);
    this->phone = new Phone(phoneType, phoneNumber);
}

bool Person::operator==(const Person& rhs) {
    return this->f_name == rhs.f_name && this->l_name == rhs.l_name && this->birthdate == rhs.birthdate; // Assuming Date class has an operator== defined
}


bool Person::operator!=(const Person& rhs) {
    return !(*this == rhs);
}

void Person::print_person() {
    // Assuming Person has f_name, l_name members, and Date, Email, Phone classes have print() or similar methods
    std::cout << this->l_name << ", " << this->f_name << std::endl;
    this->birthdate->print_date("Month D, YYYY"); // Format assumed, adjust as necessary
    this->email->print(); // Assuming a print method exists
    this->phone->print(); // Assuming a print method exists
}

void Person::makeFriend(Person* newFriend){
    myfriends.push_back(newFriend);
    newFriend->myfriends.push_back(this);
}