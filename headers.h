class personalInfo{
    public:
        personalInfo();
        ~personalInfo();
        //
    protected:
        char* name;
        char* streetAddress;
        char* city;
        char state[3];//For example " OR'\0' "
        int zipCode;
        //
};

class member: public personalInfo{
    public:
        member();
        ~member();
        //
    private:
        int memberNumber;
        bool isMember;
};

//Find a way to load data to the provider class once they type in their provider number(and password maybe).
class provider: public personalInfo{
    public:
        provider();
        ~provider();
        //
    private:
        int providerNumber;
        int* services;//we can perhaps use a database or external file to save the corresponding service
};
