#include "../headers/provider.h"

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;


provider::provider(int id){
    // Sets then number of consultations and the total weekly fee to 0
    is_cached = false;
    weekly_consultations = 0;
    total_fee_weekly = 0;

    // Prompts user input
    char verify;
    provider_number = id;
    do{
        cout<<"Please enter provider name:"<<endl;
        getline(cin,name);
        cout<<"Please enter provider street address:"<<endl;
        getline(cin,street_address);
        cout<<"Please enter provider city:"<<endl;
        getline(cin,city);
        cout<<"Please enter provider state:"<<endl;
        getline(cin,state);
        cout<<"Please enter provider zip code:"<<endl;
        getline(cin,zip_code);
        do{
            cout<<"\n\nHere are the provider details:\nname: "<<name<<"\nAddress: "<<street_address<<"\nCity: "<<city<<"\nState: "<<state<<"\nZip code: "<<zip_code<<endl;
            cout<<"Do you wish to confirm?(y for yes and n for no):"<<endl;
            cin>>verify;
            cin.ignore(100,'\n');
            if(tolower(verify)!='y' && tolower(verify)!='n'){
                cout<<"Invalid response! Try again."<<endl;
            }
        }while(tolower(verify)!='y' && tolower(verify)!='n');

    }while(tolower(verify) != 'y');
    cout<<"\nYOUR ACCOUNT HAS BEEN CREATED. "<<name<<"'S NEW PROVIDER ID IS "<<provider_number<<endl;
}


void provider::write_to_file(){
    string filename = "cache/"+to_string(provider_number)+".txt";
    ofstream out(filename);
    out<<"PROVIDER PROFILE\n===================\n\nName: "<<name<<"\nAddress: "<<street_address<<"\nCity: "<<city<<"\nState: "<<state<<"\nZip code: "<<zip_code;
    out<<"\n\nPROVIDER REPORT\n===================\n\n";
    out.close();
}


void provider::whoami(string& username, int& id){
    username = name;
    id = provider_number;
}


bool provider::is_match(int id){
    if(id == provider_number){
        return true;
    }
    return false;
}


void provider::end_week(int week){
    // Write out the final stuff out here and reset the total variables.
    if(!is_cached){
        return;
    }

    string destination, source;
    source = "cache/"+to_string(provider_number)+".txt";
    destination = "data/provider/"+to_string(provider_number)+"_"+to_string(week)+".txt";//format example  234567_1.txt

    string s;
	ofstream out(destination);
	ifstream in(source);

	while(in && !in.eof()){
        getline(in, s);
		if(!in.eof()){
			out<<s<<endl;
		}
		else{
			out<<s;
		}
	}
    
    //Write out the total cost ant the total number of consultations here
    out<<"WEEKLY TOTALS\n===================\n\n"<<"Total consultations within the week: "<<weekly_consultations<<"\nTotal service cost: "<<total_fee_weekly<<"\n\n===================\n";
    //Reset the totals for the upcoming weeks
    weekly_consultations = 0;
    total_fee_weekly = 0;

    //Reset is_cached here
    is_cached = false;
    out.close();
}


void provider::generate_report(string m_name, int m_id, int s_id, int cost, int day, int month, int year){
    if(!is_cached){
        write_to_file();
        is_cached = true;
    }

    //Adds to the total consultations and the total fee
    total_fee_weekly += cost;
    weekly_consultations += 1;

    //Open the file to which the report gets saved
    string filename = "cache/"+to_string(provider_number)+".txt";
    ofstream out(filename, ios::app);

    //Get the current time as a string
    string current_time;
    time_t now = time(0);
    current_time = ctime(&now);

    out<<"SERVICE\n=============\nDate of service: "<<month<<"/"<<day<<"/"<<year<<"\nDate Received: "<<current_time<<"\nMember name: "<<m_name<<"\nMember number: "<<m_id<<"\nService ID number: "<<s_id<<"\nService cost: "<<cost<<"\n\n";
    out.close();
}


void provider::display(){
    cout<<"Provider ID: "<<provider_number<<"\tProvider name: "<<name<<endl;
}
