// Includes specific header.
#include "ElectricVehicle.h"

// Setter for Electric Vehicles, passes through Fuel Capacity and Efficiency.
void ElectricVehicle::setEVehicle(std::string ECap, std::string Effic) {
	EnergyCapacity = ECap;
	Efficiency = Effic;
	return;
}

// Get Vehicle override, which uses Get Vehicle MMY to get the make, model, and year, then adds the specific variables,
// Fuel Capacity and Efficiency, then returns this as a big string.
std::string ElectricVehicle::getVehicle() {
	std::string reqVehicle = "Electric Vehicle - " + getVehicleMMY() + " " + EnergyCapacity + "kWh " + Efficiency + "mpkWh";
	return(reqVehicle);
}
