/**
 * @file main.cpp
 * @author Odin's Ravens
 * @date 2025-04-05
 * @brief Main program file for the Game Library Manager.
 * 
 * @description Handles the main menu and user input for adding, deleting, 
 * finding, and displaying games. Uses a Library class to manage the list 
 * and loads from and saves to a file.
 */

#include <iostream>
#include "library.h"
#include <thread>   // for sleep_for
#include <chrono>   // for milliseconds

using namespace std;
using namespace std::chrono;

void printSlow(const string& line, int ms = 12) {
    for (char c : line) {
        cout << c << flush;
        this_thread::sleep_for(milliseconds(ms));
    }
    cout << endl;
}

int main() {
    printSlow("                     __        __   _                            ");
    printSlow("                     \\ \\      / /__| | ___ ___  _ __ ___   ___  ");
    printSlow("                      \\ \\ /\\ / / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ ");
    printSlow("                       \\ V  V /  __/ | (_| (_) | | | | | |  __/ ");
    printSlow("                        \\_/\\_/ \\___|_|\\___\\___/|_| |_| |_|\\___| ");
    printSlow("                                                           ");
    printSlow("                          SPRING SALE GAME LIBRARY MANAGER                       \n\n");
    printSlow("====================================================================================");
    printSlow("Hello, Professor Falken.");
    printSlow("“Shall we play a game?” – WarGames (1983)");
    cout << endl;

    Library lib;
    string file = "games.txt";
    lib.loadFromFile(file);

    int choice;
    do {
        printSlow("====================================================================================");
        printSlow("                              SPRING SALE GAME MENU                               ");
        printSlow("====================================================================================");
        printSlow("| 1 | View All Games                                                              |");
        printSlow("| 2 | Add a Game                                                                  |");
        printSlow("| 3 | Delete a Game                                                               |");
        printSlow("| 4 | Find Game by Title                                                          |");
        printSlow("| 5 | Find Games by Genre                                                         |");
        printSlow("| 6 | Save & Exit                                                                 |");
        printSlow("====================================================================================");
        printSlow("Choose your next move.");
        cout << "Choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            lib.printAll();
        } else if (choice == 2) {
            Game g;
            cout << "Enter Title: "; getline(cin, g.title);
            cout << "Enter Publisher: "; getline(cin, g.publisher);
            cout << "Enter Genre: "; getline(cin, g.genre);
            cout << "Hours Played: "; cin >> g.hoursPlayed;
            cout << "Price: "; cin >> g.price;
            cout << "Year Released: "; cin >> g.year;
            cin.ignore();
            lib.insertSorted(g);
        } else if (choice == 3) {
            string title;
            int year;
            cout << "Enter title to delete: "; getline(cin, title);
            cout << "Enter year: "; cin >> year;
            cin.ignore();
            lib.deleteGame(title, year);
        } else if (choice == 4) {
            string keyword;
            cout << "Enter part of game title: "; getline(cin, keyword);
            lib.findGame(keyword);
        } else if (choice == 5) {
            string genre;
            cout << "Enter genre: "; getline(cin, genre);
            lib.findGenre(genre);
        }
    } while (choice != 6);

    lib.saveToFile(file);
    printSlow("\nAll systems saved.");
    printSlow("Simulation complete. No DEFCON reached.");
    printSlow("Go enjoy a nice game of chess — or buy three more you'll never play.");

    return 0;
}
