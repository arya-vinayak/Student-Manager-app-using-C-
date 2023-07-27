#include <sstream>
#include <fstream>
#include "Student.h"
#include "Admin.h"

using namespace std;



int User::count = 0;

User::User(string userID, string password,string name, string email, string phone): username(userID), password(password), name(name),email(email), phone(phone)
{
    count++;
    cout << "\t\t\t Welcome " << userID << "!" << endl;
}


void user_funcs::login()
{
    cout << "\t\t\t Executing User Login..." << endl;
    int count = 0;
    string username, password, id, pass, address, phone, email,name;
    //////system("clear");
    cout << "\t\t\t Please Enter the username and password" << endl;
    cout << "\t\t\t Username: ";
    // cin >> userID;
    global_funcs::get_input(username);
    cout << "\t\t\t Password: ";
    // cin >> password;
    global_funcs::get_input(password);
    ifstream input(databases::student_db);
    if (!input.is_open())
    {
        cout << "File not found!" << endl;
        return;
    }
    string line;
    stringstream ss;
    input >> line;
    while (input >> line)
    {
        ss << line;
        getline(ss, id, ',');
        getline(ss, pass, ',');
        getline(ss,name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        ss.clear();
       
       if (username == id && password == pass)
        {
            cout << "\t\t\t Login Successful!" << endl;
            User::count++;
            count++;
            User user(username, password,name, address, phone);
            cout << "\t\t\t OPTIONS: " << endl;
            int choice;
            bool exit = false;
            while (!exit)
            {
                cout <<"\t\t\t1.View Student Info"<<endl;
                cout <<"\t\t\t2.View Student Attendance"<<endl;
                cout <<"\t\t\t3.View Student Grades"<<endl;
                cout <<"\t\t\t4.View Timetable"<<endl;
                cout <<"\t\t\t5.Exit"<<endl;
                global_funcs::get_input(choice);
                string confirm;
                switch (choice)
                {
                case 1:
                    user.view_student_info();
                    break;
                case 2:
                    user.view_student_attendance();
                    break;
                case 3:
                    user.view_student_grades();
                    break;
                case 4:
                    user.view_timetable();
                    break;
                case 5:
                    cout << "Exiting..." << endl;
                    return;
                default:
                    cout << "Invalid choice!" << endl;
                    break;
                }
                //////system("clear");
            }
        }
    }
    input.close();
    if (count == 0)
    {
        cout << "\t\t\t Invalid Username or Password!" << endl;
        cout << "\t\t\t Please try again!" << endl;
        // ////system("pause");
        // ////system("cls");
        return;
    }

    cout << "User Login executed!" << endl
         << endl;
}
        
void user_funcs::register_user()
{
    cout << "Executing User Registration..." << endl;
    string username, password,name, email, phone;
    cout << "\t\t\t Enter username: ";
    global_funcs::get_input(username);
    cout << "\t\t\t Enter password: ";
    global_funcs::get_input(password);
    cout << "\t\t\t Enter Name: ";
    global_funcs::get_input(name);
    cout << "\t\t\t Enter your email: ";
    global_funcs::input_flush();
    getline(cin, email);
    cout << "\t\t\t Enter phone: ";
    // cin.clear();
    // cin.ignore(1000,'\n');
    global_funcs::get_input(phone);
    ofstream output(databases::student_db, ios::app);
    if(!output.is_open()){
        cout << "File not found!" << endl;
        return;
    }
    output << username << "," << password << ","<< name << "," << email << "," << phone <<'\n';
    output.close();
    cout << "\t\t\t User Registered Successfully!" << endl;
    cout << "\t\t\t Please login to continue!" << endl;
    system("clear");
}


void User::view_student_info()
{
    ifstream input(databases::student_db);
    if (!input.is_open())
    {
        cout << "File not found!" << endl;
        return;
    }
    string line;
    stringstream ss;
    input >> line;
    while (input >> line)
    {
        ss << line;
        string id, pass, name, email, phone;
        getline(ss, id, ',');
        getline(ss, pass, ',');
        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, phone, ',');
        ss.clear();
        if (id == username)
        {
            cout << "Username: " << id << endl;
            cout << "Name: " << name << endl;
            cout << "Email: " << email << endl;
            cout << "Phone: " << phone << endl;
            return;
        }
    }
    input.close();
}
//attendance database contains data in the form of student name and corresponding attendance
void User::view_student_attendance()
{
    ifstream input(databases::student_attendance_db);
    if (!input.is_open())
    {
        cout << "File not found!" << endl;
        return;
    }
    string line;
    stringstream ss;
    input >> line;
    while (input >> line)
    {
        ss << line;
        string id, maths, science, english, social_studies, computer_science;
        getline(ss, id, ',');
        getline(ss, maths, ',');
        getline(ss, science, ',');
        getline(ss, english, ',');
        getline(ss, social_studies, ',');
        getline(ss, computer_science, ',');
        ss.clear();
        if (id == username)
        {
            cout << "Username: " << id << endl;
            cout << "Maths: " << maths << endl;
            cout << "Science: " << science << endl;
            cout << "English: " << english << endl;
            cout << "Social Studies: " << social_studies << endl;
            cout << "Computer Science: " << computer_science << endl;
            return;
        }
    }
    input.close();
}


//function to view student grades containing the grades of all the subjects in the order maths, science, english, social studies, computer science
//database contains data in the form of student name and corresponding grades in subjects
void User::view_student_grades()
{
    ifstream input(databases::student_grades_db);
    if (!input.is_open())
    {
        cout << "File not found!" << endl;
        return;
    }
    string line;
    stringstream ss;
    input >> line;
    while (input >> line)
    {
        ss << line;
        string id,maths,science,english,social_studies,computer_science;
        getline(ss, id, ',');
        getline(ss, maths, ',');
        getline(ss, science, ',');
        getline(ss, english, ',');
        getline(ss, social_studies, ',');
        getline(ss, computer_science, ',');
        ss.clear();
        if (id == username)
        {
            cout << "Username: " << id << endl;
            cout << "Maths: " << maths << endl;
            cout << "Science: " << science << endl;
            cout << "English: " << english << endl;
            cout << "Social Studies: " << social_studies << endl;
            cout << "Computer Science: " << computer_science << endl;
            return;
        }
    }
    input.close();
}


//function to view timetable of the student
//database contains data in the form of student name and corresponding timetable

void User::view_timetable()
{
    ifstream file(databases::timetable_db);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string day, period1, period2, period3, period4, period5, period6;
        getline(ss, day, ',');
        getline(ss, period1, ',');
        getline(ss, period2, ',');
        getline(ss, period3, ',');
        getline(ss, period4, ',');
        getline(ss, period5, ',');
        getline(ss, period6, ',');
        cout << "\t\t\t Day: " << day << endl;
        cout << "\t\t\t Period 1: " << period1 << endl;
        cout << "\t\t\t Period 2: " << period2 << endl;
        cout << "\t\t\t Period 3: " << period3 << endl;
        cout << "\t\t\t Period 4: " << period4 << endl;
        cout << "\t\t\t Period 5: " << period5 << endl;
        cout << "\t\t\t Period 6: " << period6 << endl;
        cout << endl;
    }
    file.close();
}
