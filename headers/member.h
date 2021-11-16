#include <string>
using std::string;

class member{
    public:
        member(int id); //Data gets inputted from here
        //~member(); //unnecessary since we wont be having anything in the stack
        int write_to_file(string filename);//appends member info to filename
        bool is_match(int id); //returns true if match
    protected:
        string name;
        string street_address;
        string city;
        string state;
        string zip_code;
        //
        int member_number;
        bool is_member;//We will be simulating the value for this
};