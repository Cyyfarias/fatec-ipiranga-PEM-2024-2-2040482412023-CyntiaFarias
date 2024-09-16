 //--------------------------------------------------------*
 // Disciplina: Programaçao Estruturada e Modular *
 // Prof. Carlos Veríssimo
 //--------------------------------------------------------*
 // Objetivo do Programa: Criar tabuleiro de xadrez *
 // Data - 29/08/2024
 //Autora: Cyntia Farias Ruffo

 #include <stdio.h>
 #define TAMANHO_TABULEIRO 8

 void inicializarTabuleiro(char
 tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
 int i, j;

 tabuleiro[0][0] = 'T'; tabuleiro[0][1] = 'C'; tabuleiro[0][2] = 'B';
 tabuleiro[0][3] = 'D';
 tabuleiro[0][4] = 'R'; tabuleiro[0][5] = 'B'; tabuleiro[0][6] = 'C';
 tabuleiro[0][7] = 'T';
 for (j = 0; j < TAMANHO_TABULEIRO; j++) {
 tabuleiro[1][j] = 'P';
 }

 tabuleiro[7][0] = 'T'; tabuleiro[7][1] = 'C'; tabuleiro[7][2] = 'B';
 tabuleiro[7][3] = 'D';
 tabuleiro[7][4] = 'R'; tabuleiro[7][5] = 'B'; tabuleiro[7][6] = 'C';
 tabuleiro[7][7] = 'T';
 for (j = 0; j < TAMANHO_TABULEIRO; j++) {
 tabuleiro[6][j] = 'P';
 }

 for (i = 2; i < 6; i++) {
 for (j = 0; j < TAMANHO_TABULEIRO; j++) {
 tabuleiro[i][j] = 'X';
 }
 }
 }
 void exibirTabuleiro(char
 tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
 int i, j;
 char letrasColunas[] = "abcdefgh";
 printf(" a b c d e f g h\n");
 for (i = 0; i < TAMANHO_TABULEIRO; i++) {
 printf("%d ", TAMANHO_TABULEIRO - i);
 for (j = 0; j < TAMANHO_TABULEIRO; j++) {
 char peca = tabuleiro[i][j];
 if (i < 2) {
 printf("B%c%d ", peca, j + 1);
 } else if (i > 5) {
 printf("P%c%d ", peca, j + 1);
 } else {
 printf(" %c ", peca);
 }
 }
 printf("\n");
 }
 }
 int main() {
 	
 char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
 inicializarTabuleiro(tabuleiro);
 exibirTabuleiro(tabuleiro);
 return 0;
 }	
