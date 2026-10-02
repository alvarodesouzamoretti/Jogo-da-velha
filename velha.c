#include <stdio.h>
#include <stdlib.h>

void desenhatabuleiro(char tabuleiro[][3]) {
    system("clear");
        printf("\n");
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++){
                printf(" %c ", tabuleiro[i][j]);
                if (j < 2) {
                    printf("|");
                }
            }
            printf("\n");
            if (i < 2) {
                printf("---+---+---\n");
            }
        }
    
        printf("\n");
    }
        

char jogar(char tabuleiro[][3], int posicao, char jogadorAtual) {
   int linha = (posicao - 1) / 3;
   int coluna = (posicao - 1) % 3;

   tabuleiro[linha][coluna] = jogadorAtual;

    return 1;
}


int main(int argc, char *argv[]){
    char tabuleiro[3][3] ={
        '1','2','3',
        '4','5','6',
        '7','8','9'
    };

    int jogada = 0;
    int posicao = 'B';

    while (jogada < 9){
        desenhatabuleiro(tabuleiro);

        printf("jogador %c, escolha uma posicao (1-9): ", (jogada % 2 == 0) ? 'X' : '0'); 
        scanf("%d", &posicao);

        if (posicao < 1 || posicao > 9) {
            printf("Posicao invalida! Escolha um numero entre 1 e 9.\n");
            printf("Pressione Enter para continunar ...");
            getchar();
            getchar();
            continue;
        }

        char jogadorAtual = (jogada % 2==0) ? 'X' : '0';
        if (!jogar(tabuleiro, posicao, jogadorAtual)) {
            printf("Posicao ja ocupada! Tente novamente.\n");
            printf("Pressione Enter para continunar ...");
            getchar();
            getchar();
            continue;
        }

        jogada++;
    }

    return 0;
} 

    /*int linha = (posicao - 1) / 3; 
    int coluna = (posicao - 1) %3;

    tabuleiro[linha][coluna] = jogadorAtual;
    return 1;*\