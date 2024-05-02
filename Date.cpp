#include "Date.h"

Date::Date(){
    // cout << "Default constructor called! " << endl;
    day = 1;
    month = 1;
    year = 1970;
}


Date::Date(int day, int month, int year){
    set_date(day, month, year);
}


Date::Date(string str){

    set_date(str);
}

bool Date::set_date(int day, int month, int year){
    this->month = month;
    this->day = day;
    this->year = year;
    return true;
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


bool Date::set_date(string str){

    month = atoi(str.substr(0, str.find('/')).c_str());

    str = str.substr(str.find('/')+1).c_str();
    day = atoi(str.substr(0, str.find('/')).c_str());

    str = str.substr(str.find('/')+1).c_str();
    year = atoi(str.c_str());
    return true;
}



void Date::print_date(string type){
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
