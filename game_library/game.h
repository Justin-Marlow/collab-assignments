/**
 * @file game.h
 * @author Odin's Ravens
 * @date 2025-04-05
 * @brief Struct for storing game information.
 * 
 * @description This file defines the Game struct, which stores details 
 * for each game in the library, including title, publisher, genre, hours played, 
 * price, and release year. It also defines comparison operators used for sorting 
 * and equality checks.
 */

 #ifndef GAME_H
 #define GAME_H
 
 #include <string>
 
 /**
  * @description Stores basic information for one game.
  *
  * @struct Game game.h "game/game.h"
  * @brief Holds title, publisher, genre, hours played, price, and year.
  */
 struct Game {
     std::string title;
     std::string publisher;
     std::string genre;
     float hoursPlayed;
     float price;
     int year;
 
     /**
      * Compares two games alphabetically by title.
      * @param other Another game to compare with.
      * @return true if this game's title comes before the other's.
      */
     bool operator<(const Game& other) const {
         return title < other.title;
     }
 
     /**
      * Checks if two games are the same based on title and year.
      * @param other Another game to compare with.
      * @return true if both title and year match.
      */
     bool operator==(const Game& other) const {
         return title == other.title && year == other.year;
     }
 };
 
 #endif
 