#include "../headers/member.h"
#include "../headers/provider.h"


// Caller class to call other classes
// Ideally we can have one provider class signed in at a time but we can have multiple providers in the database
class m_node: public member{
    public:
        m_node(int id);
    private:
        m_node* next;
};
class p_node: public provider{
    public:
        p_node(int id);
    private:
        p_node* next;
};

class caller{
    public:
        caller();
        ~caller();
        void menu();
        void end_week();
    private:
        m_node* member_head;
        p_node* provider_head;
        int id_counter;//Used when making new id for member or provider
};