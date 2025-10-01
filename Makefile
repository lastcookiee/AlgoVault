# Makefile for AlgoVault - Interactive Algorithm Visualizer
# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2

# Directories
SRCDIR = .
BUILDDIR = build

# Source files
SOURCES = main.cpp utils.cpp sorting.cpp graph.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = AlgoVault.exe

# Build rules
all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "Build completed successfully!"
	@echo "Run with: ./$(TARGET)"

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Clean build artifacts
clean:
	del /Q *.o $(TARGET) 2>nul || true
	@echo "Clean completed!"

# Run the application
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CXXFLAGS += -g -DDEBUG
debug: $(TARGET)

# Release build (optimized)
release: CXXFLAGS += -O3 -DNDEBUG
release: clean $(TARGET)

# Help
help:
	@echo "AlgoVault Makefile"
	@echo "=================="
	@echo "Available targets:"
	@echo "  all      - Build the application (default)"
	@echo "  clean    - Remove build artifacts"
	@echo "  run      - Build and run the application"
	@echo "  debug    - Build with debug information"
	@echo "  release  - Build optimized release version"
	@echo "  help     - Show this help message"

# Phony targets
.PHONY: all clean run debug release help

# Dependencies (auto-generated would be better, but keeping it simple)
main.o: main.cpp utils.h sorting.h graph.h
utils.o: utils.cpp utils.h
sorting.o: sorting.cpp sorting.h utils.h
graph.o: graph.cpp graph.h utils.h