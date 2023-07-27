#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include<Admin.h>
using namespace std;


bool admin_funcs::login(string username, string password)
{
    ifstream file(databases::teacher_db);
    string line;
    while (getline(file, line))
    {
        stringstream ss(line);
        string user, pass;
        getline(ss, user, ',');
        getline(ss, pass, ',');
        if (user == username && pass == password)
        {
            return true;
        }
        cout << "\t\t\t Welcome " << username << "!" << endl;
    }
    return false;
}


bool Admin::search_teacher(string name) {
    // Open the hotel database file for reading
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
            return true;
        }
    }

    // If the loop finishes without finding a match, the teacher does not exist in the file
    return false;
}

bool search_student(string name)
{
    // Open the hotel database file for reading
    ifstream file(databases::student_db);

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
        getline(ss, n, ',');       // Extract the  students name
        getline(ss, address, ','); // Extract the students address
        getline(ss, phone, ',');   // Extract the students phone number
        getline(ss, email, ',');   // Extract the students email address

        // Clear the stringstream for the next line
        ss.clear();

        // Check if the extracted student name matches the name we are searching for
        if (n == name) {
            // If a match is found, return true to indicate that the hotel exists in the file
            return true;
        }
    }

    // If the loop finishes without finding a match, the student does not exist in the file
    return false;
}




