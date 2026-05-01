CC = gcc
CFLAGS = -Iinclude
SRC = src/main.c src/operaciones.c
OUT = bin/calculadora

all:
	mkdir -p bin
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -rf bin/*