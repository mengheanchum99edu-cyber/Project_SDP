// employee information management system
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Employee {
    int id, age, startYear, duration;
    string name, role, dateOfBirth;
    float salary;
    char gender;
    Employee *next;
    Employee *previous;
};

struct List {
    int size;
    Employee *head;
    Employee *tail;
};


int duarationOfWork(Employee *e);

List *createEmptyEmployee() {
    List *list = new List;
    list->size = 0;
    list->head = nullptr;
    list->tail = nullptr;
    return list;
}

void createFileCSV(List *list, string filename) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }

    ofstream writeToFile(filename);

    if (!writeToFile.is_open()) {
        cout << "Error: Could not create file " << filename << endl;
        return;
    }

    writeToFile << "ID,Name,Age,StartYear,Duration,Gender,Role,Salary,DateOfBirth" << endl;

    Employee *tmp = list->head;
    while (tmp != nullptr) {
        int duration = duarationOfWork(tmp); 
        writeToFile << tmp->id          << ","
                    << tmp->name        << ","
                    << tmp->age         << ","
                    << tmp->startYear   << ","
                    << duration         << ","
                    << tmp->gender      << ","
                    << tmp->role        << ","
                    << tmp->salary      << ","
                    << tmp->dateOfBirth << endl;
        tmp = tmp->next;
    }

    writeToFile.close();
}

void insertEmployeeBeginning(List *&list, Employee *newEmployee) {
    Employee *e = new Employee;
    e->id = newEmployee->id;
    e->name = newEmployee->name;
    e->age = newEmployee->age;
    e->startYear = newEmployee->startYear;
    e->duration = newEmployee->duration; 
    e->gender = toupper(newEmployee->gender);
    e->role = newEmployee->role;
    e->salary = newEmployee->salary;
    e->dateOfBirth = newEmployee->dateOfBirth;
    e->previous = nullptr;

    if (list->size == 0) {
        e->next = nullptr;
        list->head = e;
        list->tail = e;
    } else {
        e->next = list->head;
        list->head->previous = e;
        list->head = e;   
    }
    list->size++;
    createFileCSV(list, "EmployeeInformation.csv");
}

void clearList(List *list) {
    Employee *tmp = list->head;
    while (tmp != nullptr) {
        Employee *next = tmp->next;
        delete tmp;
        tmp = next;
    }
    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;
}

void readFromFileCSV(List *list, string filename) {
    ifstream readFromFile(filename);
    if (!readFromFile.is_open()) {
        cout << "Error: Could not open file " << filename << endl;
        return;
    }

    clearList(list);

    string line;
    getline(readFromFile, line);
    while (getline(readFromFile, line)) {
        Employee e;
        size_t pos = 0;
        //string token;
        
        pos = line.find(",");
        e.id = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Name
        pos = line.find(",");
        e.name = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Age
        pos = line.find(",");
        e.age = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Start Year
        pos = line.find(",");
        e.startYear = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Duration
        pos = line.find(",");
        e.duration = stoi(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Gender
        pos = line.find(",");
        e.gender = line.substr(0, pos)[0];
        line.erase(0, pos + 1);

        // Role
        pos = line.find(",");
        e.role = line.substr(0, pos);
        line.erase(0, pos + 1);

        // Salary
        pos = line.find(",");
        e.salary = stof(line.substr(0, pos));
        line.erase(0, pos + 1);

        // Date of Birth
        e.dateOfBirth = line;

        insertEmployeeBeginning(list, &e);
    }
    readFromFile.close();
}



void deleteEmployeeEnd(List *&list) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *temp = list->tail;
    if (list->size == 1) {
        list->head = nullptr;
        list->tail = nullptr;
    } else {
        list->tail = temp->previous;
        list->tail->next = nullptr;
    }
    delete temp;
    list->size--;
    createFileCSV(list, "EmployeeInformation.csv");
}

void headerOfDisplay(){
    string divider = "=======================================================================";

    cout << divider << endl;
    cout << "| "<<left
         << setw(6)  << "ID"     << " | "
         << setw(20) << "Name"   << " | "
         << setw(5)  << "Age"    << " | "
         << setw(10)  << "Start Year" << " | "
         << setw(8)  << "Duration" << " | "
         << setw(8)  << "Gender" << " | "
         << setw(15) << "Role"   << " | "
         << setw(10) << "Salary" << " | "
         << setw(11)  << "Year"   << " |"
         << endl;
    cout << divider << endl;    
}

void displayOneEmployee(Employee *tmp) {
    cout << "| "<<left
         << setw(6)  << tmp->id          << " | "
         << setw(20) << tmp->name        << " | "
         << setw(5)  << tmp->age         << " | "
         << setw(10)  << tmp->startYear   << " | "
         << setw(8)  << tmp->duration    << " | "
         << setw(8)  << tmp->gender      << " | "
         << setw(15) << tmp->role        << " | "
         << setw(10) << tmp->salary      << " | "
         << setw(10)  << tmp->dateOfBirth << " |"
         << endl<<endl;
}

void deleteEmployeeById(List *&list, int searchId) {
    bool searchIdFound = false;
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *temp = list->head;
    while (temp != nullptr) {
        if (temp->id == searchId) {
            if (temp->previous != nullptr){
                temp->previous->next = temp->next;
            }else{
                list->head = temp->next;
            }
            if (temp->next != nullptr)
                temp->next->previous = temp->previous;
            else
                list->tail = temp->previous;
            delete temp;
            list->size--;
            searchIdFound = true;
            cout << "Employee with ID " << searchId << " deleted successfully." << endl;
            createFileCSV(list, "EmployeeInformation.csv");
            cout << "All employee after the deletion:" << endl;
            headerOfDisplay();
            Employee *t = list->head;
            while (t != nullptr) {
                displayOneEmployee(t);
                t = t->next;
            }
            return;
        }
        temp = temp->next;
    }
    if (!searchIdFound) {
        cout << "Employee with ID " << searchId << " not found." << endl;
    }
}

void displayAllEmployees(List *list) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    headerOfDisplay();
    while (tmp != nullptr) {
        displayOneEmployee(tmp);
        tmp = tmp->next;
    }
}


void displayAllFemaleEmployees(List *list) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    headerOfDisplay();
    while (tmp != nullptr) {
        if (tmp->gender == 'F') {
            displayOneEmployee(tmp);
        }
        tmp = tmp->next;
    }
}

void displayAllMaleEmployees(List *list) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    headerOfDisplay();
    while (tmp != nullptr) {
        if (tmp->gender == 'M') {
            displayOneEmployee(tmp);
        }
        tmp = tmp->next;
    }
}

void searchEmployeeById(List *list, int searchId) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    headerOfDisplay();
    while (tmp != nullptr) {
        if (tmp->id == searchId) {
            displayOneEmployee(tmp);   
            return;
        }
        tmp = tmp->next;
    }
    cout << "Employee with ID " << searchId << " not found." << endl;
}


void searchEmployeeByName(List *list, string searchName) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    headerOfDisplay();
    bool found = false;
    while (tmp != nullptr) {
        if (tmp->name == searchName) {
            displayOneEmployee(tmp);
            found = true;
        }
        tmp = tmp->next;
    }
    if (!found)
        cout << "Employee with name " << searchName << " not found." << endl;
}



void UpdateAllInfoEmployeeById(List *list, int searchId, Employee *updatedEmployee) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }

    Employee *tmp = list->head;

    while (tmp != nullptr) {
        if (tmp->id == searchId) {
            cout << "Enter new name: ";
            getline(cin, updatedEmployee->name);
            cout << "Enter new start year: ";
            cin >> updatedEmployee->startYear;
            cout << "Enter new age: ";
            cin >> updatedEmployee->age;
            cout << "Enter new gender (F/M): ";
            cin >> updatedEmployee->gender;
            updatedEmployee->gender = toupper(updatedEmployee->gender);
            cout << "Enter new role: ";
            cin >> updatedEmployee->role;
            cout << "Enter new salary: ";
            cin >> updatedEmployee->salary;
            cin.ignore();
            cout << "Enter new date of birth (DD/MM/YYYY): ";
            getline(cin, updatedEmployee->dateOfBirth);


            // Update the existing employee node
            tmp->name        = updatedEmployee->name;
            tmp->age         = updatedEmployee->age;
            tmp->startYear   = updatedEmployee->startYear;
            tmp->gender      = updatedEmployee->gender;
            tmp->role        = updatedEmployee->role;
            tmp->salary      = updatedEmployee->salary;
            tmp->dateOfBirth = updatedEmployee->dateOfBirth;

            cout << "Employee with ID " << searchId 
                 << " updated successfully." << endl;

            createFileCSV(list, "EmployeeInformation.csv");
            return;
        }

        tmp = tmp->next;
    }

    cout << "Employee with ID " << searchId << " not found." << endl;
}
void updateNamebyId(List *list, int searchId, string newName) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    while (tmp != nullptr) {
        if (tmp->id == searchId) {
            tmp->name = newName;
            cout << "Employee with ID " << searchId 
                 << " updated successfully." << endl;
            createFileCSV(list, "EmployeeInformation.csv");
            return;
        }
        tmp = tmp->next;
    }
    cout << "Employee with ID " << searchId << " not found." << endl;
}
void updateAgebyId(List *list, int searchId, int newAge) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    while (tmp != nullptr) {
        if (tmp->id == searchId) {
            tmp->age = newAge;
            cout << "Employee with ID " << searchId 
                 << " updated successfully." << endl;
            createFileCSV(list, "EmployeeInformation.csv");
            return;
        }
        tmp = tmp->next;
    }
    cout << "Employee with ID " << searchId << " not found." << endl;
}
void updateStartYearbyId(List *list, int searchId, int newStartYear) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    while (tmp != nullptr) {
        if (tmp->id == searchId) {
            tmp->startYear = newStartYear;
            cout << "Employee with ID " << searchId 
                 << " updated successfully." << endl;
            createFileCSV(list, "EmployeeInformation.csv");
            return;
        }
        tmp = tmp->next;
    }
    cout << "Employee with ID " << searchId << " not found." << endl;
}
void updateDurationbyId(List *list, int searchId, int newDuration) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    while (tmp != nullptr) {
        if (tmp->id == searchId) {
            tmp->duration = newDuration;
            cout << "Employee with ID " << searchId 
                 << " updated successfully." << endl;
            createFileCSV(list, "EmployeeInformation.csv");
            return;
        }
        tmp = tmp->next;
    }
    cout << "Employee with ID " << searchId << " not found." << endl;
}
void updateGenderbyId(List *list, int searchId, char newGender) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    while (tmp != nullptr) {
        if (tmp->id == searchId) {
            tmp->gender = newGender;
            cout << "Employee with ID " << searchId 
                 << " updated successfully." << endl;
            createFileCSV(list, "EmployeeInformation.csv");
            return;
        }
        tmp = tmp->next;
    }
    cout << "Employee with ID " << searchId << " not found." << endl;
}
void updateRolebyId(List *list, int searchId, string newRole) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    while (tmp != nullptr) {
        if (tmp->id == searchId) {
            tmp->role = newRole;
            cout << "Employee with ID " << searchId 
                 << " updated successfully." << endl;
            createFileCSV(list, "EmployeeInformation.csv");
            return;
        }
        tmp = tmp->next;
    }
    cout << "Employee with ID " << searchId << " not found." << endl;
}
void updateSalarybyId(List *list, int searchId, float newSalary) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    while (tmp != nullptr) {
        if (tmp->id == searchId) {
            tmp->salary = newSalary;
            cout << "Employee with ID " << searchId 
                 << " updated successfully." << endl;
            createFileCSV(list, "EmployeeInformation.csv");
            return;
        }
        tmp = tmp->next;
    }
    cout << "Employee with ID " << searchId << " not found." << endl;
}
void updateDateOfBirthbyId(List *list, int searchId, string newDateOfBirth){
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    while (tmp != nullptr) {
        if (tmp->id == searchId) {
            tmp->dateOfBirth = newDateOfBirth;
            cout << "Employee with ID " << searchId 
                 << " updated successfully." << endl;
            createFileCSV(list, "EmployeeInformation.csv");
            return;
        }
        tmp = tmp->next;
    }
    cout << "Employee with ID " << searchId << " not found." << endl;
}

void exchange(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void exchange(float *a, float *b) {
    float tmp = *a;
    *a = *b;
    *b = tmp;
}

void exchange(char *a, char *b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void exchange(string *a, string *b) {
    string tmp = *a;
    *a = *b;
    *b = tmp;
}

void switchAllFields(Employee *a, Employee *b) {
    exchange(&a->id,          &b->id);
    exchange(&a->name,        &b->name);
    exchange(&a->age,         &b->age);
    exchange(&a->startYear,   &b->startYear);
    exchange(&a->duration,    &b->duration); 
    exchange(&a->gender,      &b->gender);
    exchange(&a->role,        &b->role);
    exchange(&a->salary,      &b->salary);
    exchange(&a->dateOfBirth, &b->dateOfBirth);
}

void switchAllInformation(List *list, bool &swapped) {
    Employee *tmp = list->head;
    while (tmp->next != nullptr) {
        if (tmp->id > tmp->next->id) {
            switchAllFields(tmp, tmp->next);
            swapped = true;
        }
        tmp = tmp->next;
    }
}

void sortEmployeeByIdAsc(List *list) {
    if (list->size <= 1) return;

    bool swapped;
    do {
        swapped = false;                    
        switchAllInformation(list, swapped);  
    } while (swapped);                        

    cout << "Employees sorted by ID in ascending order." << endl;
    Employee *tmp = list->head;             
    headerOfDisplay();
    while (tmp != nullptr) {
        displayOneEmployee(tmp);
        tmp = tmp->next;
    }
}

void sortEmployeeByIdDesc(List *list) {
    if (list->size < 1) return;

    bool swapped;
    do {
        swapped = false;
        Employee *tmp = list->head;
        while (tmp->next != nullptr) {
            if (tmp->id < tmp->next->id) {
                switchAllFields(tmp, tmp->next);
                swapped = true;
            }
            tmp = tmp->next;
        }
    } while (swapped);
    cout << "Employees sorted by ID in descending order." << endl;
    Employee *tmp = list->head;
    headerOfDisplay();
    while (tmp != nullptr) {
        displayOneEmployee(tmp);
        tmp = tmp->next;
    }
}

void sortEmployeeBySalaryAsc(List *list) {
    if (list->size < 1) return;

    bool swapped;
    do {
        swapped = false;
        Employee *tmp = list->head;
        while (tmp->next != nullptr) {
            if (tmp->salary > tmp->next->salary) {
                switchAllFields(tmp, tmp->next);
                swapped = true;
            }
            tmp = tmp->next;
        }
    } while (swapped);
    cout << "Employees sorted by salary in ascending order." << endl;
    Employee *tmp = list->head;
    headerOfDisplay();
    while (tmp != nullptr) {
        displayOneEmployee(tmp);
        tmp = tmp->next;
    }
}

void sortEmployeeBySalaryDesc(List *list) {
    if (list->size < 1) return;

    bool swapped;
    do {
        swapped = false;
        Employee *tmp = list->head;
        while (tmp->next != nullptr) {
            if (tmp->salary < tmp->next->salary) {
                switchAllFields(tmp, tmp->next);
                swapped = true;
            }
            tmp = tmp->next;
        }
    } while (swapped);
    cout << "Employees sorted by salary in descending order." << endl;
    Employee *tmp = list->head;
    headerOfDisplay();
    while (tmp != nullptr) {
        displayOneEmployee(tmp);
        tmp = tmp->next;
    }
}

void sortEmployeeByNameAsc(List *list) {
    if (list->size < 1) return;

    bool swapped;
    do {
        swapped = false;
        Employee *tmp = list->head;
        while (tmp->next != nullptr) {
            if (tmp->name > tmp->next->name) {
                switchAllFields(tmp, tmp->next);
                swapped = true;
            }
            tmp = tmp->next;
        }
    } while (swapped);
    cout << "Employees sorted by name in ascending order." << endl;
    Employee *tmp = list->head;
    headerOfDisplay();
    while (tmp != nullptr) {
        displayOneEmployee(tmp);
        tmp = tmp->next;
    }
}

void sortEmployeeByNameDesc(List *list) {
    if (list->size < 1) return;

    bool swapped;
    do {
        swapped = false;
        Employee *tmp = list->head;
        while (tmp->next != nullptr) {
            if (tmp->name < tmp->next->name) {
                switchAllFields(tmp, tmp->next);
                swapped = true;
            }
            tmp = tmp->next;
        }
    } while (swapped);
    cout << "Employees sorted by name in descending order." << endl;
    Employee *tmp = list->head;
    headerOfDisplay();
    while (tmp != nullptr) {
        displayOneEmployee(tmp);
        tmp = tmp->next;
    }
}
int duarationOfWork(Employee *e) {
    e->duration = 2026 - e->startYear;
    return e->duration;
}