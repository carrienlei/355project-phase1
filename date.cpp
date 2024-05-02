#include "date.h"

Date::Date(){
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
	string monthName;
	switch( month ) {
		case Jan: monthName = "January"; break;
		case Feb: monthName = "February"; break;
		case Mar: monthName = "March"; break;
		case Apr: monthName = "April"; break;
		case May: monthName = "May"; break;
		case Jun: monthName = "June"; break;
		case Jul: monthName = "July"; break;
		case Aug: monthName = "August"; break;
		case Sep: monthName = "September"; break;
		case Oct: monthName = "October"; break;
		case Nov: monthName = "November"; break;
		case Dec: monthName = "December"; break;
	}

    cout << monthName <<' ' << day << ", " << year << endl;
}

string Date::get_date(){
    string m = to_string(month);
    string d = to_string(day);
    string y = to_string(year);
    string date = m + "/" + d + "/" + y;
    return date;
}
