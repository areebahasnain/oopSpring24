/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>
using namespace std;

class Book {
private:
    string name;
    string author;
    int ISBN_num;
    int totalPage;
    int pages_read;

public:
    Book() : name("Emma"), author("Jane Austen"), ISBN_num(32877420), totalPage(1000), pages_read(0) {}

    void setName(string Name) {
        name = Name;
    }

    void setAuthor(string Author) {
        author = Author;
    }

    void setISBN(int ISBN) {
        ISBN_num = ISBN;
    }

    void setTotalPage(int TotalPage) {
        totalPage = TotalPage;
    }

    void setPagesRead(int Pages_read) {
        pages_read = Pages_read;
    }

    void showBookInfo() {
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << ISBN_num << endl;
        cout << "Total Pages: " << totalPage << endl;
        cout << "Pages Read: " << pages_read << endl;
    }

    void tally(int pages) {
        int readPages;
        cout << "Enter the num of pages read: ";
        cin >> readPages;

        if (readPages == pages) cout << "You have finished the book";
        else if (readPages > pages) cout << "Pages entered exceed the total number of pages";
        else cout << "You have not finished the book yet";
    }
};

int main() {
    Book book1;
    book1.setName("Emma");
    book1.setAuthor("Jane Austen");
    book1.setISBN(432703);
    book1.setTotalPage(300);
    book1.setPagesRead(50);

    book1.showBookInfo();

    return 0;
}
