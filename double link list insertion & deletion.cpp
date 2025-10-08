#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->prev = nullptr;
    newNode->next = nullptr;
    return newNode;
}

int getListLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }
    return length;
}

Node* insertAtPosition(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    int length = getListLength(head);
    
    if (position < 1 || position > length + 1) {
        cout << "Invalid position " << position << ". Valid positions are 1 to " << length + 1 << endl;
        delete newNode;
        return head;
    }
    
    if (head == nullptr) {
        return newNode;
    }
    
    if (position == 1) {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
    
    Node* current = head;
    int currentPosition = 1;
    
    while (currentPosition < position - 1 && current->next != nullptr) {
        current = current->next;
        currentPosition++;
    }
    
    newNode->next = current->next;
    newNode->prev = current;
    
    if (current->next != nullptr) {
        current->next->prev = newNode;
    }
    
    current->next = newNode;
    
    return head;
}

Node* deleteAtPosition(Node* head, int position) {
    // If list is empty
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return nullptr;
    }
    
    int length = getListLength(head);
    
    if (position < 1 || position > length) {
        cout << "Position " << position << " is invalid. Valid positions are 1 to " << length << endl;
        return head;
    }
    
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        
        if (head != nullptr) {
            head->prev = nullptr;
        }
        
        delete temp;
        cout << "Deleted node at position " << position << endl;
        return head;
    }
    
    Node* current = head;
    int currentPosition = 1;
    
    while (current != nullptr && currentPosition < position) {
        current = current->next;
        currentPosition++;
    }
    
    if (current == nullptr) {
        cout << "Position " << position << " is invalid" << endl;
        return head;
    }
    
    if (current->prev != nullptr) {
        current->prev->next = current->next;
    }
    
    if (current->next != nullptr) {
        current->next->prev = current->prev;
    }
    
    delete current;
    cout << "Deleted node at position " << position << endl;
    return head;
}

void printList(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    
    Node* current = head;
    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " ";
        }
        current = current->next;
    }
    cout << endl;
}

void printListReverse(Node* head) {
    if (head == nullptr) {
        cout << "List is empty." << endl;
        return;
    }
    
    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    
    while (current != nullptr) {
        cout << current->data;
        if (current->prev != nullptr) {
            cout << " ";
        }
        current = current->prev;
    }
    cout << endl;
}

void deleteList(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;
        delete temp;
    }
    cout << "Memory cleared successfully." << endl;
}

void displayMenu() {
    cout << "\n=== Doubly Linked List Menu ===" << endl;
    cout << "1. Insert at position" << endl;
    cout << "2. Delete at position" << endl;
    cout << "3. Display list" << endl;
    cout << "4. Reverse list" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Node* head = nullptr;
    int choice, data, position;
    
    cout << "=== Doubly Linked List ===" << endl;
    
    do {
        displayMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Enter position (1 to " << getListLength(head) + 1 << "): ";
                cin >> position;
                cout << "Enter data to insert: ";
                cin >> data;
                head = insertAtPosition(head, data, position);
                cout << "List: ";
                printList(head);
                break;
            }
            
            case 2: {
                if (head == nullptr) {
                    cout << "List is empty. Nothing to delete." << endl;
                } else {
                    cout << "Current list: ";
                    printList(head);
                    cout << "Enter position to delete (1 to " << getListLength(head) << "): ";
                    cin >> position;
                    head = deleteAtPosition(head, position);
                    cout << "List: ";
                    printList(head);
                }
                break;
            }
            
            case 3: {
                cout << "Displaying list:" << endl;
                cout << "List: ";
                printList(head);
                break;
            }
            
            case 4: {
                cout << "Displaying list in reverse:" << endl;
                cout << "Reverse list: ";
                printListReverse(head);
                break;
            }
            
            case 5: {
                cout << "Exiting program..." << endl;
                break;
            }
            
            default: {
                cout << "Invalid choice! Please enter 1-5." << endl;
                break;
            }
        }
        
    } while (choice != 5);
    
    cout << "\nCleaning up memory..." << endl;
    deleteList(head);
    
    cout << "Program ended successfully!" << endl;
    
    return 0;
}