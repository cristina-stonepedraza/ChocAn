#include "../headers/member.h"
#include "../headers/provider.h"
#include "../headers/service.h"

// Caller class to call other classes
class caller{
    public:
        //When calling functions that need id, call them using id_counter++ to increase the id counter.
        caller();
        //~caller();
        void consult();///////////////
        void menu();
        void end_week();//WHEN ENDING WEEK, iterate through all provider nodes and call the end_week() function for them
        void new_member(); // Adds a new member and assigns them an id
        void new_provider();// Adds a new provider and assigns them an id
        void new_service();// Adds a new service and assigns them an id
        void login();// Logs into a provider
        void logout();// Logs out of a provider
        //void display_member();
        //void display_provider();
        //void display_services();
    private:
        provider_list p_data;
        member_list m_data;
        service_list s_data;

        int id_counter;//Used when making new id for member or provider
};