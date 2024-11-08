 
 /*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Resolução bubblesort   *
* Data - 02/10/2024                                              * 
* Autor: Cyntia Farias Ruffo*
*--------------------------------------------------------*/

 
 
 
 
 #include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    bool trocou;

    for (i = 0; i < n - 1; i++) {
        trocou = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = true;
            }
        }
        // Se não houve troca, o array está ordenado
        if (!trocou) {
            break;
        }
    }
}

void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    
    // Solicita ao usuário o tamanho do array
    printf("Digite o tamanho do array: ");
    scanf("%d", &n);

    int arr[n];

    // Solicita ao usuário os elementos do array
    printf("Digite %d elementos:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Array original:\n");
    printArray(arr, n);
    
    bubbleSort(arr, n);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}