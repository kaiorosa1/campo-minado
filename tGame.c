#include <stdio.h>
#include <stdlib.h>
#include "tGame.h"

struct tgame{
    int state; // 0 if closed and 1 if it's already open
    int content; // vazia ou bomba ou numero de bombas vizinhas 
};


int inicia_position(tGame** g,int i,int j,int s,int c){
    int valido=0; // returns 0 if successfully started the position
    // // aloca espaco para a tabela e inicia os valores recebidos
    // tGame* position = (tGame*) malloc(sizeof(tGame));
    g[i][j].state = s;
    g[i][j].state = s;
    // position->state = s;
    // position->content = c;
    
    return valido;
}


void printPosition(tGame* g){
    if(g == NULL){
        printf("Invalid position\n");
        return;
    }
    printf("Estado: %d\n",g->state);
    printf("Conteudo: %c\n",g->content);
}

tGame** inicia_tabuleiro(int sz){
    
   tGame **tabuleiro = (tGame**) malloc(sz*sizeof(tGame*));
   // alocar espaco para of ponteiros itself
   tabuleiro[0] = (tGame*) malloc(sz*sizeof(tGame));
   int aux=0;
   for(aux=0; aux < sz; aux++){
       tabuleiro[aux] = (*tabuleiro + aux);
   }
    return tabuleiro;
}