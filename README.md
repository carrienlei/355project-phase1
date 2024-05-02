# README
Team members: Andi, Angelly (8811852306, karycabr@usc.edu), Chiara Di Camillo (1801496232, dicamill@usc.edu)

# Instructions to Run Code:
Project Code:
```
g++ test_network.cpp Date.cpp Person.cpp contact.cpp network.cpp misc.cpp -o test_network
./test_network
```

Practice with Vectors:
```
g++ test_vector.cpp -o test_vector
./test_vector
```

# Findings:
The purpose of this project is to establish a network that uses linked lists to manage contact information and load/save files. While working on phase 1, our team found that linked lists allowed us to organize information easily by storing people as nodes and apply the linked lists functions directly. Where Lab 4 taught us the benefit of creating friend classes and class objects, network.cpp involved creating and storing class objects inside a linked list to build futher on the "has-a" relationship in class composition. 

Now in phase 2, we enhance our network by implementing the vector, "myfriends", to allow us to store pointers and print the user ID of each friend. Where we would have normally implemented a new data member in the Person class to handle this, using the vector allowed us to navigate through each person using pointers in the linked list and the helper function "codeName." 

There are no non-working parts to our code.

# Notes:
4/11 - Copied repo and files from project phase part 1

4/18 - Add new option in main menu to make connection, added vector <Person*> myfriends in Person class

4/19 - Add code to make two connections friends with each other - deleted those print_Person methods from part 1

4/19 - Added function to convert first name and last name to the respective codename: string codeName(string str1, string str2) in misc.h and misc.cpp

4/20 - Update print_person() function to print codenames for Person's connections

4/20 - Fixed bug in removing spaces to create username - would duplicate letters - fixed.

4/20 - Added a search(string code) function <- ended up not needing to use it since we won't use LoadDB/SaveDB

4/21 - clean up repo and submit

# References:
1. Used Chiara's code from lab 4 to read in lines from person_template.txt (lines 66-118 in Person.cpp)
2. http://www.cplusplus.com/forum/beginner/148876/ (lines 93-97, 105-109 in Person.cpp)
3. Used to check for hyphens in phone number string in contact.cpp: https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c
4. Referred to http://faculty.cs.niu.edu/~mcmahon/CS340/Notes/doubly_linked.html to help implement push_back and remove
5. Referred to https://stackoverflow.com/questions/2340281/check-if-a-string-contains-a-string-in-c to help implement option 2 in the menu
6. Referred to https://codescracker.com/cpp/program/cpp-program-list-files-in-directory.htm to help implement option 2 in menu (lines directly from 225-237)
7. Referred to this to write the insert function for myfriends vector: https://www.educba.com/c-plus-plus-vector-functions/
8. Referred to remove spaces from string using the algorithm library: https://www.tutorialspoint.com/remove-spaces-from-std-string-in-cplusplus, &
https://www.geeksforgeeks.org/remove-spaces-from-a-given-string/
9. Referred to convert uppercase chars to lowcase to create user ID: https://www.tutorialspoint.com/how-to-convert-std-string-to-lower-case-in-cplusplus
