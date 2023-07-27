#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "Admin.h"

using namespace std;

#ifndef USER_H
#define USER_H

class User : public Admin
{
public:
    // Constructor to initialize the User object with provided username and password
    User(string username, string password)
        : Admin(username, password, "student") // Call the base class (Admin) constructor to set the username, password, and role ("user")
{}

};

#endif
