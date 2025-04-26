# Custom Deque Implementation (CSCI 325)

## Overview

This project implements a custom double-ended queue (deque) using a dynamic 2D array structure known as a blockmap, similar in concept to the internal structure of STL deques. The container supports efficient insertion and removal from both the front and back, as well as random access via indexing.

The implementation also includes an interactive, automated test suite called the Deque Gauntlet, which performs thousands of randomized operations and cross-validates against a `std::vector` to ensure correctness.

---

## Features

- `push_front()` / `push_back()` — Add to front or back
- `pop_front()` / `pop_back()` — Remove from front or back
- `front()` / `back()` — Access the first or last item
- `operator[]` — Index-based access
- `empty()` — Check if deque is empty
- `size()` — Return number of elements
- Dynamic resizing of internal structure in both directions
- Stress-tested with 1000s of operations

---

## Files

- `deque.h` — Header file for the Deque class
- `deque.cpp` — Full implementation of Deque methods
- `main.cpp` — Interactive test driver and validation system
- `Makefile` — Build configuration
- `README.md` — This file

---

## Usage

### To Compile:
make

### To Run:
./deque_test

You will be prompted to:
- Enter the number of operations for each run
- Choose between a reproducible run (same seed) or a new random run
- View comparison samples between your Deque and `std::vector` to validate behavior

### To Clean Build Files:
make clean

---

## Automated Test Harness ("Deque Gauntlet")

The `main.cpp` file includes a full-scale test harness that:
- Randomly performs a user-defined number of operations
- Compares your Deque against a `std::vector` reference
- Asserts correctness for size, front/back values, and indexed access
- Supports reproducible runs by tracking and reusing random seeds
- Outputs random comparison samples (with GO/NO-GO indicators)

---

## What Works
- All required Deque functionality  
- All operations perform correctly against reference `std::vector`  
- Memory is correctly allocated and freed  
- 100% pass rate on 5000 operation stress tests

---

## Known Issues

There are no known bugs. All operations pass correctness checks and edge cases are handled.

---