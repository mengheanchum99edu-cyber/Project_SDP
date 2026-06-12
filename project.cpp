#include "crud.h"
int main() {
    List *employeeList = createEmptyEmployee();
    Employee e1;
    int choice,subChoice,n;
    do {
        cout << "==================> Menu <==================" << endl;
        cout << "|1. Insert employee at the beginning     |" << endl;
        cout << "|2. Delete employee at the end           |" << endl;
        cout << "|3. Display all employees                |" << endl;
        cout << "|4. Display all female employees         |" << endl;
        cout << "|5. Display all male employees           |" << endl;
        cout << "|6. Search employee by ID                |" << endl;
        cout << "|7. Search employee by name              |" << endl;
        cout << "|8. Sort employee by ID                  |" << endl;
        cout << "|9. Sort employee by name                |" << endl;
        cout << "|10. Sort employee by salary             |" << endl;
        cout << "|0. Exit                                 |" << endl;
        cout << "============================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
// 10/ June/2009
// duartion of work 
// year of starting work
// year add date and month
// page// source code// video
        switch (choice) {
            case 1:{
                cout << "How many employees do you want to add? ";
                cin >> n;
                for(int i= 0 ; i< n ; i++){
                    cout << "======> Enter employee details <======" << endl;
                    cout << "Please enter ID : ";
                    cin >> e1.id;
                    cin.ignore(); // Clear the newline character from the input buffer
                    cout << "Please enter name : ";
                    getline(cin, e1.name); 
                    cout << "Please enter age : ";
                    cin >> e1.age;
                    cout << "Please enter gender(F\\M) : ";
                    e1.gender = toupper(e1.gender);
                    cin >> e1.gender;
                    cout << "Please enter role : ";
                    cin >> e1.role;
                    cout << "Please enter salary : ";
                    cin >> e1.salary;
                    cout << "Please enter year of birth : ";
                    cin >> e1.yearOfBirth;
                    insertEmployeeBeginning(employeeList, &e1);
                }
                break;
            }
            case 2:{
                deleteEmployeeEnd(employeeList);
                break;
            }
            case 3:{
                displayEmployees(employeeList);
                break;
            }
            case 4:
                displayAllFemaleEmployees(employeeList);
                break;
            case 5:
                displayAllMaleEmployees(employeeList);
                break;
            case 6: {
                int searchId;
                cout << "Enter employee ID to search: ";
                cin >> searchId;
                searchEmployeeById(employeeList, searchId);
                break;
            }
            case 7: {
                string searchName;
                cout << "Enter employee name to search: ";
                cin >> searchName;
                searchEmployeeByName(employeeList, searchName);
                break;
            }
            case 8:
                cout << "========> Sort by ID <=========" << endl;
                cout << "1. Ascending" << endl;
                cout << "2. Descending" << endl;
                cout << "Enter your choice: ";
                cin >> subChoice;
                if (subChoice == 1) {
                    sortEmployeeByIdAsc(employeeList);
                    cout << "Employees sorted by ID in ascending order." << endl;
                } else if (subChoice == 2) {
                    sortEmployeeByIdDesc(employeeList);
                    cout << "Employees sorted by ID in descending order." << endl;
                } else {
                    cout << "Invalid choice." << endl;
                }
                break;
            case 9:
                cout << "========> Sort by Name <=========" << endl;
                cout << "1. Ascending" << endl;
                cout << "2. Descending" << endl;
                cout << "Enter your choice: ";
                cin >> subChoice;
                if (subChoice == 1) {
                    sortEmployeeByNameAsc(employeeList);
                    cout << "Employees sorted by name in ascending order." << endl;
                } else if (subChoice == 2) {
                    sortEmployeeByNameDesc(employeeList);
                    cout << "Employees sorted by name in descending order." << endl;
                } else {
                    cout << "Invalid choice." << endl;
                }
                break;
            case 10:
                cout << "========> Sort by Salary <=========" << endl;
                cout << "1. Ascending" << endl;
                cout << "2. Descending" << endl;
                cout << "Enter your choice: ";
                cin >> subChoice;
                if (subChoice == 1) {
                    sortEmployeeBySalaryAsc(employeeList);
                    cout << "Employees sorted by salary in ascending order." << endl;
                } else if (subChoice == 2) {
                    sortEmployeeBySalaryDesc(employeeList);
                    cout << "Employees sorted by salary in descending order." << endl;
                } else {
                    cout << "Invalid choice." << endl;
                }
                break;
            case 0:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);  
    return 0;  
}
