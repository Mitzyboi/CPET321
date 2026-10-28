// Includes specific header.
#include "GasVehicle.h"

// Get Vehicle override, which uses Get Vehicle MMY to get the make, model, and year, then adds the specific variables,
// Fuel Capacity and Efficiency, then returns this as a big string.
std::string GasVehicle::getVehicle() {
	std::string reqVehicle = "Gas Vehicle - " + getVehicleMMY();
	return(reqVehicle);
}
