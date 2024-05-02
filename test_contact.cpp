#include <iostream>
#include "Person.h"
#include "contact.h"

// TO RUN
// g++ test_contact.cpp Date.cpp Person.cpp contact.cpp -o test_contact
// ./test_contact

int main(){

    // Have user input information
    Email e1;
    Phone phone1;
    e1.print();
    phone1.print();
    cout << "----------------\n";

    // Pre-existing arguments
    Email e2("USC", "tommytrojan@usc.edu");
    Phone phone2("Office", "310-192-2847");
    e2.print();
    phone2.print();
    cout << "----------------\n";

    // Testing Person using the given template
    Person p("person_template.txt");
    p.print_person();
    cout << "----------------\n";

}

