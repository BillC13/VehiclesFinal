#include "I_Vehicle.hpp"

void Vehicles::I_Vehicle::ReplaceWheels(double newWheelDiameter)
{
	int currentNumWheels = (int) m_wheels.size();
	if (currentNumWheels < 4)
	{
		std::cout << "Vehicle had missing wheels! Fitting 4 Wheels." << std::endl;
		currentNumWheels = 4;
	}

	m_wheels.clear();

	for (int i = 0; i < currentNumWheels; i++)
	{
		m_wheels.push_back(std::make_shared<Vehicles::Wheel>(newWheelDiameter)); //create a wheel and add it to the vector of wheels
	}
}
