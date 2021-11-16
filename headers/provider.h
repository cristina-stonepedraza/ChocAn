//Find a way to load data to the provider class once they type in their provider number(and password maybe).
class provider{
    public:
        provider(int id);// 
        ~provider();
        bool authenticate(int providerID, string password);// Logs into the database to see if the supplied provider exists
    protected:
        string name;
        string street_address;
        string city;
        string state;
        int zip_code;
        //
        int provider_number; // Has to be greater than zero
        //int* services;//unnecessary if every provider provides every service
};
