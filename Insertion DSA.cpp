#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* FuncNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void displayList(Node* head) {
    if (head == NULL) {
        cout << "The list is empty right now" << endl;
        
    }
    else
    {
	cout << "Elements in the link list are: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "  ";
        if (temp->next != NULL) {
            cout << " ";
        }
        temp = temp->next;
    }
    cout << endl ;
}}

void insertAtBeg(Node*& head, int value) {
    Node* newNode = FuncNode(value);
    newNode->next = head;
    head = newNode;
    cout << "Value " << value << " inserted at the beginning" << endl;
    displayList(head); 
}

void insertAtEnd(Node*& head, int value) {
    Node* newNode = FuncNode(value);
    
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    cout << "Value " << value << " inserted at the end" << endl;
    displayList(head); 
}

void insertAtPosition(Node*& head, int value, int position) {
    if (position < 1) {
        cout << "Invalid position! Position should be 1 or greater than 1" << endl;
        return;
    }
    
    if (position == 1) {
        insertAtBeg(head, value);
        return;
    }
    
    Node* newNode = FuncNode(value);
    Node* temp = head;
    
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        cout << "Position " << position << " is out of range" << endl;
        delete newNode;
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        cout << "Value " << value << " inserted at position " << position << endl;
        displayList(head); 
    }
}

void deleteList(Node*& head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;
    int choice, value, position;
    
    cout << "LINK LIST OPERATIONS" << endl;
    
    do {
        cout << endl << "MENU:" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert at Specific Position" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: " << endl;
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter the value to insert in the list: " << endl;
                cin >> value;
                insertAtBeg(head, value);
                break;
                
            case 2:
                cout << "Enter the value to insert in the list: " << endl;
                cin >> value;
                insertAtEnd(head, value);
                break;
                
            case 3:
                
                cout << "Enter position: ";
                cin >> position;
                cout << "Enter the value to insert in the list: " << endl;
                cin >> value;
                insertAtPosition(head, value, position);
                break;
                
            case 4:
                displayList(head);
                break;
                
            case 5:
                cout << "Exiting the program" << endl;
                break;
                
            default:
                cout << "Invalid choice please try again!!" << endl;
        }
    } while (choice != 5);
    
    deleteList(head);
    
    return 0;
}

















































/*#include <iostream>
using namespace std;
struct Node{
	int data;
	Node* next;
};
int main(){
	Node* head=new Node();
	head->data = 10;
	
	head->next = new Node();
	head->next->data = 20;
	
	head->next->next = new Node();
	head->next->next->data = 30;
	
	head->next->next->next = NULL;
	
	Node* temp = head;
	while(temp!=NULL){
		cout << temp->data << "   " << endl;
		temp = temp->next;
	}
	return 0;
}
*/	