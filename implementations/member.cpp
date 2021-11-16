#include "../headers/member.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


member::member(int id){
    char verify;
    do{
        cout<<"Please enter your name:"<<endl;
        getline(cin,name);
        cout<<"Please enter your street address:"<<endl;
        getline(cin,street_address);
        cout<<"Please enter your city:"<<endl;
        getline(cin,city);
        cout<<"Please enter your state:"<<endl;
        getline(cin,state);
        cout<<"Please enter your zip code:"<<endl;
        getline(cin,zip_code);
        is_member = false;///////////////////
        verify = 'y';///////////////////////////////
        cout<<"Here are your details:\nname: "<<name<<"\nAddress: "<<street_address<<"\nCity: "<<city<<"\nState: "<<state<<"\nZip code: "<<zip_code<<"ID: "<<member_number<<"\nIs subscribed? : "<<is_member<<endl;
    }while(tolower(verify) != 'y');
}