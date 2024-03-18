/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>
using namespace std;

class Appointment {
private:
    double cost;

public:
    static int appointments;
    static double total;

    Appointment(double cost) : cost(cost) {
        total += cost; // add the cost of the new appointment to the total earnings
        appointments++; // increment the number of appointments made
    }

    double getCost() const { return cost; }

    static double getAverageCost() {
        if (appointments == 0) return 0;
        return total / appointments;
    }
};

int Appointment::appointments = 0;
double Appointment::total = 0.0;

int main() {
    Appointment a1(75.0);
    cout << "Cost of Appointment 1: " << a1.getCost() << endl;
    Appointment a2(125.0);
    cout << "Cost of Appointment 2: " << a2.getCost() << endl;
    Appointment a3(150.0);
    cout << "Cost of Appointment 3: " << a3.getCost() << endl;

    cout << "Average Costs of all Appointments: " << Appointment::getAverageCost() << endl;
    
    return 0;
}
