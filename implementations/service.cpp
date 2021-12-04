#include "../headers/service.h"

#include <iostream>
#include <string>
using namespace std;

service::service(int id){
    service_id = id;
    char c;

    do{
        cout<<"Please enter the name of the service."<<endl;
        getline(cin, name);

        do{
            cout<<"The service name you entered was: "<<name<<endl;
            cout<<"Do you wish to confirm?(y for yes and n for no):"<<endl;
            cin>>c;
            cin.ignore(100,'\n');

            if(tolower(c)!='y' && tolower(c)!='n'){
                cout<<"Invalid response. Please try again."<<endl;
            }
        }while(tolower(c)!='y' && tolower(c)!='n');

    }while(tolower(c)!='y');
    cout<<"\nTHE NEW SERVICE HAS BEEN ADDED. THE SERVICE ID IS "<<service_id<<endl;
}


int service_list::size(){
    return data.size();
}


void service_list::display(){
    if(data.size() == 0){
        cout<<"There are no services added."<<endl;
        return;
    }
    for(int i=0; i<(int)data.size(); ++i){
        cout<<"Service ID: "<<data[i].service_id<<"\tService name: "<<data[i].name<<endl;
    }
}


void service_list::add(int id){
    data.push_back(service(id));
}


bool service_list::search(int id){
    for(int i=0; i<(int)data.size(); ++i){
        if(data[i].service_id == id){
            return true;
        }
    }
    return false;
}


string service_list::search_and_fill(int id){
    for(int i=0; i<(int)data.size(); ++i){
        if(data[i].service_id == id){
            return data[i].name;
        }
    }
    return "NONE";
}