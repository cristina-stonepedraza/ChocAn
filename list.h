//list declarations

struct service_node
{
	service_node * next;
	service * a_service;
};

struct member_node
{
	member_node * next;
	member * mem_info;
	service_node * s_head;
};

struct provider_node
{
	provider_node * next;
	provider * prov_info;
};


class member_list
{
	public:
		member_list();
		~member_list();
		void add();     //append
		void remove();  //remove 1
		void display_all();
		void display_one();
	private:
		member_node * head;
};

class provider_list
{
	public:
		provider_list();
		~provider_list();
		void add();
		void remove();
		void display_all();
		void display_one();
	private:
		provider_node * head;
};


