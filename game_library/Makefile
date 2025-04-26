# Makefile for Spring Sale Game Library
CXX = g++
CXXFLAGS = -std=c++11 -Wall
OBJ = main.o library.o
TARGET = game_library

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ)

main.o: main.cpp library.h game.h
library.o: library.cpp library.h game.h

clean:
	rm -f *.o $(TARGET)