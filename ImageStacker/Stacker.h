/**
 * @file Stacker.h
 * @author Odin's Ravens
 * @date 2025-03-08
 * @brief Header file for Stacker
 * 
 * declaration of stacker class
 */


#ifndef STACKER_H
#define STACKER_H

#include <vector>
#include <string>

using namespace std;

class Stacker {
 private:
  struct Pixel {
    int red, green, blue;
  };

  string magic_number;
  int width, height, max_color;
  vector<Pixel> pixels; // stores pixel data

 public:
  Stacker();
  bool readImage(const string& filename); // reads a single ppm image
  bool stackImages(int numImages); // averages pixel values
  bool writeImage(const string& outputFilename); // saves image

};


#endif // STACKER_H
