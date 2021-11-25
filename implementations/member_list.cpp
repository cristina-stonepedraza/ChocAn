#include "../headers/member.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;


member_list::member_list(){
    week_counter = 0;
}


void member_list::add(int id){
    data.push_back(member(id));
}


void member_list::end_week(){
    //CALL end_week function on all members and then increase week counter
    for(int i=0; i<(int)data.size(); ++i){
        data[i].end_week(week_counter);
    }
    week_counter += 1;
}


void member_list::display(){
    //Call the display function in the member 
    for(int i=0; i<(int)data.size(); ++i){
        data[i].display();
    }
}


/*
void member_list::remove(int id){
    //
}
*/


string member_list::search_and_fill(int id){
    for(int i=0; i<(int)data.size(); ++i){
        if(data[i].is_match(id) == true){
            string s;
            data[i].whoami(s,id);//writes out s and id
            return s;
        }
    }
    return "NONE";
}


int member_list::size(){
    return data.size();
}


int member_list::generate_report(int id, string provider_name, string service_name, int day, int month, int year){
    // By the time this function gets called, the id has already been verified. therefore, we search through and then generate the report for the member that matches
    for(int i=0; i<(int)data.size(); ++i){
        if(data[i].is_match(id) == true){
            int x = data[i].generate_report(provider_name, service_name, day, month, year);
            return x;
        }
    }
    return -1;
}


bool member_list::search(int id){
    //searches and returns true if a match is found;
    for(int i=0; i<(int)data.size(); ++i){
        if(data[i].is_match(id) == true){
            return true;
        }
    }
    return false;
}