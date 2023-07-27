#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#ifndef ADMIN_H
#define ADMIN_H
using namespace std;



class Admin
{
    string password;
    string role;
    public:
        string username;
        string Name;
        string Email;
        string Phone;
        static string user_db;
        Admin(string username, string password, string role)
        {
            this->username = username;
            this->password = password;
            this->role = role;
        }
        friend ostream& operator<<(ostream& os, const Admin& admin)
        {
            os << "Username: " << admin.username << endl;
            os << "Password: " << admin.password << endl;
            os << "Role: " << admin.role << endl;
            return os;
        }

        void add_student();
        void remove_student();
        void view_all_students();
        void view_student_attendance();
        void view_student_grades();
        void view_timetable();
        void edit_timetable();
        void add_teacher();
        void remove_teacher();
        void view_all_teachers();
        bool search_student(string name);
        bool search_teacher(string name);
};

namespace admin_funcs {
    bool login(string, string);
    const string admin_db = "./Database/admins.csv";
}


namespace databases {

    // const string student_db = getenv("student_db");
    // const string teacher_db = getenv("teacher_db");
    // const string student_grades_db = getenv("student_grades_db");
    // const string student_attendance_db = getenv("student_attendance_db");
    // const string timetable_db = getenv("timetable_db");

    const string student_db = "./Database/students.csv";
    const string teacher_db = "./Database/teachers.csv";
    const string student_grades_db = "./Database/student_grades.csv";
    const string student_attendance_db = "./Database/student_attendance.csv";
    const string timetable_db = "./Database/timetable.csv";

}
namespace global_funcs {
    inline void input_flush() {
        cin.clear();
        // cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.ignore(1000, '\n');
    }
    template <typename T>
    void get_input(T& var, string prompt = "") {
        cout << prompt;
        if(!(cin >> var)) {
            cin.clear();
            // cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.ignore(1000, '\n');
            cout << "Invalid input!" << endl;
            throw "Invalid input!";
            return;
        }
    }
}



#endif