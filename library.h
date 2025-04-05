/**
 * @file library.h
 * @author Odin's Ravens
 * @date 2025-04-05
 * @brief Header file for the Library class.
 * 
 * @description Declares the Library class used to store and manage 
 * a linked list of games. Includes methods for loading, saving, 
 * inserting, deleting, and searching.
 */

 #ifndef LIBRARY_H
 #define LIBRARY_H
 
 #include <list>
 #include <string>
 #include "game.h"
 
 /**
  * @description Class that manages a list of games using std::list.
  *
  * @class Library library.h "library/library.h"
  * @brief Handles game storage and operations like add, delete, search, and save.
  */
 class Library {
 private:
     std::list<Game> games;
 
 public:
 
     /**
      * Loads games from the given file and stores them in the list.
      * @param filename The name of the input file.
      */
     void loadFromFile(const std::string& filename);
 
     /**
      * Saves all games in the list to the given file.
      * @param filename The name of the output file.
      */
     void saveToFile(const std::string& filename) const;
 
     /**
      * Adds a game to the list in sorted order by title.
      * @param game The game to insert.
      */
     void insertSorted(const Game& game);
 
     /**
      * Deletes a game that matches the given title and year.
      * @param title The title of the game.
      * @param year The year the game was released.
      */
     void deleteGame(const std::string& title, int year);
 
     /**
      * Finds and prints all games that include part of the given title.
      * @param partialTitle A part of the title to search for.
      */
     void findGame(const std::string& partialTitle) const;
 
     /**
      * Finds and prints all games that match the given genre.
      * @param genre The genre to search for.
      */
     void findGenre(const std::string& genre) const;
 
     /**
      * Prints all games in the list in a formatted table.
      */
     void printAll() const;
 };
 
 #endif