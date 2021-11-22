#include <string>
#include <vector>
using std::string;
using std::vector;

class member{
    public:
        member(int id); //Data gets inputted from here
        //~member(); //unnecessary since we wont be having anything in the stack
        void write_to_file();//appends member info to filename
        void whoami(string& name, int& id);//writes out the username and id to the variables;
        bool is_match(int id); //returns true if match
        int generate_report(string provider_name, string service_name, int day, int month, int year);//generates a report for a specific service provided
        //bool is_cached();//Realized this was unnecessary
        void display();///////////
        void end_week(int week);//week gets provided by the member_list class
    protected:
        string name;
        string street_address;
        string city;
        string state;
        string zip_code;
        
        int member_number;
        bool is_member;//We will be simulating the value for this
        bool is_cached;
};


class member_list{
    public:
        member_list();
        //add helper functions here
        //such as search, add, delete, display
        void add(int id);//adds a new member to data
        //void remove(int id);
        void display();// [ID]   [Name]   [Member status]
        string search_and_fill(int id);
        bool search(int id);
        int size();
        int generate_report(int id, string provider_name, string service_name, int day, int month, int year);
        void end_week();
    private:
        vector<member> data;
        int week_counter;//Used for naming the output file
};