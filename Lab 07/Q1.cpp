/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class Book {
public:
    string title, author, publisher;

    Book(string title, string author, string publisher) : title(title), author(author), publisher(publisher) {}

    void display() {
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Publisher: " << publisher << "\n";
    }
};

class FictionBook : public Book {
public:
    string genre, protagonist;

    FictionBook(string title, string author, string publisher, string genre, string protagonist) :
        Book(title, author, publisher), genre(genre), protagonist(protagonist) {}

    void display() {
        cout << "Title: " << title << "\n";
        cout << "Author: " << author << "\n";
        cout << "Publisher: " << publisher << "\n";
        cout << "Genre: " << genre << "\n";
        cout << "Protagonist: " << protagonist << "\n";
    }
};    

int main() {
    FictionBook f1("Emma", "Jane Austen", "John Murray", "Classic Literature", "Emma Woodhouse");
    f1.display();

    return 0;
}
