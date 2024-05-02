
#include <iostream>
#include "Date.h"
using namespace std;

int main(){

// EXAMPLE 1
    Date d1(13,2,2031); // 13022031
    d1.print_date("Month D, YYYY");
    d1.print_date("M/D/YYYY");
    d1.print_date("D-Month-YYYY");
    cout << "------------------\n";
    if (d1.check_leap_date()){
        cout << "This year is a leap year!" << endl;
    }
    else{
        cout << "This year is not a leap year" << endl;
    }
    cout << "------------------\n";
    if (d1.check_pal_date()){
        cout << "This date is a palindrome!" << endl;
    }
    else{
        cout << "This date is not a palindrome" << endl;
    }
    cout << "------------------\n" << endl;

// EXAMPLE 2
    Date d2(21,2,2012); // 21022012
    d2.print_date("Month D, YYYY");
    d2.print_date("M/D/YYYY");
    d2.print_date("D-Month-YYYY");
    cout << "------------------\n";
    if (d2.check_leap_date()){
        cout << "This year is a leap year!" << endl;
    }
    else{
        cout << "This year is not a leap year" << endl;
    }
    cout << "------------------\n";
    if (d2.check_pal_date()){
        cout << "This date is a palindrome!" << endl;
    }
    else{
        cout << "This date is not a palindrome" << endl;
    }
    cout << "------------------\n" << endl;

// EXAMPLE 3
    Date d3(3,11,1945); // 03111945
    d3.print_date("Month D, YYYY");
    d3.print_date("M/D/YYYY");
    d3.print_date("D-Month-YYYY");
    cout << "------------------\n";
    if (d3.check_leap_date()){
        cout << "This year is a leap year!" << endl;
    }
    else{
        cout << "This year is not a leap year" << endl;
    }
    cout << "------------------\n";
    if (d3.check_pal_date()){
        cout << "This date is a palindrome!" << endl;
    }
    else{
        cout << "This date is not a palindrome" << endl;
    }
    cout << "------------------\n" << endl;

    return 0;
}

