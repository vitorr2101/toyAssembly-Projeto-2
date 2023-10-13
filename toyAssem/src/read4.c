#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/read4.h"

#define MAX 20

char** read4(int n)
{
    char** recipe = (char**)malloc(n * sizeof(char*)); // matriz original
    char** r = (char**)malloc(n * sizeof(char*)); // Aloca espaço para a cópia da matriz
    if (recipe == NULL)
    {
        fprintf(stderr, "Erro na alocação de memória.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        recipe[i] = (char*)malloc(MAX * sizeof(char));
        if (recipe[i] == NULL) {
            fprintf(stderr, "Erro na alocação de memória.\n");
            exit(1);
        }
        scanf(" %99[^\n]", recipe[i]);
        getchar(); // Limpa o caractere de nova linha
    }
    //loop para ter a matriz original copiada
    for (int i = 0; i < n; i++)
    {
        r[i] = strdup(recipe[i]); // Copia cada string individualmente
    }

    for (int i = 0; i < n; i++)
    {
          free(recipe[i]); // Liberar a memória alocada para cada linha da matriz
    }
    free(recipe);
    return r;
}