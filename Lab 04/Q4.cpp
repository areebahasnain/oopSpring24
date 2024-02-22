/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class Office
{
private:
    string Location;
    int SeatingCapacity;
    string Furniture[3];

public:
    Office(std::string location = " ", int seatingCapacity = 0, initializer_list<string> furniture = {"", "", ""}) : Location(location), SeatingCapacity(seatingCapacity)
    {
        int i = 0;
        for (const auto &item : furniture)
        {
            Furniture[i++] = item;
            if (i >= 3)
                break;
        }
    }

    void display()
    {
        cout << "Location: " << Location << endl;
        cout << "Seating Capacity: " << SeatingCapacity << endl;
        cout << "Furniture: ";
        for (int i = 0; i < 3; ++i)
        {
            cout << Furniture[i] << " ";
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    Office office1;
    Office office2("Karachi", 51);
    Office office3("Lahore", 30, {"Desk", "Chair", "Couch"});

    cout << "Office 1:" << endl;
    office1.display();
    cout << "Office 2:" << endl;
    office2.display();
    cout << "Office 3:" << endl;
    office3.display();

    return 0;
}
