#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <sstream>
#include <string>

using namespace std;

enum MONTH_TYPE {Jan = 1, Feb=2, Mar=3, Apr=4, May=5, Jun=6, Jul=7, Aug=8, Sep=9, Oct=10, Nov=11, Dec=12};

class Date {
    friend class Network;
private:
	int day;
	int month;
	int year;
public:
    Date();
    Date(int day, int month, int year);
    Date(string str);
    bool set_date(string str);
    bool set_date(int day, int month, int year);
    void print_date(string type);
    bool operator==(const Date& rhs);
    bool operator!=(const Date& rhs);
    string get_date();
};
#endif
