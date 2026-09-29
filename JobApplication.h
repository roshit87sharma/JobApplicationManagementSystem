#ifndef JOBAPPLICATION_H
#define JOBAPPLICATION_H

#include <string>
using namespace std;

class JobApplication
{
private:
    int id;
    string company;
    string role;
    string status;
    string applicationDate;
    string priority;

public:
    JobApplication();

    JobApplication(int id,
                   string company,
                   string role,
                   string status,
                   string applicationDate,
                   string priority);

    int getId() const;
    string getCompany() const;
    string getRole() const;
    string getStatus() const;
    string getApplicationDate() const;
    string getPriority() const;

    void setStatus(string status);
    void setPriority(string priority);

    void display() const;
};

#endif