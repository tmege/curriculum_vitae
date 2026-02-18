# Interactive CV

## Description

This project implements my full CV using data structures in C, specifically singly linked lists. It is a practical example of dynamic memory management, modular code organization and the use of complex structures.

## Architecture

```
cv/
├── cv.h           # Structure definitions and prototypes
├── main.c         # Entry point and data population
├── utils.c        # Creation and list management functions
├── print.c        # Display functions
├── free.c         # Memory management
├── Makefile       # Automated compilation
└── README.md      # This file
```

## Data structures

### Main structures:

- **t_cv**: Main structure containing all sections
- **t_competencies**: Groups all technical skills by category
- **t_project**: Linked list of projects
- **t_education**: Linked list of education entries
- **t_experience**: Linked list of professional experience
- **t_skill**: Generic linked list for skills

All lists use singly linked nodes (`next`).

## Compilation and usage

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

### Check for memory leaks with Valgrind:
```bash
make valgrind
```

### Clean:
```bash
make clean   # Remove .o files
make fclean  # Remove .o files and binary
make re      # Recompile everything
```

## Features

✅ Dynamic memory management (malloc/free)
✅ Singly linked lists
✅ Modular and organized code
✅ No memory leaks (verified with Valgrind)
✅ Makefile following 42 norms
✅ Terminal visual interface with Unicode
✅ Scalable and maintainable structure

## Concepts demonstrated

- **Structures and typedef**
- **Linked lists**
- **Dynamic memory management**
- **Code modularization**
- **Advanced Makefile**
- **Headers and prototypes**
- **Recursive memory freeing**

## License

This project is open source and available as an educational example.

---

*Project created as a demonstration of C skills and data structure management.*

```c
/* TODO: hire_talent(this_candidate); */
```
