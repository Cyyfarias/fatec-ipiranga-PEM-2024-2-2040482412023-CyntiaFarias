/*Atividade PEM N2-2
Programação Estruturada e Modular
Comparando ordenação "Bubble Sort" com ordenação 
por inserção

Cyntia Farias Ruffo

Professor: Carlos Henrique Verissimo Pereira*/

# include <stdio.h>

// Função para imprimir o array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Função para trocar dois elementos
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição
int particao(int arr[], int limInf, int limSup) {
    int pivo = arr[limSup]; // Escolhendo o pivô
    int ind = limInf - 1;   // Índice do menor elemento

    for (int j = limInf; j < limSup; j++) {
        if (arr[j] <= pivo) {
            ind++;
            troca(&arr[ind], &arr[j]); // Troca elementos
        }
    }
    troca(&arr[ind + 1], &arr[limSup]); // Coloca o pivô na posição correta
    return ind + 1; // Retorna o índice do pivô
}

// Função QuickSort
void QuickSort(int arr[], int limInf, int limSup) {
    if (limInf < limSup) {
        int indParticao = particao(arr, limInf, limSup);

        // Recursivamente ordena os sub-arrays
        QuickSort(arr, limInf, indParticao - 1);
        QuickSort(arr, indParticao + 1, limSup);
    }
}

// Função principal
int main() {
    int arr[] = {100, 70, 90, 90, 10, 40, 30};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    QuickSort(arr, 0, n - 1);

    printf("Array ordenado:\n");
    printArray(arr, n);

    return 0;
}
