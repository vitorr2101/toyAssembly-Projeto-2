#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/arit3.h"

#define MAX 20

void print(char *result, int reg[]){

    char delimitador[] = " ";
    char *r = strdup(result); // Crie uma cópia da string result para evitar modificá-la
    char *token = strtok(r, delimitador);

    // Define os registradores
    char *registro = strtok(NULL, delimitador); // Pegar o registro1 (por exemplo, "R2")

    int resultado = isRegister(registro);

    printf("Resultado esperado: %d\n", reg[resultado]);
    free(r);
}

