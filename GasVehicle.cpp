// Includes specific header.
#include "GasVehicle.h"

// Get Vehicle override, which uses Get Vehicle MMCY to get the make, model, color, and year, then adds propulsion type.
std::string GasVehicle::getVehicle() {
	std::string reqVehicle = "Gas Vehicle - " + getVehicleMMCY();
	return(reqVehicle);
}
