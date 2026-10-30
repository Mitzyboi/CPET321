// Toshiro Gibson 10/11/26 - 10/24/2026  (NOT TESTED) (NOT INTEGRATED)

// Includes specific header.
#include "Vehicle.h"

// Setter for the Make, Model, Color, and Year that passes through inputted strings.
void Vehicle::setVehicle(std::string M, std::string Mod, std::string Colour, std::string Y) {
	Make = M;
	Model = Mod;
	Color = Colour;
	Year = Y;
	return;
}

// Getter for the Make, Model, Color, and Year all at once, for use in derived classes.
std::string Vehicle::getVehicleMMCY() {
	std::string MMY = Make + " " + Model + " " + Color + " " + Year;
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

// Gets Vehicle Color specifically.
std::string Vehicle::getVehicleC() {
	return(Color);
}
