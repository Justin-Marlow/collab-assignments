# Doxygen Testing

## Overview

This project demonstrates how to use Doxygen to generate HTML documentation from a C++ codebase. The codebase includes a small class hierarchy with `Employee`, `Supervisor`, and `Officer` classes, each representing different types of employees with unique pay calculation logic.

---

## Files Included

- `Employee.h` / `Employee.cpp`: Base class for all employees.
- `Supervisor.h` / `Supervisor.cpp`: Derived from `Employee`, includes logic for supervising others.
- `Officer.h` / `Officer.cpp`: Derived from `Employee`, includes an "evilness" factor.
- `main.cpp`: Runs a series of tests on all classes.
- `doxyConfig`: Doxygen configuration file used to generate documentation.
- `html/`: Doxygen-generated HTML documentation folder.
- `latex/`: Doxygen-generated LaTeX documentation folder.

---

## How to Generate Documentation

To regenerate the documentation using Doxygen:

1. Open a terminal and navigate to the project folder.
2. Run the following command:

```bash
doxygen doxyConfig
