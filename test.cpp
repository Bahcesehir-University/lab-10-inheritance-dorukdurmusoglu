// ================================================================
// test.cpp  -  Catch2 tests for Lab: Inheritance
// Sections (for partial grading):
//   [A] Vehicle base class & getters        (20 pts)
//   [B] Vehicle::refuel logic               (15 pts)
//   [C] Car - constructor & describe        (20 pts)
//   [D] Truck - constructor & describe      (20 pts)
//   [E] Polymorphism via base pointer       (25 pts)
// ================================================================

#define main student_main
#include "MainProgram.cpp"
#undef main

#include "catch_amalgamated.hpp"

#include <string>

using Catch::Approx;

// ================================================================
// [A] Vehicle Base Class & Getters  (20 pts)
// ================================================================

TEST_CASE("A1 - Car inherits Vehicle getters: getMake", "[A]") {
    Car c("Toyota", 2020, 50.0, 4);
    REQUIRE(c.getMake() == "Toyota");
}

TEST_CASE("A2 - Car inherits Vehicle getters: getYear", "[A]") {
    Car c("Honda", 2019, 30.0, 2);
    REQUIRE(c.getYear() == 2019);
}

TEST_CASE("A3 - Car inherits Vehicle getters: getFuelLevel", "[A]") {
    Car c("BMW", 2021, 88.0, 4);
    REQUIRE(c.getFuelLevel() == Approx(88.0));
}

TEST_CASE("A4 - Truck inherits Vehicle getters: getMake", "[A]") {
    Truck t("Ford", 2018, 60.0, 5.0);
    REQUIRE(t.getMake() == "Ford");
}

TEST_CASE("A5 - Truck inherits Vehicle getters: getYear", "[A]") {
    Truck t("Volvo", 2015, 40.0, 10.0);
    REQUIRE(t.getYear() == 2015);
}

TEST_CASE("A6 - Truck inherits Vehicle getters: getFuelLevel", "[A]") {
    Truck t("Volvo", 2015, 40.0, 10.0);
    REQUIRE(t.getFuelLevel() == Approx(40.0));
}

// ================================================================
// [B] Vehicle::refuel Logic  (15 pts)
// ================================================================

TEST_CASE("B1 - refuel adds fuel correctly", "[B]") {
    Car c("Toyota", 2020, 50.0, 4);
    c.refuel(20.0);
    REQUIRE(c.getFuelLevel() == Approx(70.0));
}

TEST_CASE("B2 - refuel clamps at 100.0 when overflow", "[B]") {
    Car c("Toyota", 2020, 90.0, 4);
    c.refuel(20.0);
    REQUIRE(c.getFuelLevel() == Approx(100.0));
}

TEST_CASE("B3 - refuel with exactly 0 has no effect", "[B]") {
    Car c("Toyota", 2020, 50.0, 4);
    c.refuel(0.0);
    REQUIRE(c.getFuelLevel() == Approx(50.0));
}

TEST_CASE("B4 - refuel with negative amount has no effect", "[B]") {
    Car c("Toyota", 2020, 50.0, 4);
    c.refuel(-10.0);
    REQUIRE(c.getFuelLevel() == Approx(50.0));
}

TEST_CASE("B5 - refuel to exactly 100.0 stays at 100", "[B]") {
    Car c("Toyota", 2020, 60.0, 4);
    c.refuel(40.0);
    REQUIRE(c.getFuelLevel() == Approx(100.0));
}

TEST_CASE("B6 - refuel works on Truck too", "[B]") {
    Truck t("Ford", 2018, 55.0, 5.0);
    t.refuel(10.0);
    REQUIRE(t.getFuelLevel() == Approx(65.0));
}

// ================================================================
// [C] Car - Constructor & describe  (20 pts)
// ================================================================

TEST_CASE("C1 - Car::getNumDoors returns correct value", "[C]") {
    Car c("Toyota", 2020, 50.0, 4);
    REQUIRE(c.getNumDoors() == 4);
}

TEST_CASE("C2 - Car::getNumDoors with 2 doors", "[C]") {
    Car c("Mazda", 2022, 80.0, 2);
    REQUIRE(c.getNumDoors() == 2);
}

TEST_CASE("C3 - Car::describe contains make", "[C]") {
    Car c("Toyota", 2020, 75.5, 4);
    std::string d = c.describe();
    REQUIRE(d.find("Toyota") != std::string::npos);
}

TEST_CASE("C4 - Car::describe contains year", "[C]") {
    Car c("Toyota", 2020, 75.5, 4);
    std::string d = c.describe();
    REQUIRE(d.find("2020") != std::string::npos);
}

TEST_CASE("C5 - Car::describe contains door count", "[C]") {
    Car c("Toyota", 2020, 75.5, 4);
    std::string d = c.describe();
    REQUIRE(d.find("4") != std::string::npos);
}

TEST_CASE("C6 - Car::describe contains fuel level", "[C]") {
    Car c("Toyota", 2020, 75.5, 4);
    std::string d = c.describe();
    REQUIRE(d.find("75.5") != std::string::npos);
}

TEST_CASE("C7 - Car::describe has expected full format", "[C]") {
    Car c("Toyota", 2020, 75.5, 4);
    std::string d = c.describe();
    REQUIRE(d.find("Car")   != std::string::npos);
    REQUIRE(d.find("Toyota") != std::string::npos);
    REQUIRE(d.find("2020")   != std::string::npos);
    REQUIRE(d.find("doors")  != std::string::npos);
    REQUIRE(d.find("fuel")   != std::string::npos);
}

// ================================================================
// [D] Truck - Constructor & describe  (20 pts)
// ================================================================

TEST_CASE("D1 - Truck::getPayloadTons returns correct value", "[D]") {
    Truck t("Ford", 2018, 60.0, 5.5);
    REQUIRE(t.getPayloadTons() == Approx(5.5));
}

TEST_CASE("D2 - Truck::getPayloadTons with large payload", "[D]") {
    Truck t("Volvo", 2015, 40.0, 20.0);
    REQUIRE(t.getPayloadTons() == Approx(20.0));
}

TEST_CASE("D3 - Truck::describe contains make", "[D]") {
    Truck t("Ford", 2018, 60.0, 5.5);
    std::string d = t.describe();
    REQUIRE(d.find("Ford") != std::string::npos);
}

TEST_CASE("D4 - Truck::describe contains year", "[D]") {
    Truck t("Ford", 2018, 60.0, 5.5);
    std::string d = t.describe();
    REQUIRE(d.find("2018") != std::string::npos);
}

TEST_CASE("D5 - Truck::describe contains payload", "[D]") {
    Truck t("Ford", 2018, 60.0, 5.5);
    std::string d = t.describe();
    REQUIRE(d.find("5.5") != std::string::npos);
}

TEST_CASE("D6 - Truck::describe contains fuel level", "[D]") {
    Truck t("Ford", 2018, 60.0, 5.5);
    std::string d = t.describe();
    REQUIRE(d.find("60") != std::string::npos);
}

TEST_CASE("D7 - Truck::describe has expected full format", "[D]") {
    Truck t("Ford", 2018, 60.0, 5.5);
    std::string d = t.describe();
    REQUIRE(d.find("Truck")   != std::string::npos);
    REQUIRE(d.find("Ford")    != std::string::npos);
    REQUIRE(d.find("2018")    != std::string::npos);
    REQUIRE(d.find("payload") != std::string::npos);
    REQUIRE(d.find("fuel")    != std::string::npos);
}

// ================================================================
// [E] Polymorphism via Base Pointer  (25 pts)
// ================================================================

TEST_CASE("E1 - Base pointer to Car calls Car::describe", "[E]") {
    Car c("Toyota", 2020, 75.5, 4);
    Vehicle* v = &c;
    std::string d = v->describe();
    REQUIRE(d.find("Car")    != std::string::npos);
    REQUIRE(d.find("Toyota") != std::string::npos);
}

TEST_CASE("E2 - Base pointer to Truck calls Truck::describe", "[E]") {
    Truck t("Ford", 2018, 60.0, 5.5);
    Vehicle* v = &t;
    std::string d = v->describe();
    REQUIRE(d.find("Truck") != std::string::npos);
    REQUIRE(d.find("Ford")  != std::string::npos);
}

TEST_CASE("E3 - Base pointer refuel updates derived object", "[E]") {
    Car c("Toyota", 2020, 50.0, 4);
    Vehicle* v = &c;
    v->refuel(30.0);
    REQUIRE(v->getFuelLevel() == Approx(80.0));
}

TEST_CASE("E4 - Base pointer refuel clamps on derived object", "[E]") {
    Truck t("Ford", 2018, 90.0, 5.0);
    Vehicle* v = &t;
    v->refuel(50.0);
    REQUIRE(v->getFuelLevel() == Approx(100.0));
}

TEST_CASE("E5 - Two base pointers, each dispatches correct describe", "[E]") {
    Car   c("Honda",  2021, 55.0, 2);
    Truck t("Scania", 2017, 45.0, 15.0);

    Vehicle* vCar   = &c;
    Vehicle* vTruck = &t;

    REQUIRE(vCar->describe().find("Car")     != std::string::npos);
    REQUIRE(vTruck->describe().find("Truck") != std::string::npos);
}

TEST_CASE("E6 - Polymorphism does not mix up Car data with Truck", "[E]") {
    Car   c("Honda",  2021, 55.0, 2);
    Truck t("Scania", 2017, 45.0, 15.0);

    Vehicle* vCar   = &c;
    Vehicle* vTruck = &t;

    REQUIRE(vCar->describe().find("Truck") == std::string::npos);
    REQUIRE(vTruck->describe().find("Car") == std::string::npos);
}
