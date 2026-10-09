// Includes specific header.
#include "Vehicle.h"

// Setter for the Make, Model, and Year that passes through inputted strings.
void Vehicle::setVehicle(std::string M, std::string Mod, std::string Y) {
	Make = M;
	Model = Mod;
	Year = Y;
	return;
}

// Getter for the Make, Model, and Year all at once, for use in derived classes.
std::string Vehicle::getVehicleMMY() {
	std::string MMY = Make + " " + Model + " " + Year;
	return(MMY);
}

// Gets Vehicle Make specifically.
std::string Vehicle::getVehicleMa() {
	return(Make);
}

// Gets Vehicle Model specifically.
std::string Vehicle::getVehicleMo() {
	return(Model);
}

// Gets Vehicle Year specifically.
int Vehicle::getVehicleY() {
	int Y = std::stoi(Year);
	return(Y);
}
