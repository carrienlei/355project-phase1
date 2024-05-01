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
    Person* now = head;
    while(current != NULL){
        Person* temp = now -> next;
        delete now;
        now = temp;
    }
}


Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    Person* ptr = head;
    while (ptr != NULL){
        if (*ptr == *searchEntry){ //Assuming overloaded the equality operator for Person
            return ptr; //Found person, return pointer to it
        }
        ptr = ptr->next;
    }
    return NULL; //Person not found
}


Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly. 
    Person* ptr = head;
    while(ptr != NULL){
        if(ptr->f_name == fname && found->l_name == lname) return found;
        ptr = ptr -> next;
    }
    return NULL;
}


void Network::loadDB(string filename){
    // TODO: Complete this method
    ifstream inputfile(filename);
    string f_name, l_name, birthdate, email, phone;
    int cnt = 0;
    while(getline(input file, f_name)){
        getline(inputfile,l_name);
        getline(inputfile,birthdate);
        getline(inputfile,email);
        getline(inputfile,phone);
        Person* person = new Person(f_name,l_name,birthdate,email,phone);
        push_back(person);
        //people separated by "--------------------" string
        getline(inputfile, f_name);
    }
    inputfile.close();
}

void Network::saveDB(string filename){
    // TODO: Complete this method
    ofstream file(filename);

    Person* person = head;
    while(person != NULL){
        outFile << person->l_name <<", " << person->f_name << endl;
        outFile << person->birthdate->get_date("Month D, YYYY") << endl;
        outFile << person->phone->get_contact("full") << endl;
        outFile << person->email->get_contact("full") << endl;
        outFile << "--------------------" <<endl;
        person = person->next;
    }

    outFile.close();

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


void Network::showMenu() {
  // TODO: Complete this method!
  // All the prompts are given to you,
  // You should add code before, between and after prompts!

  int opt;
  while (1) {
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

    if (opt == 1) {
      // TODO: Complete me!
      cout << "Saving network database \n";
      cout << "Enter the name of the save file: ";
      // Save the network database into the file with the given name,
      // with each person saved in the format the save as printing out the
      // person info, and people are delimited similar to "networkDB.txt" format
      cout << "Network saved in " << fileName << endl;
    } else if (opt == 2) {
      // TODO: Complete me!
      cout << "Loading network database \n";
      // TODO: print all the files in this same directory that have
      // "networkDB.txt" format print format: one filename one line. This step
      // just shows all the available .txt file to load.
      cout << "Enter the name of the load file: ";
      // If file with name FILENAME does not exist:
      cout << "File FILENAME does not exist!" << endl;
      // If file is loaded successfully, also print the count of people in it:
      cout << "Network loaded from " << fileName << " with " << count
           << " people \n";
    } else if (opt == 3) {
      // TODO: Complete me!
      // TODO: use push_front, and not push_back
      // Add a new Person ONLY if it does not exists!
      cout << "Adding a new person \n";
    } else if (opt == 4) {
      // TODO: Complete me!
      // if found, cout << "Remove Successful! \n";
      // if not found: cout << "Person not found! \n";
      cout << "Removing a person \n";
      cout << "First name: ";
      cout << "Last name: ";
    } else if (opt == 5) {
      // TODO: Complete me!
      // print the people with the given last name
      // if not found: cout << "Person not found! \n";
      cout << "Print people with last name \n";
      cout << "Last name: ";
    }

    else
      cout << "Nothing matched!\n";

    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cout << "\n\nPress Enter key to go back to main menu ... ";
    string temp;
    std::getline(std::cin, temp);
    cout << "\033[2J\033[1;1H";
  }
}
