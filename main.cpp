#include <iostream>
#include "ApplicationManager.h"

using namespace std;

int main()
{
    ApplicationManager manager;

    manager.loadFromFile();

    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "   JOB APPLICATION MANAGEMENT SYSTEM\n";
        cout << "========================================\n";

        cout << "1. Add Application\n";
        cout << "2. View All Applications\n";
        cout << "3. Search Application\n";
        cout << "4. Update Status\n";
        cout << "5. Delete Application\n";
        cout << "6. Sort Applications\n";
        cout << "7. Filter Applications\n";
        cout << "8. Show Statistics\n";
        cout << "9. Save Applications\n";
        cout << "10. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
            {
                int id;
                string company;
                string role;
                string status;
                string applicationDate;
                string priority;

                cout << "\nEnter Application ID: ";
                cin >> id;

                cin.ignore();

                cout << "Enter Company: ";
                getline(cin, company);

                cout << "Enter Role: ";
                getline(cin, role);

                cout << "Enter Status: ";
                getline(cin, status);

                cout << "Enter Application Date: ";
                getline(cin, applicationDate);

                cout << "Enter Priority: ";
                getline(cin, priority);

                JobApplication app(
                    id,
                    company,
                    role,
                    status,
                    applicationDate,
                    priority
                );

                manager.addApplication(app);

                cout << "Application added successfully." << endl;

                break;
            }

            case 2:
                manager.displayApplications();
                break;

            case 3:
            {
                int id;

                cout << "\nEnter Application ID to search: ";
                cin >> id;

                manager.searchApplicationById(id);

                break;
            }

            case 4:
            {
                int id;

                cout << "\nEnter Application ID: ";
                cin >> id;

                if(!manager.applicationExists(id))
                {
                    cout << "Application with ID " << id << " not found." << endl;
                    break;
                }

                cin.ignore();

                string newStatus;

                cout << "Enter new status: ";
                getline(cin, newStatus);

                manager.updateStatus(id, newStatus);

                break;
            }

            case 5:
            {
                int id;

                cout << "\nEnter Application ID to delete: ";
                cin >> id;

                manager.deleteApplication(id);

                break;
            }

            case 6:
            {
                int sortChoice;

                cout << "\n========== SORT APPLICATIONS ==========\n";
                cout << "1. Sort by Company\n";
                cout << "2. Sort by Priority\n";
                cout << "3. Back\n";

                cout << "\nEnter your choice: ";
                cin >> sortChoice;

                switch(sortChoice)
                {
                    case 1:
                        manager.sortByCompany();
                        break;

                    case 2:
                        manager.sortByPriority();
                        break;

                    case 3:
                        break;

                    default:
                        cout << "Invalid choice." << endl;
                }

                break;
            }

            case 7:
            {
                int filterChoice;

                cout << "\n========== FILTER APPLICATIONS ==========\n";
                cout << "1. Applied\n";
                cout << "2. OA\n";
                cout << "3. Interview\n";
                cout << "4. Rejected\n";
                cout << "5. Selected\n";
                cout << "6. Back\n";

                cout << "\nEnter your choice: ";
                cin >> filterChoice;

                switch(filterChoice)
                {
                    case 1:
                        manager.filterByStatus("Applied");
                        break;

                    case 2:
                        manager.filterByStatus("OA");
                        break;

                    case 3:
                        manager.filterByStatus("Interview");
                        break;

                    case 4:
                        manager.filterByStatus("Rejected");
                        break;

                    case 5:
                        manager.filterByStatus("Selected");
                        break;

                    case 6:
                        break;

                    default:
                        cout << "Invalid choice." << endl;
                }

                break;
            }

            case 8:
                manager.showStatistics();
                break;

            case 9:
                manager.saveToFile();
                break;

            case 10:
            {
                manager.saveToFile();
                cout << "Exiting program..." << endl;
                break;
            }

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while(choice != 10);

    return 0;
}