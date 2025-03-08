/**
 * @file main.cpp
 * @author Odin's Ravens
 * @date 2025-03-08
 * @brief Image stacker user interface
 * 
 * interface to proccess user supplied images
 */

#include "Stacker.h"
#include <iostream>

int main() {
  int numImages;
  string outputFilename;

  // prompt user for number of images to process
  cout << "Enter the number of images to stack: ";
  cin >> numImages;

  Stacker stacker;

  if(!stacker.stackImages(numImages)) {
    cerr << "Error: stacking failed" << endl;
    return 1;
  }

  //prompt user for output filename
  cout << "Enter the output filename (including .ppm)";
  cin >> outputFilename;


  if (!stacker.writeImage(coutputFilename)) {
    cerr << "Error: could not save image " << outputFilename << "\n";
    return 1;
  }

  cout << "Image saved to "<< outputFilename << endl;
  return 0;
}
