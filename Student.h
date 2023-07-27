#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#ifndef Student_H
#define Student_H

class User 
{
    string password;

public:
    string username;
    string name;
    string email;
    string phone;
    User(string username, string password,string name, string Address, string Phone);
    static int count;

    friend ostream& operator<<(ostream& os, const User& user)
    {
        os << "Username: " << user.username << endl;
        os << "Password: " << user.password << endl;
        os << "Name: " << user.name << endl;
        os << "Email: " << user.email << endl;
        os << "Phone: " << user.phone << endl;
        return os;
    }
    //function declarations to view student info,attendance ,grades and timetables
    void view_student_info();
    void view_student_attendance();
    void view_student_grades();
    void view_timetable();
    

};

namespace user_funcs {
    void login();
    void register_user();
}



#endif

