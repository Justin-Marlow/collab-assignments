Spring Sale Game Library
Author: Odin's Ravens
Course: CSCI 325 – Data Structures and Algorithms in C++
Date: Spring 2025

Overview:
    This program is a console-based game library manager that uses a linked list (std::list) to store and sort games. Users can add, delete, search, and view games from a saved file. The list stays sorted by title automatically.

How to Compile:
Use the included Makefile to build the program. 
    In the terminal, run: make

To clean up object files and the executable, run: make clean

How to Use:
    When the program starts, it loads a list of games from "games.txt". You'll see a menu with options:
        1. View all games
        2. Add a new game
        3. Delete a game by title and year
        4. Search for games by part of the title
        5. Search for games by genre
        6. Save and exit

Any changes made while using the program will be saved automatically when you exit.

File Descriptions:
- main.cpp        – The main program with menu and user input
- library.h/.cpp  – Library class that handles game list logic
- game.h          – Struct definition for a single game
- games.txt       – Example game database file
- Makefile        – Used to build the project

Data Format (games.txt):
    Each line in the file represents one game and uses '|' to separate fields:
        Title|Publisher|Genre|HoursPlayed|Price|Year

    Example:
        Global Thermonuclear War|WOPR Simulations|Strategy|5.0|20.00|1983
