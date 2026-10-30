// Includes specific header.
#include "ElectricVehicle.h"

// Get Vehicle override, which uses Get Vehicle MMCY to get the make, model, color, and year, then adds propulsion type.
std::string ElectricVehicle::getVehicle() {
	std::string reqVehicle = "Electric Vehicle - " + getVehicleMMCY();
	return(reqVehicle);
}
