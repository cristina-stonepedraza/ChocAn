#include "../headers/caller.h"

#include <iostream>
#include <string>
using namespace std;

// caller class
caller::caller(){
    id_counter = 0;
    menu();
}

void caller::menu(){
    char c;
    do{
        cout<<"HERE ARE YOUR OPTIONS"<<endl;
        cout<<"\t1. New member"<<endl;
        cout<<"\t2. New provider"<<endl;
        cout<<"\t3. New service"<<endl;
        cout<<"\t4. Login as a provider"<<endl;
        cout<<"\t5. Logout as a provider"<<endl;
        cout<<"\t6. Conduct an appointment as a provider"<<endl;
        cout<<"\t7. End week"<<endl;
        cout<<"\t8. Exit"<<endl;
        cout<<"\nPick an option from the list supplied: ";
        cin>>c;
        cin.ignore(100,'\n');
        if(c == '1'){
            new_member();
        }
        else if(c == '2'){
            new_provider();
        }
        else if(c == '3'){
            new_service();
        }
        else if(c == '4'){
            login();
        }
        else if(c == '5'){
            logout();
        }
        else if(c == '6'){
            consult();
        }
        else if(c == '7'){
            end_week();
        }
        else if(c == '8'){
            cout<<"Thank you for using the program!"<<endl;
        }
        else{
            cout<<"INVALID CHOICE. PLEASE TRY AGAIN!"<<endl;
        }
    }while(c != '8');
}
///////////////////////////////////////////////once a provider "logs" in .....enter "VALIDATED"

void caller::consult(){
    int m_id, s_id;
    bool b;
    string m,p,s;
    if(p_data.size() == 0){
        cout<<"There is no provider added. Please add a provider and try again."<<endl;
        return;
    }
    if(m_data.size() == 0){
        cout<<"There is no member added. Please add a member and try again."<<endl;
        return;
    }
    if(s_data.size() == 0){
        cout<<"There are no services added. Please add a service and try again."<<endl;
        return;
    }
    if(p_data.login_status() == false){
        cout<<"There is no provider logged in. Please login and try again."<<endl;
        return;
    }

    //////////////////////CHECK WHETHER A MEMBER IS SUBSCRIBED OR NOT HERE
    do{
        m_data.display();
        cout<<"Please enter the member id you, the provider, want to lookup."<<endl;
        cin>>m_id;
        cin.ignore(100,'\n');
        b = m_data.search(m_id);
        if(b == false){
            cout<<"The member id was not found. Please try again."<<endl;
        }
    }while(b == false);
    m = m_data.search_and_fill(m_id);

    do{
        s_data.display();
        cout<<"Please enter the service id you, the provider, want to provide."<<endl;
        cin>>s_id;
        cin.ignore(100,'\n');
        b = s_data.search(s_id);
        if(b == false){
            cout<<"The service id was not found. Please try again."<<endl;
        }
    }while(b == false);
    s = s_data.search_and_fill(s_id); //Fills out the service name to s
    //Once we reach here, we should have a valid ID
    p = p_data.search_and_fill(); //Fills out the logged in provider to p

    int day, month, year;
    do{
        cout<<"Please enter the day of the service(for example, enter 14 if the date is 11/14/2021):"<<endl;
        cin>>day;
        cin.ignore(100,'\n');
         
        if((day<1)||(day>31)){
            cout<<"Invalid date entered. Make sure to have the day be between 1 and 31 and try again."<<endl;
        }
    }while((day<1)||(day>31));

    do{
        cout<<"Please enter the month of the service(make sure to input a NUMBER):"<<endl;
        cin>>month;
        cin.ignore(100,'\n');
        if((month<1)||(month>12)){
            cout<<"Invalid month entered. Make sure to have the month be between 1 and 12 and try again."<<endl;
        }
    }while((month<1)||(month>12));

    do{
        cout<<"Please enter the year of the service:"<<endl;
        cin>>year;
        cin.ignore(100,'\n');
        if((year<1970)||(year>2030)){
            cout<<"Invalid year entered. Make sure the year is within the range of 1970 and 2030 and try again."<<endl;
        }
    }while((year<1970)||(year>2030));

    int retval = m_data.generate_report(m_id, p, s, day, month, year);
    if(retval == 0){
        //generate provider report here
        float cost;
        do{
            cout<<"Please enter the cost of the service (Has to be greater than or equal to 0 and less than 1000):"<<endl;
            cin>>cost;
            cin.ignore(100,'\n');
            if(cost<0 || cost>1000){
                cout<<"Invalid cost entered. Please try again."<<endl;
            }
        }while(cost<0 || cost>1000);
        p_data.generate_report(m, m_id, s_id, cost, day, month, year);
    }
}


void caller::end_week(){
    m_data.end_week();
    p_data.end_week();
    cout<<"Weekly member reports have been stored at './data/member' and weekly provider reports have been stored at './data/provider'."<<endl;
}


void caller::new_member(){
    m_data.add(id_counter);
    id_counter += 1;
}


void caller::new_provider(){
    p_data.add(id_counter);
    id_counter += 1;
}


void caller::new_service(){
    s_data.add(id_counter);
    id_counter += 1;
}


void caller::login(){
    p_data.login();
}


void caller::logout(){
    p_data.logout();
}