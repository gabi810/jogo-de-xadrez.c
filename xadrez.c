#include <stdio.h>

// Constantes para movimentos
#define bispo_passos 5
#define torre_passos 5
#define rainha_passos 8

// Funções recursivas (Nível Mestre)
void moverbispo(int passos) {
    if(passos == 0) return;
    printf("cima\n");
    printf("direita\n");
    moverbispo(passos - 1);
}

void movertorre(int passos) {
    if(passos == 0) return;
    printf("direita\n");
    movertorre(passos - 1);
}

void moverrainha(int passos) {
    if(passos == 0) return;
    printf("esquerda\n");
    moverrainha(passos - 1);
}

int main() {
    int opcao;
    int i, j;

    do {
        printf("\n===== menu de movimentos =====\n");
        printf("1 - nível novato (bispo, torre, rainha com loops)\n");
        printf("2 - nível aventureiro (cavalo com loops aninhados)\n");
        printf("3 - nível mestre (recursão e condições multiplas)\n");
        printf("0 - sair\n");
        printf("escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                // Bispo com for
                printf("\nmovimento do bispo:\n");
                for(i = 0; i < bispo_passos; i++) {
                    printf("cima\n");
                    printf("direita\n");
                }

                // Torre 
                printf("\nmovimento da torre:\n");
                i = 0;
                while(i < torre_passos) {
                    printf("direita\n");
                    i++;
                }

                // Rainha 
                printf("\nmovimento da rainha:\n");
                i = 0;
                do {
                    printf("esquerda\n");
                    i++;
                } while(i < rainha_passos);
                break;

            case 2:
                // Cavalo 
                printf("\nmovimento do cavalo:\n");
                for(i = 0; i < 2; i++) {
                    printf("baixo\n");
                    for(j = 0; j < 1; j++) {
                        printf("esquerda\n");
                    }
                }
                break;

            case 3:
                // Bispo recursivo
                printf("\nmovimento do bispo:\n");
                moverbispo(bispo_passos);

                // Torre 
                printf("\nmovimento da torre:\n");
                movertorre(torre_passos);

                // Rainha 
                printf("\nmovimento da rainha:\n");
                moverrainha(rainha_passos);

                // Cavalo 
                printf("\nmovimento do cavalo:\n");
                for(int x = 0, y = 0; x < 2 || y < 1; ) {
                    if(x < 2) {
                        printf("cima\n");
                        x++;
                        continue;
                    }
                    if(y < 1) {
                        printf("direita\n");
                        y++;
                        break;
                    }
                }
                break;

            case 0:
                printf("\nsaindo do programa...\n");
                break;

            default:
                printf("\nopção inválida! tente novamente.\n");
        }

    } while(opcao != 0);

    return 0;
}
