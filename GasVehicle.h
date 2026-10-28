// Header File for Gas Vehicle Derived Class.
#ifndef __GASVEHICLE_H__
#define __GASVEHICLE_H__
#include "Vehicle.h"

// New Class Gas Vehicle which uses Vehicle Class.
class GasVehicle: public Vehicle {
public:
	// Two functions, one is an override one is a setter for the two variables.
	std::string getVehicle() override;
};

#endif