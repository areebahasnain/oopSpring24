#include <iostream>
#include <string> // Include string header separately

using namespace std;

class BoardMarker {
private:
    string brand;
    string shade;
    bool refillable;
    bool inkStatus;

public:
    void setBrand(const string& brand) { // Pass string arguments by const reference
        this->brand = brand;
    }

    string getBrand() {
        return brand;
    }

    void setShade(const string& shade) { // Pass string arguments by const reference
        this->shade = shade;
    }

    string getShade() {
        return shade;
    }

    void setRefillable(bool refillable) {
        this->refillable = refillable;
    }

    bool isRefillable() {
        return refillable;
    }

    void setInkStatus(bool inkStatus) {
        this->inkStatus = inkStatus;
    }

    bool hasInk() {
        return inkStatus;
    }

    void write() {
        if (inkStatus) {
            cout << "The marker writes smoothly." << endl;
        } else {
            cout << "The marker is out of ink." << endl;
        }
    }

    void refill() {
        if (refillable) {
            cout << "Refilling the marker..." << endl;
            inkStatus = true; // Refill the ink
            cout << "Marker has been refilled." << endl;
        } else {
            cout << "This marker cannot be refilled." << endl;
        }
    }
};

int main() {
    BoardMarker marker;

    string brand;
    string shade;
    bool refillable;
    bool inkStatus;

    cout << "Enter the brand of the marker: ";
    cin >> brand;
    marker.setBrand(brand);

    cout << "Enter the shade of the marker: ";
    cin >> shade;
    marker.setShade(shade);

    cout << "Is the marker refillable? (1 for Yes, 0 for No): ";
    cin >> refillable;
    marker.setRefillable(refillable);

    cout << "Does the marker have ink? (1 for Yes, 0 for No): ";
    cin >> inkStatus;
    marker.setInkStatus(inkStatus);

    marker.write();
    marker.refill();

    return 0;
}
