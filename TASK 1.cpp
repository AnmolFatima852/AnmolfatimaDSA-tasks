#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* head = nullptr;

void insertBefore(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        newNode->prev = temp;
        head->prev = newNode;
        temp->next = newNode;
        head = newNode;
    }
    
    cout << "Value " << value << " inserted at beginning successfully.\n";
}

void insertAfter(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    
    if (head == nullptr) {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        newNode->prev = temp;
        temp->next = newNode;
        head->prev = newNode;
    }
    
    cout << "Value " << value << " inserted at end successfully.\n";
}

void deleteNode(int position) {
    if (head == nullptr) {
        cout << "List is empty. Cannot delete.\n";
        return;
    }
    
    int count = 1;
    Node* temp = head;
    Node* toDelete = nullptr;
    
    if (position == 1) {
        if (head->next == head) {
            toDelete = head;
            head = nullptr;
            delete toDelete;
            cout << "Node at position " << position << " deleted successfully.\n";
            return;
        }
        
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        toDelete = head;
        head = head->next;
        last->next = head;
        head->prev = last;
        delete toDelete;
        cout << "Node at position " << position << " deleted successfully.\n";
        return;
    }
    
    temp = head->next;
    count = 2;
    while (temp != head && count < position) {
        temp = temp->next;
        count++;
    }
    
    if (temp == head || count < position) {
        cout << "Position " << position << " not found in the list.\n";
        return;
    }
    
    toDelete = temp;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete toDelete;
    cout << "Node at position " << position << " deleted successfully.\n";
}

void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    
    cout << "Circular Linked List: ";
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    int choice, value, position;
    
    do {
        cout << "\nCircular Linked List Operations:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Delete node\n";
        cout << "4. Display list\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert at beginning: ";
                cin >> value;
                insertBefore(value);
                displayList();
                break;
                
            case 2:
                cout << "Enter value to insert at end: ";
                cin >> value;
                insertAfter(value);
                displayList();
                break;
                
            case 3:
                cout << "Enter position to delete: ";
                cin >> position;
                deleteNode(position);
                displayList();
                break;
                
            case 4:
                displayList();
                break;
                
            case 5:
                cout << "Exiting program.\n";
                break;
                
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);
    
    return 0;
}