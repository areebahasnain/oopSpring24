#include <iostream>

using namespace std;

class WaterBottle {
private:
    string company, color;
    float waterCapacity, waterCapacity_1;
public:
    void setCompany(string comp) {
        company = comp;
    }
    void setColor(string clr) {
        color = clr;
    }
    void setWaterCapacity(float water) {
        waterCapacity = water / 1000;
        waterCapacity_1 = water;
    }
    string getCompany() {
        return company;
    }
    string getColor() {
        return color;
    }
    float getWaterCapacity() {
        return waterCapacity;
    }
    float getWaterCapacityMl() {
        return waterCapacity_1;
    }
};

int main()
{
    WaterBottle bottle;
    float water_in_ml;
    bottle.setCompany("Nestle");
    bottle.setColor("Blue");

    cout << "Enter amount of water consumed: ";
    cin >> water_in_ml;
    bottle.setWaterCapacity(water_in_ml);

    cout << "Drunk " << bottle.getWaterCapacity() << " L or " << bottle.getWaterCapacityMl() << " mL from a " << bottle.getColor() << " bottle of company " << bottle.getCompany() << endl;

    return 0;
}
