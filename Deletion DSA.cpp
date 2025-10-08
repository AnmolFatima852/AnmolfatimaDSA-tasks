#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void deleteAtBeginning(Node*& head) {
    if (head == NULL) {
        cout << "List is empty there is nothing to delete" << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted: " << temp->data << endl;
    delete temp;
}

void deleteAtEnd(Node*& head) {
    if (head == NULL) {
        cout << "List is empty right now it has nothing to delete" << endl;
        return;
    }
    
    if (head->next == NULL) {
        cout << "Deleted: " << head->data << endl;
        delete head;
        head = NULL;
        return;
    }
    
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    
    cout << "Deleted: " << temp->next->data << endl;
    delete temp->next;
    temp->next = NULL;
}

void deleteAtPosition(Node*& head, int position) {
    if (head == NULL) {
        cout << "List is empty nothing to delete at this moment" << endl;
        return;
    }
    
    if (position < 1) {
        cout << "Invalid position!!! Position must be 1 or greater than 1" << endl;
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
        cout << "List is empty" << endl;
        return;
    }
    
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "  ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int choice, position;
    
    insertAtEnd(head, 5000);
    insertAtEnd(head, 4000);
    insertAtEnd(head, 3000);
    insertAtEnd(head, 2000);
    insertAtEnd(head, 1000);
    
    cout << "Initial List: ";
    display(head);
    
    do {
        cout << endl << "MENU:" << endl;
        cout << "1. Delete at Beginning" << endl;
        cout << "2. Delete at End" << endl;
        cout << "3. Delete at Specific Position" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        
        switch (choice) {
            case 1:
                deleteAtBeginning(head);
                cout << "List after deletion: " << endl;
                display(head);
                break;
                
            case 2:
                deleteAtEnd(head);
                cout << "List after deletion: " << endl;
                display(head);
                break;
                
            case 3:
                cout << "Enter position you want to delete: " << endl;
                cin >> position;
                deleteAtPosition(head, position);
                cout << "List after deletion: " << endl;
                display(head);
                break;
                
            case 4:
                cout << "Current List is: " << endl;
                display(head);
                break;
                
            case 5:
                cout << "Exiting the program!!!..." << endl;
                break;
                
            default:
                cout << "Invalid choice please try again!!" << endl;
        }
    } while (choice != 5);
    
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
    
    return 0;
}