# Makefile for Deque Project
# Author: Odin's Ravens
# Date: April 25, 2025
# Description: Compiles main.cpp and deque.cpp into an executable called deque_test

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
OBJS = main.o deque.o
TARGET = deque_test

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp deque.h
	$(CXX) $(CXXFLAGS) -c main.cpp

deque.o: deque.cpp deque.h
	$(CXX) $(CXXFLAGS) -c deque.cpp

clean:
	rm -f *.o $(TARGET)
