#include <iostream>
#include <fstream>
using namespace std;

class A {
private:
    int id;
    char name[40];
    int age;
    float height;
    char gender;

public:
    void putdata();
    void getdata();
    void savedata();
    void readdata();
    void searchById(int);
    void deleteById(int);
    void updateById(int);
    int getId() const { return id; }
};

// Input data
void A::putdata() {
    cout << "Enter unique ID: ";
    cin >> id;
    cin.ignore(); // flush newline
    cout << "Enter name: ";
    cin.getline(name, 40);
    cout << "Enter age: ";
    cin >> age;
    cout << "Enter height: ";
    cin >> height;
    cout << "Enter gender: ";
    cin >> gender;
}

// Display data
void A::getdata() {
    cout << "ID: " << id << "\n";
    cout << "Name: " << name << "\n";
    cout << "Age: " << age << "\n";
    cout << "Height: " << height << "\n";
    cout << "Gender: " << gender << "\n";
}

// Save record
void A::savedata() {
    ofstream out("File9.txt", ios::binary | ios::app);
    out.write((char*)this, sizeof(*this));
    out.close();
    cout << "Record saved.\n";
}

// Show all records
void A::readdata() {
    ifstream in("File9.txt", ios::binary);
    A temp;
    cout << "\nAll records:\n";
    while (in.read((char*)&temp, sizeof(temp))) {
        temp.getdata();
        cout << "-----------------\n";
    }
    in.close();
}

// Search by ID
void A::searchById(int searchId) {
    ifstream in("File9.txt", ios::binary);
    A temp;
    bool found = false;
    while (in.read((char*)&temp, sizeof(temp))) {
        if (temp.getId() == searchId) {
            cout << "Record found:\n";
            temp.getdata();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No record found with ID: " << searchId << "\n";
    }
    in.close();
}

// Delete by ID
void A::deleteById(int deleteId) {
    ifstream in("File9.txt", ios::binary);
    ofstream out("temp.txt", ios::binary);
    A temp;
    bool found = false;

    while (in.read((char*)&temp, sizeof(temp))) {
        if (temp.getId() != deleteId) {
            out.write((char*)&temp, sizeof(temp));
        } else {
            found = true;
        }
    }

    in.close();
    out.close();
    remove("File9.txt");
    rename("temp.txt", "File9.txt");

    if (found) {
        cout << "Record with ID " << deleteId << " deleted successfully.\n";
    } else {
        cout << "No record found with ID: " << deleteId << "\n";
    }
}

// Update by ID (simplified)
void A::updateById(int updateId) {
    fstream file("File9.txt", ios::binary | ios::in | ios::out);
    A temp;
    bool found = false;
    long pos;

    while (!found && file.read((char*)&temp, sizeof(temp))) {
        if (temp.getId() == updateId) {
            pos = file.tellg();
            pos -= sizeof(temp);
            file.seekp(pos);

            cout << "Record found:\n";
            temp.getdata();

            cout << "\nEnter new data:\n";
            temp.putdata();

            file.write((char*)&temp, sizeof(temp));
            cout << "Record updated successfully.\n";
            found = true;
        }
    }

    if (!found) {
        cout << "No record found with ID: " << updateId << "\n";
    }

    file.close();
}

// Main menu
int main() {
    A ob;
    int choice;
    int idInput;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Show All Records\n";
        cout << "3. Search by ID\n";
        cout << "4. Delete by ID\n";
        cout << "5. Update by ID\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            ob.putdata();
            ob.savedata();
            break;
        case 2:
            ob.readdata();
            break;
        case 3:
            cout << "Enter ID to search: ";
            cin >> idInput;
            ob.searchById(idInput);
            break;
        case 4:
            cout << "Enter ID to delete: ";
            cin >> idInput;
            ob.deleteById(idInput);
            break;
        case 5:
            cout << "Enter ID to update: ";
            cin >> idInput;
            ob.updateById(idInput);
            break;
        case 6:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 6);

    return 0;
}

