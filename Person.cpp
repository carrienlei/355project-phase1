#include "Person.h"
#include "misc.h"
// Assuming Date, Email, and Phone classes are fully defined elsewhere

Person::Person(){
    // Assume this initializes a Person with interactive input
    set_person();
}

Person::~Person(){
    delete birthdate;
    delete email;
    delete phone;
    prev = NULL;
    next = NULL;
}

Person::Person(string f_name, string l_name, string bdate, string email, string phone){
    this->f_name = f_name;
    this->l_name = l_name;
    this->birthdate = new Date(bdate);
    this->email = new Email("full", email);
    this->phone = new Phone("full", phone);
}

Person::Person(string filename){
    set_person(filename);
}

void Person::set_person(){
        string temp, type, email_addr, num;

	cout << "First Name: ";
    std::getline(std::cin,f_name);

	cout << "Last Name: ";
    std::getline(std::cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    std::getline(std::cin,temp);
    birthdate = new Date(temp);

    // Assuming file contains email and phone in a specific format
    cout << "Type of email address: ";
    std::getline(std::cin,type);
    cout << "Email address: ";
    std::getline(std::cin,email_addr);
    email = new Email(type, email_addr);

    cout << "Type of phone number: ";
    std::getline(std::cin,type);
    cout << "Phone number: ";
    std::getline(std::cin,num);
    phone = new Phone(type, num);
}


void Person::set_person(string filename){
    std::ifstream infile;
    infile.open(filename.c_str());

    if(!infile.is_open()){
      cout << "Error opening file!" << endl;
      return;
    }

    if (infile.good()){
      // Line #1: first name
      std::getline(infile, f_name, '\n');

      // Line #2: last name
      std::getline(infile, l_name, '\n');

      // Line #3: date of birth in string format
      std::string bdate;
      std::getline(infile, bdate);
      birthdate = new Date(bdate);

        std::string type1, type2, num, e;
        // Line #4: phone number and type
        std::getline(infile, type1, ' ');
        for(string::iterator i = type1.begin(); i != type1.end(); i++){
            if(!isalnum(type1.at(i - type1.begin()))){
                type1.erase(i);
                i--;
            }
        }
        std::getline(infile, num, '\n');
        phone = new Phone(type1, num);

        // Line #5: email and type
        std::getline(infile, type2, ' ');
        for(string::iterator i = type2.begin(); i != type2.end(); i++){
            if(!isalnum(type2.at(i - type2.begin()))){
                type2.erase(i);
                i--;
            }
        }
        std::getline(infile, e, '\n');
        email = new Email(type2, e);

    }
    infile.close();
}

bool Person::operator==(const Person& rhs){
    if ((f_name == rhs.f_name) && (l_name == rhs.l_name) && (birthdate == rhs.birthdate))
	    return true;
    else
	    return false;
}

bool Person::operator!=(const Person& rhs){
    return !(*this == rhs);
}

void Person::makeFriend(Person* newFriend)
{
    myfriends.insert(myfriends.begin(), newFriend);
}

void Person::print_person(){
    // Print the person's information
    cout << l_name <<", " << f_name << endl;
    birthdate->print_date("Month D, YYYY");
    email->print(); // Assuming a print method exists
    phone->print(); // Assuming a print method exists
    for (int i = 0; i < myfriends.size(); i++){
        Person* temp = myfriends[i];
        string code_name = codeName(temp->f_name, temp->l_name);
        cout << code_name << endl;
    }
}
