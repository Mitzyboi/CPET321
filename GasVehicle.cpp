// Includes specific header.
#include "GasVehicle.h"

// Setter for Electric Vehicles, passes through Fuel Capacity and Efficiency.
void GasVehicle::setGasVehicle(std::string fuelCap, std::string Effic) {
	FuelCapacity = fuelCap;
	Efficiency = Effic;
	return;
}

// Get Vehicle override, which uses Get Vehicle MMY to get the make, model, and year, then adds the specific variables,
// Fuel Capacity and Efficiency, then returns this as a big string.
std::string GasVehicle::getVehicle() {
	std::string reqVehicle = "Gas Vehicle - " + getVehicleMMY() + " " + FuelCapacity + "gal " + Efficiency + "mpg";
	return(reqVehicle);
}
