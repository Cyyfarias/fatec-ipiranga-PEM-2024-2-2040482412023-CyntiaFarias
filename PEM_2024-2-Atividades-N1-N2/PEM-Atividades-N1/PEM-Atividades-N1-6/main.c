#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#define TAMANHO_MAXIMO 4  // Tamanho da pilha definido como 4

// Estrutura de dados para a pilha

typedef struct {

    double dados[TAMANHO_MAXIMO];

    int topo;

} Pilha;

// Função para inicializar a pilha

void inicializaPilha(Pilha *pilha) {

    pilha->topo = -1;

}

// Função para verificar se a pilha está vazia

int pilhaVazia(Pilha *pilha) {

    return pilha->topo == -1;

}

// Função para empilhar um valor

void empilhar(Pilha *pilha, double valor) {

    if (pilha->topo < TAMANHO_MAXIMO - 1) {

        pilha->dados[++(pilha->topo)] = valor;

    } else {

        printf("Erro: Pilha cheia!\n");

        exit(1);

    }

}

// Função para desempilhar um valor

double desempilhar(Pilha *pilha) {

    if (!pilhaVazia(pilha)) {

        return pilha->dados[(pilha->topo)--];

    } else {

        printf("Erro: Pilha vazia!\n");

        exit(1);

    }

}

// Função para calcular uma operação

void calcularOperacao(Pilha *pilha, char operador) {

    if (pilha->topo < 1) {

        printf("Erro: Operação requer ao menos dois operandos!\n");

        return;

    }

    double b = desempilhar(pilha);

    double a = desempilhar(pilha);

    double resultado;

    switch (operador) {

        case '+':

            resultado = a + b;

            break;

        case '-':

            resultado = a - b;

            break;

        case '*':

            resultado = a * b;

            break;

        case '/':

            if (b == 0) {

                printf("Erro: Divisão por zero!\n");

                empilhar(pilha, a);

                empilhar(pilha, b);

                return;

            }

            resultado = a / b;

            break;

        default:

            printf("Erro: Operador desconhecido!\n");

            empilhar(pilha, a);

            empilhar(pilha, b);

            return;

    }

    // Empilha o resultado da operação

    empilhar(pilha, resultado);

    printf("Resultado da operação %c: %.2lf\n", operador, resultado);

}

int main() {

    Pilha pilha;

    inicializaPilha(&pilha);

    char entrada[10];

    printf("Calculadora HP12C Simulada (RPN)\n");

    printf("Insira números ou operadores (+, -, *, /). Digite 'sair' para encerrar.\n");

    while (1) {

        printf("Entrada: ");

        scanf("%s", entrada);

        // Se o usuário digitar 'sair', finaliza o programa

        if (strcmp(entrada, "sair") == 0) {

            break;

        }

        // Se o valor inserido é um número, empilha

        if (entrada[0] >= '0' && entrada[0] <= '9') {

            empilhar(&pilha, atof(entrada));

        }

        // Se for um operador, realiza a operação

        else if (entrada[0] == '+' || entrada[0] == '-' || entrada[0] == '*' || entrada[0] == '/') {

            calcularOperacao(&pilha, entrada[0]);

        }

        // Caso o input seja inválido

        else {

            printf("Entrada inválida!\n");

        }

    }

    // Exibe o valor final da pilha

    if (!pilhaVazia(&pilha)) {

        printf("Valor final na pilha: %.2lf\n Obrigado por usar nossa Calculador Fatec-HP12c", desempilhar(&pilha));

    } else {

        printf("Pilha vazia!\n");

    }

    return 0;

}
 