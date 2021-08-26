#pragma once
#include "I_Vehicle.hpp"


namespace Vehicles
{
	class Car : public I_Vehicle
	{
	public:
		Car(std::string, int, double);	// prototype for declaring cars (notice names for the parameters are optional here)
		~Car();							// I'll also provide a destructor for when we dont need the car any more.
		std::string VehicleReport();	// VehicleReport required by I_Vehicle
		void SetNumDoors(int);
	};
}

