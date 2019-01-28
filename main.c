#include <stdio.h>

int main(int argc, char* argv[]){
    
    char nomeJogador[1000];
    
    // Verificar Parementros
    if(argc != 2){
        printf("ERRO: O diretorio de arquivos de configuração nao foi informado!\n");
        return 1;
    }
    // Inicializar o jogo
    // ler arquivo tabuleiro.txt
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
    //imprimir Estado inicial do tabuleiro 
    
    //Lendo cada linha do arquivo
    
    // primeira linha do arquivo 3 characters;
    //fechadas - abertas bomba - aberta vazia
      
    // segunda linha numero de linhas e de columas do tabuleiro
    
    // proximas linhas 1 bomba e 0 vazia
    
    fclose(filePointer);
    return 0;
}