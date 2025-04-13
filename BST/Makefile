# Makefile for building the Binary Search Tree project

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++17

# Output binary
TARGET = bst

# Object files
OBJS = driver.o bst.o node.o

# Default target
all: $(TARGET)

# Link object files into final executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files
driver.o: driver.cpp bst.h
	$(CXX) $(CXXFLAGS) -c driver.cpp

bst.o: bst.cpp bst.h
	$(CXX) $(CXXFLAGS) -c bst.cpp

node.o: node.cpp node.h
	$(CXX) $(CXXFLAGS) -c node.cpp

# Clean up build artifacts
clean:
	rm -f $(OBJS) $(TARGET)
