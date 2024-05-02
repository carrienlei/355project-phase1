#include "Person.h"
#include "misc.h"
#include <map>
#include <vector>
using namespace std;

Person::Person(){
    set_person();
}

Person::~Person(){
    delete birthdate;
    delete email;
    delete phone;
    prev = NULL;
    next = NULL;
}

Person::Person(string f_name, string l_name, string birth, string email, string phone){
    this->f_name = f_name;
    this->l_name = l_name;
    this->birthdate = new Date(birth);
    this->email = new Email("full", email);
    this->phone = new Phone("full", phone);
}

Person::Person(string filename){
    set_person(filename);
}

void Person::set_person(){
        string temp, type, email_addr, num;

	cout << "First Name: ";
    getline(cin,f_name);

	cout << "Last Name: ";
    getline(cin,l_name);

    cout << "Birthdate (M/D/YYYY): ";
    getline(cin,temp);
    birthdate = new Date(temp);

    cout << "Type of email address: ";
    getline(cin,type);
    cout << "Email address: ";
    getline(cin,email_addr);
    email = new Email(type, email_addr);

    cout << "Type of phone number: ";
    getline(cin,type);
    cout << "Phone number: ";
    getline(cin,num);
    phone = new Phone(type, num);
}

void Person::set_person(string filename){
    ifstream input_file;
    input_file.open(filename.c_str());

    if (input_file.good()){
        getline(input_file, f_name, '\n');
        getline(input_file, l_name, '\n');
        string birth_date;
        getline(input_file, birth_date);
        birthdate = new Date(birth_date);

        string phone_type, email_type, phone_number, email_address;
        getline(input_file, phone_type, ' ');
        for(string::iterator i = phone_type.begin(); i != phone_type.end(); i++){
            if(!isalnum(phone_type.at(i - phone_type.begin()))){
                phone_type.erase(i);
                i--;
            }
        }
        getline(input_file, phone_number, '\n');
        phone = new Phone(phone_type, phone_number);

        getline(input_file, email_type, ' ');
        for(string::iterator i = email_type.begin(); i != email_type.end(); i++){
            if(!isalnum(email_type.at(i - email_type.begin()))){
                email_type.erase(i);
                i--;
            }
        }
        getline(input_file, email_address, '\n');
        email = new Email(email_type, email_address);
    }
    input_file.close();
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


void Person::print_friends(vector<Person*> myfriends) {
	vector<string> sortNames;
	map<string, string> sortedMap;
	for (Person* p : myfriends) {
		string code = codeName(p->f_name, p->l_name);
		sortedMap[code] = p->f_name + " " + p->l_name; 
		sortNames.push_back(code);
	}
	cout << "\nFriends of " << this->f_name << " " << this->l_name << ": \n";
    sort(sortNames.begin(), sortNames.end(), [](const string& a, const string& b) {
        // Check first letter
        if (a[0] != b[0]) {
            return a[0] < b[0];
        }
        if (a[1] != b[1]) {
            return a[1] < b[1];
        }
        return a < b;
    });
	
    for (const auto& code : sortNames) {
        for (const auto& friendPtr : myfriends) {
            if (code == codeName(friendPtr->f_name, friendPtr->l_name)) {
                cout << friendPtr->f_name << ", " << friendPtr->l_name << endl;
                break;
            }
        }
    }
}

void Person::print_person(){
    // Already implemented for you! Do not change!
	cout << l_name <<", " << f_name << endl;
	birthdate->print_date("Month D, YYYY");
    phone->print();
    email->print();
    this->print_friends(myfriends);
}