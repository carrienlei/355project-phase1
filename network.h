#ifndef NETWORK_H
#define NETWORK_H

#include "Person.h"
#include "Date.h"
// You may need to add more libraries
#include <stdlib.h>
#include <fstream>
#include <dirent.h>
#include <string>
#include <limits>

class Network{
private:
    Person* head;
    Person* tail;
    int count;
    Person* search(Person* searchEntry);
    Person* search(string fname, string lname);
    Person* search(string code);

public:
    Network();
    Network(string fileName);
    ~Network();
    void push_front(Person* newEntry);
    void push_back(Person* newEntry);
    bool remove(string fname, string lname);
    void printDB();
    void showMenu();
};

#endif
