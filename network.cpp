#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>
#include <sstream>

Network::Network(){
    head = NULL;
    tail = NULL;
    count = 0;
}

Network::Network(string fileName){
    loadDB(fileName);
}

Network::~Network(){ 
    Person* now = head;
    while(now != NULL){
        Person* temp = now -> next;
        delete now;
        now = temp;
    }
}

Person* Network::search(Person* searchEntry){
    Person* ptr = head;
    while (ptr != NULL){
        if (*ptr == *searchEntry){
            return ptr; //Found person, return pointer to it
        }
        ptr = ptr->next;
    }
    return NULL; //Person not found
}

Person* Network::search(string fname, string lname){
    Person* ptr = head;
    while(ptr != NULL){
        if(ptr->f_name == fname && ptr->l_name == lname) return ptr;
        ptr = ptr -> next;
    }
    return NULL;
}

void Network::loadDB(string filename){
    ifstream inputfile(filename);
    string f_name, l_name, birthdate, email, phone;
    int cnt = 0;
    while(getline(inputfile, f_name)){
        getline(inputfile,l_name);
        getline(inputfile,birthdate);
        getline(inputfile,email);
        getline(inputfile,phone);
        Person* person = new Person(f_name,l_name,birthdate,email,phone);
        push_back(person);
        getline(inputfile, f_name);
    }
    inputfile.close();
}

void Network::saveDB(string filename){
    ofstream outfile(filename);

    Person* person = head;
    while(person != NULL){
        outfile << person->l_name <<", " << person->f_name << endl;
        outfile << person->phone->get_contact("full") << endl;
        outfile << person->email->get_contact("full") << endl;
        outfile << "--------------------" <<endl;
        person = person->next;
    }

    outfile.close();
}

void Network::printDB(){
    cout << "Number of people: " << count << endl;
    cout << "------------------------------" << endl;
    Person* ptr = head;
    while(ptr != NULL){
        ptr->print_person();
        cout << "------------------------------" << endl;
        ptr = ptr->next;
    }
}

void Network::push_front(Person* newEntry){
    newEntry->prev = NULL;
    newEntry->next = head;

    if (head != NULL)
        head->prev = newEntry;
    else
        tail = newEntry;
    
    head = newEntry;
    count++;
}

void Network::push_back(Person* newEntry){
    newEntry->next = NULL;
    newEntry->prev = tail;

    if (tail != NULL)
        tail->next = newEntry;
    else
        head = newEntry;
    
    tail = newEntry;
    count++;
}

bool Network::remove(string fname, string lname){
    Person* ptr = search(fname, lname);
    if(ptr == NULL) return false;

    Person* prev = ptr->prev;
    Person* next = ptr->next;
            
    if(prev == NULL){
        head = next;
        next->prev = NULL;
    }
    if(next == NULL){
        tail = prev;
        prev->next = NULL;
    }
    if(prev != NULL && next != NULL){
        prev->next = next;
        next-> prev = prev;
    }

    delete ptr;
    count--;

    return true;
}

void Network::showMenu() {
  int opt;
  while (1) {
    cout << "\033[2J\033[1;1H";
    printMe("banner");

    cout << "Select from below: \n";
    cout << "1. Save network database \n";
    cout << "2. Load network database \n";
    cout << "3. Add a new person \n";
    cout << "4. Remove a person \n";
    cout << "5. Print people with last name  \n";
    cout << "6. Connect \n"; // New option added
    cout << "\nSelect an option ... ";

    if (cin >> opt) {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } 
    else {
      cin.clear();
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      cout << "Wrong option! " << endl;
      return;
    }

    string fname, lname, fileName, bdate;
    cout << "\033[2J\033[1;1H";
    if (opt == 1) {
      cout << "Saving network database \n";
      cout << "Enter the name of the save file: ";
      cin >> fileName;
      saveDB(fileName);  
      cout << "Network saved in " << fileName << endl;
    } 
    else if (opt == 2) {
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have "networkDB.txt" format
            // print format: one filename one line.
            // This step just shows all the available .txt file to load.
            cout << "Enter the name of the load file: "; 
            cin >> fileName;

            ifstream file(fileName);

            if(file){
                loadDB(fileName);
                            // If file is loaded successfully, also print the count of people in it: 
                cout << "Network loaded from " << fileName << " with " << count << " people \n";
            }
            else{
                // If file with name FILENAME does not exist: 
                cout << "File FILENAME does not exist!" << endl;
            }
        }
        else if (opt == 3) {
        cout << "Adding a new person \n";
        Person* person = new Person();
        if(search(person) == NULL){
            push_front(person);
        }
        }
        else if (opt == 4) {
            // TODO: Complete me!
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            cout << "First name: ";
            cin >> fname;
            cout << "Last name: ";
            cin >> lname;

            if(search(fname, lname) == NULL){
                cout << "Person not found! \n";
            }
            else{
                remove(fname, lname);
            }
        }
        else if (opt==5){

            // TODO: Complete me!
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            cout << "Print people with last name \n";
            cout << "Last name: ";
            cin >> lname;

            Person* ptr = head;
            int lastCount = 0;

            while(ptr != NULL){
                if(ptr->l_name == lname){
                    ptr->print_person();
                    lastCount++;
                }
                ptr=ptr->next;
            }
            if(!lastCount){
                cout << "Person not found! \n";
            }
        }
        
    else if (opt==6){
        cout << "Make friends\n";
        cout << "Person 1\n";
        cout << "First Name: ";
        getline(cin, fname);
        cout << "Last Name: ";
        getline(cin, lname);

        Person* person1 = search(fname, lname);
        if(person1 == NULL) {
            cout << "Person not found\n";
            continue;
        }

        cout << "Person 2\n";
        cout << "First Name: ";
        getline(cin, fname);
        cout << "Last Name: ";
        getline(cin, lname);

        Person* person2 = search(fname, lname);
        if(person2 == NULL) {
            cout << "Person not found\n";
            continue;
        }

        // Make them friends
        person1->makeFriend(person2);
        person2->makeFriend(person1);

        // Print the information of both persons
        cout << person1->l_name << ", " << person1->f_name << endl;
        cout << person1->birthdate<< endl;
        cout << "Phone (Cell): " << person1->phone->get_contact("full") << endl;
        cout << "Email (USC): " << person1->email->get_contact("full") << endl << endl;

        cout << person2->l_name << ", " << person2->f_name << endl;
        cout << person2->birthdate << endl;
        cout << "Phone (Cell): " << person2->phone->get_contact("full") << endl;
        cout << "Email (USC): " << person2->email->get_contact("full") << endl << endl;
    }
    else{
        cout << "Nothing matched!\n";
    
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}
}
