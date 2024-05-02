#ifndef CONTACT_H
#define CONTACT_H

#include "Date.h"
#include "fstream"
#include <string>

class Contact {
public:
    string type;
    virtual void set_contact() = 0;
    virtual string get_contact(string style = "full") = 0;
    virtual void print() = 0;
};

class Email : public Contact {
    friend class Network;
private:
    string email_addr;
public:
    Email();
    Email(string type, string email_addr);
    void set_contact();
    string get_contact(string style);
    void print();
};

class Phone : public Contact {
    friend class Network;
private:
    string phone_num;
public:
    Phone();
    Phone(string type, string num);
    void set_contact();
    string get_contact(string style);
    void print();
};

#endif
