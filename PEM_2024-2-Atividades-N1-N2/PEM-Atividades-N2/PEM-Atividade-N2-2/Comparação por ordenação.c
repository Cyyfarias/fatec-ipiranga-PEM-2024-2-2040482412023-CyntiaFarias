/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa: ordenacao por Insercao  com tempo      *
*                                                              *
* Data: 10/10/2024                                             * 
* Autor:Cyntia Farias Ruffo       *
*--------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Ordena um array usando o algoritmo de ordenação por inserção
void ordenacaoInsercao(int numeros[], int quantidade, int *swapCount, int *cycleCount) {
    *swapCount = 0;
    *cycleCount = 0;

    for (int i = 1; i < quantidade; i++) {
        int elemento = numeros[i];
        int posicao = i - 1;

        while (posicao >= 0 && numeros[posicao] > elemento) {
            numeros[posicao + 1] = numeros[posicao];
            posicao--;
            (*cycleCount)++;
            (*swapCount)++;
        }
        numeros[posicao + 1] = elemento;
        (*cycleCount)++;
    }
}

// Imprime o array
void imprimirArray(int numeros[], int quantidade) {
    for (int i = 0; i < quantidade; i++)
        printf("%d ", numeros[i]);
    printf("\n");
}

int main() {
    int arr[] = {5, 3, 8, 4, 2,
                  115, 113, 118, 114, 112,
                  125, 123, 128, 124, 122,
                  35, 33, 38, 34, 32,
                  45, 43, 48, 44, 42,
                  55, 53, 58, 54, 52,
                  65, 63, 68, 64, 62,
                  75, 73, 78, 74, 72,
                  85, 83, 88, 84, 82,
                  95, 93, 98, 94, 92,
                  15, 13, 18, 14, 12,
                  25, 23, 28, 24, 22};

    int quantidadeNumeros = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, quantidadeNumeros);

    int swapCount, cycleCount;
    clock_t start, end;
    double cpu_time_used;

    start = clock();
    ordenacaoInsercao(arr, quantidadeNumeros, &swapCount, &cycleCount);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array ordenado: ");
    imprimirArray(arr, quantidadeNumeros);
    printf("Tempo de execução: %f segundos\n", cpu_time_used);
    printf("Trocas: %d\n", swapCount);
    printf("Ciclos: %d\n", cycleCount);

    return 0;
}