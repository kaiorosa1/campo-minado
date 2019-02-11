#include <stdio.h>
#include <stdlib.h>
#include "tGame.h"

int askUser();
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
    scanf("%[^\n]s",nomeJogador);
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
    
    //inicializa tabuleiro
    tGame** game = inicia_tabuleiro(tableSize);
    
    int i=0,j=0;
    
    do
    { 
        // lendo cada caractere 
        char c = fgetc(filePointer); 
        if(c  == '0'){
            inicia_position(game,i,j,0,vazia);
            j++;
        }else if(c == '1'){
           inicia_position(game,i,j,0,bomba);
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
    
    // calcular bombas e place them in the right place
    
    calcularBombas(game,tableSize,bomba);
    //imprimir Estado inicial do tabuleiro 
    int sair = 0,x = 0,y = 0;
    int nJogada=1;
    
    do{
        // print the entire table
        print_tabuleiro(game,tableSize,fechada);
        
        printf("%s Jogada: %d\n",nomeJogador,nJogada);
        // recebe jogada
        printf("Digite a posicao (x e y):\n");
        scanf("%d %d",&x,&y);
        
        printf("Digitado(%d %d)\n",x,y);
        
        // Pedir Jogada do Usuario
        // verificar e realizar jogada
        sair = realizarJogada(game, x, y, tableSize, bomba, vazia, &nJogada);
        
        if(sair == -1){
            print_tabuleiro(game,tableSize,fechada);
            printf("%s Perdeu!\n",nomeJogador);
            // as the user if they want to continue playing before ending the game
            sair = askUser();
        }
        if(sair == -2){
            printf("%s Ganhou!\n",nomeJogador);
            sair = askUser();
        }
        if(sair == -3){
            break;
        }
        if(sair== - 4){
            // limpar jogo para reiniciar
            restartGame(game,tableSize,&nJogada);
        }
       
        
    }
    while(1);
    
    
    
    //fechar o arquivo
    fclose(filePointer);
    return 0;
}

int askUser(){
    int cod =0;
    char answer;
    printf("Deseja jogar novamente?(y or n)\n");
    scanf(" %c",&answer);
    
    if(answer == 'n' || answer == 'N'){
        cod=-3; // codigo para sair
    }else if(answer == 'y' || answer == 'Y'){
        cod =-4;// codigo para reiniciar o jogo;
    }else{
       cod=-3; // mudar depois esse behavior 
    }
    return cod;
}
