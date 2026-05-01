# Proyecto: Calculadora Básica con Makefile

**Materia:** IoT / Sistemas Computacionales  
**Escuela:** ESCOM - IPN  
**Alumno:** Alonso Pardo Cordova  
**Fecha:** 30/04/2026

---

# 1. Descripción del proyecto

Este proyecto consiste en el desarrollo de una calculadora básica en lenguaje C, cuya finalidad es demostrar el uso de **Makefiles** para automatizar procesos de compilación, ejecución y limpieza de archivos dentro de un proyecto de software.

El programa realiza cuatro operaciones aritméticas fundamentales:

- Suma
- Resta
- Multiplicación
- División

El proyecto implementa un archivo **Makefile** que automatiza las tareas principales del desarrollo, permitiendo mantener un flujo de trabajo más organizado, reproducible y eficiente.

---

# 2. Objetivo

Aplicar el uso de Makefiles para:

- Automatizar la compilación del proyecto.
- Estandarizar la ejecución del programa.
- Organizar archivos fuente y ejecutables.
- Facilitar mantenimiento y reutilización del código.
- Excluir archivos innecesarios mediante `.gitignore`.

---

# 3. Estructura del proyecto

```bash
calculadora-makefile/
│
├── src/
│   ├── main.c
│   └── operaciones.c
│
├── include/
│   └── operaciones.h
│
├── bin/
│
├── Makefile
README.md
.gitignore
```

## Descripción de carpetas

| Carpeta/Archivo | Función |
|----------------|---------|
| `src` | Contiene el código fuente |
| `include` | Archivos de cabecera |
| `bin` | Ejecutables generados |
| `Makefile` | Automatización |
| `README.md` | Documentación |
| `.gitignore` | Exclusión de archivos |

---

# 4. Tecnologías utilizadas

- Lenguaje C
- GCC (GNU Compiler Collection)
- GNU Make / MinGW32-Make
- Git
- GitHub

---

# 5. Instalación y requisitos

## Requisitos

- GCC
- Make o MinGW32-Make
- Git

## Verificar instalación

```bash
gcc --version
mingw32-make --version
git --version
```

---
---

#Análisis del Makefile de ejemplo

Como parte de la actividad se reprodujo el ejercicio base proporcionado en clase, el cual consiste en un programa en C con un Makefile que automatiza compilación, ejecución y limpieza.

## Código fuente (`main.c`)

```c
#include <stdio.h>

int main(void) {
    printf("Hola desde un ejemplo basico de Makefile.\n");
    printf("Este programa fue compilado y ejecutado con make.\n");
    return 0;
}
```

Este programa tiene como objetivo mostrar un mensaje simple en consola para comprobar que el proceso de compilación y ejecución mediante `make` funciona correctamente.

---

## Código del Makefile

```make
CC = gcc
CFLAGS = -Wall -Wextra -O2
TARGET = hola
SRCS = main.c
OBJS = $(SRCS:.c=.o)

.PHONY: all run clean help rebuild

all: $(TARGET)

help:
	@echo "Objetivos disponibles:"
	@echo "  make         -> compila el programa"
	@echo "  make run     -> compila y ejecuta"
	@echo "  make clean   -> elimina archivos generados"
	@echo "  make rebuild -> limpia y vuelve a compilar"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all
```

---

## Explicación del Makefile

### Variables

| Variable | Función |
|----------|---------|
| `CC` | Define el compilador a utilizar (`gcc`) |
| `CFLAGS` | Configura opciones de compilación |
| `TARGET` | Nombre del ejecutable final |
| `SRCS` | Archivos fuente |
| `OBJS` | Archivos objeto generados |

### Explicación detallada

#### `CC = gcc`

Define el compilador del proyecto:

```make
CC = gcc
```

Esto evita repetir el nombre del compilador en múltiples partes.

---

#### `CFLAGS = -Wall -Wextra -O2`

Establece opciones para compilación:

```make
CFLAGS = -Wall -Wextra -O2
```

- `-Wall`: activa advertencias generales.
- `-Wextra`: advertencias adicionales.
- `-O2`: optimización del código.

Estas opciones ayudan a mejorar calidad y rendimiento.

---

#### `TARGET = hola`

Define el ejecutable:

```make
TARGET = hola
```

El programa compilado se llamará `hola`.

---

#### `SRCS = main.c`

Especifica archivos fuente:

```make
SRCS = main.c
```

---

#### `OBJS = $(SRCS:.c=.o)`

Genera archivos objeto automáticamente:

```make
OBJS = $(SRCS:.c=.o)
```

Convierte:

```bash
main.c -> main.o
```

Esto automatiza dependencias.

---

#### `.PHONY`

```make
.PHONY: all run clean help rebuild
```

Indica objetivos que no representan archivos físicos.

Esto evita conflictos si existe un archivo con el mismo nombre.

---

#### `all`

```make
all: $(TARGET)
```

Objetivo principal.

Al ejecutar:

```bash
make
```

se compila el proyecto completo.

---

#### `help`

```make
help:
```

Muestra comandos disponibles:

```bash
make help
```

Salida:

```bash
Objetivos disponibles:
  make
  make run
  make clean
  make rebuild
```

Mejora usabilidad.

---

#### Regla patrón `%.o: %.c`

```make
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
```

Automatiza compilación de `.c` a `.o`.

Ejemplo:

```bash
main.c -> main.o
```

Elementos:

- `$<` = archivo fuente
- `$@` = archivo destino

---

#### Construcción del ejecutable

```make
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@
```

Une archivos objeto para crear el programa final.

Ejemplo:

```bash
gcc -Wall -Wextra -O2 main.o -o hola
```

---

#### `run`

```make
run: $(TARGET)
	./$(TARGET)
```

Compila (si es necesario) y ejecuta:

```bash
make run
```

---

#### `clean`

```make
clean:
	rm -f $(OBJS) $(TARGET)
```

Elimina archivos generados:

- `.o`
- ejecutable

Comando:

```bash
make clean
```

---

#### `rebuild`

```make
rebuild: clean all
```

Hace limpieza y recompilación completa.

Comando:

```bash
make rebuild
```

---

## Resultados obtenidos

### Compilación

Comando:

```bash
mingw32-make
```

Salida:

```bash
gcc -Wall -Wextra -O2 -c main.c -o main.o
gcc -Wall -Wextra -O2 main.o -o hola
```

---

### Ejecución

Comando:

```bash
mingw32-make run
```

Salida:

```bash
Hola desde un ejemplo basico de Makefile.
Este programa fue compilado y ejecutado con make.
```

---

### Limpieza

Comando:

```bash
mingw32-make clean
```

Salida:

```bash
rm -f main.o hola
```

---

## Contribución a la automatización

Este Makefile permite:

- Compilar automáticamente.
- Crear archivos objeto.
- Enlazar ejecutables.
- Ejecutar el programa.
- Limpiar archivos temporales.
- Recompilar desde cero.
- Estandarizar flujo de trabajo.

La automatización reduce errores humanos, mejora mantenimiento y facilita trabajo colaborativo.
# 6. Funcionamiento del Makefile

## Código del Makefile

```make
CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/operaciones.c
OUT = bin/calculadora

all:
	mkdir -p bin
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./bin/calculadora.exe

clean:
	rm -rf bin/*
```

## Explicación

| Elemento | Descripción |
|----------|-------------|
| `CC` | Compilador |
| `CFLAGS` | Directorio de headers |
| `SRC` | Archivos fuente |
| `OUT` | Ejecutable final |
| `all` | Compila |
| `run` | Ejecuta |
| `clean` | Limpia archivos |

---

# 7. Instrucciones de uso

## Compilar

```bash
mingw32-make
```

## Ejecutar

```bash
mingw32-make run
```

## Limpiar

```bash
mingw32-make clean
```

---

# 8. Resultados obtenidos

Al ejecutar:

```bash
mingw32-make
```

Se obtuvo:

```bash
mkdir -p bin
gcc src/main.c src/operaciones.c -Iinclude -o bin/calculadora
```
<img width="602" height="65" alt="image" src="https://github.com/user-attachments/assets/24e8e6b7-41af-402c-97c7-31f958cf66fc" />


Al ejecutar:

```bash
.\bin\calculadora.exe
```

Resultado:

```bash
Suma: 15
Resta: 5
Multiplicacion: 50
Division: 2
```
<img width="688" height="113" alt="image" src="https://github.com/user-attachments/assets/7d3dff5a-6adc-476d-8331-a02cd7d2fcbc" />

Esto demuestra que el Makefile automatiza la compilación y ejecución.

---

# 9. Uso del archivo .gitignore

El archivo `.gitignore` evita subir archivos innecesarios al repositorio.

## Código

```gitignore
bin/
*.o
*.out
*.exe
.vscode/
.idea/
*.log
*.tmp
```

## Beneficios

- Mantiene limpio el repositorio.
- Reduce archivos basura.
- Facilita revisión.
- Mejora colaboración.

---

# 10. Repositorio Git

El proyecto se administra mediante Git y GitHub.

# 11. Conclusiones

El uso de Makefiles permite automatizar tareas repetitivas, reduciendo errores humanos y mejorando la organización del proyecto.

Se comprobó que mediante targets como `all`, `run` y `clean` es posible:

- Automatizar compilación
- Estandarizar ejecución
- Mantener orden del repositorio
- Mejorar mantenimiento del software

El archivo `.gitignore` complementa la organización del proyecto al excluir archivos temporales y ejecutables.

---

# 12. Autor

**Alonso Pardo Cordova**  
ESCOM - IPN  
Ingeniería en Sistemas Computacionales
