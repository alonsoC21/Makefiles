#include <stdio.h>
#include "operaciones.h"

int main() {
    int a = 10, b = 5;

    printf("Suma: %d\n", suma(a, b));
    printf("Resta: %d\n", resta(a, b));
    printf("Multiplicacion: %d\n", multiplicacion(a, b));
    printf("Division: %d\n", division(a, b));

    return 0;
}