#include "../headers/member.h"

// constructor
member::member()
{
    memberNumber = 0;
    isMember = false;
}

void member::get_info()
{
    personalInfo::get_info();
    
    cout << "Member number: ";
    cin >> memberNumber;
    cin.ignore(100, '\n');

    char answer;

    do {
        cout << "Is this person a member? (Y/N) ";
        cin >> answer;
        answer = toupper(answer);
        cin.ignore(100, '\n');

        if (answer != 'Y' && answer != 'N')
            cout << "Invalid input. Try again." << endl;

    } while (answer != 'Y' && answer != 'N');
}