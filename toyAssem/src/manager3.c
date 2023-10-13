#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../include/read4.h"
#include "../include/translate3.h"
#include "../include/arit3.h"
#include "../include/logica3.h"
#include "../include/memoria2.h"
#include "../include/print.h"


#define MAX 20
#define MAX_INSTRUCOES 100000
int main(void){

int n; //n linhas código fornecido
scanf("%d", &n);

int space = 32;
int reg[space];  //registradores
  for(int i = 0; i < space; i++)
  {
    reg[i] = 0;
  }

int slots = 1000;
int mem[slots]; //memória
  for(int i = 0; i < slots; i++)
  {
    mem[i] = 0;
  }

    char** result = read4(n);


    /*for(int i = 0; i < n ;i++){
      printf("%s\n", result[i]);
    }*/

    int index = 0;//endereço ou indice do código fornecido

    // Inicialize a tradução como uma string vazia
    char traducao[MAX];
    traducao[0] = '\0';

    for (int i = 0; i < MAX_INSTRUCOES && index < n; i++){

    char *acao = translate3(n, result[index], reg, traducao);

    if(strcmp(acao, "aritmetica") == 0){
        arit3(result[index], reg, space, n);
        index++;
    }else if(strcmp(acao, "logica") == 0){
        index = logica3(result[index], reg, space, n, index);
    }else if(strcmp(acao, "mov") == 0){
      index++;
    }else if(strcmp(acao, "memoria") == 0){
        memoria2(result[i], reg, mem, space, slots, n);
        index++;
    }else if(strcmp(acao, "print") == 0){
        print(result[index], reg);
        index++;
    }else{
        break;
    }

    printf("\nindex: %d\n", index);
    //printf("Endereço: %d\n", index);
    /*for(int i = 0; i < space; i++){
            printf("%d\n", reg[i]);
    }*/

    }
      for (int i = 0; i < n; i++)
      {
          free(result[i]); // Liberar a memória alocada para cada linha da matriz
      }
      free(result); // Liberar a memória alocada para a matriz
      return 0;
  }

