// Header File for Gas Vehicle Derived Class.
#ifndef __GASVEHICLE_H__
#define __GASVEHICLE_H__
#include "Vehicle.h"

// New Class Gas Vehicle which uses Vehicle Class.
class GasVehicle: public Vehicle {
private:
	// Private variables are Fuel Capacity and Vehicle Efficiency, specifically for it being an gas vehicle.
	std::string FuelCapacity;
	std::string Efficiency;
public:
	// Two functions, one is an override one is a setter for the two variables.
	void setGasVehicle(std::string fuelCap, std::string Effic);
	std::string getVehicle() override;
};

#endif