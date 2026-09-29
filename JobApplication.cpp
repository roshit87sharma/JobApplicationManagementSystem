#include "JobApplication.h"
#include <iostream>

using namespace std;

// Default constructor
JobApplication::JobApplication()
{
    id = 0;
    company = "";
    role = "";
    status = "Applied";
    applicationDate = "";
    priority = "Medium";
}

// Parameterized constructor
JobApplication::JobApplication(int id,
                               string company,
                               string role,
                               string status,
                               string applicationDate,
                               string priority)
{
    this->id = id;
    this->company = company;
    this->role = role;
    this->status = status;
    this->applicationDate = applicationDate;
    this->priority = priority;
}

// Getters
int JobApplication::getId() const
{
    return id;
}

string JobApplication::getCompany() const
{
    return company;
}

string JobApplication::getRole() const
{
    return role;
}

string JobApplication::getStatus() const
{
    return status;
}

string JobApplication::getApplicationDate() const
{
    return applicationDate;
}

string JobApplication::getPriority() const
{
    return priority;
}

// Setters
void JobApplication::setStatus(string status)
{
    this->status = status;
}

void JobApplication::setPriority(string priority)
{
    this->priority = priority;
}

// Display function
void JobApplication::display() const
{
    cout << "ID: " << id << endl;
    cout << "Company: " << company << endl;
    cout << "Role: " << role << endl;
    cout << "Status: " << status << endl;
    cout << "Application Date: " << applicationDate << endl;
    cout << "Priority: " << priority << endl;
    cout << "-----------------------------" << endl;
}