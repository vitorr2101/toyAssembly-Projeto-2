#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 20

int isRegister3(char *str)
{
    // Verifica se a string está no formato "Rx" (onde x é um número de 0 a 31)
    if (strlen(str) >= 2 && str[0] == 'R')
    {
        char *numStr = str + 1; // Pule o caractere 'R' e pegue o número restante
        int num = atoi(numStr); // Converta a parte numérica em um inteiro

        if (num >= 0 && num <= 31)
        {
            return num; // Retorna o número do registrador
        }
    }

     return -1; // Não é um registrador válido
}

char *translate3(int n, char *result, int *reg, char *traducao){

    //sempre usando uma cópia para manter a recipe obtida em read inalterada
 char *r = (char *)malloc((strlen(result) + 1) * sizeof(char)); // Aloca espaço para a cópia da matriz

    strcpy(r, result);

    char delimitador[] = " ";

    // Use strtok para dividir a linha em palavras
    char *token = strtok(r, delimitador);
    printf("%s\n", r);
            if (strcmp(token, "MOV") == 0)
            {
                char *registro1 = strtok(NULL, delimitador); // Pegar o registro 1 (por exemplo, "R0")

                char *registro2 = strtok(NULL, delimitador); // Pegar o registro 2 (por exemplo, "R1")

                int destRegister = isRegister3(registro1);

            // Verifique se registro2 é um valor numérico
                int reg2 = isRegister3(registro2);
                int num;

                if (sscanf(registro2, "%d", &num) == 1) // Se registro2 for um valor numérico, atribua-o diretamente a R0
                {
                    reg[destRegister] = num;
                }else if(reg2 != -1)
                { // Caso contrário, registro2 deve ser um nome de registrador (Rn) válido
                    reg[destRegister] = reg[reg2];
                }
                else
                { // Lidar com caso em que registro2 não é um valor numérico nem um nome de registrador válido
                    printf("Erro: %s não é um valor numérico nem um registrador válido.\n", registro2);
                }
                strcpy(traducao,"mov");
                printf("(%d)\n", reg[destRegister]);

            }else if (strcmp(token, "ADD") == 0 || strcmp(token, "SUB") == 0 || strcmp(token, "MUL") == 0 || strcmp(token, "DIV") == 0 || strcmp(token, "MOD") == 0)
            {
            strcpy(traducao,"aritmetica");

            }else if (strcmp(token, "BEQ") == 0 || strcmp(token, "BLT") == 0 || strcmp(token, "JMP") == 0)
            {
            strcpy(traducao,"logica");

            }else if (strcmp(token, "LOAD") == 0 || strcmp(token, "STORE") == 0)
            {
            strcpy(traducao,"memoria");

            }else if (strcmp(token, "PRINT") == 0)
            {
            strcpy(traducao,"print");

            }else
            {
                traducao[0] = '\0';
            }

            token = strtok(NULL, delimitador); // Obtenha o próximo token
            //printf("(%s)\n", traducao);
    free(r);
    return traducao;
}
