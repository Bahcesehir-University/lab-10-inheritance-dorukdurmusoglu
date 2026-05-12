# Inheritance in C++

## 1. Concept Overview

Inheritance is a mechanism where one class (**derived**) acquires the properties and behaviour of another class (**base**). The derived class can add new members and override existing behaviour.

In this lab:
- `Vehicle` is the **base class** — holds shared data: `make`, `year`, `fuelLevel`
- `Car` and `Truck` are **derived classes** — each adds its own data and implements `describe()`

The relationship is: *"A Car IS-A Vehicle"* — this is the hallmark of correct inheritance use.

---

## 2. Key Concepts

- **Base class** defines the common interface and shared data
- **Derived class** inherits via `class Derived : public Base`
- **Constructor chaining**: the derived constructor *must* call the base constructor explicitly in its initialiser list
- **`virtual` function**: tells the compiler "this method can be overridden in a subclass"
- **Pure virtual (`= 0`)**: makes the base class abstract — derived classes *must* override it
- **`override` keyword**: compiler-checked signal that you are intentionally overriding a base virtual method
- **`protected` access**: members visible inside the class itself and all derived classes, but not from outside
- **Polymorphism**: a `Vehicle*` pointer can hold a `Car` or `Truck` and call the correct `describe()` at runtime

---

## 3. Important Keywords

| Keyword | Meaning |
|---------|---------|
| `public` inheritance | Public and protected members of base remain accessible in derived |
| `protected` | Accessible inside the class and all subclasses, not from outside |
| `virtual` | Enables runtime dispatch (polymorphism) |
| `= 0` | Makes the function pure virtual; the whole class becomes abstract |
| `override` | Compiler verifies you are actually overriding a base virtual |
| `virtual ~Base()` | Virtual destructor — ensures correct cleanup when deleting via base pointer |
| initialiser list | `: Base(args), member(val)` — how constructors chain to the base |

---

## 4. Common Mistakes

| Mistake | Why it's wrong | Fix |
|---------|---------------|-----|
| No `virtual` on `describe()` | Base version always called, polymorphism silently broken | Add `virtual` |
| No `= 0` on base `describe()` | `Vehicle` can be instantiated directly (unintended) | Add `= 0` |
| Not chaining constructor | Base members uninitialised or default-constructed | Add `: Vehicle(make, year, fuelLevel)` |
| No `virtual` destructor | Deleting via `Vehicle*` causes undefined behaviour | `virtual ~Vehicle() = default;` |
| `private` instead of `protected` | Derived classes cannot access base data | Change to `protected` |
| Forgetting `override` | Works, but compiler cannot catch accidental signature mismatch | Always add `override` |
| Using `std::to_string(double)` | Can output excessive decimal places | Use `std::ostringstream` instead |

---

## 5. Mini Examples

### Basic inheritance and constructor chaining

```cpp
class Animal {
protected:
    std::string name;
public:
    Animal(std::string n) : name(n) {}
    virtual std::string sound() const = 0;
    virtual ~Animal() = default;
};

class Dog : public Animal {
public:
    Dog(std::string n) : Animal(n) {}       // chains to Animal
    std::string sound() const override {
        return name + " says: Woof!";
    }
};
```

### Polymorphism in action

```cpp
Animal* a = new Dog("Rex");
std::cout << a->sound();    // prints: Rex says: Woof!
delete a;                   // safe because destructor is virtual
```

### refuel-style clamping pattern

```cpp
void refuel(double amount) {
    if (amount <= 0) return;           // guard: ignore bad input
    fuelLevel += amount;
    if (fuelLevel > 100.0) fuelLevel = 100.0;  // clamp to max
}
```

### ostringstream for clean describe()

```cpp
#include <sstream>

std::string describe() const {
    std::ostringstream oss;
    oss << "Car: " << make << " (" << year << "), "
        << numDoors << " doors, fuel: " << fuelLevel << "%";
    return oss.str();
}
```

### Constructor chaining (the initialiser list)

```cpp
// Derived constructor MUST call the base constructor:
Car::Car(std::string make, int year, double fuelLevel, int numDoors)
    : Vehicle(make, year, fuelLevel),   // <-- base constructor call
      numDoors(numDoors)                // <-- Car's own member
{}
```

---

## 6. When to Use Inheritance

| Scenario | Inheritance appropriate? |
|----------|--------------------------|
| `Car` and `Truck` share make/year logic | ✅ Yes — common base `Vehicle` |
| `Stack` needs an internal array | ❌ No — use a member variable (composition) |
| `AdminUser` is a special kind of `User` | ✅ Yes |
| `Logger` needs to be attached to `Service` | ❌ No — use composition |
| `Square` and `Circle` share area/perimeter | ✅ Yes — common base `Shape` |

**Rule of thumb:** Only inherit when the relationship is genuinely **"is-a"**, not **"has-a"**.

---

## 7. Lab-Specific Reminder

In this lab, `Vehicle::describe()` is **pure virtual**, which means:

1. You cannot create a `Vehicle` object directly — it is abstract
2. Both `Car` and `Truck` **must** implement `describe()` or the code won't compile
3. A `Vehicle*` pointer will correctly call `Car::describe()` or `Truck::describe()` at runtime

That last point is the payoff — it is called **runtime polymorphism**, and it only works because `describe()` is declared `virtual` in the base class.

```
Vehicle* v = &someCar;
v->describe();   // --> Car::describe() called, not Vehicle::describe()
                 //     This decision is made at RUNTIME, not compile time
```
