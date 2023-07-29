#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "Admin.h"
using namespace std;


bool admin_funcs::login(string username, string password)
{
    ifstream file(databases::admin_db);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string user, pass;
        getline(ss, user, ',');
        getline(ss, pass, ',');
        if (user == username && pass == password)
        {
            cout <<"Welcome!" << endl;
            return true;
        }
        // cout << "\t\t\t Welcome " << username << "!" << endl;
    }
    return false;
}


bool Admin::search_teacher(const std::string& name) {
    // Open the teacher database file for reading
    ifstream file(databases::teacher_db);

    // Check if the file was successfully opened
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return false;
    }

    // Declare variables to store data from each line of the file
    string line;
    stringstream ss;
    string n, address, phone, email;

    // Read the first line (header line) to skip it as the file contains a header line
    file >> line;

    // Loop through each line in the file
    while (file >> line) {
        // Insert the line into the stringstream for parsing
        ss << line;

        // Parse the data from the stringstream using commas as delimiters
        getline(ss, n, ',');       // Extract the  teachers name
        getline(ss, address, ','); // Extract the teachers address
        getline(ss, phone, ',');   // Extract the teachers phone number
        getline(ss, email, ',');   // Extract the teachers email address

        // Clear the stringstream for the next line
        ss.clear();

        // Check if the extracted teacher name matches the name we are searching for
        if (n == name) {
            // If a match is found, return true to indicate that the hotel exists in the file
            //print the details of the teacher
            
            return true;
        }
    }

    // If the loop finishes without finding a match, the teacher does not exist in the file
    return false;
}
//student database contains username, password, name, phone, email
bool Admin::search_student(const std::string& name1)
{
    // Open the student database file for reading
    ifstream file(databases::student_db);

    // Check if the file was successfully opened
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return false;
    }

    // Declare variables to store data from each line of the file
    string line;
    stringstream ss;
    string username,password,name, phone, email;

    // Read the first line (header line) to skip it as the file contains a header line
    file >> line;

    // Loop through each line in the file
    while (file >> line) {
        // Insert the line into the stringstream for parsing
        ss << line;

        // Parse the data from the stringstream using commas as delimiters
        getline(ss, username, ',');       // Extract the student's username
        getline(ss, password, ','); // Extract the student's password
        getline(ss, name, ',');       // Extract the student name
        getline(ss, phone, ',');   // Extract the student phone number
        getline(ss, email, ',');   // Extract the student email address

        // Clear the stringstream for the next line
        ss.clear();

        // Check if the extracted student name matches the name we are searching for
        if (username == name1) {
            // If a match is found, return true to indicate that the hotel exists in the file
            return true;
        }
    }

    // If the loop finishes without finding a match, the student does not exist in the file
    return false;


}
//student database contains username, password, name, phone, email
void Admin::add_teacher()
{
    cout << "\t\t\t Enter teacher name: ";
    string username;
    cin.clear();
    cin.ignore(10000, '\n');
    getline(cin, username);

    cout << "\t\t\t Enter the teacher's address: ";
    string address;
    getline(cin, address);


    cout << "\t\t\t Enter Phone: ";
    string phone;
    getline(cin, phone);
    // cin.ignore(); // Add this to clear the newline character from the buffer

    cout << "\t\t\t Enter Email: ";
    string email;
    getline(cin, email);
    // cin.ignore(); // Add this to clear the newline character from the buffer

    ofstream file(databases::teacher_db, ios::app);
    file << username << "," << address << "," << email << "," << phone << endl;
    file.close();

    cout << "\t\t\t Teacher added successfully!" << endl;
}



void Admin::remove_student()
{
    cout << "\t\t\t Enter Student SRN: ";
    string name;
    global_funcs::input_flush();
    getline(cin, name);
    if (!search_student(name))
    {
        cout << "\t\t\t Student does not exist!" << endl;
        return;
    }
    ifstream file(databases::student_db);
    ofstream temp("temp.csv");
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string n, username, password, phone, email;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, n, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        if (username != name)
        {
            temp << line << endl;
        }
    }
    file.close();
    temp.close();
    remove(databases::student_db.c_str());
    rename("temp.csv", databases::student_db.c_str());
    cout << "\t\t\t Student removed successfully!" << endl;
}


void Admin::view_all_students()
{
    ifstream file(databases::student_db);
    string line;
    getline(file, line);//skip the header line
    while (getline(file, line))
    {
        stringstream ss(line);
        string username, password, name, phone, email;
        getline(ss, username, ',');
        getline(ss, password, ',');
        getline(ss, name, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        cout << "\t\t\t Username: " << username << endl;
        cout << "\t\t\t Password: " << password << endl;
        cout << "\t\t\t Name: " << name << endl;
        cout << "\t\t\t Phone: " << phone << endl;
        cout << "\t\t\t Email: " << email << endl;
        cout << endl;
    }
    file.close();
}

//view attendance of all students
void Admin::view_student_attendance()
{
   //viewing attendance of all students
    ifstream file(databases::student_attendance_db);
    string line;
    getline(file, line);//skip the header line
    while (getline(file, line))
    {
        stringstream ss(line);
        string n, maths, science, english, social_studies, computer_science;
        getline(ss, n, ',');
        getline(ss, maths, ',');
        getline(ss, science, ',');
        getline(ss, english, ',');
        getline(ss, social_studies, ',');
        getline(ss, computer_science, ',');
        cout << "\t\t\t Name: " << n << endl;
        cout << "\t\t\t Maths: " << maths << endl;
        cout << "\t\t\t Science: " << science << endl;
        cout << "\t\t\t English: " << english << endl;
        cout << "\t\t\t Social Studies: " << social_studies << endl;
        cout << "\t\t\t Computer Science: " << computer_science << endl;
        cout << endl;
    }
    file.close();
}


//student_grades_db contains student name and corresponding grades in subjects stored in order maths, science, english, social studies, computer science
void Admin::view_student_grades()
{
    cout << "\t\t\t Enter Student SRN: ";
    string name;
    global_funcs::input_flush();
    getline(cin, name);
    if (!search_student(name))
    {
        cout << "\t\t\t Student does not exist!" << endl;
        return;
    }
    ifstream file(databases::student_grades_db);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string n, maths, science, english, social_studies, computer_science;
        getline(ss, n, ',');
        getline(ss, maths, ',');
        getline(ss, science, ',');
        getline(ss, english, ',');
        getline(ss, social_studies, ',');
        getline(ss, computer_science, ',');
        if (n == name)
        {
            cout << "\t\t\t Maths: " << maths << endl;
            cout << "\t\t\t Science: " << science << endl;
            cout << "\t\t\t English: " << english << endl;
            cout << "\t\t\t Social Studies: " << social_studies << endl;
            cout << "\t\t\t Computer Science: " << computer_science << endl;
            return;
        }
    }
    file.close();
}


void Admin::view_timetable()
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


void Admin::view_all_teachers()
{
    ifstream file(databases::teacher_db);
    string line;
    getline(file, line);//skip the header line
    while (getline(file, line))
    {
        stringstream ss(line);
        string n, address, phone, email;
        getline(ss, n, ',');
        getline(ss, address, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        cout << "\t\t\t Name: " << n << endl;
        cout << "\t\t\t Address: " << address << endl;
        cout << "\t\t\t Phone: " << phone << endl;
        cout << "\t\t\t Email: " << email << endl;
        cout << endl;
    }
    file.close();
}


void Admin::edit_timetable()
{
    global_funcs::input_flush();
    cout << "\t\t\t Enter Day: ";
    string day;
    getline(cin, day);

    cout << "\t\t\t Enter Period 1: ";
    string period1;
    getline(cin, period1);

    cout << "\t\t\t Enter Period 2: ";
    string period2;
    getline(cin, period2);

    cout << "\t\t\t Enter Period 3: ";
    string period3;
    getline(cin, period3);

    cout << "\t\t\t Enter Period 4: ";
    string period4;
    getline(cin, period4);

    cout << "\t\t\t Enter Period 5: ";
    string period5;
    getline(cin, period5);

    cout << "\t\t\t Enter Period 6: ";
    string period6;
    getline(cin, period6);

    ifstream file(databases::timetable_db);
    ofstream temp("temp.csv");
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string d, p1, p2, p3, p4, p5, p6;
        getline(ss, d, ',');
        getline(ss, p1, ',');
        getline(ss, p2, ',');
        getline(ss, p3, ',');
        getline(ss, p4, ',');
        getline(ss, p5, ',');
        getline(ss, p6, ',');
        if (d != day)
        {
            temp << line << endl;
        }
        else
        {
            temp << day << "," << period1 << "," << period2 << "," << period3 << "," << period4 << "," << period5 << "," << period6 << endl;
        }
    }
    file.close();
    temp.close();
    remove(databases::timetable_db.c_str());
    rename("temp.csv", databases::timetable_db.c_str());
    cout << "\t\t\t Timetable edited successfully!" << endl;
}

void Admin::add_student()
{
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

    cout << "\t\t\t Student added successfully!" << endl;
}


void Admin::remove_teacher()
{
    cout << "\t\t\t Enter Teacher Name: ";
    string name;
    global_funcs::input_flush();
    getline(cin, name);
    if (!search_teacher(name))
    {
        cout << "\t\t\t Teacher does not exist!" << endl;
        return;
    }
    ifstream file(databases::teacher_db);
    ofstream temp("temp.csv");
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string n, address, phone, email;
        getline(ss, n, ',');
        getline(ss, address, ',');
        getline(ss, phone, ',');
        getline(ss, email, ',');
        if (n != name)
        {
            temp << line << endl;
        }
    }
    file.close();
    temp.close();
    remove(databases::teacher_db.c_str());
    rename("temp.csv", databases::teacher_db.c_str());
    cout << "\t\t\t Teacher removed successfully!" << endl;
}
