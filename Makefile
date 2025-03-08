# Author: Odin's Ravens
# File: Makefile
# Last Modified: 2025-02-14
# Purpose: Makefile to compile Image Stacker

# Compiler
CC = g++

# Target executable name
TARGET = image_stacker

# Compilation flags
CFLAGS = -c -Wall -Wextra

# Object files
OBJS = main.o stacker.o

# Default target
all: $(TARGET)

#link executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Compile main.o
main.o: main.cpp Stacker.h
	$(CC) $(CFLAGS) main.cpp -o main.o

# Compile stacker.o
stacker.o: Stacker.cpp Stacker.h
	$(CC) $(CFLAGS) Stacker.cpp -o stacker.o

# Clean up object file and executable
clean:
	rm -f $(OBJS) $(Target) *~
