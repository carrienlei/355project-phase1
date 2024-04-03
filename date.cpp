#include "date.h"
#include <iostream>
#include <sstream>

Date::Date() {
    month = 1;
    day = 1;
    year = 1900;
}

Date::Date(string date_str) {
    stringstream ss(date_str);
    char delimiter;
    ss >> month >> delimiter >> day >> delimiter >> year;
}

void Date::print_date(string format) {
    string month_names[] = {"January", "February", "March", "April", "May", "June",
                            "July", "August", "September", "October", "November", "December"};

    if (format == "Month D, YYYY") {
        cout << month_names[month - 1] << " " << day << ", " << year << endl;
    } else {
        cout << "Invalid format!" << endl;
    }
}
