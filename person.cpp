#include "person.h"

Person::Person(){
    // I'm already done! 
    set_person();
}


Person::~Person(){
    delete birthdate;
    // TODO: complete the method!
}


Person::Person(string f_name, string l_name, string b_date, string email, string phone) 
    : f_name(f_name), l_name(l_name), email(email), phone(phone) {
    birthdate = new Date(b_date);
}


Person::Person(string filename){
    set_person(filename);
}


void Person::set_person(){
    // prompts for the information of the user from the terminal
    // first/last name can have spaces!
    // date format must be "M/D/YYYY"
    // We are sure user enters info in correct format.
    // TODO: complete this method!
    
    string temp;
    string type;

    cout << "First Name: ";
    // pay attention to how we read first name, as it can have spaces!
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    // pay attention to how we passed argument to the constructor of a new object created dynamically using new command
    birthdate = new Date(temp); 

    cout << "Type of email address: ";
    // code here
    cout << "Email address: ";
    // code here

    cout << "Type of phone number: ";
    // code here
    cout << "Phone number: ";
    // code here
    // code here
}


void Person::set_person(string filename){
    // reads a Person from a file
    // Look at person_template files as examples.     
    // Phone number in files can have '-' or not.
    // TODO: Complete this method!
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    string first_name, last_name, birthdate_str, phone_home, phone_work, email_work;
    // Read each line from the file
    getline(file, first_name);
    getline(file, last_name);
    getline(file, birthdate_str);
    getline(file, phone_home);
    getline(file, email_work);

    // Set the member variables accordingly
    f_name = first_name;
    l_name = last_name;
    birthdate = new Date(birthdate_str);
    phone = phone_home; // Assuming you only have one phone number
    email = email_work; // Assuming you only have one email address

    // Close the file
    file.close();
}


bool Person::operator==(const Person& rhs){
    // TODO: Complete this method!
    // Note: you should check first name, last name and birthday between two persons
    // refer to bool Date::operator==(const Date& rhs)
    return (f_name == rhs.f_name && l_name == rhs.l_name && *birthdate == *(rhs.birthdate));

}

bool Person::operator!=(const Person& rhs){ 
    // TODO: Complete this method!
    return !(*this == rhs);

}


void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    phone->print();
    email->print();
}