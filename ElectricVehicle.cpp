// Includes specific header.
#include "ElectricVehicle.h"

// Get Vehicle override, which uses Get Vehicle MMY to get the make, model, and year, then adds the specific variables,
// Fuel Capacity and Efficiency, then returns this as a big string.
std::string ElectricVehicle::getVehicle() {
	std::string reqVehicle = "Electric Vehicle - " + getVehicleMMY();
	return(reqVehicle);
}
