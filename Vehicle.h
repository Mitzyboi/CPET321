// Header File for Vehicle Base Class.
#ifndef __VEHICLE_H__
#define __VEHICLE_H__
#include <iostream>
#include <string>
#include <vector>

// New Class Vehicle
class Vehicle {
	// Private variables for the Make, Model, and year for the vehicle.
private:
	std::string Make;
	std::string Model;
	std::string Year;
public:
	// Setter for the variables, then a function to get Make, Model, and Year, then all three seperately,
	// then a virtual for the other classes to inheret and override.
	void setVehicle(std::string M, std::string Mod, std::string Y);
	std::string getVehicleMMY();
	std::string getVehicleMa();
	std::string getVehicleMo();
	int getVehicleY();
	virtual std::string getVehicle(void) = 0;
};

#endif