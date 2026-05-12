// ================================================================
// Lab: Inheritance in C++
// Course: Object-Oriented Programming for Engineers
// File: MainProgram.cpp
// ================================================================

#include <iostream>
#include <string>
#include <sstream>

// ================================================================
// CLASS DEFINITIONS
// ================================================================

// ----------------------------------------------------------------
// Base Class: Vehicle
// ----------------------------------------------------------------

class Vehicle {
protected:
 std::string make;
 int year;
 double fuelLevel;

public:
 // Constructor
 Vehicle(std::string make, int year, double fuelLevel);

 // Getters
 std::string getMake() const;
 int getYear() const;
 double getFuelLevel() const;

 // Refuel function
 void refuel(double amount);

 // Pure virtual function
 virtual std::string describe() const = 0;

 // Virtual destructor
 virtual ~Vehicle() {}
};

// ----------------------------------------------------------------
// Derived Class: Car
// ----------------------------------------------------------------

class Car : public Vehicle {
private:
 int numDoors;

public:
 // Constructor
 Car(std::string make, int year, double fuelLevel, int numDoors);

 // Getter
 int getNumDoors() const;

 // Override describe
 std::string describe() const override;
};

// ----------------------------------------------------------------
// Derived Class: Truck
// ----------------------------------------------------------------

class Truck : public Vehicle {
private:
 double payloadTons;

public:
 // Constructor
 Truck(std::string make, int year, double fuelLevel, double payloadTons);

 // Getter
 double getPayloadTons() const;

 // Override describe
 std::string describe() const override;
};

// ================================================================
// FUNCTION IMPLEMENTATIONS
// ================================================================

// ----------------------------------------------------------------
// Vehicle member function implementations
// ----------------------------------------------------------------

Vehicle::Vehicle(std::string make, int year, double fuelLevel)
 : make(make), year(year), fuelLevel(fuelLevel) {
}

std::string Vehicle::getMake() const {
 return make;
}

int Vehicle::getYear() const {
 return year;
}

double Vehicle::getFuelLevel() const {
 return fuelLevel;
}

void Vehicle::refuel(double amount) {
 if (amount <= 0) {
 return;
 }

 fuelLevel += amount;

 if (fuelLevel > 100.0) {
 fuelLevel = 100.0;
 }
}

// ----------------------------------------------------------------
// Car member function implementations
// ----------------------------------------------------------------

Car::Car(std::string make, int year, double fuelLevel, int numDoors)
 : Vehicle(make, year, fuelLevel), numDoors(numDoors) {
}

int Car::getNumDoors() const {
 return numDoors;
}

std::string Car::describe() const {
 std::ostringstream out;
 out << "Car: " << make
<< " (" << year << "), "
<< numDoors << " doors, fuel: "
<< fuelLevel << "%";
 return out.str();
}

// ----------------------------------------------------------------
// Truck member function implementations
// ----------------------------------------------------------------

Truck::Truck(std::string make, int year, double fuelLevel, double payloadTons)
 : Vehicle(make, year, fuelLevel), payloadTons(payloadTons) {
}

double Truck::getPayloadTons() const {
 return payloadTons;
}

std::string Truck::describe() const {
 std::ostringstream out;
 out << "Truck: " << make
<< " (" << year << "), payload: "
<< payloadTons << "t, fuel: "
<< fuelLevel << "%";
 return out.str();
}

// ================================================================
// MAIN
// ================================================================

int main() {
 // --- Basic usage demo ---
 Car c("Toyota", 2020, 75.5, 4);
 Truck t("Ford", 2018, 60.0, 5.5);

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
