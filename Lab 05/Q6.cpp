/* K230059 - AREEBA HASNAIN SHAIKH */

#include <iostream>

using namespace std;

class GraphicsRenderer {
public:
    void render() {
        cout << "Rendering graphics..." << endl;
    }
};

class InputHandler {
public:
    void handleInput() {
        cout << "Handling input..." << endl;
    }
};

class PhysicsEngine {
public:
    void updatePhysics() {
        cout << "Updating physics..." << endl;
    }
};

class GameEngine {
private:
    GraphicsRenderer graphicsRenderer;
    InputHandler inputHandler;
    PhysicsEngine physicsEngine;
public:
    void run() {
            inputHandler.handleInput();
            physicsEngine.updatePhysics();
            graphicsRenderer.render();
    }
};

int main() {
    GameEngine gameEngine;
    gameEngine.run();

    return 0;
}
