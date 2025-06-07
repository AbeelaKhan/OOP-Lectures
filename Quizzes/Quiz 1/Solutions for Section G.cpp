#include <iostream>
#include <string>

#define MAX_PLACES 10

using namespace std;

// Place Class to store information about a place
class Place {
private:
    string placeName;
    string visitDate;

public:
    Place() : placeName(""), visitDate("") {} // Default constructor
    Place(string name, string date) : placeName(name), visitDate(date) {}

    string getPlaceName() const { return placeName; }
    string getVisitDate() const { return visitDate; }

    void displayPlace() const {
        cout << "Visited: " << placeName << " on " << visitDate << endl;
    }
};

// Passport Class to manage visitor name and visited places
class Passport {
private:
    string visitorName;
    Place placesVisited[MAX_PLACES];
    int placesCount;

public:
    Passport(string name) : visitorName(name), placesCount(0) {}

    // Copy Constructor
    Passport(const Passport& other) {
        visitorName = other.visitorName;
        placesCount = other.placesCount;
        for (int i = 0; i < placesCount; ++i) {
            placesVisited[i] = other.placesVisited[i];
        }
    }

    void addPlace(const Place& place) {
        if (placesCount < MAX_PLACES) {
            placesVisited[placesCount++] = place;
        } else {
            cout << "Maximum places reached. Cannot add more places." << endl;
        }
    }

    void changeName(const string& newName) {
        visitorName = newName;
    }

    void displayTravelHistory() const {
        cout << "Travel History for " << visitorName << ":" << endl;
        for (int i = 0; i < placesCount; ++i) {
            placesVisited[i].displayPlace();
        }
    }
};

int main() {
    // Create a passport for Amira
    Passport amiraPassport("Amira");

    // Add places to the passport
    amiraPassport.addPlace(Place("Sky Dome", "2025-02-01"));
    amiraPassport.addPlace(Place("VR Cultural Museum", "2025-02-02"));

    // Display travel history
    amiraPassport.displayTravelHistory();

    // Create a duplicate passport using the copy constructor
    Passport amiraDuplicate = amiraPassport;
    cout << "\nDuplicate Passport Travel History:" << endl;
    amiraDuplicate.displayTravelHistory();

    // Change Amira's name after marriage
    amiraPassport.changeName("Amira Khan");

    // Display updated travel history
    cout << "\nUpdated Travel History after Name Change:" << endl;
    amiraPassport.displayTravelHistory();

    return 0;
}

