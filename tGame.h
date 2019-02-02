#ifndef HEAP_H
#define TGAME_H

// for lack of a better name
// this holds the state of each position 
typedef struct tgame tGame;

// inicia a posicao com o estado e o conteudo
void inicia_position(tGame** g,int i,int j,int s,int c);

// aloca memoria para o tabuleiro
tGame** inicia_tabuleiro(int sz);

// prints a specific position
void printPosition(tGame* g);

// print the entire table
void print_tabuleiro(tGame** g, int sz,int int csd);

// desaloca memoria alocada de uma tGame
void freePosition(tGame* g);

#endif /* TGAME_H */