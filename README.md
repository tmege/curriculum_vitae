# 📄 CV en C - Curriculum Vitae Generator

## Descripción

Este proyecto implementa mi CV completo utilizando estructuras de datos en C, específicamente listas enlazadas simples. Es un ejemplo práctico de gestión dinámica de memoria, organización modular de código y uso de estructuras complejas.

## Arquitectura

```
cv/
├── cv.h           # Definiciones de estructuras y prototipos
├── main.c         # Punto de entrada y población de datos
├── utils.c        # Funciones de creación y gestión de listas
├── print.c        # Funciones de visualización
├── free.c         # Gestión de memoria
├── Makefile       # Compilación automatizada
└── README.md      # Este archivo
```

## Estructuras de datos

### Principales estructuras:

- **t_cv**: Estructura principal que contiene todas las secciones
- **t_competencias**: Agrupa todas las competencias técnicas
- **t_proyecto**: Lista enlazada de proyectos
- **t_formacion**: Lista enlazada de formación académica
- **t_experiencia**: Lista enlazada de experiencia profesional
- **t_skill**: Lista enlazada genérica para habilidades

Todas las listas utilizan nodos enlazados simples (`next`).

## Compilación y uso

### Compilar:
```bash
make
```

### Ejecutar:
```bash
./cv
# o
make run
```

### Verificar memory leaks con Valgrind:
```bash
make valgrind
```

### Limpiar:
```bash
make clean   # Elimina .o
make fclean  # Elimina .o y ejecutable
make re      # Recompila todo
```

## Características

✅ Gestión dinámica de memoria (malloc/free)
✅ Listas enlazadas simples
✅ Código modular y organizado
✅ Sin memory leaks (comprobado con Valgrind)
✅ Makefile con normas de 42
✅ Interfaz visual en terminal con Unicode
✅ Estructura escalable y mantenible

## Conceptos demostrados

- **Estructuras y typedef**
- **Listas enlazadas**
- **Gestión de memoria dinámica**
- **Modularización de código**
- **Makefile avanzado**
- **Headers y prototipos**
- **Liberación recursiva de memoria**

## Posibles mejoras

- [ ] Exportar a JSON/XML
- [ ] Búsqueda de competencias específicas
- [ ] Filtrado por categorías
- [ ] Ordenación por fechas
- [ ] Estadísticas (años de experiencia, etc.)
- [ ] Interfaz interactiva (menú)

## Licencia

Este proyecto es de código abierto y está disponible como ejemplo educativo.

---

*Proyecto creado como demostración de competencias en C y gestión de estructuras de datos.*

```c
/* TODO: recrutar_talento(este_candidato); */
```
