// ================================================================
// Lab: Inheritance in C++
// Course: Object-Oriented Programming for Engineers
// File: MainProgram.cpp
// ================================================================
// INSTRUCTIONS:
//   Complete every TODO. Do NOT change function signatures.
//   All code stays in this single file. No .h files allowed.
// ================================================================

#include <iostream>
#include <string>

// ================================================================
// CLASS DEFINITIONS
// ================================================================

// ----------------------------------------------------------------
// Base Class: Vehicle
// ----------------------------------------------------------------
// Represents a generic vehicle.
// Data members (protected):
//   - make       (std::string)  : e.g. "Toyota"
//   - year       (int)          : e.g. 2020
//   - fuelLevel  (double)       : 0.0 - 100.0 (percentage)
//
// Methods:
//   - Constructor(make, year, fuelLevel)
//   - getMake()       -> std::string  (const)
//   - getYear()       -> int          (const)
//   - getFuelLevel()  -> double       (const)
//   - refuel(amount)  -> void         : adds amount to fuelLevel,
//                                       clamps max to 100.0
//   - describe()      -> std::string  : pure virtual
//   - virtual destructor
// ----------------------------------------------------------------

class Vehicle {
protected:
    // TODO: declare protected data members
    //       std::string make
    //       int year
    //       double fuelLevel

public:
    // TODO: declare constructor
    //       Vehicle(std::string make, int year, double fuelLevel)

    // TODO: declare getters (const)
    //       getMake(), getYear(), getFuelLevel()

    // TODO: declare refuel(double amount)
    //       Adds amount to fuelLevel. Max is 100.0. Ignore negative amounts.

    // TODO: declare pure virtual describe() returning std::string

    // TODO: declare virtual destructor
};

// ----------------------------------------------------------------
// Derived Class: Car
// ----------------------------------------------------------------
// Inherits from Vehicle.
// Additional data (private):
//   - numDoors (int)
//
// Methods:
//   - Constructor(make, year, fuelLevel, numDoors)
//     -> must call Vehicle constructor
//   - getNumDoors() -> int (const)
//   - describe()    -> std::string (override)
//     Format: "Car: <make> (<year>), <numDoors> doors, fuel: <fuelLevel>%"
//     Example: "Car: Toyota (2020), 4 doors, fuel: 75.5%"
// ----------------------------------------------------------------

class Car : public Vehicle {
private:
    // TODO: int numDoors

public:
    // TODO: Constructor(make, year, fuelLevel, numDoors)

    // TODO: getNumDoors()

    // TODO: describe() override
};

// ----------------------------------------------------------------
// Derived Class: Truck
// ----------------------------------------------------------------
// Inherits from Vehicle.
// Additional data (private):
//   - payloadTons (double)   : cargo capacity in tons
//
// Methods:
//   - Constructor(make, year, fuelLevel, payloadTons)
//     -> must call Vehicle constructor
//   - getPayloadTons() -> double (const)
//   - describe()       -> std::string (override)
//     Format: "Truck: <make> (<year>), payload: <payloadTons>t, fuel: <fuelLevel>%"
//     Example: "Truck: Ford (2018), payload: 5.5t, fuel: 60%"
// ----------------------------------------------------------------

class Truck : public Vehicle {
private:
    // TODO: double payloadTons

public:
    // TODO: Constructor(make, year, fuelLevel, payloadTons)

    // TODO: getPayloadTons()

    // TODO: describe() override
};

// ================================================================
// FUNCTION IMPLEMENTATIONS
// ================================================================

// ----------------------------------------------------------------
// Vehicle member function implementations
// ----------------------------------------------------------------

// TODO: Implement Vehicle constructor

// TODO: Implement getMake(), getYear(), getFuelLevel()

// TODO: Implement refuel(double amount)
//       Rules:
//         - Ignore if amount <= 0
//         - fuelLevel += amount
//         - If fuelLevel > 100.0, clamp to 100.0

// ----------------------------------------------------------------
// Car member function implementations
// ----------------------------------------------------------------

// TODO: Implement Car constructor (chain to Vehicle)

// TODO: Implement getNumDoors()

// TODO: Implement describe()
//       Hint: use std::ostringstream for formatted decimal output

// ----------------------------------------------------------------
// Truck member function implementations
// ----------------------------------------------------------------

// TODO: Implement Truck constructor (chain to Vehicle)

// TODO: Implement getPayloadTons()

// TODO: Implement describe()

// ================================================================
// MAIN
// ================================================================

int main() {
    // --- Basic usage demo ---
    Car   c("Toyota", 2020, 75.5, 4);
    Truck t("Ford",   2018, 60.0, 5.5);

    std::cout << c.describe() << "\n";
    std::cout << t.describe() << "\n";

    // Polymorphism via base pointer
    Vehicle* v1 = &c;
    Vehicle* v2 = &t;
    std::cout << v1->describe() << "\n";
    std::cout << v2->describe() << "\n";

    // Refuel demo
    c.refuel(20.0);
    std::cout << "After refuel: " << c.getFuelLevel() << "%\n";

    return 0;
}
