#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

int isRegister(char *str){

    if (str == NULL) {
        return -1; // Trate o caso de str ser um ponteiro nulo
    }

    // Verifica se a string está no formato "Rx" (onde x é um número de 0 a 31)

    if (strlen(str) >= 2 && str[0] == 'R') {
        char *numStr = str + 1; // Pule o caractere 'R' e pegue o número restante
        int num = atoi(numStr); // Converta a parte numérica em um inteiro

        if (num >= 0 && num <= 31) {
            return num; // Retorna o número do registrador
        }
    }
    return -1; // Não é um registrador válido
}

   void arit3(char *result, int reg[], int space, int n){

    char delimitador[] = " ";
    char *r = strdup(result); // Crie uma cópia da string result para evitar modificá-la
    char *token = strtok(r, delimitador);

    int regSize = space; // Determina o tamanho da matriz reg

    // Define os registradores
    char *destino = strtok(NULL, delimitador); // Pegar o destino (por exemplo, "R0")
    char *registro1 = strtok(NULL, delimitador); // Pegar o registro1 (por exemplo, "R2")
    char *registro2 = strtok(NULL, delimitador); // Pegar o registro2 (por exemplo, "R4")

    int destRegister = isRegister(destino);
    int reg1 = isRegister(registro1);
    int reg2 = isRegister(registro2);

    if (destRegister >= 0 && reg1 >= 0 && reg2 >= 0)
    {
        // Verifique se os registradores são válidos e alocar espaço no registrador de destino
        if (destRegister < regSize)
        {
            // Realize a operação e armazene o resultado no registrador de destino
            if (strcmp(token, "ADD") == 0) {
                reg[destRegister] = reg[reg1] + reg[reg2];
            } else if (strcmp(token, "SUB") == 0) {
                reg[destRegister] = reg[reg1] - reg[reg2];
            }
            else if (strcmp(token, "MUL") == 0) {
                reg[destRegister] = reg[reg1]*reg[reg2];
            }
            else if (strcmp(token, "DIV") == 0) {
                reg[destRegister] = reg[reg1]/reg[reg2];
            }
            else if(strcmp(token, "MOD") == 0){
                reg[destRegister] = reg[reg1]%reg[reg2];
            }
            else{
                printf("Erro: Registrador de destino inválido: %s\n", destino);
            }
        }
    }
    printf("(%d %d %d) [%d]\n", destRegister, reg1, reg2, reg[destRegister]);

    free(r);
}
