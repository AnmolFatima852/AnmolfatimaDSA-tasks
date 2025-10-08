#include <iostream>
using namespace std;

struct Employee {
    string name;
    Employee* next;
};

Employee* head = nullptr;

void addEmployee(string empName) {
    Employee* newEmployee = new Employee;
    newEmployee->name = empName;
    
    if (head == nullptr) {
        head = newEmployee;
        newEmployee->next = head;
    } else {
        Employee* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newEmployee;
        newEmployee->next = head;
    }
    
    cout << "Employee '" << empName << "' added successfully.\n";
}

void deleteEmployee(string empName) {
    if (head == nullptr) {
        cout << "Dataset is empty. Cannot delete.\n";
        return;
    }
    
    Employee* temp = head;
    Employee* prev = nullptr;
    Employee* toDelete = nullptr;
    
    if (head->name == empName && head->next == head) {
        toDelete = head;
        head = nullptr;
        delete toDelete;
        cout << "Employee '" << empName << "' deleted successfully.\n";
        return;
    }
    
    if (head->name == empName) {
        toDelete = head;
        Employee* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        delete toDelete;
        cout << "Employee '" << empName << "' deleted successfully.\n";
        return;
    }
    
    temp = head->next;
    prev = head;
    
    while (temp != head && temp->name != empName) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == head) {
        cout << "Employee '" << empName << "' not found in dataset.\n";
        return;
    }
    
    toDelete = temp;
    prev->next = temp->next;
    delete toDelete;
    cout << "Employee '" << empName << "' deleted successfully.\n";
}

void searchEmployee(string empName) {
    if (head == nullptr) {
        cout << "Dataset is empty.\n";
        return;
    }
    
    Employee* temp = head;
    
    if (head->name == empName) {
        cout << "Employee '" << empName << "' found successfully.\n";
        return;
    }
    
    temp = head->next;
    while (temp != head && temp->name != empName) {
        temp = temp->next;
    }
    
    if (temp == head) {
        cout << "Employee '" << empName << "' not found in dataset.\n";
    } else {
        cout << "Employee '" << empName << "' found successfully.\n";
    }
}

void updateEmployee(string oldName, string newName) {
    if (head == nullptr) {
        cout << "Dataset is empty. Cannot update.\n";
        return;
    }
    
    Employee* temp = head;
    
    if (head->name == oldName) {
        head->name = newName;
        cout << "Employee '" << oldName << "' updated to '" << newName << "' successfully.\n";
        return;
    }
    
    temp = head->next;
    while (temp != head && temp->name != oldName) {
        temp = temp->next;
    }
    
    if (temp == head) {
        cout << "Employee '" << oldName << "' not found in dataset.\n";
    } else {
        temp->name = newName;
        cout << "Employee '" << oldName << "' updated to '" << newName << "' successfully.\n";
    }
}

void displayEmployees() {
    if (head == nullptr) {
        cout << "Dataset is empty.\n";
        return;
    }
    
    cout << "Employee Dataset: ";
    Employee* temp = head;
    do {
        cout << temp->name << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int choice;
    string name, newName;
    
    do {
        cout << "\nEmployee Data Entry Operations:\n";
        cout << "1. Add Employee\n";
        cout << "2. Delete Employee\n";
        cout << "3. Search Employee\n";
        cout << "4. Update Employee\n";
        cout << "5. Display All Employees\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter employee name to add: ";
                cin >> name;
                addEmployee(name);
                displayEmployees();
                break;
                
            case 2:
                cout << "Enter employee name to delete: ";
                cin >> name;
                deleteEmployee(name);
                displayEmployees();
                break;
                
            case 3:
                cout << "Enter employee name to search: ";
                cin >> name;
                searchEmployee(name);
                break;
                
            case 4:
                cout << "Enter employee name to update: ";
                cin >> name;
                cout << "Enter new name: ";
                cin >> newName;
                updateEmployee(name, newName);
                displayEmployees();
                break;
                
            case 5:
                displayEmployees();
                break;
                
            case 6:
                cout << "Exiting program.\n";
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);
    
    return 0;
}