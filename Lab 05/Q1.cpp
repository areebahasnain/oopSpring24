/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class Square
{
public:
    float sideLength, area;
    static float allareas;

    Square(float sideLength = 0.0) : sideLength(sideLength) {}

    float calculateArea()
    {
        area = sideLength * sideLength;
        allareas += area;
        return area;
    }

    float getSideLength() { return sideLength; }
    void setSideLength(float side) { sideLength = side; }

    float getArea() { return area; }
    void setArea(float a) { area = a; }

    static float getAllAreas() { return allareas; }
    static void setAllAreas(float all) { allareas = all; }
};

float Square::allareas = 0.f;


int main() {
    Square sq1(2.0), sq2(4.0), sq3(6.0);

    sq1.calculateArea();
    cout << "Area of square 1: " << sq1.getArea() << endl << "Total area of all squares: " << sq1.getAllAreas() << "\n" << endl;
    sq2.calculateArea();
    cout << "Area of square 2: " << sq2.getArea() << endl << "Total area of all squares: " << sq2.getAllAreas() << "\n" << endl;
    sq3.calculateArea();
    cout << "Area of square 3: " << sq3.getArea() << endl << "Total area of all squares: " << sq3.getAllAreas() << "\n";

    return 0;
}
