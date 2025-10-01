# Changelog

All notable changes to AlgoVault will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.0] - 2025-10-01

### Added
- **Sorting Algorithms Module**
  - Bubble Sort with step-by-step visualization
  - Quick Sort with partition visualization
  - Merge Sort with divide-and-conquer steps
  - Heap Sort with heap construction and extraction
  - Interactive menu system for algorithm selection
  - Time and space complexity analysis for each algorithm

- **Graph Algorithms Module**
  - Breadth-First Search (BFS) with queue state visualization
  - Depth-First Search (DFS) with stack state visualization
  - Dijkstra's Shortest Path with distance table updates
  - Adjacency list representation for graphs
  - Sample graph generation for quick testing
  - Custom graph input validation

- **User Interface Features**
  - Color-coded console output for better visualization
  - Interactive main menu with ASCII art
  - Step-by-step algorithm execution
  - Input validation and error handling
  - About section with complexity information
  - Graceful exit with thank you message

- **Development Tools**
  - Comprehensive Makefile for easy compilation
  - Windows batch script for compilation
  - Modular code architecture with separate classes
  - Utility functions for common operations
  - Cross-platform compatibility considerations

- **Documentation**
  - Comprehensive README with examples and complexity tables
  - MIT License for open source distribution
  - Contributing guidelines for developers
  - Build instructions for multiple platforms
  - Algorithm explanations and use cases

- **Version Control**
  - Complete .gitignore for C++ projects
  - Professional commit structure
  - Ready for GitHub deployment

### Technical Details
- **Language**: C++ (C++11 standard)
- **Platform**: Windows Console Application with color support
- **Architecture**: Object-oriented design with separate modules
- **Dependencies**: Standard C++ library only
- **Compiler**: GCC (MinGW) and Visual Studio compatible

### Known Limitations
- Console color support is Windows-specific
- Threading sleep functionality removed for older GCC compatibility
- Sample graphs are pre-defined (custom graphs supported via input)

## [Unreleased]

### Planned Features
- Cross-platform color support (Linux/macOS)
- Additional sorting algorithms (Radix Sort, Counting Sort)
- Additional graph algorithms (A*, Bellman-Ford)
- Configuration file support
- Algorithm performance benchmarking
- Save/load graph functionality
- Unit test suite