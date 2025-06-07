#include <iostream>
using namespace std;
class Engine {
    int horsepower;  
public:
    Engine(int hp) {  
        horsepower = hp;
        cout << "Engine created with " << horsepower << " HP." << endl;  }
Engine() {} 
    void start() {
        cout << "Engine with " << horsepower << " HP started." << endl;
    }

    ~Engine() {
        cout << "Engine destroyed." << endl;
    }
};

class Car {
    Engine engine;  // Composition: Car "owns" Engine
public:
    Car(int hp) : engine(hp) {  // Initialize Engine with horsepower
        cout << "Car created." << endl;
    }
    Car(){
	}

    void drive() {
        engine.start();
        cout << "Car is driving." << endl; 
    }

    ~Car() {
        cout << "Car destroyed." << endl;
    }
};

int main() {
	Car c1;
    Car car(200);  // Pass horsepower to Car, which passes it to Engine
    car.drive();
    return 0;
}

