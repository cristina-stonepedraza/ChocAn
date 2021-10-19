#include "info.h"

//Find a way to load data to the provider class once they type in their provider number(and password maybe).
class provider: public personalInfo{
    public:
        provider();// 
        ~provider();
        bool authenticate(int providerID, string password);// Logs into the database to see if the supplied provider exists
        bool isLogged();// Returns back whether a user is logged in to ChocAn or not
    private:
        int providerNumber; // Has to be greater than zero
        int* services;//we can perhaps use a database or external file to save the corresponding service
};
