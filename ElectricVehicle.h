// Header File for Electric Vehicle Derived Class
#ifndef __ELECTRICVEHICLE_H__
#define __ELECTRICVEHICLE_H__
#include "Vehicle.h"

// New Class Electric Vehicle which uses Vehicle Class
class ElectricVehicle: public Vehicle {
// Private variables are Fuel Capacity and Vehicle Efficiency, specifically for it being an electric vehicle.
private:
	std::string EnergyCapacity;
	std::string Efficiency;
public:
	// Two functions, one is an override one is a setter for the two variables.
	void setEVehicle(std::string ECap, std::string Effic);
	std::string getVehicle() override;
};

#endif