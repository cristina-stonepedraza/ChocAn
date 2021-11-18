#include "../headers/info.h"
#include <iostream>

personalInfo::personalInfo(){
    // strings do not have a zero equivalent value(?)
    zipCode = 0;
}

// doesn't seem to be a need for destructors?
/*
personalInfo::~personalInfo(){
    //
}
*/

void personalInfo::get_info() {
    cout << "\nName: ";
    cin >> name;
    cin.ignore(100, '\n');

    cout << "Street address: ";
    cin >> streetAddress;
    cin.ignore(100, '\n');

    cout << "City: ";
    cin >> city;
    cin.ignore(100, '\n');

    cout << "State: ";
    cin >> state;
    cin.ignore(100, '\n');

    cout << "Zip code: ";
    cin >> zipCode;
    cin.ignore(100, '\n');
}
