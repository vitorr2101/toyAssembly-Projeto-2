#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "../include/arit3.h"
#include "../include/translate3.h"

#define MAX 20

int logica3(char *result, int reg[], int space, int n, int index){

    char delimitador[] = " ";

    char *r = strdup(result); // Crie uma cópia da string result para evitar modificá-la
    char *token = strtok(r, delimitador);

    int regSize = space; // Determina o tamanho da matriz reg

    int resposta = 0;
    printf("(%s)\n", token);
    if (strcmp(token, "BEQ") == 0 || strcmp(token, "BLT") == 0)
    {

    // Define os registradores
    char *destino = strtok(NULL, delimitador); // Pegar o destino (por exemplo, "R0")
    char *registro = strtok(NULL, delimitador); // Pegar o registro1 (por exemplo, "R2")
    char *endereco = strtok(NULL, delimitador); // Pegar o registro2 (por exemplo, "12")

    int destRegister = isRegister(destino);
    int regist = isRegister(registro);
    int enderecoDestino = atoi(endereco);

    if (destRegister >= 0 && regist >= 0)
    {
        printf("(%s %s %s)\n", destino, registro, endereco);
        // Verifique se os registradores são válidos e alocar espaço no registrador de destino
        if (destRegister < regSize)
        {
            // Realize a operação e armazene o resultado no registrador de destino
            if (strcmp(token, "BEQ") == 0)
            {
                // Verifica se os registradores são iguais
                if (reg[destRegister] == reg[regist])
                {
                    // (pule) para o endereço especificado
                    printf("%d e %d são iguais\n", reg[destRegister], reg[regist]);

                    resposta = enderecoDestino;
                }else{
                    resposta = index++;
                }
            }

            else //BLT
            {
                // Verifica se os registradores são iguais
                if (reg[destRegister] < reg[regist])
                {
                    printf("%d < %d\n", reg[destRegister], reg[regist]);
                    // (pule) para o endereço especificado
                    resposta = enderecoDestino;
                }else{
                    resposta = index++;
                }
            }
        }
    }
    }
        //caso especial JMP
        if (strcmp(token, "JMP") == 0 )
        {
            char *destino = strtok(NULL, delimitador);
            if (atoi(destino) <= n)
            {
                printf("jmp: %d\n", resposta);
                resposta = atoi(destino);
            }else{
                    resposta = index++;
                }
        }
     free(r);
     printf("%d", resposta);
     
return resposta;
}