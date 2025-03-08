Name: Odin's Ravens
Date: 3/7/2025
Course: CSCI 325

Description:
This project implements an image stacking program that reads multiple .PPM images, averages their pixel values, and saves the processed image.
The program requires the user to manually enter each image filename and an output filename. 

Design decisions:
The design process followed the coding recomendation of simply getting a basic framework in place.
1. Read in an image
2. Store it in a class instance
3. Output it to a new file.  

From there, we built out the program to:
1. Read in all supplied images
2. Add each to a running total for pixel values
3. Divide the total by the number of images
4. Use the new averaged totals in writing to a new output file.

Directory Structure:
imageStacker/

-inputImages/  # place input .ppm files here

-outputImages/ # stacked images will be saved here

-Stacker.h     # defining the Stacker class

-Stacker.cpp   # Implementaion of the Stacker class

-main.cpp      # User interface for image stacking

-Makefile      # for compiling

-README.md     # documentation

How to Compile: "make" will utlize the provided Makefile

How to Run: "./image_stacker"

Follow Prompts: (with example input)

1. Enter the number of images to stack: 3
   
2. Enter filename 1 (inside inputImages/): image1.ppm
   
   Enter filename 2 (inside inputImages/): image2.ppm
   
   Enter filename 3 (inside inputImages/): image3.ppm
   
3. Enter the output filename (imcluding.ppm): stacked.ppm
   
4. A new file will be saved in the outputImages directory.
  
How to Clean and Recompile:  "make clean && make"


Collaboration:

Justin:
- basic framework/layout
- Stacker::Stacker()
- Stacker::stackImage()
- main.cpp
- README.md
  
Jacob:
- basic framework/layout
- Stacker::readImage()
- Stacker::writeImage()
- main.cpp
- Makefile
