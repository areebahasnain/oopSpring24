/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class Calendar {
private:
    string January[31];
    string February[29];
    string March[31];
    string April[30];
    string May[31];
    string June[30];
    string July[31];
    string August[31];
    string September[30];
    string October[31];
    string November[30];
    string December[31];

    void show_one_month(string month[], int size) {
    for (int i = 0; i < size; i++) 
        if (!month[i].empty() && month[i] != "") 
            cout << month[i] << "  ";
    cout << endl;
}

public:
    void add_task(int date, int month, string task) {
        switch(month) {
            case 1:
                January[date-1] = task;
                break;
            case 2:
                February[date-1] = task;
                break;
            case 3:
                March[date-1] = task;
                break;
            case 4:
                April[date-1] = task;
                break;
            case 5:
                May[date-1] = task;
                break;
            case 6:
                June[date-1] = task;
                break;
            case 7:
                July[date-1] = task;
                break;
            case 8:
                August[date-1] = task;
                break;
            case 9:
                September[date-1] = task;
                break;
            case 10:
                October[date-1] = task;
                break;
            case 11:
                November[date-1] = task;
                break;
            case 12:
                December[date-1] = task;
                break;
            default:
                cout << "Invalid month!" << endl;
        }
    }

    void remove_task(int date, int month) {
        switch(month) {
            case 1:
                January[date-1] = "";
                break;
            case 2:
                February[date-1] = "";
                break;
            case 3:
                March[date-1] = "";
                break;
            case 4:
                April[date-1] = "";
                break;
            case 5:
                May[date-1] = "";
                break;
            case 6:
                June[date-1] = "";
                break;
            case 7:
                July[date-1] = "";
                break;
            case 8:
                August[date-1] = "";
                break;
            case 9:
                September[date-1] = "";
                break;
            case 10:
                October[date-1] = "";
                break;
            case 11:
                November[date-1] = "";
                break;
            case 12:
                December[date-1] = "";
                break;
            default:
                cout << "Invalid month!" << endl;
        }
    }

    void show_all_tasks() {
        show_one_month(January, 30);
        show_one_month(February, 30);
        show_one_month(March, 30);
        show_one_month(April, 30);
        show_one_month(May, 30);
        show_one_month(June, 30);
        show_one_month(July, 30);
        show_one_month(August, 30);
        show_one_month(September, 30);
        show_one_month(October, 30);
        show_one_month(November, 30);
        show_one_month(December, 30);
    }
};

int main() {
    Calendar calendar;

    calendar.add_task(13, 1, "Mom Dad's Anniversary");
    calendar.add_task(16, 2, "OOP Theory Mid 1");
    calendar.add_task(10, 3, "Lunch with Uni Friends");
    calendar.add_task(10, 4, "Flight to Isb");
    calendar.remove_task(10, 4);
    calendar.add_task(10, 4, "Flight to Lahore");

    calendar.show_all_tasks();

    return 0;
}
