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
    // TODO: complete this method!
    // Implement it in one single line!
    // You may need to implement the load method before this!
    loadDB(fileName);
}

Network::~Network(){ 
    delete head;
    delete tail;
}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    Person* ptr = head;
    while (ptr != nullptr){
        if (*ptr == *searchEntry){ //Assuming overloaded the equality operator for Person
            return ptr; //Found person, return pointer to it
        }
        ptr = ptr->next;
    }
    return nullptr; //Person not found
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly. 
    Person* ptr = head;
    int i = 0;
    Person arr[count];
    while (ptr->next != NULL) {
        if (ptr->f_name == fname && ptr->l_name == lname) {
            arr[i] = *ptr;
            i++;
        }
        ptr = ptr->next;
    }
    Person fin[i];
    for(int j=0; j<i; j++){
        fin[j] = arr[i];
    }
    return fin;
}




void Network::loadDB(string filename){
    // TODO: Complete this method
    ifstream inputfile(filename);
    string line, f_name, l_name, b_date, email, phone;
    int cnt = 0;
    while(getline(inputFile, line)){
        cnt++;
    }
    string arr[cnt];

    int i = 0;
    while(getline(inputFile, line)){
        arr[i++] = line;
    }

    int pcnt = cnt/6;
    Person *temp;

    for(int j=0; j<pcnt; j++){
        string f_name = arr[j*6];
        string _lname = arr[j*6 + 1];
        string b_date = arr[j*6 + 2];
        string email = arr[arr[j*6 + 3];
        string phone = arr[j*6 + 4];

        Person *newP = new Person(fname, lname, b_date, email, phone);
        if(j==0){
            head = newP;
            temp = newP;
            newP->prev = NULL;
        }
        else if(j==(pcnt-1)){
            newP->prev = temp;
            newP->prev->next = newP;
            newP->next = NULL;
            tail = newP;
        }
        else{
            newP->prev = temp;
            newP->prev->next = newP;
            temp = newP;
        }
    }
    inputFile.close();
}

void Network::saveDB(string filename){
    // TODO: Complete this method
    ofstream file(filename);
    if (!file) {
        cerr << "Error: Could not create file " << filename << endl;
        return;
    }

    Person* ptr = head;
    while (ptr != NULL) {
        // Write the information of each Person to the file
        file << ptr->f_name << "," << ptr->l_name << "," << ptr->b_date << endl;
        ptr = ptr->next;
    }

    file.close();
}


void Network::printDB(){
    // Leave me alone! I know how to print! 
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
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
    // Adds a new Person (newEntry) to the back of LL
    // TODO: Complete this method
    if (tail) {
        tail->next = newEntry;
        newEntry->prev = tail;
    } 
    tail = newEntry;
    if(!head){
        head = newEntry;
    }
    count++;
}


bool Network::remove(string fname, string lname){
    // TODO: Complete this method
    Person* ptr = search(fname, lname);
    if(ptr == nullptr){
        return false;
    }

    if(ptr->prev) ptr->prev->next = ptr->next;
    if(ptr->next) ptr->next->prev = ptr->prev;
    if(ptr==head) head = ptr->next;
    if(ptr==tail) tail = ptr->prev;

    delete ptr;
    count--;
    return true;
}


void Network::showMenu(){
    // TODO: Complete this method!
    // All the prompts are given to you, 
    // You should add code before, between and after prompts!

    int opt;
    while(1){
        cout << "\033[2J\033[1;1H";
        printMe("banner"); // from misc library

        cout << "Select from below: \n";
        cout << "1. Save network database \n";
        cout << "2. Load network database \n";
        cout << "3. Add a new person \n";
        cout << "4. Remove a person \n";
        cout << "5. Print people with last name  \n";
        cout << "\nSelect an option ... ";
        
        if (cin >> opt) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Wrong option! " << endl;
            return;
        }
        
        // You may need these variables! Add more if you want!
        string fname, lname, fileName, bdate;
        cout << "\033[2J\033[1;1H";

        if (opt==1){
            // TODO: Complete me!
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
            // Save the network database into the file with the given name,
            // with each person saved in the format the save as printing out the person info,
            // and people are delimited similar to "networkDB.txt" format
            cin >> fileName;
            saveDB(fileName);
            cout << "Network saved in " << fileName << endl;
        }
        else if (opt==2){
            // TODO: Complete me!
            cout << "Loading network database \n";
            // TODO: print all the files in this same directory that have "networkDB.txt" format
            // print format: one filename one line.
            // This step just shows all the available .txt file to load.
            DIR* dir;
            struct dirent* ent;
            if ((dir = opendir(".")) != NULL) {
                cout << "Available files:" << endl;
                while ((ent = readdir(dir)) != NULL) {
                    string filename = ent->d_name;
                    if (filename.find("networkDB.txt") != string::npos) {
                        cout << filename << endl;
                    }
                }
                closedir(dir);
            } else {
                cerr << "Error: Unable to open directory." << endl;
            }
            cout << "Enter the name of the load file: "; 
            cin >> fileName;
            loadDB(fileName);
            // If file with name FILENAME does not exist:
            ifstream file(fileName);
            if (!file) {
                cout << "File " << fileName << " does not exist!" << endl;
            } else { // If file is loaded successfully, also print the count of people in it:
                file.close();
                cout << "Network loaded from " << fileName << " with " << count << " people \n";
            }
        }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back 
            // Add a new Person ONLY if it does not exists!
            // Check if the person already exists in the network
            if (search(fname, lname) != nullptr) {
                cout << "Person already exists!" << endl;
            } else {
                // Create a new Person object with the provided information
                Person* newPerson = new Person(fname, lname, bdate);
                // Add the new person to the network
                push_front(newPerson);
                cout << "Adding a new person \n";
            }
        }
        else if (opt == 4){
            // TODO: Complete me!
            // if found, cout << "Remove Successful! \n";
            // if not found: cout << "Person not found! \n";
            cout << "Removing a person \n";
            cout << "First name: ";
            cin >> fname;
            cout << "Last name: ";
            cin >> lname;
            // Remove the person from the network
            if (remove(fname, lname)) {
                cout << "Remove Successful! \n";
            } else {
                cout << "Person not found! \n";
            }
        }
        else if (opt==5){
            // TODO: Complete me!
            // print the people with the given last name
            // if not found: cout << "Person not found! \n";
            cout << "Print people with last name \n";
            cout << "Last name: ";
            cin >> lname;
            // Search for people with the given last name
            Person* ptr = head;
            bool found = false;
            while (ptr != nullptr) {
                if (ptr->lname() == lname) {
                    // Print the details of the person
                    ptr->print_person();
                    found = true;
                }
                ptr = ptr->next;
            }
            // If no person with the given last name is found, print "Person not found!"
            if (!found) {
                cout << "Person not found! \n";
            }
        }
        
        else
            cout << "Nothing matched!\n";
        
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "\n\nPress Enter key to go back to main menu ... ";
        string temp;
        std::getline (std::cin, temp);
        cout << "\033[2J\033[1;1H";
    }
}
