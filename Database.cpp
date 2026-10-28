// Christopher Valerio 10/11/26 - 10/21/2026  (NOT TESTED) (NOT INTEGRATED)

// Includes specific headers.
#include "Database.h"
#include "GasVehicle.h"
#include "ElectricVehicle.h"
#include <algorithm>
#include <cctype>

// Started This section on 10/11/26 - 10/12/26

// Max days constant. 
static const int MAX_RESERVED_DAYS = 3;

// sets to day 1.
Database::Database() : currentDay(1) {}

// deletes every vehicle the Database owns.
Database::~Database() {
    for (size_t i = 0; i < vehicles.size(); i++)
        delete vehicles[i];
}

// Adds a vehicle to the inventory, its position in the vector is its vehicle number.
void Database::addVehicle(Vehicle* v) { vehicles.push_back(v); }
int Database::getVehicleCount() const { return (int)vehicles.size(); }
int Database::getCurrentDay() const { return currentDay; }

// Case-insensitive substring match, an empty key matches everything.
bool Database::contains(const std::string& field, const std::string& key) {
    if (key.empty()) return true;
    std::string f = field, k = key;
    std::transform(f.begin(), f.end(), f.begin(), ::tolower);
    std::transform(k.begin(), k.end(), k.begin(), ::tolower);
    return f.find(k) != std::string::npos;
}

//started  this section from 10/14/26 - 10/21/26

// Returns the vehicle numbers of every vehicle matching all the given fields, "" ignores a field.
std::vector<int> Database::search(std::string make, std::string model, std::string propulsion,
    std::string color, std::string year) {
    std::vector<int> results;
    for (size_t i = 0; i < vehicles.size(); i++) {
        Vehicle* v = vehicles[i];

        std::string prop = "unknown";
        if (dynamic_cast<GasVehicle*>(v) != nullptr) prop = "gas";
        else if (dynamic_cast<ElectricVehicle*>(v) != nullptr) prop = "electric";

        if (contains(v->getVehicleMa(), make) &&
            contains(v->getVehicleMo(), model) &&
            contains(prop, propulsion) &&
            contains(v->getVehicleC(), color) &&
            contains(std::to_string(v->getVehicleY()), year))
            results.push_back((int)i);
    }
    return results;
}

// Reserves the given future days for a vehicle, returns false if it breaks a rule (max 3 days, future only, no repeats).
bool Database::reserve(int vehicleIndex, const std::vector<int>& days) {
    if (vehicleIndex < 0 || vehicleIndex >= (int)vehicles.size()) return false;
    if (days.empty()) return false;

    std::set<int> requested(days.begin(), days.end());
    std::set<int>& existing = reservations[vehicleIndex];

    for (std::set<int>::iterator it = requested.begin(); it != requested.end(); ++it) {
        if (*it <= currentDay) return false;
        if (existing.count(*it)) return false;
    }
    if ((int)(existing.size() + requested.size()) > MAX_RESERVED_DAYS) return false;

    existing.insert(requested.begin(), requested.end());
    return true;
}

// Returns true if the vehicle has any reserved days that haven't passed yet.
bool Database::hasReservation(int vehicleIndex) const {
    std::map<int, std::set<int> >::const_iterator it = reservations.find(vehicleIndex);
    return it != reservations.end() && !it->second.empty();
}

// Prints one vehicle on one line with its color and reserved days (if any).
void Database::printVehicleLine(int index) {
    Vehicle* v = vehicles[index];
    std::cout << "  [" << index << "] " << v->getVehicle();
    if (!v->getVehicleC().empty()) std::cout << " " << v->getVehicleC();

    std::map<int, std::set<int> >::const_iterator it = reservations.find(index);
    if (it != reservations.end() && !it->second.empty()) {
        std::cout << "  (reserved days:";
        for (std::set<int>::const_iterator d = it->second.begin(); d != it->second.end(); ++d)
            std::cout << " " << *d;
        std::cout << ")";
    }
    std::cout << std::endl;
}

// Prints every vehicle in the inventory.
void Database::printInventory() {
    std::cout << "Inventory (" << vehicles.size() << " vehicles), today is day " << currentDay << ":" << std::endl;
    for (size_t i = 0; i < vehicles.size(); i++)
        printVehicleLine((int)i);
}

// Prints only the vehicles that have reservations in the future.
void Database::printReserved() {
    std::cout << "Vehicles with future reservations:" << std::endl;
    bool any = false;
    for (size_t i = 0; i < vehicles.size(); i++)
        if (hasReservation((int)i)) { printVehicleLine((int)i); any = true; }
    if (!any) std::cout << "  (none)" << std::endl;
}

// Prints vehicles that have no reservations at all nothing else.
void Database::printAvailable() {
    std::cout << "Vehicles without any reservations:" << std::endl;
    bool any = false;
    for (size_t i = 0; i < vehicles.size(); i++)
        if (!hasReservation((int)i)) { printVehicleLine((int)i); any = true; }
    if (!any) std::cout << "  (none)" << std::endl;
}

// Moves the date forward one day and removes any reservations for days that have ended,
// makes cars available again.
void Database::advanceDay() {
    currentDay++;
    for (std::map<int, std::set<int> >::iterator it = reservations.begin(); it != reservations.end(); ++it) {
        std::set<int>& s = it->second;
        s.erase(s.begin(), s.lower_bound(currentDay));
    }
}