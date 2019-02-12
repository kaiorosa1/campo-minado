#include <stdio.h>
#include <stdlib.h>
#include "tGame.h"

struct tgame{
    int state; // 0 if closed and 1 if it's already open
    int content; // vazia ou bomba ou numero de bombas vizinhas 
};


void  inicia_position(tGame** g,int i,int j,int s,int c){
    // it will possibly have a verification step here in the future
    g[i][j].state = s;
    g[i][j].content = c;
}


void printPosition(tGame** g,int i, int j){
    if(g == NULL){
        printf("Invalid position\n");
        return;
    }
    printf("\n");
    printf("coordenadas: %d %d\n",i,j);
    printf("Estado: %d\n",g[i][j].state);
    printf("Conteudo: %c\n",g[i][j].content);
    printf("\n");
}

tGame** inicia_tabuleiro(int sz){
    
   tGame **tabuleiro = (tGame**) malloc(sz*sizeof(tGame*));
   // alocar espaco para of ponteiros itself
   int aux=0;
   for(aux=0; aux < sz; aux++){
        tabuleiro[aux] = (tGame*) malloc(sz*sizeof(tGame));
   }
    return tabuleiro;
}

void print_tabuleiro(tGame** g, int sz,int csd){
    printf("\n");
    int i=0,j=0;
    int sideJ=0;
    int sideI=0;
    // I'll think of a better way to display the table
    printf("    ");
    for(sideI=0;sideI < sz ;sideI++){
        printf("%.3d  ",sideI);
    }
    printf("\n");
    for(i=0;  i < sz; i++){
        for(j=0; j < sz; j++){
            if(j == 0){
                printf("%.3d",sideJ);
                sideJ++;
            }
            if(g[i][j].state == 0){
                printf(" %c%c%c ",csd,csd,csd);
            }else{
                printf("  %c  ",g[i][j].content);
            }
            
        }
        printf("\n");
    }
    printf("\n");
}

void calcularBombas(tGame** g,int sz,char bomba){
    // calcula o numero de bombas vizinhas percorrendo todo o tabuleiro
    int i=0,j=0;
    for(i=0;  i < sz; i++){
        for(j=0; j < sz; j++){
           // verificar bomba em cada posicao 
           conta_bomba_position(g,i,j,sz,bomba);
         
        }
    }
    
}

void conta_bomba_position(tGame **g,int i,int j, int sz, char bomba){
    // verify all the position before continuing
    int up = i - 1;
    int down= i + 1;
    int front = j + 1;
    int back = j - 1;
    
    // conta bomba
    char conta = '0';
    
    // verifica as posicoes para nao acessar indices invalidos
    if(up >= 0 && up < sz && g[up][j].content == bomba){
        conta++;
    }
    if(down >= 0 && down < sz && g[down][j].content == bomba){
        conta++;
    }
    if(front >= 0 && front < sz && g[i][front].content == bomba){
        conta++;
    }
    if(back >= 0 && back < sz && g[i][back].content == bomba){
        conta++;
    }
    if(back >= 0 && back < sz && up >=0 && up < sz && g[up][back].content == bomba){
        conta++;
    }
    if(up >= 0 && up < sz && front >=0 && front < sz && g[up][front].content == bomba){
        conta++;
    }
    if(down >= 0 && down < sz && back >=0 && back < sz && g[down][back].content == bomba){
        conta++;
    }
    if(down >= 0 && down < sz && front >=0 && front < sz && g[down][front].content == bomba){
        conta++;
    }
    
    // so coloca no tabuleiro o numero de bombas vizinhas caso tenha bombas vizinhad e nao seja bomba
    if(g[i][j].content != bomba && conta != '0'){
        g[i][j].content = conta;
    }
    
}


int realizarJogada(tGame** g,int x, int y, int sz, char bomba,char vazia, int *jogada,int nBombas){
    
    // verifica validade
    if(!((x >= 0 && x < sz) && (y >= 0 && y < sz))){
        printf("Posicao invalida (FORA DO TABULEIRO)\n");
        return -5;
    }
    else if(g[x][y].state  == 1){
        printf("Posicao invalida (JA ABERTA)!\n");
        return -5;
    }
    else{
        // registra jogada para escrever em um arquivo de saida
        if(analisaJogo(g,sz,x,y) ==  -3){
            return -3;
        }
        
        // analisa natureza das jogada validas
        if(g[x][y].content == vazia){
            floodFillVazias(g, sz,bomba, vazia, x, y);
        }
        if(g[x][y].content == bomba){
            g[x][y].state  = 1;
            return -1;
        }else{
            g[x][y].state  = 1;
        }
        if(verificaVencedor(g,sz,nBombas) == 1){
            return -2;
        }
        
        // aumenta o numero de jogadas pois foi valida
        (*jogada)++;
    }
    return 0;
}

void floodFillVazias(tGame** g,  int sz, char bomba, char vazia, int x, int y){
    // Need some tweaking to be full-fledged functional
    if(x >= sz || y >= sz){
        return;
    }
    if(x < 0 || y < 0){
        return;
    }
    if(g[x][y].state == 1){
        return;
    }
    if(g[x][y].content == bomba || g[x][y].content != vazia){
         return;
    }
   
    g[x][y].state = 1;
    
    floodFillVazias(g, sz, bomba, vazia, x + 1, y);
    floodFillVazias(g, sz, bomba, vazia, x - 1, y);
    floodFillVazias(g, sz, bomba, vazia, x, y + 1);
    floodFillVazias(g, sz, bomba, vazia, x, y - 1);
    
}

void restartGame(tGame** g, int sz, int* nJogada){
    int i,j;
    *nJogada = 1;
    for(i=0;  i < sz; i++){
        for(j=0; j < sz; j++){
            if(g[i][j].state == 1){
               g[i][j].state = 0;
            }
        }
    }
   
}

int verificaVencedor(tGame** g, int sz, int nBombas){
    // verifica se o jogador ganhou a partida;
    // contar o numero de bombas e subtrair do numero de posicoes disponiveis
    // se o numero de posicoes abertas for igual a esse numero ele ganhou
    int pDisponiveis = sz*sz;
    int abertas = 0;
    int ganhaJogo = pDisponiveis - nBombas;
    // nao precisamos nos preocupar com as bombas pois o jogo termina antes desse ponto 
    // caso tenha uma bomba aberta
    int i,j;
    for(i=0;  i < sz; i++){
        for(j=0; j < sz; j++){
            if(g[i][j].state == 1){
               abertas++;
            }
        }
    }
    
    if(abertas == ganhaJogo){
        return 1;
    }
    return 0;
}

int analisaJogo(tGame** g, int sz, int x, int y){
    // escrever arquivo com as jogadas e o impacto
    // impacto sao quantas casas foram abertas
    FILE * fp = fopen("analiseJogo.txt","w");
    if(fp == NULL){
        printf("ERRO: Nao foi possível salvar arquivo para analise.\n");
        return -3;
    }
    fclose(fp);
    return 0;
}

void freeGame(tGame** g,int sz){
    // liberar o espaco alocado para a matriz do jogo
}