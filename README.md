# Network Management System

## Overview

This project implements a network management system in C++. It allows users to manage a network of individuals, including storing and retrieving their personal information, managing contacts, and connecting individuals as friends within the network.

## Files

### Date.cpp

This file defines the `Date` class, representing a date object with attributes for day, month, and year. It includes constructors for creating date objects and methods for setting the date, comparing dates, printing dates in different formats, and retrieving the date as a string.

### Person.cpp

The `Person` class is implemented in this file, providing functionalities for managing individual persons within the network. It includes constructors for creating person objects with various input formats and methods for setting attributes such as name, birthdate, email, and phone number. Additionally, it defines methods for comparing persons, printing person information, and retrieving person attributes.

### Contact.cpp

This file contains the implementation of two classes, `Email` and `Phone`, representing email and phone contact information, respectively. Each class includes constructors for creating contact objects and methods for setting and retrieving contact details. Additionally, it provides functionality for printing contact information in different formats.

### Misc.cpp

The miscellaneous functions used in the project are implemented in this file. It includes a function for printing a banner displaying the application name and a helper function for generating code names by concatenating and formatting strings.

### Network.cpp

The `Network` class is defined in this file, representing the network management system. It includes methods for managing a collection of person objects within the network, such as adding, removing, and searching for persons, loading and saving network data, and displaying a menu for user interaction. The class also provides functionality for connecting persons as friends within the network.

## Usage

To use the network management system:

1. Compile all the C++ files.
2. Run the compiled program.
3. Follow the prompts in the menu to perform various operations, such as adding or removing connections, searching for persons, connecting persons as friends, and saving or loading network data.

## Contributors

- Elaina Huber (ehuber@usc.edu)
- Carrie Lei (cnlei@usc.edu)
- Donya Badamchi (badamchi@usc.edu)

## Improvements/Next Steps

- Implement more robust error handling and input validation to enhance user experience and prevent unexpected behavior.
- Add support for additional features such as group management, event scheduling, or messaging within the network.
- Improve the efficiency of search and sorting algorithms to handle larger datasets more efficiently.
- Enhance the user interface with graphical elements for a more intuitive interaction experience.
- Conduct thorough testing to identify and fix any potential bugs or issues.
