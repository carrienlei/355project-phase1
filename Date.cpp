#include "Date.h"
#include <iostream>

Date::Date(){
    // cout << "Default constructor called! " << endl;
    day = 1;
    month = 1;
    year = 1900;
}

Date::Date(int day, int month, int year){
    // cout << "Constructor with integer arguments is called!" << endl;
    set_date(day, month, year);
}

Date::Date(string date_str){
    // input format is M/D/YYYY
    // cout << "Constructor wtih string argument is called" << endl;
    set_date(date_str);
}

bool Date::operator==(const Date& rhs){
    if ( (day == rhs.day) &&
         (month == rhs.month) &&
         (year == rhs.year))
        return true;
    else
        return false;
}

bool Date::operator!=(const Date& rhs){
    return !(*this == rhs);
}

bool Date::set_date(string date_str){
    // input format is M/D/YYYY

    month = atoi(str.substr(0, str.find('/')).c_str());

    str = str.substr(str.find('/')+1).c_str();
    day = atoi(str.substr(0, str.find('/')).c_str());

    str = str.substr(str.find('/')+1).c_str();
    year = atoi(str.c_str());

    if (check_date()==false){
        cout << "Error! Invalid date!" << endl;
        cout << "Date set to default!" << endl;
        day = 1;
        month = 1;
        year = 1970;
        return false;
    }
    return true;
}

bool Date::set_date(int day, int month, int year){
    this->month = month;
    this->day = day;
    this->year = year;
    if (check_date()==false){
        cout << "Error! Invalid date!" << endl;
        cout << "Date set to default!" << endl;
        this->day = 1;
        this->month = 1;
        this->year = 1970;
        return false;
    }

    return true;
}

void Date::print_date(string format){
	string month_str;
	switch( month ) {
		case Jan: month_str = "January"; break;
		case Feb: month_str = "February"; break;
		case Mar: month_str = "March"; break;
		case Apr: month_str = "April"; break;
		case May: month_str = "May"; break;
		case Jun: month_str = "June"; break;
		case Jul: month_str = "July"; break;
		case Aug: month_str = "August"; break;
		case Sep: month_str = "September"; break;
		case Oct: month_str = "October"; break;
		case Nov: month_str = "November"; break;
		case Dec: month_str = "December"; break;
	}
	if (type == "M/D/YYYY")
            cout << month <<'/' << day << '/' << year << endl;
    else if (type == "Month D, YYYY")
            cout << month_str <<' ' << day << ", " << year << endl;
    else if (type == "D-Month-YYYY")
            cout << day << '-' << month_str << '-' << year << endl;
    else
        cout << "Wrong print type!" << endl;
}

string Date::get_date(){
    string m = to_string(month);
    string d = to_string(day);
    string y = to_string(year);
    string date = m + "/" + d + "/" + y;
    return date;
}
