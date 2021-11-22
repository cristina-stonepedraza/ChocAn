#include "../headers/member.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


member::member(int id){
    char verify, mem_status;
    is_cached = false;
    member_number = id;
    do{
        cout<<"Please enter member name:"<<endl;
        getline(cin,name);
        cout<<"Please enter member street address:"<<endl;
        getline(cin,street_address);
        cout<<"Please enter member city:"<<endl;
        getline(cin,city);
        cout<<"Please enter member state:"<<endl;
        getline(cin,state);
        cout<<"Please enter member zip code:"<<endl;
        getline(cin,zip_code);

        do{
            cout<<"Is member subscribed to chocan?(enter y for yes and n for no):"<<endl;
            cin>>mem_status;
            cin.ignore(100,'\n');
            if(tolower(mem_status)!='y' && tolower(mem_status)!='n'){
                cout<<"Invalid response! Try again."<<endl;
            }
        }while(tolower(mem_status)!='y' && tolower(mem_status)!='n');

        if(tolower(mem_status)=='y'){
            is_member = true;
        }
        else{
            is_member = false;
        }

        do{
            cout<<"\n\nHere are the member details:\nname: "<<name<<"\nAddress: "<<street_address<<"\nCity: "<<city<<"\nState: "<<state<<"\nZip code: "<<zip_code<<"\nID: "<<member_number<<"\nIs subscribed? : "<<is_member<<endl;
            cout<<"Do you wish to confirm?(y for yes and n for no):"<<endl;
            cin>>verify;
            cin.ignore(100,'\n');
            if(tolower(verify)!='y' && tolower(verify)!='n'){
                cout<<"Invalid response! Try again."<<endl;
            }
        }while(tolower(verify)!='y' && tolower(verify)!='n');

    }while(tolower(verify) != 'y');
    cout<<"\nYOUR ACCOUNT HAS BEEN CREATED. YOUR NEW MEMBER ID IS "<<member_number<<endl;
}


void member::write_to_file(){
    string filename = "cache/"+to_string(member_number)+".txt";
    ofstream out(filename);
    out<<"MEMBER PROFILE\n===================\n\nName: "<<name<<"\nAddress: "<<street_address<<"\nCity: "<<city<<"\nState: "<<state<<"\nZip code: "<<zip_code<<"\nMembership Status: "<<is_member;
    out<<"\n\nMEMBER REPORT\n===================\n\n";
    out.close();
}


void member::whoami(string& username, int& id){
    username = name;
    id = member_number;
}


bool member::is_match(int id){
    if(id == member_number){
        return true;
    }
    return false;
}


int member::generate_report(string provider_name, string service_name, int day, int month, int year){
    if(!is_member){
        char c;
        do{
            cout<<"The member is not currently subscribed to ChocAn.\nPress y if the member would want to resubscribe and n if not"<<endl;
            cin>>c;
            cin.ignore(100,'\n');
            if(tolower(c)!='y' && tolower(c)!='n'){
                cout<<"Invalid response. Please try again."<<endl;
            }
        }while(tolower(c)!='y' && tolower(c)!='n');

        if(tolower(c) == 'y'){
            is_member = true;
        }
        else{
            cout<<"The report was not generated since the member is not subscribed."<<endl;
            return -1;
        }
    }
    
    if(!is_cached){
        write_to_file();
        is_cached = true;
    }

    string filename = "cache/"+to_string(member_number)+".txt";
    ofstream out(filename, ios::app);

    out<<"SERVICE\n=============\nDate of service: "<<month<<"/"<<day<<"/"<<year<<"\nProvider name: "<<provider_name<<"\nService name: "<<service_name<<"\n\n";
    out.close();
    return 0;
}

/*
bool member::is_cached(){
    return cached;
}
*/


void member::end_week(int week){
    if(!is_cached){
        return;
    }

    string destination, source;
    source = "cache/"+to_string(member_number)+".txt";
    destination = "data/member/"+to_string(member_number)+"_"+to_string(week)+".txt";//format example  234567_1.txt

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
    //RESET is_cached here
    is_cached = false;
    out.close();
}


void member::display(){
    cout<<"Member ID: "<<member_number<<"\tMember name: "<<name<<"\tMember status: "<<is_member<<endl;
}