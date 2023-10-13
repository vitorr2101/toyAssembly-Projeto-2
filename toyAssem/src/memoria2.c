#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/arit3.h"

#define MAX 20

void memoria2(char *result, int reg[], int mem[], int space, int slots, int n){

    char delimitador[] = " ";
    char *r = strdup(result); // Crie uma cópia da string result para evitar modificá-la
    char *token = strtok(r, delimitador);

    int memSize = slots;
    int regSize = space; // Determina o tamanho da matriz reg

    // Define os registradores
    char *registro = strtok(NULL, delimitador); // Pegar o registro1 (por exemplo, "R2")
    char *memoria = strtok(NULL, delimitador); // Pegar o registro2 (por exemplo, "R4")

    int regist = isRegister(registro);
    int memoriaDestino = isRegister(memoria);

if (regist >= 0 && memoriaDestino >= 0)
{
    // Verifique se os registradores são válidos e alocar espaço no registrador de destino
    if (regist < regSize && regist < memSize)
    {
        if (strcmp(token, "LOAD") == 0){
            reg[regist] = mem[memoriaDestino];

            printf("Valor: %d,registro: R%d\n", reg[regist], regist);
        }
        else {//store
            mem[memoriaDestino] = reg[regist];

            printf("Valor: %d, memória: R%d\n", mem[memoriaDestino], memoriaDestino);
        }
    }
}
    free(r);
}