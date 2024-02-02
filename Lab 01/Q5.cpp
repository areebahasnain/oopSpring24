#include <iostream>
using namespace std;

typedef struct {
    string name;
    string date;
    string venue;
    string organizer;
} Event;

Event event_input() {
    Event event;

    cout << "Event Name: ";
    getline(cin, event.name);

    cout << "Date (dd/mm/yy): ";
    getline(cin, event.date);

    cout << "Venue: ";
    getline(cin, event.venue);

    cout << "Organizer: ";
    getline(cin, event.organizer);

    return event;
}


int main() {
    int events;

    cout << "Enter number of events: ";
    cin >> events;
    cin.ignore();  
    Event *event_arr = new Event[events];

    for (int i = 0; i < events; i++) {
        cout << "Event " << i + 1 << endl;
        event_arr[i] = event_input();
        cout << endl;
    }

    string date;
    cout << "Enter a date to search for an event (dd/mm/yy): ";
    getline(cin, date);

    for (int i = 0; i < events; i++) {
        if (event_arr[i].date == date) {
            cout << "Event Name: " << event_arr[i].name << endl;
            cout << "Event Date: " << event_arr[i].date << endl;
            cout << "Event Venue: " << event_arr[i].venue << endl;
            cout << "Event Organizer: " << event_arr[i].organizer << endl;

            break;
        }
    }

    delete[] event_arr;  
    return 0;
}
