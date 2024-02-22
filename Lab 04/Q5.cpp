/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class Office
{
private:
    string Location;
    int SeatingCapacity;
    string *Furniture; 

public:
    Office(string location = "", int seatingCapacity = 0, int furniture = 3) : Location(location), SeatingCapacity(seatingCapacity)
    {
        Furniture = new string[furniture]; 
    }

    
    ~Office()
    {
        delete[] Furniture; 
    }

    void setFurniture(string furniture[], int size)
    {
        for (int i = 0; i < size; ++i)
        {
            Furniture[i] = furniture[i];
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
        }
        cout << endl;
    }
};

int main()
{
    Office *office = new Office("Islamabad", 40, 3);
    string furniture[] = {"Desk", "Chair", "Bookshelf"};
    office->setFurniture(furniture, 3);

    cout << "Office:" << endl;
    office->display();

    delete office;

    return 0;
}
