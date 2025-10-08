#include <iostream>
using namespace std;

struct Book {
    string bookId;
    string bookName;
    double bookPrice;
    string bookAuthor;
    string bookISBN;
};

struct Node {
    Book book;
    Node* next;
    Node* prev;
};

struct BookList {
    Node* head;
    
    BookList() {
        head = nullptr;
    }
};

void addBook(BookList& list, string bookId, string bookName, double bookPrice, string bookAuthor, string bookISBN) {
    Node* newNode = new Node;
    newNode->book.bookId = bookId;
    newNode->book.bookName = bookName;
    newNode->book.bookPrice = bookPrice;
    newNode->book.bookAuthor = bookAuthor;
    newNode->book.bookISBN = bookISBN;
    
    if (list.head == nullptr) {
        list.head = newNode;
        newNode->next = list.head;
        newNode->prev = list.head;
    } else {
        Node* temp = list.head;
        while (temp->next != list.head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = list.head;
        list.head->prev = newNode;
    }
    
    cout << "Book '" << bookName << "' added successfully."<< endl;
}

void removeBook(BookList& list, string bookId) {
    if (list.head == nullptr) {
        cout << "Book list is empty. Cannot remove."<< endl;
        return;
    }
    
    Node* temp = list.head;
    Node* toDelete = nullptr;
    
    if (list.head->book.bookId == bookId && list.head->next == list.head) {
        toDelete = list.head;
        list.head = nullptr;
        delete toDelete;
        cout << "Book with ID '" << bookId << "' removed successfully."<< endl;
        return;
    }
    
    if (list.head->book.bookId == bookId) {
        toDelete = list.head;
        Node* last = list.head->prev;
        list.head = list.head->next;
        last->next = list.head;
        list.head->prev = last;
        delete toDelete;
        cout << "Book with ID '" << bookId << "' removed successfully."<< endl;
        return;
    }
    
    temp = list.head->next;
    while (temp != list.head && temp->book.bookId != bookId) {
        temp = temp->next;
    }
    
    if (temp == list.head) {
        cout << "Book with ID '" << bookId << "' not found."<< endl;
        return;
    }
    
    toDelete = temp;
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    delete toDelete;
    cout << "Book with ID '" << bookId << "' removed successfully."<< endl;
}

void updateBook(BookList& list, string bookId, string bookName, double bookPrice, string bookAuthor, string bookISBN) {
    if (list.head == nullptr) {
        cout << "Book list is empty. Cannot update."<< endl;
        return;
    }
    
    Node* temp = list.head;
    
    if (list.head->book.bookId == bookId) {
        cout << "Book to be updated:\n";
        cout << "ID: " << list.head->book.bookId << ", Name: " << list.head->book.bookName 
             << ", Price: " << list.head->book.bookPrice << ", Author: " << list.head->book.bookAuthor 
             << ", ISBN: " << list.head->book.bookISBN << endl;
             
        list.head->book.bookName = bookName;
        list.head->book.bookPrice = bookPrice;
        list.head->book.bookAuthor = bookAuthor;
        list.head->book.bookISBN = bookISBN;
        
        cout << "Book with ID '" << bookId << "' updated successfully."<< endl;
        return;
    }
    
    temp = list.head->next;
    while (temp != list.head && temp->book.bookId != bookId) {
        temp = temp->next;
    }
    
    if (temp == list.head) {
        cout << "Book with ID '" << bookId << "' not found."<< endl;
    } else {
        cout << "Book to be updated:"<< endl;
        cout << "ID: " << temp->book.bookId << ", Name: " << temp->book.bookName 
             << ", Price: " << temp->book.bookPrice << ", Author: " << temp->book.bookAuthor 
             << ", ISBN: " << temp->book.bookISBN << endl;
             
        temp->book.bookName = bookName;
        temp->book.bookPrice = bookPrice;
        temp->book.bookAuthor = bookAuthor;
        temp->book.bookISBN = bookISBN;
        
        cout << "Book with ID '" << bookId << "' updated successfully."<< endl;
    }
}

void printBooks(BookList& list) {
    if (list.head == nullptr) {
        cout << "Book list is empty."<< endl;
        return;
    }
    
    cout << "All Books in List:"<< endl;
    Node* temp = list.head;
    do {
        cout << "ID: " << temp->book.bookId << ", Name: " << temp->book.bookName 
             << ", Price: " << temp->book.bookPrice << ", Author: " << temp->book.bookAuthor 
             << ", ISBN: " << temp->book.bookISBN << endl;
        temp = temp->next;
    } while (temp != list.head);
}

void printBook(BookList& list, string bookId) {
    if (list.head == nullptr) {
        cout << "Book list is empty."<< endl;
        return;
    }
    
    Node* temp = list.head;
    
    if (list.head->book.bookId == bookId) {
        cout << "Required Book:"<< endl;
        cout << "ID: " << list.head->book.bookId << ", Name: " << list.head->book.bookName 
             << ", Price: " << list.head->book.bookPrice << ", Author: " << list.head->book.bookAuthor 
             << ", ISBN: " << list.head->book.bookISBN << endl;
        return;
    }
    
    temp = list.head->next;
    while (temp != list.head && temp->book.bookId != bookId) {
        temp = temp->next;
    }
    
    if (temp == list.head) {
        cout << "Book with ID '" << bookId << "' not found."<< endl;
    } else {
        cout << "Required Book:\n";
        cout << "ID: " << temp->book.bookId << ", Name: " << temp->book.bookName 
             << ", Price: " << temp->book.bookPrice << ", Author: " << temp->book.bookAuthor 
             << ", ISBN: " << temp->book.bookISBN << endl;
    }
}

int main() {
    BookList bookList;
    
    cout << "=== 1. AddBook method 10 times ==="<< endl;
    addBook(bookList, "book1", "C++ Programming", 100.99, "Ali", "123-45678");
    addBook(bookList, "book2", "Data Structures", 505.50, "Elvish", "098-23456");
    addBook(bookList, "book3", "Algorithms", 650.75, "Sara", "164-9876543");
    addBook(bookList, "book4", "Database Systems", 490.99, "Robert", "232-8765345");
    addBook(bookList, "book5", "Operating Systems", 509.99, "Sierra", "233-098765");
    addBook(bookList, "book6", "Computer Networks", 592.25, "Emily", "456-8765435");
    addBook(bookList, "book7", "Software Engineering", 437.80, "Maria", "342-876543");
    addBook(bookList, "book8", "Artificial Intelligence", 698.99, "John", "914-9876522");
    addBook(bookList, "book9", "Machine Learning", 705.50, "Peter", "875-0987654");
    addBook(bookList, "book10", "Web Development", 423.99, "Kevin", "643-876543");
    
    cout << "\n=== 2. PrintBooks method 1 time ===" << endl;
    printBooks(bookList);
    
    cout << "\n=== 3. RemoveBook method 2 times ===" << endl;
    cout << "First removal (valid ID):" << endl;
    removeBook(bookList, "book3");
    cout << "\nSecond removal (invalid ID):" << endl;
    removeBook(bookList, "book99");
    
    cout << "\n=== 4. PrintBooks method 1 time ===" << endl;
    printBooks(bookList);
    
    cout << "\n=== 5. UpdateBook method ==="<< endl;
    cout << "Updating book book5:"<< endl;
    updateBook(bookList, "book5", "Advanced Operating Systems", 64.99, "Sierra", "233-098765");
    cout << "\nPrinting the updated book:"<< endl;
    printBook(bookList, "book5");
    
    return 0;
}