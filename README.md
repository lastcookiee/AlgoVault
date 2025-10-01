# AlgoVault - Interactive Algorithm Visualizer

<div align="center">

```
    ╔═══════════════════════════════════════════════════════════════╗
    ║                                                               ║
    ║      $$\      $$\                  $$\    $$\                ║
    ║      $$ |     $$ |                 $$ |   $$ |               ║
    ║   $$$$$$$ |$$$$$$ | $$$$$$\        $$ |   $$ | $$$$$$\  $$\  ║
    ║  $$  __$$ |$$  __$$ |\____$$\      $$ |   $$ |$$  __$$\  $$ | ║
    ║  $$ /  $$ |$$ /  $$ |$$$$$$$ |     \$$\  $$  /$$ /  \__|$$ | ║
    ║  $$ |  $$ |$$ |  $$ |$$  __$$ |      \$$\$$  / $$ |     $$ | ║
    ║  \$$$$$$$ |\$$$$$$$ |\$$$$$$$ |       \$$$  /  $$ |     $$ | ║
    ║   \_______| \_______| \_______|        \___/   \__|     \__| ║
    ║                                                               ║
    ║           Interactive Algorithm Visualizer                    ║
    ║                                                               ║
    ╚═══════════════════════════════════════════════════════════════╝
```

**A C++ console-based interactive algorithm visualizer that demonstrates sorting and graph algorithms step-by-step**

[![Language](https://img.shields.io/badge/Language-C++-blue.svg)](https://isocpp.org/)
[![Platform](https://img.shields.io/badge/Platform-Windows-lightgrey.svg)](https://www.microsoft.com/windows)
[![License](https://img.shields.io/badge/License-MIT-green.svg)](https://opensource.org/licenses/MIT)
[![GitHub Stars](https://img.shields.io/github/stars/lastcookiee/AlgoVault?style=social)](https://github.com/lastcookiee/AlgoVault)
[![GitHub Forks](https://img.shields.io/github/forks/lastcookiee/AlgoVault?style=social)](https://github.com/lastcookiee/AlgoVault)

</div>

---

## 🎯 Project Overview

AlgoVault is an educational tool designed to help students and developers understand algorithms through interactive visualization. The application provides step-by-step execution of popular sorting and graph algorithms with color-coded output, making complex algorithmic concepts easy to understand.

### ✨ Key Features

- **🔢 Sorting Algorithms**: Bubble Sort, Quick Sort, Merge Sort, Heap Sort
- **🕸️ Graph Algorithms**: BFS, DFS, Dijkstra's Shortest Path
- **📊 Step-by-step Visualization**: Watch algorithms execute in real-time
- **🎨 Color-coded Output**: Enhanced visual feedback for better understanding
- **⏱️ Complexity Analysis**: Time and space complexity information for each algorithm
- **🎮 Interactive Input**: Choose between custom input or sample data
- **🏗️ Modular Design**: Clean, maintainable code structure

---

## 🚀 Quick Start

### Clone and Run

```bash
# Clone the repository
git clone https://github.com/lastcookiee/AlgoVault.git
cd AlgoVault

# Compile (Windows with MinGW)
g++ -std=c++11 -Wall -Wextra -O2 -o AlgoVault.exe main.cpp utils.cpp sorting.cpp graph.cpp

# Or use the build script
./build.bat

# Run the application
./AlgoVault.exe
```

## 🚀 Getting Started

### Prerequisites

- **Compiler**: GCC (MinGW) or Microsoft Visual C++
- **Operating System**: Windows (for console color support)
- **C++ Standard**: C++11 or later

### 📁 Project Structure

```
AlgoVault/
├── main.cpp           # Main application entry point
├── utils.h            # Utility functions header
├── utils.cpp          # Utility functions implementation
├── sorting.h          # Sorting algorithms header
├── sorting.cpp        # Sorting algorithms implementation
├── graph.h            # Graph algorithms header
├── graph.cpp          # Graph algorithms implementation
└── README.md          # Project documentation
```

### 🔨 Compilation

#### Using GCC (MinGW):

```bash
g++ -std=c++11 -o AlgoVault main.cpp utils.cpp sorting.cpp graph.cpp
```

#### Using Visual Studio:

1. Create a new C++ Console Application project
2. Add all source files to the project
3. Build and run (Ctrl+F5)

### ▶️ Running the Application

```bash
./AlgoVault.exe
```

---

## 📖 Algorithm Implementations

### 🔢 Sorting Algorithms

#### 1. Bubble Sort

- **Description**: Compares adjacent elements and swaps them if they're in wrong order
- **Visualization**: Shows each swap operation and pass through the array
- **Use Case**: Educational purposes, small datasets

#### 2. Quick Sort

- **Description**: Divide-and-conquer algorithm using pivot partitioning
- **Visualization**: Shows pivot selection, partitioning, and recursive calls
- **Use Case**: General-purpose sorting, large datasets

#### 3. Merge Sort

- **Description**: Divide-and-conquer algorithm that merges sorted subarrays
- **Visualization**: Shows division process and merging steps
- **Use Case**: Stable sorting, linked lists, external sorting

#### 4. Heap Sort

- **Description**: Uses binary heap data structure to sort elements
- **Visualization**: Shows heap construction and extraction process
- **Use Case**: When consistent O(n log n) performance is needed

### 🕸️ Graph Algorithms

#### 1. Breadth-First Search (BFS)

- **Description**: Explores vertices level by level using a queue
- **Visualization**: Shows queue state and traversal order
- **Use Case**: Shortest path in unweighted graphs, level-order traversal

#### 2. Depth-First Search (DFS)

- **Description**: Explores as far as possible along each branch using a stack
- **Visualization**: Shows stack state and traversal path
- **Use Case**: Topological sorting, detecting cycles, pathfinding

#### 3. Dijkstra's Shortest Path

- **Description**: Finds shortest paths from source to all vertices in weighted graph
- **Visualization**: Shows distance updates and path reconstruction
- **Use Case**: GPS navigation, network routing, shortest path problems

---

## 📊 Complexity Analysis Table

| Algorithm              | Time Complexity             | Space Complexity | Stability   | In-Place |
| ---------------------- | --------------------------- | ---------------- | ----------- | -------- |
| **Sorting Algorithms** |
| Bubble Sort            | O(n²)                       | O(1)             | ✅ Stable   | ✅ Yes   |
| Quick Sort             | O(n log n) avg, O(n²) worst | O(log n)         | ❌ Unstable | ✅ Yes   |
| Merge Sort             | O(n log n)                  | O(n)             | ✅ Stable   | ❌ No    |
| Heap Sort              | O(n log n)                  | O(1)             | ❌ Unstable | ✅ Yes   |
| **Graph Algorithms**   |
| BFS                    | O(V + E)                    | O(V)             | -           | -        |
| DFS                    | O(V + E)                    | O(V)             | -           | -        |
| Dijkstra               | O((V + E) log V)            | O(V)             | -           | -        |

_Where V = number of vertices, E = number of edges_

---

## 💡 Example Outputs

### Sorting Algorithm Example (Bubble Sort)

```
===============================================================
                    BUBBLE SORT VISUALIZATION
===============================================================
Bubble Sort works by repeatedly swapping adjacent elements if they are in wrong order.

Initial array: [64, 34, 25, 12, 22, 11, 90]

--- Pass 1 ---
Step 1 - Swapped 34 and 64: [34, 64, 25, 12, 22, 11, 90]
Step 2 - Swapped 25 and 64: [34, 25, 64, 12, 22, 11, 90]
Step 3 - Swapped 12 and 64: [34, 25, 12, 64, 22, 11, 90]
Step 4 - Swapped 22 and 64: [34, 25, 12, 22, 64, 11, 90]
Step 5 - Swapped 11 and 64: [34, 25, 12, 22, 11, 64, 90]

--- Pass 2 ---
Step 6 - Swapped 25 and 34: [25, 34, 12, 22, 11, 64, 90]
...

Final sorted array: [11, 12, 22, 25, 34, 64, 90]

--- Complexity Analysis ---
Algorithm: Bubble Sort
Time Complexity: O(n²)
Space Complexity: O(1)
```

### Graph Algorithm Example (BFS)

```
===============================================================
            BREADTH-FIRST SEARCH (BFS) VISUALIZATION
===============================================================
BFS explores vertices level by level using a queue.

--- Graph Adjacency List ---
Vertex 0: 1 2
Vertex 1: 0 2 3
Vertex 2: 0 1 4
Vertex 3: 1 4
Vertex 4: 2 3

Starting BFS from vertex 0

Traversal order:
----------------------------------------
BFS - Visiting vertex 0 [Queue: []]
  Exploring neighbors of 0: 1 (added to queue) 2 (added to queue)
--------------------
BFS - Visiting vertex 1 [Queue: [2]]
  Exploring neighbors of 1: 0 (already visited) 2 (already visited) 3 (added to queue)
--------------------
BFS - Visiting vertex 2 [Queue: [3]]
  Exploring neighbors of 2: 0 (already visited) 1 (already visited) 4 (added to queue)
...

--- Complexity Analysis ---
Algorithm: Breadth-First Search
Time Complexity: O(V + E)
Space Complexity: O(V)
```

---

## 🎮 User Interaction

### Main Menu

```
╔═════════════════════════════════════════════╗
║              Choose an option:              ║
├─────────────────────────────────────────────┤
║  1. 🔢 Sorting Algorithms                   ║
║      • Bubble Sort                          ║
║      • Quick Sort                           ║
║      • Merge Sort                           ║
║      • Heap Sort                            ║
├─────────────────────────────────────────────┤
║  2. 🕸️  Graph Algorithms                    ║
║      • Breadth-First Search (BFS)          ║
║      • Depth-First Search (DFS)            ║
║      • Dijkstra's Shortest Path            ║
├─────────────────────────────────────────────┤
║  3. ℹ️  About AlgoVault                     ║
├─────────────────────────────────────────────┤
║  4. 🚪 Exit                                 ║
╚═════════════════════════════════════════════╝
```

### Input Options

- **Custom Input**: Enter your own array/graph data
- **Sample Data**: Use pre-defined examples for quick testing
- **Validation**: Input validation prevents crashes and guides users

---

## 🏗️ Architecture & Design

### Code Organization

#### `main.cpp` - Application Entry Point

- AlgoVault class with main application logic
- Menu system and user interaction
- Exception handling and error management

#### `utils.h/cpp` - Utility Functions

- Console output formatting and colors
- Input validation and array handling
- Cross-platform compatibility helpers

#### `sorting.h/cpp` - Sorting Algorithms

- All sorting algorithm implementations
- Step-by-step visualization logic
- Performance analysis integration

#### `graph.h/cpp` - Graph Algorithms

- Graph data structure with adjacency list
- BFS, DFS, and Dijkstra implementations
- Traversal visualization and path tracking

### Design Principles

- **Modularity**: Each algorithm type is in separate files
- **Encapsulation**: Classes hide implementation details
- **Reusability**: Utility functions used across modules
- **Maintainability**: Clear separation of concerns
- **Extensibility**: Easy to add new algorithms

---

## 🎨 Visual Features

### Color Coding

- 🟢 **Green**: Successful operations, completed steps
- 🔴 **Red**: Errors, invalid input
- 🟡 **Yellow**: Headers, important information
- 🔵 **Blue**: Menu options, structure display
- 🟣 **Cyan**: Algorithm descriptions, informational text

### Console Enhancements

- Unicode characters for better visual appeal
- Formatted tables and separators
- Timed delays for step visualization
- Clear screen functionality for clean output

---

## 🔧 Customization & Extension

### Adding New Sorting Algorithms

1. **Add to `sorting.h`**:

```cpp
static void newSortAlgorithm(std::vector<int>& arr);
```

2. **Implement in `sorting.cpp`**:

```cpp
void SortingAlgorithms::newSortAlgorithm(std::vector<int>& arr) {
    // Implementation with visualization
}
```

3. **Update menu system** in `showSortingMenu()` and `runSortingAlgorithms()`

### Adding New Graph Algorithms

1. **Add to `graph.h`**:

```cpp
void newGraphAlgorithm(int startVertex);
```

2. **Implement in `graph.cpp`** with step-by-step visualization

3. **Update menu system** in graph algorithm functions

---

## 🐛 Troubleshooting

### Common Issues

**Compilation Errors:**

- Ensure C++11 or later standard
- Check all header files are included
- Verify Windows-specific functions on other platforms

**Runtime Issues:**

- Input validation prevents most crashes
- Check console encoding for special characters
- Ensure sufficient stack space for recursive algorithms

**Display Problems:**

- Enable console color support
- Use UTF-8 compatible terminal
- Adjust console window size for better display

---

## 📚 Learning Resources

### Algorithm Study Guide

**Sorting Algorithms:**

- [Bubble Sort Tutorial](https://www.geeksforgeeks.org/bubble-sort/)
- [Quick Sort Explained](https://www.geeksforgeeks.org/quick-sort/)
- [Merge Sort Visualization](https://www.geeksforgeeks.org/merge-sort/)
- [Heap Sort Algorithm](https://www.geeksforgeeks.org/heap-sort/)

**Graph Algorithms:**

- [BFS Algorithm](https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/)
- [DFS Traversal](https://www.geeksforgeeks.org/depth-first-search-or-dfs-for-a-graph/)
- [Dijkstra's Algorithm](https://www.geeksforgeeks.org/dijkstras-shortest-path-algorithm-greedy-algo-7/)

### Practice Problems

- [LeetCode Sorting](https://leetcode.com/tag/sorting/)
- [LeetCode Graph](https://leetcode.com/tag/graph/)
- [HackerRank Algorithms](https://www.hackerrank.com/domains/algorithms)

---

## 🤝 Contributing

We welcome contributions to AlgoVault! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch**: `git checkout -b feature/new-algorithm`
3. **Make your changes** with proper documentation
4. **Add tests** for new functionality
5. **Commit changes**: `git commit -m "Add new sorting algorithm"`
6. **Push to branch**: `git push origin feature/new-algorithm`
7. **Submit a pull request**

### Contribution Guidelines

- Follow existing code style and structure
- Add comprehensive comments for new algorithms
- Include visualization for new implementations
- Update README.md with new features
- Test thoroughly on Windows platform

Please read [CONTRIBUTING.md](CONTRIBUTING.md) for detailed contribution guidelines.

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🙋‍♂️ Support

If you encounter any issues or have questions:

1. **Check the troubleshooting section** above
2. **Review example outputs** for expected behavior
3. **Verify compilation steps** and requirements
4. **Open an issue** with detailed error information

---

## 🌟 Acknowledgments

- **Educational Inspiration**: Created for students learning algorithms
- **Visualization Concept**: Inspired by algorithm visualization websites
- **C++ Community**: Thanks to the C++ community for best practices
- **Open Source**: Built with open-source development principles

---

<div align="center">

**🚀 Happy Learning! 🚀**

_AlgoVault - Making algorithms visual, interactive, and fun to learn!_

⭐ If you found this project helpful, please consider giving it a star!

</div>
