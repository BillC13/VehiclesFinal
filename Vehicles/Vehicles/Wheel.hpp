#pragma once
#include <string>

namespace Vehicles
{
	class Wheel
	{
		
	public:
		Wheel(double diameter);		// declare constructor (you must provide a diameter to create a wheel)
		~Wheel();					// declare a destructor
		std::string WheelReport();  // declare a function that will tell us about the wheel
		double GetWheelDiameter() { return m_diameter; }
	private:
		double m_diameter;			// declare a private variable to contain the diameter
	};

}