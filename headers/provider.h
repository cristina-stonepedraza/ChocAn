#include <string>
#include <vector>
using std::string;
using std::vector;

class provider{
    public:
        provider(int id);//
        void write_to_file();//appends provider info to filename
        bool is_match(int id);
        void whoami(string& name, int& id);//writes out the username and id to the variables;
        void end_week(int week);//Writes out remaining stuff to filename and ends week
        void generate_report(string m_name, int m_id, int s_id, int cost, int day, int month, int year);
        void display();
    private:
        string name;
        string street_address;
        string city;
        string state;
        string zip_code;
        int provider_number;
        int total_fee_weekly; //Gets reset every week
        int weekly_consultations; //number of consultations within the week
        bool is_cached;//////////////////checks to see if write_to_file has been called. Use this to avoid having an empty doc during end of week function call
};

class provider_list{
    //Login and logout functions can be here. also login_status functions
    public:
        provider_list();
        void add(int id);
        void login();
        void logout();
        void display();
        bool login_status();
        string search_and_fill();//Fills out the data of the logged in provider
        void generate_report(string m_name, int m_id, int s_id, int cost, int day, int month, int year);
        int size();
        void end_week();
    private:
        //Functions
        int return_index(int id);//searches through the data and returns the index of the match, if there is one. If not returns -1;
        //Variables
        vector<provider> data;
        int login_index;//gets set to -1 if noone is logged in
        int week_counter;
};
