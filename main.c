#include <stdio.h>
#include <stdlib.h>
#include "tGame.h"

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
    do
    { 
        // lendo cada caractere 
        char c = fgetc(filePointer); 
        if(c == '1'){
            //game[i][j].state =0;
            //game[i][j].content = bomba;
        }
        
        // sai do loop quando eh o fim do arquivo
        if (feof(filePointer)) 
            break ; 
  
        printf("%c", c); 
    }  while(1);
    
    // teste tGame
    //tGame* gameTeste = inicia_tGame(1,bomba);
    // proximas linhas 1 bomba e 0 vazia
    //printPosition(gameTeste);

    //imprimir Estado inicial do tabuleiro 
    
    
    
    //fechar o arquivo
    fclose(filePointer);
    return 0;
}