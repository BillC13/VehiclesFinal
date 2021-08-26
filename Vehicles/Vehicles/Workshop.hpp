#pragma once

#include "I_Vehicle.hpp"
#include "Car.hpp"
#include "Lorry.hpp"

namespace Vehicles
{
	class Workshop
	{
		std::shared_ptr<Vehicles::I_Vehicle> m_WorkingVehicle;

	public:
		Workshop();		// declare constructor  
		~Workshop();	// destructor

		void SetWorkingVehicle(std::shared_ptr<Vehicles::I_Vehicle>);
		void ChangeNumberOfDoors(int);
		void ChangeNumberOfWheels(int);
		void ReplaceWheels(double);

		bool WorkingVehicleIsLorry();
		bool WorkingVehicleIsCar();
	};
}
