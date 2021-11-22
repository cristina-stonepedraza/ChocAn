#include "../headers/provider.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


provider_list::provider_list(){
    week_counter = 0;
    login_index = -1;
}


void provider_list::login(){
    if(data.size() == 0){
        cout<<"There are no providers added. Please create a new provider before logging in."<<endl;
        return;
    }
    if(login_index != -1){
        string s;
        int i;
        data[login_index].whoami(s,i);
        cout<<"It seems that you are currently logged in as "<<s<<". Please log out and try to login again."<<endl;
        return;
    }

    int id;
    do{
        cout<<"Here is a list of all providers\n"<<endl; // If this were in real life, we wouldn't be displaying other providers' info since it will violate provacy.
        display();
        cout<<"Please enter the id you want to login with"<<endl;
        cin>>id;
        cin.ignore(100,'\n');
        if(return_index(id) == -1){
            cout<<"No matches were found with the id you provided. Please try again.\n\n"<<endl;
        }
    }while(return_index(id) == -1);
    login_index = return_index(id);
    cout<<"You have successfully logged in."<<endl;
}


void provider_list::add(int id){
    data.push_back(provider(id));//////////////////////////////
}


void provider_list::logout(){
    login_index = -1;
    cout<<"You have successfully logged out."<<endl;
}


bool provider_list::login_status(){
    if(login_index == -1){
        return false;
    }
    return true;
}


string provider_list::search_and_fill(){
    //Fills in the logged in provider's info
    if(login_index == -1){
        return "NONE";
    }
    string s;
    int i;
    data[login_index].whoami(s,i);
    return s;
}


void provider_list::generate_report(string m_name, int m_id, int s_id, int cost, int day, int month, int year){
    if(login_index == -1){
        cout<<"Failed to generate provider report. Reaseon is because there is no provider logged in"<<endl;
        return;
    }
    data[login_index].generate_report(m_name, m_id, s_id, cost, day, month, year);
}


int provider_list::size(){
    return data.size();
}


int provider_list::return_index(int id){
    //to be used by other functions within the provider_list class
    for(int i=0; i<(int)data.size(); ++i){
        if(data[i].is_match(id) == true){
            return i;
        }
    }
    return -1;
}


void provider_list::display(){
    //Call the display function in the provider 
    for(int i=0; i<(int)data.size(); ++i){
        data[i].display();
    }
}


void provider_list::end_week(){
    //CALL end_week function on all providers and then increase week counter
    for(int i=0; i<(int)data.size(); ++i){
        data[i].end_week(week_counter);
    }
    week_counter += 1;
}