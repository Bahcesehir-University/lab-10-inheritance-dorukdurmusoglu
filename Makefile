# ================================================================
# Makefile - Lab: Inheritance in C++
# ================================================================
# Targets:
#   make              -> build main_program
#   make test         -> run ALL sections
#   make test_A       -> Section A: Vehicle base class & getters   (20 pts)
#   make test_B       -> Section B: refuel logic                   (15 pts)
#   make test_C       -> Section C: Car constructor & describe()   (20 pts)
#   make test_D       -> Section D: Truck constructor & describe() (20 pts)
#   make test_E       -> Section E: Polymorphism via base pointer  (25 pts)
#   make clean        -> remove all build artifacts
# ================================================================

CXX      = g++
CXXFLAGS = -Wall --std=c++17

MAIN     = MainProgram.cpp
TEST_SRC = test.cpp catch_amalgamated.cpp
TEST_BIN = test_runner

.PHONY: all test test_A test_B test_C test_D test_E clean

# ── Default: build the main program ──────────────────────────────
all:
	$(CXX) $(CXXFLAGS) $(MAIN) -o main_program
	@echo "Build successful. Run with: ./main_program"

# ── Build test runner (internal helper) ──────────────────────────
$(TEST_BIN): $(TEST_SRC) catch_amalgamated.hpp
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(TEST_BIN)

# ── Run ALL sections ─────────────────────────────────────────────
test: $(TEST_BIN)
	@echo "========================================"
	@echo " Running ALL sections"
	@echo "========================================"
	./$(TEST_BIN) --reporter compact

# ── Section A: Vehicle base class & getters  (20 pts) ────────────
test_A: $(TEST_BIN)
	@echo "========================================"
	@echo " Section A: Vehicle Getters  [20 pts]"
	@echo "========================================"
	./$(TEST_BIN) [A] --reporter compact

# ── Section B: refuel logic  (15 pts) ────────────────────────────
test_B: $(TEST_BIN)
	@echo "========================================"
	@echo " Section B: refuel Logic     [15 pts]"
	@echo "========================================"
	./$(TEST_BIN) [B] --reporter compact

# ── Section C: Car constructor & describe()  (20 pts) ────────────
test_C: $(TEST_BIN)
	@echo "========================================"
	@echo " Section C: Car Class        [20 pts]"
	@echo "========================================"
	./$(TEST_BIN) [C] --reporter compact

# ── Section D: Truck constructor & describe()  (20 pts) ──────────
test_D: $(TEST_BIN)
	@echo "========================================"
	@echo " Section D: Truck Class      [20 pts]"
	@echo "========================================"
	./$(TEST_BIN) [D] --reporter compact

# ── Section E: Polymorphism via base pointer  (25 pts) ───────────
test_E: $(TEST_BIN)
	@echo "========================================"
	@echo " Section E: Polymorphism     [25 pts]"
	@echo "========================================"
	./$(TEST_BIN) [E] --reporter compact

# ── Clean ────────────────────────────────────────────────────────
clean:
	rm -f main_program $(TEST_BIN)
	@echo "Clean complete."
