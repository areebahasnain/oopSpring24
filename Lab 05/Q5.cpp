/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class Engine
{
    int horsepower;
    string type;

public:
    Engine(int hp, string type) : horsepower(hp), type(type) {}
    int getHorsepower() const { return horsepower; }
    string getType() const { return type; }
};

class Wheels
{
    int numberOfWheels;
    string brand;

public:
    Wheels(int numberOfWheels, string brand) : numberOfWheels(numberOfWheels), brand(brand) {}
    int getNumberOfWheels() const { return numberOfWheels; }
    string getBrand() const { return brand; }
}; 

class Headlights
{
    string typeoflights;

public:
    Headlights(string lights) : typeoflights(lights) {}
    string getTypeOfLights() const { return typeoflights; }
};

class Steering
{
    string steeringmode;

public:
    Steering(string mode) : steeringmode(mode) {}
    string getMode() const { return steeringmode; }
}; 

class Car
{
    Engine *engine;
    Wheels *wheels;
    Headlights *headlights[4]; 
    Steering *steering;

public:
    Car(Engine *eng, Wheels *w, Headlights *h[], Steering *st)
        : engine(eng), wheels(w), steering(st)
    {
        for (int i = 0; i < 4; i++)
        {
            headlights[i] = h[i];
        }
    } 

    ~Car()
    {
        delete engine;
        delete wheels;
        for (int i = 0; i < 4; i++)
        {
            delete headlights[i];
        }
        delete steering;
    } 

    void detailsOfCar()
    {
        cout << "Engine: " << engine->getHorsepower() << " " << engine->getType() << endl;
        cout << "Wheels: " << wheels->getNumberOfWheels() << " " << wheels->getBrand() << endl;
        for (int i = 0; i < 4; i++)
        {
            cout << "Headlight " << i + 1 << ": " << headlights[i]->getTypeOfLights() << endl;
        } 
        cout << "Steering: " << steering->getMode() << endl;
    } 
};   

int main()
{
    Engine *e1 = new Engine(2000, "V8");
    Wheels *w1 = new Wheels(4, "Bridgestone");
    Headlights* h1[4];
    for (int i = 0; i < 4; ++i) {
        h1[i] = new Headlights("LED");
    }
    Steering *s1 = new Steering("Power");

    Car car1(e1, w1, h1, s1);
    car1.detailsOfCar();

    return 0;
} 