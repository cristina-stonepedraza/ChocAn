#include <string>
#include <cctype>
#include <iostream>
//using std::string;
using namespace std;

class personalInfo{
    public:
        personalInfo();
        //~personalInfo(); // is there a need for a destructor?

        void get_info();
        
    protected:
        string name;
        string streetAddress;
        string city;
        string state;
        int zipCode;
};
