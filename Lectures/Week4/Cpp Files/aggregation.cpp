#include <iostream>
using namespace std;

class Address {
public:
    string city;
    string street;

    Address(string c, string s) {
        city = c;
        street = s;
        cout << "Address created: " << street << ", " << city << endl;
    }

    void display() {
        cout << "Address: " << street << ", " << city << endl;
    }

    ~Address() {
        cout << "Address destroyed: " << street << ", " << city << endl;
    }
};

class Employee {
    string name;
    Address* address;  // Aggregation: Address is not owned by Employee
public:
    Employee(string n, Address* addr) {
        name = n;
        address = addr;
        cout << "Employee created: " << name << endl;
    }

    void display() {
        cout << "Employee: " << name << " lives at ";
        address->display();
    }

    ~Employee() {
        cout << "Employee destroyed: " << name << endl;
    }
};

int main() {
    Address addr("New York", "5th Avenue");


{

    Employee emp1("Alice", &addr);
    Employee emp2("Bob", &addr);

    emp1.display();
    emp2.display();
	}
    
    addr.display();
    
    return 0;
}

