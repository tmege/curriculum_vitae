# Interactive CV in C

## Description

This project implements a complete interactive CV using C data structures, specifically singly linked lists. It serves as a practical demonstration of dynamic memory management, modular code organization, and the use of complex structures.

## Architecture

```
cv/
├── inc/
│   └── cv.h           # Structure definitions and function prototypes
├── src/
│   ├── main.c         # Entry point and data population
│   ├── utils.c        # Creation functions and list management
│   ├── print.c        # Display functions and interactive menu
│   └── free.c         # Memory management and cleanup
├── obj/               # Object files (generated at build time)
├── Makefile           # Automated compilation
└── README.md          # This file
```

## Data Structures

### Main structures:

- **t_cv**: Main structure containing all CV sections
- **t_competencias**: Groups all skill categories
- **t_proyecto**: Linked list of projects
- **t_formacion**: Linked list of education entries
- **t_experiencia**: Linked list of professional experience
- **t_skill**: Generic linked list for skills and items

All lists use singly linked nodes (`next`).

## Build and Usage

### Compile:
```bash
make
```

### Run:
```bash
./cv
# or
make run
```

### Check memory leaks with Valgrind:
```bash
make valgrind
```

### Clean:
```bash
make clean   # Remove .o files
make fclean  # Remove .o files and executable
make re      # Recompile everything
```

## Features

- Dynamic memory management (malloc/free)
- Singly linked lists
- Modular and organized code
- No memory leaks (verified with Valgrind)
- 42-compliant Makefile
- Unicode terminal interface
- Interactive menu navigation
- Scalable and maintainable structure

## Concepts Demonstrated

- **Structures and typedef**
- **Linked lists**
- **Dynamic memory management**
- **Code modularization**
- **Advanced Makefile**
- **Headers and prototypes**
- **Recursive memory deallocation**

## License

This project is open source and available as an educational example.

---

```c
/* TODO: hire(this_candidate); */
```
