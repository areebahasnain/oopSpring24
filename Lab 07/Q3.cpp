/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class Position {
public:
    float x, y, z;

    Position(float x, float y, float z) : x(x), y(y), z(z) {}
};

class Health {
public:
    int health;

    Health(int h) : health(h) {}
};

class Character : public Position, public Health {
public:
    string name;

    Character(string name, float x, float y, float z, int health) : Position(x, y, z), Health(health), name(name) {}

    void move(int dx, int dy, int dz) {
        x += dx, y += dy, z += dz;
    }

    void takeDamage(int damage) {
        health -= damage;
        if (health < 0)
            health = 0;
    }
    void heal(int amount) {
        health += amount;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Position: (" << x << ", " << y << ", " << z << ")" << endl;
        cout << "Health: " << health << endl;
    }
};

int main() {
    Character player("Player", 0.0f, 0.0f, 0.0f, 100);

    player.move(10, 5, -3);
    player.takeDamage(20);
    player.heal(10);
    player.display();

    return 0;
}
