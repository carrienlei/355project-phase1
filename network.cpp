#include "network.h"
#include <limits>
#include "misc.h"
#include <fstream>

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
    Person* temp = head;
    while (temp != NULL){
        head = temp->next;
        delete head;
        temp = temp->next;
    }
    head = tail = NULL;
}

Person* Network::search(Person* searchEntry){
    // Searches the Network for searchEntry
    // if found, returns a pointer to it, else returns NULL
    Person* temp = head;
    if (temp == NULL){
        return NULL;
    }
    while (temp != NULL){
        if((temp->f_name == searchEntry->f_name) && (temp->l_name == searchEntry->l_name)){
            if ((temp->birthdate->day == searchEntry->birthdate->day) && (temp->birthdate->month == searchEntry->birthdate->month) && (temp->birthdate->year == searchEntry->birthdate->year)){
                if ((temp->email->email_addr == searchEntry->email->email_addr) && (temp->phone->phone_num == searchEntry->phone->phone_num)){
                    return temp;
                }
            }
        }
        temp = temp->next;
    }
    return NULL;
}

Person* Network::search(string fname, string lname){
    // New == for Person, only based on fname and lname
    // if found, returns a pointer to it, else returns NULL
    // TODO: Complete this method
    // Note: two ways to implement this, 1st making a new Person with fname and lname and and using search(Person*), 2nd using fname and lname directly.
    Person* temp = head;
    if (temp == NULL){
        return NULL;
    }
    while (temp != NULL){
        if((temp->f_name == fname) && (temp->l_name == lname)){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void Network::loadDB(string filename){
    ifstream inputfile(filename);
    if (!inputfile) {
        cerr << "Error opening file: " << filename << endl;
        return;
    }

    // Clear existing list first
    Person* current = head;
    while (current != nullptr) {
        Person* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
    tail = nullptr;
    count = 0;  // Reset the count variable

    string dashed_line, fname, lname, birthdate, email, phone;

    // Skipping empty lines or separator lines
    while (getline(inputfile, fname)) {
        if (fname.empty() || fname[0] == '-') {
            continue;  
        }

        getline(inputfile, lname);
        getline(inputfile, birthdate);
        getline(inputfile, email);
        getline(inputfile, phone);
        getline(inputfile, dashed_line); 

        try {
            Person* newEntry = new Person(fname, lname, birthdate, email, phone);
            this->push_back(newEntry);  // Add the new person to the list
        } catch (const std::invalid_argument& e) {
            cerr << "Error creating person: " << e.what() << endl;
        }
    }

    inputfile.close();

}

void Network::saveDB(string filename){
    ofstream outfile(filename);
 
    Person* person = head;
    while(person != NULL){
        outfile << person->l_name <<", " << person->f_name << endl;
        outfile << person->birthdate->get_date() << endl;
        outfile << person->phone->get_contact("full") << endl;
        outfile << person->email->get_contact("full") << endl;
        outfile << "--------------------" <<endl;
        person = person->next;
    }

    outfile.close();

}

void Network::printDB(){
    // Leave me alone! I know how to print!
    // Note: Notice that we don't need to update this even after adding to Personattributes
    // This is a feature of OOP, classes are supposed to take care of themselves!
    cout << "Number of People: " << count << endl;
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
    newEntry->next = NULL;
    newEntry->prev = tail;

    if (head == NULL)
        head = newEntry;
    else
        tail->next = newEntry;

    tail = newEntry;
    count++;
}

Person* Network::search(string code){
    Person* temp = head;
    if (temp == NULL){
        return NULL;
    }
    while (temp != NULL){
        string temp_code = codeName(temp->f_name, temp->l_name);
        if(temp_code == code){
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

bool Network::remove(string fname, string lname){

    if (head == NULL){
        cout << "Network is empty" << endl;
        return false;
    }

    // If there is only one entry
    if (head == tail){
        if((head->f_name == fname) && (head->l_name == lname)){
            delete head;
            head = NULL;
            tail = NULL;
            count--;
            return true;
        }
    }

    Person* temp = head;
    while (temp != NULL){
        if((temp->f_name == fname) && (temp->l_name == lname)){
            // If at front
            if (temp == head){
                head = head->next;
                head->prev = NULL;
                delete temp;
                count--;
                return true;
            }

            // If at end
            else if (temp == tail){
                tail = tail->prev;
                tail->next = NULL;
                delete temp;
                count--;
                return true;
            }

            // If somewhere in middle
            else{
                Person* prevPerson = temp->prev;
                Person* nextPerson = temp->next;

                prevPerson->next = temp->next;
                nextPerson->prev = temp->prev;
                delete temp;
                count--;
                return true;
            }
        }
        temp = temp->next;
    }
    return false;
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
        cout << "6. Connect \n";
        cout << "7. Print Database \n";
        cout << "8. Exit \n";
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
            cout << "Saving network database \n";
            cout << "Enter the name of the save file: ";
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
	        cout << "Enter the name of the load file: "; 
	        getline(cin, fileName);
	        // If file with name FILENAME does not exist: 
	        ifstream load_fileName(fileName);
	        if(!load_fileName){
	            cout << "File " << fileName << " does not exist!" << endl;
	        }   
	        else{
	            loadDB(fileName);
	            cout << "Network loaded from " << fileName << " with " << count << " people \n";
	        }       
	    }
        else if (opt == 3){
            // TODO: Complete me!
            // TODO: use push_front, and not push_back
            // Add a new Person ONLY if it does not exists!
            cout << "Adding a new person \n";
            Person* new_person = new Person();
            Person* temp = search(new_person->f_name, new_person->l_name);
            if (temp != NULL){
                cout << "Person already exists!" << endl;
            }
            else{
                push_front(new_person);
            }
        }

        else if (opt == 4){
            // TODO: Complete me!
            cout << "Removing a person \n";
            cout << "First name: ";
            std::getline(std::cin, fname);
            cout << "Last name: ";
            std::getline(std::cin,lname);

            if(remove(fname, lname)){
                cout << "Remove Successful! \n";
            }
            else{
                cout << "Person not found! \n";
            }
        }
        else if (opt == 5){
            // TODO: Complete me!
            cout << "Print people with last name \n";
            cout << "Last name: ";
            std::getline(std::cin,lname);

            bool found = false;
            Person* current = head; 
            while (current != NULL) {
            if (current->l_name == lname) {
                current->print_person();
                cout << "------------------------------" << endl;
                found = true;
            }
            current = current->next;
            }

            if (!found) {
                cout << "Nothing matched! \n";
            }

        }
	else if (opt == 6)
        {
            cout << "Make friends \n";

            cout << "Person 1 \n";
            cout << "First name: ";
            std::getline(std::cin, fname);
            cout << "Last name: ";
            std::getline(std::cin,lname);

            Person *entry = search(fname, lname);
            if(entry != NULL){
                cout << "Person 2 \n";
                cout << "First name: ";
                std::getline(std::cin, fname);
                cout << "Last name: ";
                std::getline(std::cin,lname);
                Person *second_entry = search(fname, lname);
                if(second_entry != NULL){
                    if((second_entry->f_name == entry->f_name) && (second_entry->l_name == entry->l_name)){
                        cout << "Note: Cannot connect with oneself." << endl;
                    }
                    else{
                        entry->makeFriend(second_entry);
                        second_entry->makeFriend(entry);
                        cout << "Friendship made!" << endl;
                    }
                }
                else{
                    cout << "Person not found! \n";
                }
            }
            else{
                cout << "Person not found! \n";
            }
        }

        else if (opt == 7){
            printDB();
        }

        else if (opt == 8){
            return;
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