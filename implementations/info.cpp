#include "../headers/info.h"
#include <iostream>
using namespace std;

personalInfo::personalInfo(){
    name = new string;
    street_address = new string;
    city = new string;
}

personalInfo::~personalInfo(){
    delete name;
    delete street_address;
    delete city;
}
