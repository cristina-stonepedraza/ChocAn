#include <string>
using std::string;

class personalInfo{
    public:
        personalInfo();
        ~personalInfo();
        //
    protected:
        string* name;
        string* street_address;
        string* city;
        char state[3];//For example " OR'\0' "
        int zipCode;
        //
};
