///////////////////////////////////////////////////////////////////////////////
// This program implements a rudimentary used car database.  It reads a text
// file that contains the list of cars in the database.  Each line of the file
// represents a single vehicle where there are six fields: Make, Model, Year,
// Engine Type (ICE or EV), Fuel/Energy Capacity, and mileage efficiency.
// The user is allowed to query the database to see the list of vehicles that
// match their search criteria.
///////////////////////////////////////////////////////////////////////////////
#include "GasVehicle.h"
#include "ElectricVehicle.h"
#include "Database.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char* argv[])
{
    // The inventory file
    std::ifstream InFile;
    // The string for each line of the inventory file
    std::string Line;
    // Clears Database
    Database::~Database();
    // Open the output file
    InFile.open("Inventory.txt");
    // Contingency for if file cannot open.
    if (!InFile.is_open())
    {
        std::cout << "Error! Inventory file could not be opened." << std::endl;
        return -1;
    } // if()

  // Read the contents of the file one line at a time
    int NumVehicles = 0;
    while (getline(InFile, Line))
    {
        // String stream for parsing words from the line
        std::istringstream Record(Line);
        // String to hold the parsed field
        std::string Field;
        // Strings to hold the individual fields
        std::string Make, Model, EngineType, Color, Year;

        // Get the strings from the line
        int FieldCount = 0;
        while (Record >> Field)
        {
            FieldCount++;
            switch (FieldCount)
            {
            case 1: { Make = Field; break; }
            case 2: { Model = Field; break; }
            case 3: { EngineType = Field; break; }
			case 4: { Color = Field; break; }
            case 5: { Year = Field; break; }
            } // switch()
        } // while()
        if (FieldCount != 5)
        {
            std::cout << "Error! Inventory file is malformed." << std::endl;
            std::cout << Line << std::endl;
            return -2;
        } // if()

      // Depending on the propulsion type, instantiate a GasCar or ElectricCar,
      //   populate the fields, and put it into the database array
        if (EngineType == "ICE")
        {
            // Instantiate a gas propulsion car object
            GasVehicle* pGasVehicle = new GasVehicle;
            // Set the field
            pGasVehicle->setVehicle(Make, Model, Color, Year);
            // Insert the gas car into the database at current position
            Database::addVehicle(pGasVehicle);
        } // if()
        else if (EngineType == "EV")
        {
            // Instantiate an electric Propulsion car object
            ElectricVehicle* pEVehicle = new ElectricVehicle;
            // Set the field
            pEVehicle->setVehicle(Make, Model, Color, Year);
            // Insert the Electric car into the database at current position
			Database::addVehicle(pEVehicle);
        } // if...if...else()
        else
        {
            std::cout << "Error! Unrecognized propulsion type." << std::endl;
            return -3;
        } // if...else()

       // Increment the running counter of the cars in the inventory
        NumVehicles++;
    } // while()

    bool ExitRequested = false;
    while (ExitRequested == false) {
        char Command;
        // Prompt the user for the program option (search by Make, Model, Year, or
        //   or exit the program)
        std::cout << "Enter Command (? for help) > ";
        std::cin >> Command;

        // Process the command
        switch (Command)
        {
        case '?': // Help screen
        {
            std::cout << " ? = Display Help" << std::endl;
            std::cout << " A = Search by Make" << std::endl;
            std::cout << " O = Search by Model" << std::endl;
            std::cout << " Y = Search by Year" << std::endl;
            std::cout << " I = Display Inventory" << std::endl;
            std::cout << " R = Print Cars with Reservations" << std::endl;
            std::cout << " N = Print Cars without Reservations" << std::endl;
            std::cout << " Q = Quit / Exit the program" << std::endl;
            break;
        } // Case '?'
        case 'a': case 'A': // Search by Make
        {
            // Prompt the user for the search criteria
            std::string DesiredMake;
            std::cout << "Enter Make > ";
            std::cin >> DesiredMake;
            std::cout << "\n";
            // Search the database
            // Int to keep track of number of matches
            int match = 0;
            for (int i = 0; i < DatabaseSize; i++) {
                if (Database[i]->getVehicleMa() == DesiredMake) {
                    // Print out matching entries
                    std::cout << Database[i]->getVehicle() << "\n";
                    match++;
                }
            }
            // If no matches are found, say so.
            if (match == 0) {
                std::cout << "No Matching Makes\n";
            }
            std::cout << "\n";
            break;
        } // case 'a' or 'A'
        case 'o': case 'O': // Search by Model
        {
            // Prompt the user for the search criteria
            std::string DesiredModel;
            std::cout << "Enter Model > ";
            std::cin >> DesiredModel;
            std::cout << "\n";
            // Search the database
            // Int to keep track of number of matches
            int match = 0;
            for (int i = 0; i < DatabaseSize; i++) {
                if (Database[i]->getVehicleMo() == DesiredModel) {
                    // Print out matching entries
                    std::cout << Database[i]->getVehicle() << "\n";
                    match++;
                }
            }
            // If no matches are found, say so.
            if (match == 0) {
                std::cout << "No Matching Models\n";
            }
            std::cout << "\n";
            break;
        } // case 'o' or 'O'
        case 'y': case 'Y': // Search by Year
        {
            // Prompt the user for the search criteria
            int DesiredYear;
            std::cout << "Enter Year > ";
            std::cin >> DesiredYear;
            std::cout << "\n";
            // Search the database
            // Int to keep track of number of matches
            int match = 0;
            for (int i = 0; i < DatabaseSize; i++) {
                if (Database[i]->getVehicleY() == DesiredYear) {
                    // Print out matching entries
                    std::cout << Database[i]->getVehicle() << "\n";
                    match++;
                }
            }
            // If no matches are found, say so.
            if (match == 0) {
                std::cout << "No Matching Years\n";
            }
            std::cout << "\n";
            break;
        } // case 'y' or 'Y'
        case 'q': case 'Q': // Exit the program
        {
            ExitRequested = true;
            break;
        } // case 'q' or 'Q'
       // "otherwise" is not needed, any other command is ignored
        } // switch()

    } while (!ExitRequested);

    // No error possible
    return 0;
} // main()
