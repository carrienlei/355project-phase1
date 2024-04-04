# 355project-phase1

### README

This repository contains C++ code snippets for a simple network management system. The system allows users to manage a network of persons, including adding, removing, and searching for individuals. 

#### Code Structure:

- `person.h`: Defines the `Person` class, including constructors, destructor, member functions, and overloaded operators.
- `contact.h`: Defines the `Email` and `Phone` classes along with their member functions.
- `network.h`: Defines the `Network` class responsible for managing the network of persons.
- `misc.h`: Contains miscellaneous helper functions.
- `date.h`: Defines the `Date` class to represent date information.
- `main.cpp`: Implements the main program logic, including user interactions and menu options.

#### `person.h`:

- Defines the `Person` class, which represents an individual in the network.
- Constructors allow instantiation of a `Person` object using interactive input or data from a file.
- Provides member functions for setting person details, printing person information, and overloading comparison operators.
- Memory management handled through dynamic memory allocation and proper destruction in the destructor.

#### `contact.h`:

- Defines the `Email` and `Phone` classes to represent contact information.
- Includes constructors to initialize contact details and member functions for setting contact information, retrieving in different styles, and printing.

#### `network.h`:

- Defines the `Network` class responsible for managing the network of persons.
- Includes constructors, destructor, and member functions for adding, removing, searching persons, loading and saving data, and displaying the menu.
- Implements functionality to interact with the user, load and save data from files, and perform operations on the network.

#### `misc.h`:

- Contains miscellaneous helper functions used within the program, such as banner printing.

#### `date.h`:

- Defines the `Date` class to represent date information.
- Provides constructors to initialize date objects from string input.
- Includes member function to print the date in specified formats.

#### Usage:

To use the provided code snippets, include the respective header files in your C++ project and instantiate necessary classes to manage a network of persons. Compile and run the program, follow the prompts to interact with the network, add, remove, or search for persons, and save or load the network data from files.

#### Note:

- Ensure all necessary header files are included in your project.
- Modify and extend the code as per your requirements.
- Error handling and input validation are not extensively covered in the provided code snippets, enhance them as needed for robustness.
