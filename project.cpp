#include "crud.h"
int main() {
    List *employeeList = createEmptyEmployee();
    Employee e1;
    int choice,subChoice,n;
    do {
        cout << "==================> Menu <==================" << endl;
        cout << "|1. Insert employee at the beginning     |" << endl;
        cout << "|2. Delete employee at the end           |" << endl;
        cout << "|3. Delete employee by ID                |" << endl;
        cout << "|4. Update employee by ID                |" << endl;
        cout << "|5. Display all employees                |" << endl;
        cout << "|6. Display all female employees         |" << endl;
        cout << "|7. Display all male employees           |" << endl;
        cout << "|8. Search employee by ID                |" << endl;
        cout << "|9. Search employee by name              |" << endl;
        cout << "|10. Sort employee by ID                 |" << endl;
        cout << "|11. Sort employee by name               |" << endl;
        cout << "|12. Sort employee by salary             |" << endl;
        cout << "|0. Exit                                 |" << endl;
        cout << "============================================" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:{
                cout << "How many employees do you want to add? ";
                cin >> n;
                for(int i= 0 ; i< n ; i++){
                    cout << "======> Enter employee details <======" << endl;
                    cout << "Please enter ID(integer) : ";
                    cin >> e1.id;
                    cin.ignore(); 
                    cout << "Please enter name : ";
                    getline(cin, e1.name); 
                    cout << "Please enter age(integer) : ";
                    cin >> e1.age;
                    cin.ignore();
                    cout << "Please enter gender(F\\M) : ";
                    cin >> e1.gender;
                    cin.ignore();
                    e1.gender = toupper(e1.gender);
                    cout << "Please enter role : ";
                    getline(cin, e1.role);
                    cout << "Please enter salary : ";
                    cin >> e1.salary;
                    cout << "Please enter start year(integer) : ";
                    cin >> e1.startYear;
                    cin.ignore(); 
                    cout << "Please enter date of birth(DD/MM/YYYY) : ";
                    getline(cin, e1.dateOfBirth);
                    insertEmployeeBeginning(employeeList, &e1);
                }
                break;
            }
            case 2:{
                deleteEmployeeEnd(employeeList);
                break;
            }
            case 3:{
                int searchId;
                cout << "Enter employee ID to delete: ";
                cin >> searchId;
                deleteEmployeeById(employeeList, searchId);
                break;
            }
            case 4:{
                int updateChoice;
                do{
                    cout << "========> Update Employee by ID <=========" << endl;
                    cout << "=====================Menu====================" << endl;
                    cout << "|1. Update all information of employee      |" << endl;
                    cout << "|2. Update only name                        |" << endl;
                    cout << "|3. Update only age                         |" << endl;
                    cout << "|4. Update only start year                  |" << endl;
                    cout << "|5. Update only duration                    |" << endl;
                    cout << "|6. Update only gender                      |" << endl;
                    cout << "|7. Update only role                        |" << endl;
                    cout << "|8. Update only salary                      |" << endl;
                    cout << "|9. Update only date of birth               |" << endl;
                    cout << "|0. Back to main menu                       |" << endl;
                    cout << "==============================================" << endl;
                    cout << "Enter your choice: ";
                    cin >> updateChoice;
                    int searchId;
                    Employee updatedEmployee;

                    switch (updateChoice) {
                        case 1:{
                            cout << "Enter employee ID to update all information: ";
                            cin >> searchId;
                            cin.ignore();
                            readFromFileCSV(employeeList, "EmployeeInformation.csv");
                            UpdateAllInfoEmployeeById(employeeList, searchId, &updatedEmployee);
                            break;
                        }
                        case 2:{
                            string newName;
                            cout << "Enter employee ID to update name: ";
                            cin >> searchId;
                            cin.ignore();
                            cout << "Enter new name: ";
                            getline(cin, newName);
    
                            readFromFileCSV(employeeList, "EmployeeInformation.csv");
                            updateNamebyId(employeeList, searchId, newName);
                            break;
                        }
                        case 3:{
                            int newAge;
                            cout << "Enter employee ID to update age: ";
                            cin >> searchId;
                            cin.ignore();
                            cout << "Enter new age: ";
                            cin >> newAge;
    
                            readFromFileCSV(employeeList, "EmployeeInformation.csv");
                            updateAgebyId(employeeList, searchId, newAge);
                            break;
                        }
                        case 4:{
                            int newStartYear;
                            cout << "Enter employee ID to update start year: ";
                            cin >> searchId;
                            cin.ignore();
                            cout << "Enter new start year: ";
                            cin >> newStartYear;
    
                            readFromFileCSV(employeeList, "EmployeeInformation.csv");
                            updateStartYearbyId(employeeList, searchId, newStartYear);
                            break;
                        }
                        case 5:{
                            int newDuration;
                            cout << "Enter employee ID to update duration: ";
                            cin >> searchId;
                            cin.ignore();
                            cout << "Enter new duration: ";
                            cin >> newDuration;
    
                            readFromFileCSV(employeeList, "EmployeeInformation.csv");
                            updateDurationbyId(employeeList, searchId, newDuration);
                            break;
                        }
                        case 6:{
                            char newGender;
                            cout << "Enter employee ID to update gender: ";
                            cin >> searchId;
                            cin.ignore();
                            cout << "Enter new gender (M/F): ";
                            cin >> newGender;
    
                            readFromFileCSV(employeeList, "EmployeeInformation.csv");
                            updateGenderbyId(employeeList, searchId, newGender);
                            break;
                        }
                        case 7:{
                            string newRole;
                            cout << "Enter employee ID to update role: ";
                            cin >> searchId;
                            cin.ignore();
                            cout << "Enter new role: ";
                            getline(cin, newRole);
    
                            readFromFileCSV(employeeList, "EmployeeInformation.csv");
                            updateRolebyId(employeeList, searchId, newRole);
                            break;
                        }
                        case 8:{
                            float newSalary;
                            cout << "Enter employee ID to update salary: ";
                            cin >> searchId;
                            cin.ignore();
                            cout << "Enter new salary: ";
                            cin >> newSalary;
    
                            readFromFileCSV(employeeList, "EmployeeInformation.csv");
                            updateSalarybyId(employeeList, searchId, newSalary);
                            break;
                        }
                        case 9:{
                            string newDateOfBirth;
                            cout << "Enter employee ID to update date of birth: ";
                            cin >> searchId;
                            cin.ignore();
                            cout << "Enter new date of birth (DD/MM/YYYY): ";
                            getline(cin, newDateOfBirth);
    
                            readFromFileCSV(employeeList, "EmployeeInformation.csv");
                            updateDateOfBirthbyId(employeeList, searchId, newDateOfBirth);
                            break;
                        }
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                }while (updateChoice !=0);
                break;
            }
            case 5:
                readFromFileCSV(employeeList, "EmployeeInformation.csv");
                displayAllEmployees(employeeList);
                break;
            
            case 6:
                readFromFileCSV(employeeList, "EmployeeInformation.csv");
                displayAllFemaleEmployees(employeeList);
                break;
            case 7:
            readFromFileCSV(employeeList, "EmployeeInformation.csv");
                displayAllMaleEmployees(employeeList);
                break;
            case 8: {
                int searchId;
                cout << "Enter employee ID to search: ";
                cin >> searchId;
                searchEmployeeById(employeeList, searchId);
                break;
            }
            case 9: {
                string searchName;
                cout << "Enter employee name to search: ";
                cin >> searchName;
                searchEmployeeByName(employeeList, searchName);
                break;
            }
            case 10:
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
            case 11:
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
            case 12:
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