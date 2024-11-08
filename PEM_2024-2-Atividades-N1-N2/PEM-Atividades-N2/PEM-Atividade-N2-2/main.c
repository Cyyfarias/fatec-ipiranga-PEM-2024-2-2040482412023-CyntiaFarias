
/*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa:   bubbleSort com tempo                 *
*                                                              *
* Data: 10/10/2024                                             * 
* Autor: Cyntia Farais Ruffo              *
*--------------------------------------------------------------*/

#include <stdio.h>
#include <time.h>

// Função para imprimir o array
void imprimirArray(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função que implementa o Bubble Sort
void bubbleSort(int arr[], int tamanho, int *swapCount, int *cycleCount) {
    *swapCount = 0;
    *cycleCount = 0;

    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            (*cycleCount)++;
            if (arr[j] > arr[j + 1]) {
                // Trocar arr[j] e arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swapCount)++;
            }
        }
    }
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
    bubbleSort(arr, quantidadeNumeros, &swapCount, &cycleCount);
    end = clock();

    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Array ordenado: ");
    imprimirArray(arr, quantidadeNumeros);
    printf("Tempo de execução: %f segundos\n", cpu_time_used);
    printf("Trocas: %d\n", swapCount);
    printf("Ciclos: %d\n", cycleCount);

    return 0;
}