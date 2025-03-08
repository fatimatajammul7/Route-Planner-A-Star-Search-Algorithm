# Rescue 1122 Route Planner - A* Search Algorithm

## Project Overview  
This project simulates an optimal route planner for Rescue 1122 ambulances in Lahore using the A* search algorithm. The goal is to find the shortest path from the rescue station to the accident site while avoiding obstacles.  

The simulation represents the city as a **40x40 grid**, where:  
- Roads are passable cells (1)  
- Obstacles (e.g., buildings, traffic) are blocked cells (0)  

The A* algorithm efficiently finds the shortest route from the start position (Rescue Station) to the destination (Accident Site) while considering heuristic costs.

---

## Features  
- **Grid-Based Map Representation** – Simulates city roads using a 40x40 matrix.  
- **Obstacle Generation** – Randomly places 500 obstacles to represent real-world roadblocks.  
- **A* Search Algorithm** – Finds the shortest route using heuristic-based pathfinding.  
- **Visualization of Paths** – Displays the grid before and after running the algorithm.  
- **Dynamic Neighbor Exploration** – Uses 8-directional movement for accurate pathfinding.  

---

## Technologies Used  
- **Programming Language:** C++  
- **Algorithm:** A* Search Algorithm  
- **Libraries:** `<iostream>` `<queue>` `<cmath>` `<ctime>`  

---

## File Structure  
- `main.cpp` – Contains the grid initialization, A* search implementation, and pathfinding logic.  
- `displayGrid()` – Function to print the before and after grid states.  
- `applyAStar()` – Implements the A* algorithm to compute the shortest path.  
- `findpath()` – Traces back and marks the optimal route.  

---

## How It Works  
1. **Initialize Grid** – A `40x40` grid is generated with random obstacles (`0`) and roads (`1`).  
2. **Set Source & Destination** – Define start point (Rescue Station) and end point (Accident Site).  
3. **Run A* Algorithm** – Computes the shortest path using heuristic-based cost evaluation.  
4. **Mark Path on Grid** – The optimal path is visualized by modifying the grid.  

---

## Compilation Instructions

To compile and run the file, follow these instructions:

1. **Ensure you have a C++ compiler installed** (e.g., g++, clang++).

2. **Compile the code** using the following command:
   ```bash
   g++ -o program Route_planner.cpp
3. **Run the executable with the following command:**
   ```bash
   ./program


If you encounter any issues or have questions, please feel free to reach out for assistance. Happy coding!


