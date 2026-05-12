# Lab: Inheritance in C++

**Course:** Object-Oriented Programming for Engineers
**Level:** 2nd Year Engineering
**Duration:** 40 minutes
**Topic:** Single-level inheritance, virtual functions, polymorphism

---

## Learning Objectives

After completing this lab you will be able to:
- Define a base class with protected members
- Derive a class using `public` inheritance
- Override `virtual` functions
- Use a base-class pointer to achieve runtime polymorphism
- Chain constructors from derived to base

---

## Prerequisites

- Struct vs class
- Basic class syntax (constructors, methods, access specifiers)
- Familiarity with `std::string` and `std::ostringstream`

---

## File Structure

```
lab_inheritance/
├── MainProgram.cpp          <- Your work goes here
├── MainProgram_SOLUTION.cpp <- Teacher solution (do not open until done)
├── test.cpp                 <- Do not modify
├── catch_amalgamated.hpp    <- Do not modify
├── catch_amalgamated.cpp    <- Do not modify
├── Makefile
├── README.md
├── explain.txt              <- Read BEFORE coding
└── explain.md               <- Deeper reference
```

---

## Instructions

### Step 1 - Read First
Open `explain.txt` before touching `MainProgram.cpp`. It takes 2 minutes and will save you time.

### Step 2 - Compile & Run (Main Program)
```bash
make
./main_program
```

### Step 3 - Run All Tests
```bash
make test
```

### Step 4 - Run Individual Sections (for partial grading)
```bash
make test_A       # Section A: Vehicle base class & getters   (20 pts)
make test_B       # Section B: refuel logic                   (15 pts)
make test_C       # Section C: Car constructor & describe()   (20 pts)
make test_D       # Section D: Truck constructor & describe() (20 pts)
make test_E       # Section E: Polymorphism via base pointer  (25 pts)
```

### Step 5 - Clean Build Artifacts
```bash
make clean
```

---

## Task Summary

| Task | What to implement |
|------|-------------------|
| `Vehicle` base class | Protected members, getters, `refuel()`, pure virtual `describe()` |
| `Car` derived class | `numDoors`, constructor chaining, `describe()` override |
| `Truck` derived class | `payloadTons`, constructor chaining, `describe()` override |
| Polymorphism | Works automatically once `virtual` is used correctly |

---

## Expected Output (./main_program)

```
Car: Toyota (2020), 4 doors, fuel: 75.5%
Truck: Ford (2018), payload: 5.5t, fuel: 60%
Car: Toyota (2020), 4 doors, fuel: 75.5%
Truck: Ford (2018), payload: 5.5t, fuel: 60%
After refuel: 95.5%
```

---

## Grading Breakdown

| Section | Topic                          | Points |
|---------|--------------------------------|--------|
| [A]     | Vehicle base class & getters   | 20     |
| [B]     | Vehicle::refuel logic          | 15     |
| [C]     | Car constructor & describe()   | 20     |
| [D]     | Truck constructor & describe() | 20     |
| [E]     | Polymorphism via base pointer  | 25     |
| **Total** |                              | **100** |

---

## Common Mistakes

| Mistake | Fix |
|---------|-----|
| Forgetting `virtual` on `describe()` | Polymorphism won't work — base version always called |
| Not calling `Vehicle(...)` in derived constructor | Base members left uninitialised |
| Missing `= 0` on pure virtual | Vehicle can be instantiated directly (unintended) |
| Forgetting `virtual ~Vehicle()` | Undefined behaviour when deleting via base pointer |
| Using `std::to_string` on double | Can produce messy decimals — use `ostringstream` instead |
| Adding `.h` files | Not allowed — everything must be in `MainProgram.cpp` |
| Forgetting `override` keyword | Works, but loses compiler safety net |

---

## Submission Instructions

1. Submit **only** `MainProgram.cpp`
2. Ensure it compiles cleanly with `make` (no errors, minimal warnings)
3. Ensure `make test` passes as many sections as possible
4. Do **not** rename the file

---

## Academic Integrity

Write your own code. Discussion of concepts is encouraged; sharing or copying implementations is not permitted. All submitted files will be checked for similarity.
