/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class Table {
private:
    int capacity;
public:
    int occupied_seats;
    int free_seats;
    bool clean;

    Table(int capacity = 4) {
        this->capacity = (capacity < 6) ? 4 : 8;
        this->occupied_seats = 0;
        this->free_seats = this->capacity;
        this->clean = true;
    }

    void useTable(int group_size) {
        if (clean && group_size <= capacity) {
            occupied_seats = group_size;
            free_seats = capacity - group_size;
            clean = false;
            cout << "Table with capacity " << capacity << " is now occupied by a group of " << group_size << ".\n";
        }
    }

    void haveLunch() {
        if (!clean) {
            cout << "Lunch is being had at the table.\n";
            clean = false;
        }
    }

    void leaveTable() {
        cout << "Leaving the table.\n";
        occupied_seats = 0;
        free_seats = capacity;
        clean = true;
    }

    void cleanTable() {
        if (occupied_seats == 0) {
            cout << "Table is being cleaned.\n";
            clean = true;
        } else {
            cout << "Cannot clean the table while it's occupied.\n";
        }
    }

    bool isClean() {
        return clean;
    }

    int getCapacity() {
        return capacity;
    }
};

void OccupyTable(Table tables[], int group_size) {
    for (int i = 0; i < 5; i++) {
        if (tables[i].isClean() && group_size <= tables[i].getCapacity()) {
            tables[i].useTable(group_size);
            return;
        }
    }
    cout << "No available table for this group size.\n";
}

void EmptyTable(Table tables[], int table_number) {
    if (table_number >= 0 && table_number < 5) {
        tables[table_number].leaveTable();
    } else {
        cout << "Invalid table number.\n";
    }
}

int main() {

    cout << "-------------------------------------------" << endl;
    cout << "\tNAME: AREEBA HASNAIN SHAIKH"<< endl << "\tSTUDENT ID: K23-0059" << endl;
    cout << "-------------------------------------------" << endl;

    Table tables[5] = {Table(8), Table(8), Table(), Table(), Table()};

    OccupyTable(tables, 4);

    OccupyTable(tables, 6);

    tables[0].useTable(4);
    tables[0].haveLunch();
    tables[0].leaveTable();
    tables[0].cleanTable();

    EmptyTable(tables, 1);

    return 0;
}
