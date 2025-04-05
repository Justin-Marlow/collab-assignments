/**
 * @file library.cpp
 * @author Odin's Ravens
 * @date 2025-04-05
 * @brief Implements the Library class functions.
 * 
 * @description Defines methods for loading, saving, printing, and searching 
 * a linked list of Game objects. Games are kept in sorted order by title.
 */

 #include "library.h"
 #include <fstream>
 #include <iostream>
 #include <iomanip>
 #include <algorithm>
 
 using namespace std;
 
 // Prints the top header of the game table (used by multiple functions).
 static void printTableHeader() {
    cout << "===========================================================================================================\n";
    cout << "                                        Game Library Search                                                \n";
    cout << "===========================================================================================================\n";
    cout << "| Title                                      | Publisher           | Genre       | Hours | Year | Price  |\n";
    cout << "===========================================================================================================\n";
 }
 
 // Prints one row of game info formatted for the table.
 static void printGameRow(const Game& g) {
    cout << "| " << setw(43) << left << g.title
         << "| " << setw(20) << left << g.publisher
         << "| " << setw(11) << left << g.genre
         << "| " << setw(6) << right << fixed << setprecision(1) << g.hoursPlayed
         << " | " << g.year
         << " | $" << setw(6) << right << fixed << setprecision(2) << g.price
         << " |\n";
}
 
 /**
  * @description Loads game data from a file and inserts each game into the list.
  * @param filename The name of the file to read from.
  * @pre File should exist and be formatted correctly.
  * @post Games are added in sorted order into the list.
  */
 void Library::loadFromFile(const string& filename) {
     ifstream file(filename);
     if (!file) {
         cerr << "Could not open database for reading: " << filename << endl;
         return;
     }
 
     Game g;
     while (getline(file, g.title, '|')) {
         getline(file, g.publisher, '|');
         getline(file, g.genre, '|');
         file >> g.hoursPlayed;
         file.ignore();
         file >> g.price;
         file.ignore();
         file >> g.year;
         file.ignore();
         insertSorted(g);
     }
 
     file.close();
 }
 
 /**
  * @description Writes all games in the list to a file.
  * @param filename The name of the file to save to.
  * @pre File should be writable.
  * @post All current games are saved in the expected format.
  */
 void Library::saveToFile(const string& filename) const {
     ofstream file(filename);
     if (!file) {
         cerr << "Could not open database for writing: " << filename << endl;
         return;
     }
 
     for (const Game& g : games) {
         file << g.title << '|'
              << g.publisher << '|'
              << g.genre << '|'
              << g.hoursPlayed << '|'
              << g.price << '|'
              << g.year << '\n';
     }
 
     file.close();
 }
 
 /**
  * @description Inserts a game into the list in alphabetical order by title.
  * @param game The game to add.
  * @pre The list may be empty or already sorted.
  * @post The list remains sorted after the new game is added.
  */
 void Library::insertSorted(const Game& game) {
     auto it = games.begin();
     while (it != games.end() && *it < game) {
         ++it;
     }
     games.insert(it, game);
 }
 
 /**
  * @description Removes a game from the list that matches the given title and year.
  * @param title The title of the game to delete.
  * @param year The release year of the game to delete.
  * @pre At least one game should exist.
  * @post Game is removed if found; otherwise, no changes are made.
  */
 void Library::deleteGame(const string& title, int year) {
     auto it = find_if(games.begin(), games.end(), [&](const Game& g) {
         return g.title == title && g.year == year;
     });
     if (it != games.end()) {
         games.erase(it);
         cout << "Deleted game: " << title << " (" << year << ")" << endl;
         cout << "May it rest in bytes.\n";
     } else {
         cout << "Game not found. Maybe it's hiding in the cloud?\n";
     }
 }
 
 /**
  * @description Searches for and prints games that contain part of the given title.
  * Includes special messages for themed titles.
  * @param partialTitle The text to search for in game titles.
  * @pre Games should be loaded into the list.
  * @post Matching games are printed in table format.
  */
 void Library::findGame(const string& partialTitle) const {
     bool found = false;
     int count = 0;
 
     for (const Game& g : games) {
         if (g.title.find(partialTitle) != string::npos) {
             if (!found) {
                 printTableHeader();
                 found = true;
             }
             printGameRow(g);
             count++;
 
             string lowerTitle = g.title;
             transform(lowerTitle.begin(), lowerTitle.end(), lowerTitle.begin(), ::tolower);
 
             if (lowerTitle.find("global thermonuclear war") != string::npos) {
                 cout << "\n “A strange game. The only winning move is not to play.” – WarGames\n";
                 cout << "   How about a nice game of chess instead?\n";
             }
             else if (lowerTitle.find("falken") != string::npos) {
                 cout << "\n “Hello, Professor Falken.” – WarGames\n";
                 cout << "   Let’s see if you can escape Falken’s Maze...\n";
             }
             else if (lowerTitle.find("chemical warfare") != string::npos) {
                 cout << "\n  Initiating chemical protocol… hope you're vaccinated.\n";
             }
             else if (lowerTitle.find("biotoxic") != string::npos || lowerTitle.find("biological") != string::npos) {
                 cout << "\n Viral vector confirmed. This might be contagious.\n";
             }
             else if (lowerTitle.find("theaterwide") != string::npos) {
                 cout << "\n Theaterwide warfare engaged. The stage is set.\n";
             }
             else if (lowerTitle.find("desert warfare") != string::npos) {
                 cout << "\n Desert terrain loaded. Sandstorms possible.\n";
             }
             else if (lowerTitle.find("air-to-ground") != string::npos) {
                 cout << "\n Deploying payload. Hope you remembered to toggle hardpoint G.\n";
             }
             else if (lowerTitle.find("poker") != string::npos) {
                 cout << "\n You called that bluff? Bold.\n";
             }
             else if (lowerTitle.find("checkers") != string::npos) {
                 cout << "\n King me.\n";
             }
             else if (lowerTitle.find("hearts") != string::npos) {
                 cout << "\n Don't shoot the moon...\n";
             }
         }
     }
 
     if (found) {
         cout << "====================================================================================\n";
         cout << "Matches found: " << count << "\n";
     } else {
         cout << "No game titles containing \"" << partialTitle << "\" found.\n";
         cout << "Check your spelling — or your wishlist.\n";
     }
 }
 
 /**
  * @description Searches for and prints all games in a specific genre.
  * @param genre The genre to look for.
  * @pre Games should be loaded into the list.
  * @post Matching games are printed in table format.
  */
 void Library::findGenre(const string& genre) const {
     bool found = false;
     int count = 0;
 
     for (const Game& g : games) {
         if (g.genre == genre) {
             if (!found) {
                 printTableHeader();
                 found = true;
             }
             printGameRow(g);
             count++;
         }
     }
 
     if (found) {
         cout << "====================================================================================\n";
         cout << "Matches found: " << count << "\n";
     } else {
         cout << "No games found in genre \"" << genre << "\".\n";
     }
 }
 
 /**
  * @description Prints all games in the library in a table format.
  * @pre Games should be loaded or added to the list.
  * @post All games are displayed with formatted columns.
  */
 void Library::printAll() const {
     if (games.empty()) {
         cout << "Your game library is empty.\n";
         cout << "Perfect time to buy something in the Steam sale!\n";
         return;
     }
 
     printTableHeader();
 
     int total = 0;
     for (const Game& g : games) {
         printGameRow(g);
         total++;
     }
 
     cout << "====================================================================================\n";
     cout << "Total Games: " << total << "\n";
 }
 