#ifndef PERSON_H
#define PERSON_H

#include "date.h"
#include "contact.h"
#include "fstream"
#include <string>
#include <iostream>
#include <vector>   
class Person{
    friend class Network;
private:
	string f_name;
	string l_name;
	Date *birthdate;
	Email *email;
    Phone *phone;
    Person* next;
    Person* prev;

public:
    Person();
    ~Person();
    vector <Person*> myfriends;     
    Person(string filename);
    Person(string f_name, string l_name, string bdate, string email, string phone);
	void print_person();
	void set_person();
	void set_person(string filename);
    bool operator==(const Person& rhs);
    bool operator!=(const Person& rhs);
    void makeFriend(Person* newFriend); 
    void print_friends(vector<Person*> myfriends);
};

#endif
