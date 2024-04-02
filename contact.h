
#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <string>
#include <algorithm> //added
using namespace std;

class Contact {
    // TODO: private or protected? Look at your children!
protected:
	string type;
public:
	virtual void print() = 0;
    	virtual string get_contact(string style="full") = 0;
	virtual void set_contact() = 0;
};


class Email: public Contact{
private:
    string email_addr;
public:
    Email(string type, string email_addr);
    void print() override;
    string get_contact(string style = "full") override;
    void set_contact() override;
    // TODO: Complete me! done
};


class Phone: public Contact{
private:
    // TODO: modify dataType! Can int store 10 digit phone-number? 
	string num; 
public:
    Phone(string type, string phone_number);
    void print() override;
    string get_contact(string style = "full") override;
    void set_contact() override;
    // TODO: Complete me! done 
};

#endif
