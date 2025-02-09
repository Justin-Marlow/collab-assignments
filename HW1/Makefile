# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -g

# Executable name
TARGET = test

# Object files
OBJS = main.o Vector.o

# Default target: Build everything
all: $(TARGET)

# Compile and link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Compile main.cpp into main.o
main.o: main.cpp Vector.h
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

# Compile Vector.cpp into Vector.o
Vector.o: Vector.cpp Vector.h
	$(CXX) $(CXXFLAGS) -c Vector.cpp -o Vector.o

# Clean target to remove compiled files
clean:
	rm -f $(OBJS) $(TARGET)
