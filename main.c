#include <stdio.h>
#include <stdlib.h>
#include "tGame.h"

void printTableChar(char **c, int tableSize);

int main(int argc, char* argv[]){
    
    char nomeJogador[1000];
    
    // Verificar Parametros
    if(argc != 2){
        printf("ERRO: O diretorio de arquivos de configuração nao foi informado!\n");
        return 1;
    }
    // Inicializar o jogo
    //  abrir arquivo tabuleiro.txt
    FILE * filePointer = fopen(argv[1],"r");
    
    // verificar se foi possivel ler o arquivo
    if(filePointer == NULL){
        printf("Nao foi possivel ler o tabuleiro.txt em %s\n",argv[1]);
        return 1;
    }
    
    // Pedir nome do usuario 
    printf("Digite o nome do jogador:\n");
    scanf("%s",nomeJogador);
    // Mostrar nome digitado
    printf("Digitado (%s)\n",nomeJogador);
    
    //Lendo cada linha do arquivo
    
    // primeira linha do arquivo 3 characters;
    //fechadas - abertas bomba - aberta vazia
    int tableSize=0;
    char fechada = fgetc(filePointer);
    char bomba = fgetc(filePointer);
    char vazia = fgetc(filePointer);
    
    
    // segunda linha numero de linhas e de columas do tabuleiro
    fscanf(filePointer,"%d %d\n",&tableSize,&tableSize);
    
    //PRINTING TESTS
    printf("Fechada : %c\n",fechada);
    printf("Bomba : %c\n",bomba);
    printf("Vazia: %c\n",vazia);
    printf("Table Size: %d\n",tableSize);
    
    //inicializa tabuleiro
    tGame** game = inicia_tabuleiro(tableSize);
    
    int i=0,j=0;
    // copiar em uma tabela as posicoes depois verifcar e trocar
    char**copyTable = (char**) malloc(tableSize*sizeof(char*));
    // alocar espaco para of ponteiros itself
    copyTable[0] = (char*) malloc(tableSize*sizeof(char));
    int aux=0;
    for(aux=0; aux < tableSize; aux++){
       copyTable[aux] = (*copyTable + aux);
    }
    
    // I FINALLY DISCOVER THE PROBLEM IT'S IN THE TWO DIMENSION ARRAYYY
    do
    { 
        // lendo cada caractere 
        char c = fgetc(filePointer); 
        if(c != '\n'){
            copyTable[i][j] = c;
            j++;
        }else{
            j=0;
            i++;
        }
         
        // sai do loop quando eh o fim do arquivo
        if (feof(filePointer)) {
            break;
        }
            
  
        
    }  while(1);
    printf("\n");
    // print copied table
    printTableChar(copyTable,tableSize);
    // print the entire table
    //print_tabuleiro(game,tableSize,fechada);
    
    // //imprimir Estado inicial do tabuleiro 
    
    
    
    //fechar o arquivo
    fclose(filePointer);
    return 0;
}

void printTableChar(char **c, int tableSize){
    int k=0,m=0;
    for(k=0;  k < tableSize; k++){
        for(m=0; m < tableSize; m++){
            printf("|%c|",c[k][m]);
        }
        printf("\n");
    }
    
}