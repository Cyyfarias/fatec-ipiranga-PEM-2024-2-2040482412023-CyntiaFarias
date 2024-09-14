
#include <stdio.h>
#include <string.h>

#define TAMANHO 256

void inicializarTabuleiro(char *tabuleiro) {
    for (int i = 0; i < TAMANHO; i += 4) {
        snprintf(&tabuleiro[i], 4, "  ");
    }

    snprintf(&tabuleiro[0], 4, "PT1");
    snprintf(&tabuleiro[4], 4, "PC1"); 
    snprintf(&tabuleiro[8], 4, "PB1"); 
    snprintf(&tabuleiro[12], 4, "PD1"); 
    snprintf(&tabuleiro[16], 4, "PR1"); 
    snprintf(&tabuleiro[20], 4, "PB2"); 
    snprintf(&tabuleiro[24], 4, "PC2"); 
    snprintf(&tabuleiro[28], 4, "PT2"); 

    for (int i = 32; i < 64; i += 4) {
        snprintf(&tabuleiro[i], 4, "PP%d", (i - 32) / 4 + 1); // Peões de a2 a h2
    }

    snprintf(&tabuleiro[224], 4, "BT1"); 
    snprintf(&tabuleiro[228], 4, "BC1"); 
    snprintf(&tabuleiro[232], 4, "BB1"); 
    snprintf(&tabuleiro[236], 4, "BD1"); 
    snprintf(&tabuleiro[240], 4, "BR1"); 
    snprintf(&tabuleiro[244], 4, "BB2"); 
    snprintf(&tabuleiro[248], 4, "BC2"); 
    snprintf(&tabuleiro[252], 4, "BT2"); 

    for (int i = 192; i < 224; i += 4) {
        snprintf(&tabuleiro[i], 4, "BP%d", (i - 192) / 4 + 1); // Peões de a7 a h7
    }
}

void imprimirTabuleiro(const char *tabuleiro, int inicial) {
    if (inicial) {
        printf("*******************************\n");
        printf("           início              \n");
        printf("*******************************\n");
        printf("\n");
    }
    for (int i = 0; i < TAMANHO; i += 4) {
        if (i % 32 == 0 && i != 0) {
            printf("\n");
        }
        printf("%s ", &tabuleiro[i]);
    }
    printf("\n");
    printf("\n");
}

void realizarMovimento(char *tabuleiro, const char *movimento, int posOrigem, int posDestino) {
    snprintf(&tabuleiro[posDestino], 4, "%s", &tabuleiro[posOrigem]);
    snprintf(&tabuleiro[posOrigem], 4, "  ");
}

void mostrarMovimento(const char *movimento) {
    printf("*******************************\n");
    printf("         %s:          \n", movimento);
    printf("*******************************\n");
    printf("\n");
}

int main() {
    char tabuleiro[TAMANHO];

    inicializarTabuleiro(tabuleiro);
    imprimirTabuleiro(tabuleiro, 1); 

    mostrarMovimento(" 1ª Jogada:\n BRANCAS JOGAM PE2 PARA PE4");
    realizarMovimento(tabuleiro, "BP5", 208, 144);
    imprimirTabuleiro(tabuleiro, 0);  

    mostrarMovimento("\nPRETAS DE PE7 PARA PE5");
    realizarMovimento(tabuleiro, "PP5", 48, 112);
    imprimirTabuleiro(tabuleiro, 0);

    mostrarMovimento("2ª Jogada:\n BRANCAS DE BF1 PARA BC4");
    realizarMovimento(tabuleiro, "BB2", 244, 136);
    imprimirTabuleiro(tabuleiro, 0);

    mostrarMovimento("\nPRETAS DE CB8 PARA CC6");
    realizarMovimento(tabuleiro, "PC1", 4, 72);
    imprimirTabuleiro(tabuleiro, 0);

    mostrarMovimento("3ª Jogada:\n BRANCAS DE DD1 PARA DH5");
    realizarMovimento(tabuleiro, "BD1", 236, 124);
    imprimirTabuleiro(tabuleiro, 0);

    mostrarMovimento("\nPRETAS DE CG8 PARA CF6");
    realizarMovimento(tabuleiro, "PC1", 24, 84);
    imprimirTabuleiro(tabuleiro, 0);

    printf("*************************************************\n");
    printf("            4ª Jogada (Xeque Mate):              \n");
    printf("*************************************************\n");
    printf("\nBRANCAS CAPTURAM PP6 EM F7 E XEQUE MATE (DxF7#)\n");
    printf("-------------------------------------------------\n");
    snprintf(&tabuleiro[52], 4, "BD1"); 
    snprintf(&tabuleiro[124], 4, "  "); 
    imprimirTabuleiro(tabuleiro, 0);

    printf("\nFim de jogo.");

    return 0;
}