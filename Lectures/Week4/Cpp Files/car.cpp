#include <iostream>
using namespace std;
class Engine {
public:
    Engine() {
        cout << "Engine created." << endl;
    }
    void start() {
        cout << "Engine started." << endl;
    }
    ~Engine() {
        cout << "Engine destroyed." << endl;
    }
};


class Car {
    Engine engine;  // Composition: Car "owns" Engine
public:
    Car() {
        cout << "Car created." << endl;
    }
    void drive() {
        engine.start();
        cout << "Car is driving." << endl; }
    ~Car() {
        cout << "Car destroyed." << endl;
    }
};
int main() {
    Car car;
    car.drive();
    return 0;}


