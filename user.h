//user classes definitions 

class service
{
	public:
		service();
		service(char * service_date, int service_type);

		~service();

		void display_service();
	private:
		char * service_date; //format: month/day/year
		int service_type;    //1 for massage, 2 for gym, etc, etc...
};

class member
{
	public:
		member();
		member(char * id_num, char * name, char * address);

		~member();

		void display_member();

	private:
		char * id_num;
		char * name;
		char * address;
};

class provider
{
	public:
		provider();
		provider(char * id_num, char * name);

		~provider();

		void display_provider();

	private:
		char * id_num;
		char * name;
};
