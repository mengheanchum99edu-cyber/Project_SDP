// employee information management system
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Employee {
    int id, age, yearOfBirth;
    string name, role;
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

List *createEmptyEmployee() {
    List *list = new List;
    list->size = 0;
    list->head = nullptr;
    list->tail = nullptr;
    return list;
}

void insertEmployeeBeginning(List *&list, Employee *newEmployee) {
    Employee *e = new Employee;
    e->id = newEmployee->id;
    e->name = newEmployee->name;
    e->age = newEmployee->age;
    e->gender = toupper(newEmployee->gender);
    e->role = newEmployee->role;
    e->salary = newEmployee->salary;
    e->yearOfBirth = newEmployee->yearOfBirth;
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
}
void headerOfDisplay(){
    string divider = "=======================================================================";

    cout << divider << endl;
    cout << "| "<<left
         << setw(6)  << "ID"     << " | "
         << setw(20) << "Name"   << " | "
         << setw(5)  << "Age"    << " | "
         << setw(8)  << "Gender" << " | "
         << setw(15) << "Role"   << " | "
         << setw(10) << "Salary" << " | "
         << setw(6)  << "Year"   << " |"
         << endl;
    cout << divider << endl;    
}

void displayOneEmployee(Employee *tmp) {
    cout << "| "<<left
         << setw(6)  << tmp->id          << " | "
         << setw(20) << tmp->name        << " | "
         << setw(5)  << tmp->age         << " | "
         << setw(8)  << tmp->gender      << " | "
         << setw(15) << tmp->role        << " | "
         << setw(10) << tmp->salary      << " | "
         << setw(6)  << tmp->yearOfBirth << " |"
         << endl;
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
            cout << "Employee with ID " << searchId << " deleted successfully." << endl;
            return;
            searchIdFound = true;
        }
        temp = temp->next;
    }
    if (!searchIdFound) {
        cout << "Employee with ID " << searchId << " not found." << endl;
    }
    cout << "All employee after the deletion:" << endl;
    headerOfDisplay();
    temp = list->head;
    while (temp != nullptr) {
        displayOneEmployee(temp);
        temp = temp->next;
    }
}

void displayEmployees(List *list) {
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



void UpdateEmployeeById(List *list, int searchId, Employee *updatedEmployee) {
    if (list->size == 0) {
        cout << "The list is empty." << endl;
        return;
    }
    Employee *tmp = list->head;
    while (tmp != nullptr) {
        if (tmp->id == searchId) {
            tmp->name        = updatedEmployee->name;
            tmp->age         = updatedEmployee->age;
            tmp->gender      = updatedEmployee->gender;
            tmp->role        = updatedEmployee->role;
            tmp->salary      = updatedEmployee->salary;
            tmp->yearOfBirth = updatedEmployee->yearOfBirth;
            cout << "Employee with ID " << searchId << " updated successfully." << endl;
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

void sortEmployeeByIdAsc(List *list) {
    if (list->size <1) return;

    bool swapped;
    do {
        swapped = false;
        Employee *tmp = list->head;
        while (tmp->next != nullptr) {
            if (tmp->id > tmp->next->id) {
                exchange(&tmp->id, &tmp->next->id);
                exchange(&tmp->name, &tmp->next->name);
                exchange(&tmp->age, &tmp->next->age);
                exchange(&tmp->gender, &tmp->next->gender);
                exchange(&tmp->role, &tmp->next->role);
                exchange(&tmp->salary, &tmp->next->salary);
                exchange(&tmp->yearOfBirth, &tmp->next->yearOfBirth);
                swapped = true;
            }
            tmp = tmp->next;
        }
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
                exchange(&tmp->id, &tmp->next->id);
                exchange(&tmp->name, &tmp->next->name);
                exchange(&tmp->age, &tmp->next->age);
                exchange(&tmp->gender, &tmp->next->gender);
                exchange(&tmp->role, &tmp->next->role);
                exchange(&tmp->salary, &tmp->next->salary);
                exchange(&tmp->yearOfBirth, &tmp->next->yearOfBirth);
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
                exchange(&tmp->id, &tmp->next->id);
                exchange(&tmp->name, &tmp->next->name);
                exchange(&tmp->age, &tmp->next->age);
                exchange(&tmp->gender, &tmp->next->gender);
                exchange(&tmp->role, &tmp->next->role);
                exchange(&tmp->salary, &tmp->next->salary);
                exchange(&tmp->yearOfBirth, &tmp->next->yearOfBirth);
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
                exchange(&tmp->id, &tmp->next->id);
                exchange(&tmp->name, &tmp->next->name);
                exchange(&tmp->age, &tmp->next->age);
                exchange(&tmp->gender, &tmp->next->gender);
                exchange(&tmp->role, &tmp->next->role);
                exchange(&tmp->salary, &tmp->next->salary);
                exchange(&tmp->yearOfBirth, &tmp->next->yearOfBirth);
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
                exchange(&tmp->id, &tmp->next->id);
                exchange(&tmp->name, &tmp->next->name);
                exchange(&tmp->age, &tmp->next->age);
                exchange(&tmp->gender, &tmp->next->gender);
                exchange(&tmp->role, &tmp->next->role);
                exchange(&tmp->salary, &tmp->next->salary);
                exchange(&tmp->yearOfBirth, &tmp->next->yearOfBirth);
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
                exchange(&tmp->id, &tmp->next->id);
                exchange(&tmp->name,        &tmp->next->name);
                exchange(&tmp->age,         &tmp->next->age);
                exchange(&tmp->gender,      &tmp->next->gender);
                exchange(&tmp->role,        &tmp->next->role);
                exchange(&tmp->salary,      &tmp->next->salary);
                exchange(&tmp->yearOfBirth, &tmp->next->yearOfBirth);
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
