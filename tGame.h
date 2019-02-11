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
void printPosition(tGame** g,int i, int j);

// print the entire table
void print_tabuleiro(tGame** g, int sz,int csd);

// calcula as bombas e adiciona no tabuleiro
void calcularBombas(tGame** g,int sz, char bomba);

// receber jogadas e verificar a validez
int realizarJogada(tGame** g,int x, int y, int sz, char bomba,char vazia, int *jogada);

// implementa o algoritmo flood fill para abrir as posicoes vazias
void floodFillVazias(tGame** g, int sz, char bomba, char vazia, int x, int y);

// conta as bombas em uma dada posicao
void conta_bomba_position(tGame **g,int i,int j,int sz,char bomba);

// reinicia o jogo para o estado inicial
void restartGame(tGame** g, int sz, int* nJogada);

// verifica se o jogador ganhou a partida
int verificaVencedor(tGame** g, int sz);

// desaloca memoria alocada de uma tGame
void freePosition(tGame* g);

#endif /* TGAME_H */