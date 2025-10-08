#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning." << endl;
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        cout << "Inserted " << value << " at the end." << endl;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    cout << "Inserted " << value << " at the end." << endl;
}

void insertAtPosition(Node*& head, int value, int position) {
    if (position < 1) {
        cout << "Invalid position!! it must be 1 or greater than 1." << endl;
        return;
    }
    
    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }
    
    Node* newNode = new Node();
    newNode->data = value;
    
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "Position " << position << " is out of range" << endl;
        delete newNode;
        return;
    }
    
    newNode->next = temp->next;
    temp->next = newNode;
    cout << "Inserted " << value << " at position " << position << "." << endl;
}

void deleteAtBeginning(Node*& head) {
    if (head == NULL) {
        cout << "List is empty right now there is nothing to delete" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted: " << temp->data << " from the beginning." << endl;
    delete temp;
}

void deleteAtEnd(Node*& head) {
    if (head == NULL) {
        cout << "List is empty it has nothing to delete!" << endl;
        return;
    }
    
    if (head->next == NULL) {
        cout << "Deleted: " << head->data << " from the end." << endl;
        delete head;
        head = NULL;
        return;
    }
    
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    cout << "Deleted: " << temp->next->data << " from the end." << endl;
    delete temp->next;
    temp->next = NULL;
}

void deleteAtPosition(Node*& head, int position) {
    if (head == NULL) {
        cout << "List is empty there is nothing to delete at this moment" << endl;
        return;
    }
    
    if (position < 1) {
        cout << "Invalid position!!! Position must be 1 or greater than 1." << endl;
        return;
    }
    
    if (position == 1) {
        deleteAtBeginning(head);
        return;
    }
    
    Node* temp = head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL || temp->next == NULL) {
        cout << "Position " << position << " is out of range" << endl;
        return;
    }
    
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    cout << "Deleted: " << nodeToDelete->data << " from position " << position << endl;
    delete nodeToDelete;
}

void display(Node* head) {
    if (head == NULL) {
        cout << "List is empty!!!!!!!!!!!!!!" << endl;
        return;
    }
    
    Node* temp = head;
    cout << "Current List: ";
    while (temp != NULL) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int choice, value, position;
    
    cout << "=====LINK LIST OPERATIONS PROGRAM=====" << endl;

    
    do {
        cout  << endl << "MENU:" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Specific Position" << endl;
        cout << "4. Delete at Beginning" << endl;
        cout << "5. Delete at End" << endl;
        cout << "6. Delete at Specific Position" << endl;
        cout << "7. Display List" << endl;
        cout << "8. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter the value to insert: " << endl;
                cin >> value;
                insertAtBeginning(head, value);
                display(head);
                break;
                
            case 2:
                cout << "Enter the value to insert: " << endl;
                cin >> value;
                insertAtEnd(head, value);
                display(head);
                break;
                
            case 3:
            	cout << "Enter position: " << endl;
                cin >> position;
                cout << "Enter the value to insert: " << endl;
                cin >> value;
                insertAtPosition(head, value, position);
                display(head);
                break;
                
            case 4:
                deleteAtBeginning(head);
                display(head);
                break;
                
            case 5:
                deleteAtEnd(head);
                display(head);
                break;
                
            case 6:
                cout << "Enter the position to delete: " << endl;
                cin >> position;
                deleteAtPosition(head, position);
                display(head);
                break;
                
            case 7:
                display(head);
                break;
                
            case 8:
                cout << "Exiting program!!!" << endl;
                break;
                
            default:
                cout << "Invalid choice please try again." << endl;
        }
    } while (choice != 8);
    
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}