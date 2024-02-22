/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class Book {

    public:
    string name;
    string author;
    int ISBN_num;
    int totalPage;
    int pages_read;
   
    //Default Constructor
    Book(){
        name = "Emma";
        author = "Jane Austen";
        ISBN_num = 32877420;
        totalPage = 300;
        pages_read = 50;
    }
   
    //Parameterized constructor
    Book(string Name, string Author, int ISBN, int TotalPage, int Pages_read){
        name = Name;
        author = Author;
        ISBN_num = ISBN;
        totalPage = TotalPage;
        pages_read = Pages_read;
    }
   
    void tally(int pages){
        int readPages;
        cout << "Enter the num of pages read: ";
        cin >> readPages;
       
        if(readPages == pages) cout << "You have finished the book";
        else if (readPages > pages) cout << "Pages entered exceeds the total number of pages";
        else cout << "You have not finished the book yet";
    }
};

int main() {
   
    Book book1("Emma", "Jane Austen", 432703, 300, 50);
    book1.tally(300);

    return 0;
}