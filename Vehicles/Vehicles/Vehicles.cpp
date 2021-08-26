// Vehicles.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Modified by A. Cal 02/09/2020 with Lorry Class completed.
//             A. Cal 02/09/2020 addition of smart pointers

#include <iostream>
#include <memory>

#include "Car.hpp"
#include "Lorry.hpp"
#include "I_Vehicle.hpp"
#include "Workshop.hpp"

void runProgram();
struct Owner {
    Owner(std::string o_name, std::shared_ptr<Vehicles::Lorry>int_ptr) : int_ptr_(int_ptr),location(o_name) {
     }
    void get_info() {
        std::cout<< "Lorry from: " + location + " \n";
        std::cout << int_ptr_->VehicleReport() <<std::endl;

    }
private:
    std::shared_ptr<Vehicles::Lorry>int_ptr_;
    std::string location;
};

int main()
{
    runProgram();

    std::cout << "end of program" << std::endl;
}

void runProgram()
{
     // unique_ptr<Car> P1; 
    std::unique_ptr<Vehicles::Car> P1(new Vehicles::Car("Tony's Car", 4, 482.6));

    // report on the vehicles:
    std::cout << P1->VehicleReport() << std::endl;

    // free the pointer
    std::cout << "Resetting the Car pointer" << std::endl;
    P1.reset();

    

    // unique_ptr<Lorry> P2; 
    std::unique_ptr<Vehicles::Car> P2(new Vehicles::Car("David's car", 4, 609.6));
    P1 = move(P2);
    // report on the vehicles:
    std::cout << P1->VehicleReport() << std::endl;

 
    std::cout << "Resetting the Car pointer" << std::endl;
    P1.reset();

    //Let us create and share several pointers to a lorry - this method will prevent uncertainty about releasing memory
   
    std::shared_ptr<Vehicles::Lorry> P3 = std::make_shared<Vehicles::Lorry>("Tony", 6, 700.6);
    std::shared_ptr<Vehicles::Lorry> P4 = std::make_shared<Vehicles::Lorry>("David", 3, 50.6);

    //auto test = std::make_unique<Vehicles::Lorry>("David", 3, 50.6);

    Owner a("London",P3);
    a.get_info();
    Owner b("Corsham",P4);
    b.get_info();
    Owner c("Bath",P3);
    c.get_info();

    Vehicles::Workshop workshop;
    workshop.ChangeNumberOfDoors(2);
    workshop.ChangeNumberOfWheels(8);
    workshop.ReplaceWheels(300.0);
    // lines below commented out because it won't work with unique_ptr. Homework: Why?
    //workshop.SetWorkingVehicle(P2);
    //workshop.SetWorkingVehicle(std::dynamic_pointer_cast<Vehicles::I_Vehicle> (P2));

    workshop.SetWorkingVehicle(P3); // can accept a concrete class or an abstract one as below:
    workshop.ChangeNumberOfDoors(2);
    workshop.ChangeNumberOfWheels(8);
    workshop.ReplaceWheels(650.0);

    std::shared_ptr<Vehicles::Car> P5 = std::make_shared<Vehicles::Car>("Luke", 4, 500.0);
    workshop.SetWorkingVehicle(P5);
    workshop.ChangeNumberOfDoors(2);
    workshop.ChangeNumberOfWheels(8);
    workshop.ReplaceWheels(450.0);

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

