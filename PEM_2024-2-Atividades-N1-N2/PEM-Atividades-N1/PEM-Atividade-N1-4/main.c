
// Disciplina Programação Estruturada e Modular
// Prof. Carlos Veríssimo
// Objetivo do Programa: Simular Jogada Xeque Pastor
// Data:06/09/2024
// Autora: Cyntia Farias Ruffo

#include <stdio.h>
#include <string.h>

#define TAMANHO 256
int main() {
    char tabuleiro[TAMANHO];

    for (int i = 0; i < TAMANHO; i += 4) {
        snprintf(&tabuleiro[i], 4, "  ");
    }
      // Fileira de peças pretas de A1 a H1
      
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
      // Fileira de peças brancas de A8 a H8

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
  
    printf("*******************************\n");
    printf("            Início             \n");
    printf("*******************************\n");
    printf("\n");
    for (int i = 0; i < TAMANHO; i += 4) {
        if (i % 32 == 0 && i != 0) {
            printf("\n");
        }
        printf("%s ", &tabuleiro[i]);
    }
    printf("\n");
    printf("\n");
    printf("*******************************\n");
    printf("      1º Jogada Brancas        \n");
    printf("*******************************\n");
    printf("\n  BRANCAS DE PE2 PARA PE4    \n");
    printf("-------------------------------\n");
    printf("\n");
    snprintf(&tabuleiro[208], 4, "  "); // Limpa o e2
    snprintf(&tabuleiro[144], 4, "BP5"); // Move para e4
    
    for (int i = 0; i < TAMANHO; i += 4) {
        if (i % 32 == 0 && i != 0) {
            printf("\n");
        }
        printf("%s ", &tabuleiro[i]);
    }
    printf("\n");
    printf("\n");
    printf("*******************************\n");
    printf("     1ª Jogada Pretas          \n");     
    printf("*******************************\n");
    printf("\n  PRETAS DE PE7 PARA PE5     \n");
    printf("-------------------------------\n");
    printf("\n");
    snprintf(&tabuleiro[112], 4, "PP5"); // Move para e5
    snprintf(&tabuleiro[48], 4, "  "); // Limpa o e7

    for (int i = 0; i < TAMANHO; i += 4) {
        if (i % 32 == 0 && i != 0) {
            printf("\n");
        }
        printf("%s ", &tabuleiro[i]);
    }
    printf("\n");
    printf("\n");
    printf("*******************************\n");
    printf("          2ª Jogada            \n");
    printf("*******************************\n");
    printf("\n BRANCAS DE BF1 PARA BC4     \n");
    printf("-------------------------------\n");
    printf("\n");
    snprintf(&tabuleiro[244], 4, "  "); // Limpa o f1
    snprintf(&tabuleiro[136], 4, "BB2"); // Move para c4

    for (int i = 0; i < TAMANHO; i += 4) {
        if (i % 32 == 0 && i != 0) {
            printf("\n");
        }
        printf("%s ", &tabuleiro[i]);
    }
    printf("\n");
    printf("\n");
    printf("*******************************\n");
    printf("          2ª Jogada            \n");
    printf("*******************************\n");
    printf("\n  PRETAS DE CB8 PARA CC6     \n");
    printf("-------------------------------\n");
    printf("\n");
    snprintf(&tabuleiro[72], 4, "PC1"); // Move para c6
    snprintf(&tabuleiro[4], 4, "  "); // Limpa o b8

    for (int i = 0; i < TAMANHO; i += 4) {
        if (i % 32 == 0 && i != 0) {
            printf("\n");
        }
        printf("%s ", &tabuleiro[i]);
    }
    printf("\n");
    printf("\n");
    printf("*******************************\n");
    printf("          3ª Jogada            \n");
    printf("*******************************\n");
    printf("\n  BRANCAS DE DD1 PARA DH5    \n");
    printf("-------------------------------\n");
    printf("\n");
    snprintf(&tabuleiro[236], 4, "  "); // Limpa o d1
    snprintf(&tabuleiro[124], 4, "BD1"); // Move para h5


    for (int i = 0; i < TAMANHO; i += 4) {
        if (i % 32 == 0 && i != 0) {
            printf("\n");
        }
        printf("%s ", &tabuleiro[i]);
    }
    printf("\n");
    printf("\n");
    printf("*******************************\n");
    printf("          3ª Jogada            \n");
    printf("*******************************\n");
    printf("\n    PRETAS DE CG8 PARA CF6   \n");
    printf("-------------------------------\n");
    printf("\n");
    snprintf(&tabuleiro[84], 4, "PC1"); // Move para f6
    snprintf(&tabuleiro[24], 4, "  "); // Limpa o g8

    for (int i = 0; i < TAMANHO; i += 4) {
        if (i % 32 == 0 && i != 0) {
            printf("\n");
        }
        printf("%s ", &tabuleiro[i]);
    }
    printf("\n");
    printf("\n");
    printf("*************************************************\n");
    printf("           4ª Jogada (Xeque Mate):               \n");
    printf("*************************************************\n");
    printf("\nBRANCAS CAPTURAM PP6 EM F7 E XEQUE MATE (DxF7#)\n");
    printf("-------------------------------------------------\n");
    snprintf(&tabuleiro[52], 4, "BD1"); // Move para f7
    snprintf(&tabuleiro[124], 4, "  "); // Limpa o h5

    for (int i = 0; i < TAMANHO; i += 4) {
        if (i % 32 == 0 && i != 0) {
            printf("\n");
        }
        printf("%s ", &tabuleiro[i]);
    }
    printf("\n");

    printf("\nFim de jogo.");

    return 0;
}
