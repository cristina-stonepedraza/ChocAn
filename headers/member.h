#include "info.h"

class member: public personalInfo{
    public:
        member();
        //~member(); // is there a need for a destructor?

        void get_info();
        
    private:
        int memberNumber;
        bool isMember;
};
