/* K230059 - AREEBA HASNAIN SHAIKH */
/* Task Description: Design a program to manage a library's book inventory, incorporating features to search for books by 
title or author, and enabling functionalities for creating, modifying, and displaying book data*/
#include <iostream>

using namespace std;

struct Book {
    string title;
    string author;
    int year;
    string genre;
};

void addBook(Book library[], int& count) {
    cout << "Enter book title: ";
    cin.ignore();
    getline(cin, library[count].title);
    cout << "Enter book author: ";
    getline(cin, library[count].author);
    cout << "Enter publication year: ";
    cin >> library[count].year;
    cout << "Enter book genre: ";
    cin.ignore();
    getline(cin, library[count].genre);
    count++;
}

void displayBooks(const Book library[], int count) {
    if (count == 0) {
        cout << "Library is empty." << endl;
        return;
    }
    cout << "Library Inventory:" << endl;
    for (int i = 0; i < count; ++i) {
        cout << "Title: " << library[i].title << endl;
        cout << "Author: " << library[i].author << endl;
        cout << "Year: " << library[i].year << endl;
        cout << "Genre: " << library[i].genre << endl;
        cout << "-----------------------------" << endl;
    }
}

void findBookByTitle(const Book library[], int count, const string& title) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (library[i].title == title) {
            cout << "Book found:" << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Year: " << library[i].year << endl;
            cout << "Genre: " << library[i].genre << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

void findBookByAuthor(const Book library[], int count, const string& author) {
    bool found = false;
    for (int i = 0; i < count; ++i) {
        if (library[i].author == author) {
            cout << "Book found:" << endl;
            cout << "Title: " << library[i].title << endl;
            cout << "Author: " << library[i].author << endl;
            cout << "Year: " << library[i].year << endl;
            cout << "Genre: " << library[i].genre << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Book not found." << endl;
    }
}

int main() {
    Book library[100];
    int count = 0;
    char choice;

    do {
        cout << "\nMenu:\n1. Add a book\n2. Display all books\n3. Find a book by title\n4. Find a book by author\n5. Exit\nEnter your choice: ";
        cin >> choice;

        switch(choice) {
            case '1':
                if (count < 100) {
                    addBook(library, count);
                } else {
                    cout << "Library is full." << endl;
                }
                break;
            case '2':
                displayBooks(library, count);
                break;
            case '3':
                {
                    string title;
                    cout << "Enter title to search: ";
                    cin.ignore();
                    getline(cin, title);
                    findBookByTitle(library, count, title);
                }
                break;
            case '4':
                {
                    string author;
                    cout << "Enter author to search: ";
                    cin.ignore();
                    getline(cin, author);
                    findBookByAuthor(library, count, author);
                }
                break;
            case '5':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != '5');

    return 0;
}
