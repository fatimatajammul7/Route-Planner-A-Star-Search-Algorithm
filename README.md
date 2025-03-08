
# Rescue 1122 Route Planner - A* and Genetic Algorithm

## Project Overview  
This project simulates an **optimal route planning system** for Rescue 1122 ambulances in Lahore, ensuring the shortest and most efficient path to an accident site. The simulation models a **40x40 grid**, with roads, obstacles, and infrastructure.

The project implements and compares two **pathfinding algorithms**:  
1. **A* Search Algorithm** – A heuristic-based approach for finding the shortest path.  
2. **Genetic Algorithm (GA)** – An evolutionary approach for optimized routing.

---

## Features  
- **Grid-Based Environment** – Simulates a city using a **40x40** matrix.  
- **Obstacle Handling** – Randomly generated roadblocks that influence pathfinding.  
- **A* Algorithm** – Uses heuristics to compute the most efficient route.  
- **Genetic Algorithm (GA)** – Evolves a population of paths to find an optimized solution.  
- **Comparison of A* vs GA** – Evaluates the efficiency of both algorithms in real-time scenarios.  

---

## Technologies Used  
- **Programming Language:** C++  
- **Algorithms:** A* Search Algorithm, Genetic Algorithm  
- **Libraries:** `<iostream>` `<vector>` `<queue>` `<cmath>` `<ctime>` `<cstdlib>`  

---

## File Structure  
- `Route_Planner.cpp` – Implements the **A* Search Algorithm** for shortest-path routing.  
- `Genetic_Algorithm.cpp` – Implements the **Genetic Algorithm (GA)** for optimized route generation.  
- `displayGrid()` – Function to visualize the grid before and after applying algorithms.  
- `applyAStar()` – Executes the A* search algorithm for pathfinding.  
- `geneticAlgorithm()` – Uses selection, crossover, and mutation to evolve an optimized path.  
- `findpath()` – Traces the computed route and updates the grid for visualization.  

---

## How It Works  
1. **Grid Initialization** – A `40x40` grid is generated with roads (`1`) and obstacles (`0`).  
2. **Pathfinding Approaches**:  
   - **A* Algorithm:** Computes the shortest path using heuristic costs.  
   - **Genetic Algorithm:** Evolves a set of paths, using crossover and mutation, to find an optimized route.  
3. **Route Visualization** – The grid is displayed before and after the computation.  
 

---

## Compilation Instructions

To compile and run the file, follow these instructions:

1. **Ensure you have a C++ compiler installed** (e.g., g++, clang++).

2. **Compile the code** for A* code using the following command:
   ```bash
   g++ -o astar Route_Planner.cpp
3. **Run the executable with the following command:**
   ```bash
   ./astar

2. **Compile the code** using the following command:
   ```bash
   g++ -o genetic Genetic_Algorithm.cpp
3. **Run the executable with the following command:**
   ```bash
   ./genetic

If you encounter any issues or have questions, please feel free to reach out for assistance. Happy coding!


