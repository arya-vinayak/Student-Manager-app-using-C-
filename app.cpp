#include<iostream>
#include "Admin.h"
#include "Student.h"

using namespace std;

void displayMainMenu()
{
    cout << "\t\t\t Welcome to School Management System" << endl;
    cout << "\t\t\t 1. Admin" << endl;
    cout << "\t\t\t 2. User" << endl;
    cout << "\t\t\t 3. Exit" << endl;
}



namespace main_funcs
{
    // Function to execute option 1
    void Admin_func()
    {
        string name,name1;
        // cout << "Executing Option 1..." << endl;
        cout << "\t\t\t Welcome to Admin Login" << endl;
        cout << "\t\t\t Enter Username: ";
        string username;
        global_funcs::input_flush();
        cin >> username;
        cout << "\t\t\t Enter Password: ";
        string password;
        global_funcs::input_flush();
        cin >> password;

        if (admin_funcs::login(username, password))
        {
            cout << "\t\t\t Login Successful!" << endl;
            Admin admin(username, password, "dev");
            cout << "\t\t\t Welcome " << endl;
            cout << admin << endl;
            int choice = -1;
            do
            {
                cout << "\t\t\t 1.  Add Student" << endl;
                cout << "\t\t\t 2.  Remove Student" << endl;
                cout << "\t\t\t 3.  View all students" << endl;
                cout << "\t\t\t 4.  View Student attendance" << endl;
                cout << "\t\t\t 5.  View Student grades" << endl;
                cout << "\t\t\t 6.  View TimeTable" << endl;
                cout << "\t\t\t 7.  Edit TimeTable" << endl;
                cout << "\t\t\t 8.  Add Teacher" << endl;
                cout << "\t\t\t 9.  Remove Teacher" << endl;
                cout << "\t\t\t 10. View Teachers" << endl;
                cout << "\t\t\t 11. Search student" << endl;
                cout << "\t\t\t 12. Search teacher" << endl;
                cout << "\t\t\t 13. Exit" << endl;
                cout << "\t\t\t Enter your choice: ";
                // int choice;
                global_funcs::get_input(choice);
                switch (choice)
                {
                case 1:
                    cout << "Adding Student ..." << endl;
                    admin.add_student();
                    break;
                case 2:
                    cout << "Removing Student ..." << endl;
                    admin.remove_student();
                    break;
                case 3:
                    cout << "View All Students Functionality..." << endl;
                    admin.view_all_students();
                    break;
                case 4:
                    cout << "View Student Attendance Functionality..." << endl;
                    admin.view_student_attendance();
                    break;
                case 5:
                    cout << "View Student Grades Functionality..."  << endl;
                    admin.view_student_grades();
                    break;
                case 6:
                    cout << "View TimeTable Functionality..." << endl;
                    admin.view_timetable();
                    break;
                case 7:
                    cout << "Edit TimeTable Functionality..." << endl;
                    admin.edit_timetable();
                    break;
                case 8:
                    cout << "Add Teacher Functionality..."<< endl;
                    admin.add_teacher();
                    break;
                case 9:
                    cout << "Remove Teacher Functionality..." << endl;
                    admin.remove_teacher();
                    break;
                case 10:
                    cout << "View Teachers Functionality..." << endl;
                    admin.view_all_teachers();
                    break;
                case 11:
                    cout << "Search Student Functionality..." << endl;
                    cout << "Enter the SRN of the student: ";
                    //string name = "";
                    global_funcs::input_flush();
                    getline(cin, name);
                    if(admin.search_student(name))
                    {
                        cout<<"\t\t\t student is present "<<endl;

                    }
                    else
                    {
                        cout<<"\t\t\t student is not present"<<endl;
                    }
                    break;
                case 12:
                    cout << "Search Teacher Functionality..." << endl;
                    cout << "Enter the name of the teacher: ";
                    //string name1 = "";
                    global_funcs::input_flush();
                    getline(cin, name1);
                    if(admin.search_teacher(name1))
                    {
                        cout<<"\t\t\t teacher is present details are:"<<endl;

                    }
                    else
                    {
                        cout<<"\t\t\t teacher is not present"<<endl;
                    }
                    break;    
                case 13:
                    cout << "Exiting Admin Panel..." << endl;
                    return;
                    break;    
                default:
                    cout << "Invalid choice!" << endl;
                }
            } while (choice != 13);
        }
        else
        {
            cout << "\t\t\t Login Failed!" << endl;
        }
        // cout << "Option 1 executed!" << endl << endl;
    }

    void User()
    {
        cout << "\t\t\t Welcome to User Login" << endl;
        cout << "\t\t\t 1. Login" << endl;
        cout << "\t\t\t 2. Register" << endl;
        cout << "\t\t\t 3. Exit" << endl;
        cout << "\t\t\t Enter your choice: ";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            user_funcs::login();
            break;
        case 2:
            user_funcs::register_user();
            break;

        case 3:
            cout << "Exiting..." << endl;
            cout << "BYE"
                 << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl
                 << endl;
            break;
        }
    }
}





int main()
{

    int choice;
    bool exit = false;


    while (!exit)
    {
        displayMainMenu();

        global_funcs::get_input(choice, "Enter your choice: ");

        switch (choice)
        {
        case 1:
            main_funcs::Admin_func();
            break;
        case 2:
            main_funcs::User();
            break;
        case 3:
            exit = true;
            cout << "Exiting..." << endl;
            cout << "BYE"
                 << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl
                 << endl;
            break;
        }
    }

    return 0;
}
