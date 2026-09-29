#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include "JobApplication.h"
#include <vector>
#include <algorithm>
#include <map>
#include <string>

using namespace std;

class ApplicationManager
{
private:
    vector<JobApplication> applications;

public:
    void addApplication(const JobApplication& app);
    void displayApplications() const;
    void searchApplicationById(int id) const;
    void updateStatus(int id, string newStatus);
    void deleteApplication(int id);
    void sortByCompany();
    void sortByPriority();
    void filterByStatus(string status) const;
    void showStatistics() const;
    void saveToFile() const;
    void loadFromFile();
    bool applicationExists(int id) const;
};

#endif