/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>
#include <cmath>

using namespace std;

class RollerCoaster
{
private:
    string name;
    unsigned height, length;
    double speed;
    int capacity, currentNumRiders;
    bool rideInProgress;

public:
    RollerCoaster() : name("roller coaster"), height(500), length(2000), capacity(20), speed(0), currentNumRiders(0), rideInProgress(false) {}

    RollerCoaster(string n, unsigned h, unsigned l, double s, int cap)
        : name(n), height(h), length(l), speed(s), currentNumRiders(0), rideInProgress(false)
    {
        // Ensure capacity is a multiple of 2 or 3 and greater than 3
        if (cap <= 3)
            capacity = 4;
        else
            capacity = round(cap / 2.0) * 2;
    }

    string getName() { return name; }
    void setName(string name) { this->name = name; }

    unsigned getHeight() { return height; }
    void setHeight(unsigned height) { this->height = height; }

    unsigned getLength() { return length; }
    void setLength(unsigned length) { this->length = length; }

    double getSpeed() { return speed; }
    void setSpeed(double speed) { this->speed = speed; }

    int getCurrentNumRiders() { return currentNumRiders; }
    bool getRideInProgress() { return rideInProgress; }

    int getCapacity() { return capacity; }
    void setCapacity(int capacity)
    {
        if (capacity <= 3)
            this->capacity = 4;
        else
            this->capacity = round(capacity / 2.0) * 2;
    }

    int loadRiders(int numRiders)
    {
        if (!rideInProgress && currentNumRiders + numRiders <= capacity)
        {
            currentNumRiders += numRiders;
            return 0;
        }
        else
            return numRiders - (capacity - currentNumRiders); // Return excess riders
    }

    int startRide()
    {
        if (!rideInProgress)
        {
            if (currentNumRiders == capacity)
            {
                rideInProgress = true;
                return 0; // Ride started successfully
            }
            else
                return capacity - currentNumRiders; // Return empty seats
        }
        else
            return -1; // Ride already in progress
    }

    void stopRide()
    {
        if (rideInProgress)
            rideInProgress = false;
    }

    void unloadRiders()
    {
        if (!rideInProgress)
            currentNumRiders = 0;
    }

    void accelerate(string roll)
    {
        for (auto it = roll.end() - 1; it >= roll.begin(); it--)
        {
            if (*it == '0')
                continue;
            this->setSpeed(speed + (*it - '0'));
            return;
        }
    }

    void decelerate(string roll)
    {
        for (auto it = roll.begin(); it < roll.end(); it++)
        {
            if (*it != '0')
            {
                this->setSpeed(speed - (*it - '0'));
                return;
            }
        }
    }
};

int main()
{
    cout << "-------------------------------------------" << endl;
    cout << "\tNAME: AREEBA HASNAIN SHAIKH" << endl
         << "\tSTUDENT ID: K23-0059" << endl;
    cout << "-------------------------------------------" << endl;

    // Create RollerCoaster instances
    RollerCoaster coaster1;
    RollerCoaster coaster2("Top Thrill", 600, 2500, 50, 15);

    // Print RollerCoaster information
    cout << endl
         << "Name: " << coaster2.getName() << endl;
    cout << endl
         << "Capacity: " << coaster2.getCapacity() << endl;

    // Load riders onto coaster2
    int remainingRiders = coaster2.loadRiders(39);
    cout << "Total Riders: 39" << endl;
    cout << "Excess number of Riders: " << remainingRiders << endl;

    // Start the ride if enough riders are loaded
    if (remainingRiders == 0)
    {
        coaster2.startRide();
    }

    // Print current number of riders and ride status
    cout << "Current riders: " << coaster2.getCurrentNumRiders() << endl;
    cout << "Ride status: " << (coaster2.getRideInProgress() ? "In progress" : "Not in progress") << endl;

    // Accelerating Ride
    coaster2.accelerate("0059");
    cout << "Speed after acceleration: " << coaster2.getSpeed() << endl;

    // Decelerating Ride
    for (int i = 0; i < 9; i++)
        coaster2.decelerate("0059");
    cout << "Speed after calling decelerate Function 9 times: " << coaster2.getSpeed() << endl;

    // Stop the ride and unload riders
    coaster2.stopRide();
    coaster2.unloadRiders();

    // Print current number of riders after unloading
    cout << "Current riders after unloading: " << coaster2.getCurrentNumRiders() << endl;

    return 0;
}
