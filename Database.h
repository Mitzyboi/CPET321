// Christopher Valerio 10/11/26 (NOT TESTED) (NOT INTEGRATED)
// Header File for Database Class.
#ifndef __DATABASE_H__
#define __DATABASE_H__
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include "Vehicle.h"

// Holds every vehicle in the inventory and tracks which days each one is reserved.
class Database {
private:
    std::vector<Vehicle*> vehicles;            // owned by the Database
    std::map<int, std::set<int> > reservations; // vehicle index
    int currentDay;

    void printVehicleLine(int index);
    static bool contains(const std::string& field, const std::string& key);
public:
    Database();
    ~Database();

    // Inventory: Database takes ownership (use new GasVehicle / new ElectricVehicle).
    void addVehicle(Vehicle* v);
    int getVehicleCount() const;

    // search. Empty string = "don't care". propulsion is "gas" or "electric".
    std::vector<int> search(std::string make, std::string model, std::string propulsion,
        std::string color, std::string year);

    // reservations (future days only, max 3 days total per vehicle). Returns true on success.
    bool reserve(int vehicleIndex, const std::vector<int>& days);

    // print all the listings.
    void printInventory();
    void printReserved();
    void printAvailable();

    // Used to advance the date by 1
    void advanceDay();
    int getCurrentDay() const;

    bool hasReservation(int vehicleIndex) const;
};

#endif