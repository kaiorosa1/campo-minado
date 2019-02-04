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
    for(i=0;  i < sz; i++){
        for(j=0; j < sz; j++){
            if(g[i][j].state == 0){
                printf(" %c ",csd);
            }else{
                printf(" %c ",g[i][j].content);
            }
            
        }
        printf("\n");
    }
    printf("\n");
}