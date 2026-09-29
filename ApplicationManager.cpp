#include "ApplicationManager.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

void ApplicationManager::addApplication(const JobApplication& app)
{
    applications.push_back(app);
}

void ApplicationManager::displayApplications() const
{
    if(applications.empty())
    {
        cout << "No job applications found." << endl;
        return;
    }

    for(const JobApplication& app : applications)
    {
        app.display();
    }
}

void ApplicationManager::searchApplicationById(int id) const
{
    for(const JobApplication& app : applications)
    {
        if(app.getId() == id)
        {
            cout << "Application Found:" << endl;
            app.display();
            return;
        }
    }

    cout << "Application with ID " << id << " not found." << endl;
}

bool ApplicationManager::applicationExists(int id) const
{
    for(const JobApplication& app : applications)
    {
        if(app.getId() == id)
        {
            return true;
        }
    }

    return false;
}

void ApplicationManager::updateStatus(int id, string newStatus)
{
    for(JobApplication& app : applications)
    {
        if(app.getId() == id)
        {
            app.setStatus(newStatus);

            cout << "Status updated successfully." << endl;
            return;
        }
    }

    cout << "Application with ID " << id << " not found." << endl;
}

void ApplicationManager::deleteApplication(int id)
{
    for(auto it = applications.begin(); it != applications.end(); ++it)
    {
        if(it->getId() == id)
        {
            applications.erase(it);

            cout << "Application deleted successfully." << endl;
            return;
        }
    }

    cout << "Application with ID " << id << " not found." << endl;
}

void ApplicationManager::sortByCompany()
{
    sort(applications.begin(), applications.end(),
         [](const JobApplication& a, const JobApplication& b)
         {
             return a.getCompany() < b.getCompany();
         });

    cout << "Applications sorted by company name." << endl;
}

void ApplicationManager::sortByPriority()
{
    sort(applications.begin(), applications.end(),
         [](const JobApplication& a, const JobApplication& b)
         {
             int priorityA;
             int priorityB;

             if(a.getPriority() == "High")
                 priorityA = 3;
             else if(a.getPriority() == "Medium")
                 priorityA = 2;
             else
                 priorityA = 1;

             if(b.getPriority() == "High")
                 priorityB = 3;
             else if(b.getPriority() == "Medium")
                 priorityB = 2;
             else
                 priorityB = 1;

             return priorityA > priorityB;
         });

    cout << "Applications sorted by priority." << endl;
}

void ApplicationManager::filterByStatus(string status) const
{
    bool found = false;

    for(const JobApplication& app : applications)
    {
        if(app.getStatus() == status)
        {
            app.display();
            found = true;
        }
    }

    if(!found)
    {
        cout << "No applications found with status: "
             << status << endl;
    }
}

void ApplicationManager::showStatistics() const
{
    map<string, int> statusCount;

    for(const JobApplication& app : applications)
    {
        statusCount[app.getStatus()]++;
    }

    cout << "\n========== APPLICATION STATISTICS ==========\n";

    cout << "Total Applications : "
         << applications.size() << endl;

    cout << "\n";

    cout << "Applied   : " << statusCount["Applied"] << endl;
    cout << "OA        : " << statusCount["OA"] << endl;
    cout << "Interview : " << statusCount["Interview"] << endl;
    cout << "Rejected  : " << statusCount["Rejected"] << endl;
    cout << "Selected  : " << statusCount["Selected"] << endl;

    cout << "============================================\n";
}

void ApplicationManager::saveToFile() const
{
    ofstream file("applications.txt");

    if(!file)
    {
        cout << "Error opening file for saving." << endl;
        return;
    }

    for(const JobApplication& app : applications)
    {
        file << app.getId() << "|"
             << app.getCompany() << "|"
             << app.getRole() << "|"
             << app.getStatus() << "|"
             << app.getApplicationDate() << "|"
             << app.getPriority() << "\n";
    }

    file.close();

    cout << "Applications saved successfully." << endl;
}

void ApplicationManager::loadFromFile()
{
    ifstream file("applications.txt");

    if(!file)
    {
        cout << "No saved application data found." << endl;
        return;
    }

    applications.clear();

    string line;

    while(getline(file, line))
    {
        if(line.empty())
            continue;

        stringstream ss(line);

        string idStr;
        string company;
        string role;
        string status;
        string applicationDate;
        string priority;

        getline(ss, idStr, '|');
        getline(ss, company, '|');
        getline(ss, role, '|');
        getline(ss, status, '|');
        getline(ss, applicationDate, '|');
        getline(ss, priority, '|');

        int id = stoi(idStr);

        JobApplication app(
            id,
            company,
            role,
            status,
            applicationDate,
            priority
        );

        applications.push_back(app);
    }

    file.close();

    cout << "Applications loaded successfully." << endl;
}