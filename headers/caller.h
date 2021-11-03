#include "member.h"
#include "provider.h"


// Caller class to call other classes
// Ideally we can have one provider class signed in at a time but we can have multiple providers in the database
class m_node{
    public:
        m_node();
        ~m_node();
        void set_next(m_node* data);
        m_node* get_next();
    private:
        member data;
        m_node* next;
};
class p_node{
    public:
        p_node();
        ~p_node();
        void set_next(p_node* data);
        p_node* get_next();
    private:
        provider data;
        p_node* next;
};

class caller{
    public:
        caller();
        ~caller();
        void menu();
    private:
        m_node* member_head;
        p_node* provider_head;
};