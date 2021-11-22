#include <string>
#include <vector>
using std::string;
using std::vector;


//Decided on a struct because service is too trivial
struct service{
    service(int service_id);
    string name;
    int service_id;
};


class service_list{
    public:
        int size();
        void add(int id);
        void display();
        bool search(int id);
        string search_and_fill(int id);
    private:
        vector<service> data;
};