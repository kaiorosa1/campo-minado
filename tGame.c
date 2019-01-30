#include <stdio.h>
#include <stdlib.h>
#include "tGame.h"

struct tgame{
    int state; // 0 if closed and 1 if it's already open
    int content; // vazia ou bomba ou numero de bombas vizinhas 
};


tGame* inicia_tGame(int s,int c){
    // aloca espaco para a tabela e inicia os valores recebidos
    tGame* position = (tGame*) malloc(sizeof(tGame));
    position->state = s;
    position->content = c;
    
    return position;
}


void printPosition(tGame* g){
    if(g == NULL){
        printf("Invalid position\n");
        return;
    }
    printf("Estado: %d\n",g->state);
    printf("Conteudo: %c\n",g->content);
}