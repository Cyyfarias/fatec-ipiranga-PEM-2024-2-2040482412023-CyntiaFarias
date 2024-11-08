 
 /*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Solução bubblesort   *
* Data - 02/10/2024                                              * 
* Autor: Cyntia Farias Ruffo*
*--------------------------------------------------------*/

 
 #include <stdio.h>
#include <stdbool.h>

// Função para realizar o Bubble Sort com otimização
void bubbleSort(int arr[], int n) {
    int temp;
    bool trocou;

    for (int i = 0; i < n - 1; i++) {
        trocou = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Troca os elementos
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                trocou = true;
            }
        }
        // Se não houve troca, o array já está ordenado
        if (!trocou) {
            break;
        }
    }
}

// Função para imprimir o array
void printArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Solicita ao usuário o número de elementos
    printf("Digite a quantidade de números a serem inseridos no array: ");
    scanf("%d", &n);

    // Verifica se o número de elementos é válido
    if (n <= 0) {
        printf("A quantidade de números deve ser maior que 0.\n");
        return 1; // Encerra o programa se a quantidade for inválida
    }

    int arr[n];

    // Solicita ao usuário os elementos do array
    printf("Digite %d números:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Exibe o array na sequência de entrada
    printf("Array na sequência de entrada:\n");
    printArray(arr, n);

    // Realiza a ordenação
    bubbleSort(arr, n);

    // Exibe o array após a ordenação
    printf("Array após a ordenação:\n");
    printArray(arr, n);

    return 0;
 
 
 