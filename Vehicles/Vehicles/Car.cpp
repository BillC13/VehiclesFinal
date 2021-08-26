#include <iostream>
#include "Car.hpp"

namespace Vehicles
{
	Car::Car(std::string name, int doors, double wheeldiameter)  //names for the parameters are NOT optional here
	{
		// hook up the name and number of doors to the private fields:
		m_name = name;
		m_doors = doors;

		// give the car 4 wheels:
		// we will add them to the m_wheels vector declared in I_Vehicle
		m_wheels.push_back(std::make_shared<Vehicles::Wheel>(wheeldiameter));  //create a wheel and add it to the vector of wheels
		m_wheels.push_back(std::make_shared<Vehicles::Wheel>(wheeldiameter));
		m_wheels.push_back(std::make_shared<Vehicles::Wheel>(wheeldiameter));
		m_wheels.push_back(std::make_shared<Vehicles::Wheel>(wheeldiameter));

		// give it a default size
		m_length = 4000;
		m_width  = 2000;
		m_height = 1300;
	}

	Car::~Car()
	{
		// destructor, just for fun.  // This will run automatically when the program ends.
		std::cout << m_name + " was sold to WeBuyAnyCar!" << std::endl;
	}

	std::string Car::VehicleReport()
	{
		// this is just declaring a string then sequentially adding more to it:

		std::string report = "This car is: " + m_name + "\n";
		report += "  Length: " + std::to_string(m_length) + "\n";
		report += "  Width:  " + std::to_string(m_width) + "\n";
		report += "  Height: " + std::to_string(m_height) + "\n";
		report += "  Number of doors: " + std::to_string(m_doors) + "\n";
		report += "  Number of wheels: " + std::to_string(m_wheels.size()) + "\n";
		for (unsigned int i = 0; i < m_wheels.size(); i++)
		{
			report += "  #" + std::to_string(i + 1) + ": " + m_wheels[i]->WheelReport();
		}

		return report;
	}
	void Car::SetNumDoors(int newNumDoors)
	{
		m_doors = newNumDoors;
	}
}