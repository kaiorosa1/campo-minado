#include <stdio.h>

int main(int argc, char* argv[]){
    // Verificar Parementros
    if(argc != 2){
        printf("ERRO: O diretorio de arquivos de configuração nao foi informado!\n");
        return 1;
    }
    // Inicializar o jogo
    // ler arquivo tabuleiro.txt
    FILE * filePointer = fopen(argv[1],"r");
    
    if(filePointer == NULL){
        printf("Nao foi possivel ler o tabuleiro.txt em %s\n",argv[1]);
        return 1;
    }
    // Pedir nome do usuario 
    
    //imprimir Estado inicial do tabuleiro 
    
    return 0;
}