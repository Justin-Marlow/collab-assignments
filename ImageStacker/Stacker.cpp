/**
 * @file Stacker.cpp
 * @author Odin's Ravens
 * @date 2025-03-07
 * @brief Implementation of Stacker
 * 
 * Implementation of image stacker
 */


#include "Stacker.h"
#include <iostream>
#include <fstream>

using namespace std;

/**
 * @brief Constructor with default values
 */
Stacker::Stacker() : magic_number(""), width(0), height(0), max_color(0) {}



/**
 * @brief Reads a single image and add pixel values to the accumulator.
 *
 * @param filename The name of the image file to read
 * @return True if the read was successful, false otherwise
 */
bool Stacker::readImage(const string& filename) {
  string filepath = "inputImages/" + filename; // looks in the inputImages directory
  ifstream file(filepath);
  if (!= file) {
    cerr << "Error: Cannot open file " << filepath << endl;
    return false;
  }

  string fileMagic;
  int fileWidth = 0, fileHeight = 0, fileMaxColor = 0;

  // Read header
  file >> fileMagic >> fileWidth >> fileMaxColor;

  if (magic_number.empty()) {
      magic_number = fileMagic;
      width = fileWidth;
      height = fileHeight;
      max_color = fileMaxColor;
      pixels.resize(width * height, {0,0,0});  // running totals
  } else if (width != fileWidth || height != fileHeight || max_color != fileMaxColor) {
    cerr << "Error: Image " << filename << " dimensions do not match the first image!" << endl;
    return false;
  }

  // Read in pixel data
  for (int i = 0; i < width * height; i++) {
    int r, g, b;
    file >> r >> g >> b;
    pixels[i].red += r;
    pixels[i].green += g;
    pixels[i].blue += b;
  }

  file.close();
  cout << "Successfully read: " << filepath << endl;
  return true;
  
}


/**
 * @brief Stacks multiple images by averaging pixel values
 *
 * @param numImages The number of images to be stacked.
 * @return True if stacked successfully, false otherwise
 */
bool Stacker::stackImages(int numImages) {
  for (int i = 0; i < numImages; ++i) {
    string filename;
    cout << "Enter filename " << i + 1 << " (inside inputImages/): ";
    cin >> filename;

    if (!readImage(filename)) {
      cerr << "Error: Unable to read image " << filename << endl;
      return false;
    }
  }

  // Average the values
  for (auto& pixel : pixels) {
    pixel.red /= numImages;
    pixel.green /= numImages;
    pixel.blue /= numImages;
  }

  cout << "Successfully stacked images" << endl;
  return true;
}


/**
 * @brief Writes the new image
 * 
 * @param outputFilename The name of the  output file
 * @return True if the image saved successfully, false otherwise.
 */
bool Stacker::writeImage(const string& outputFilename) {
  string filepath = "outputImages/" + outputFilename; // writes to outputImages directory
  ofstream file(filepath);
  if (!file) {
    cerr << "Error: Cannot create file " << filepath << endl;
    return false;
  }

  // write header file
  file << magic_number << "\n";
  file << width << " " << height << "\n";
  file << max_color << "\n";

  // write pixel data
  for (const auto& pixel : pixels) {
    file << pixel.red << " " << pixel.green << " " << pixel.blue << "\n";
  }

  file.close();
  cout << "Successfully saved to " << filepath << endl;
  return true;
}
