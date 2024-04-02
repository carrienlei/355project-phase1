#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;

public:
    Date();
    Date(string date_str);
    void print_date(string format);
};

#endif // DATE_H
