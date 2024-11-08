 
 /*-------------------------------------------------------------*
* Disciplina: Programação Estruturada e Modular                *
*          Prof. Carlos Veríssimo                              *
*--------------------------------------------------------------*
* Objetivo do Programa:Manipulando Struct             *
*                                                              *
* Data: 10/10/2024                                             * 
* Autora: Cyntia Farias Ruffo              *
*--------------------------------------------------------------*/

 
 #include <stdio.h>
#include <string.h>

#define MAX_PRODUTOS 100
#define TAM_NOME 50
#define TAM_DESC 100

typedef struct {
    int id;
    char nome[TAM_NOME];
    char descricao[TAM_DESC];
    float preco;
    int quantidadeEstoque;
} Produto;

void inserirProduto(Produto *produtos, int *totalProdutos);
void listarProdutos(Produto *produtos, int totalProdutos);
void comprarProduto(Produto *produtos, int totalProdutos);
void ordenarProdutos(Produto *produtos, int totalProdutos);
void exibirProduto(const Produto *produto);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcao;

    do {
        printf("\n--- Loja de Produtos Eletrônicos ---\n");
        printf("1. Inserir Produto\n");
        printf("2. Comprar Produto\n");
        printf("3. Listar Produtos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &totalProdutos);
                break;
            case 2:
                comprarProduto(produtos, totalProdutos);
                break;
            case 3:
                ordenarProdutos(produtos, totalProdutos);
                listarProdutos(produtos, totalProdutos);
                break;
            case 4:
                printf("Encerrando o programa.\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 4);

    return 0;
}

void inserirProduto(Produto *produtos, int *totalProdutos) {
    if (*totalProdutos >= MAX_PRODUTOS) {
        printf("Capacidade máxima de produtos atingida.\n");
        return;
    }

    Produto *novoProduto = &produtos[*totalProdutos];
    printf("Digite o ID do produto: ");
    scanf("%d", &novoProduto->id);
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novoProduto->nome);
    printf("Digite a descrição do produto: ");
    scanf(" %[^\n]", novoProduto->descricao);
    printf("Digite o preço unitário do produto: ");
    scanf("%f", &novoProduto->preco);
    printf("Digite a quantidade disponível em estoque: ");
    scanf("%d", &novoProduto->quantidadeEstoque);

    (*totalProdutos)++;
    printf("Produto inserido com sucesso!\n");
}

void listarProdutos(Produto *produtos, int totalProdutos) {
    printf("\n--- Lista de Produtos ---\n");
    for (int i = 0; i < totalProdutos; i++) {
        exibirProduto(&produtos[i]);
    }
}

void comprarProduto(Produto *produtos, int totalProdutos) {
    int id, quantidadeDesejada;
    printf("Digite o código do produto que deseja comprar: ");
    scanf("%d", &id);

    int indiceProduto = -1;
    for (int i = 0; i < totalProdutos; i++) {
        if (produtos[i].id == id) {
            indiceProduto = i;
            break;
        }
    }

    if (indiceProduto == -1) {
        printf("Produto inexistente.\n");
        return;
    }

    printf("Digite a quantidade que deseja comprar: ");
    scanf("%d", &quantidadeDesejada);

    Produto *produto = &produtos[indiceProduto];
    if (quantidadeDesejada > produto->quantidadeEstoque) {
        printf("Quantidade insuficiente em estoque.\n");
    } else {
        produto->quantidadeEstoque -= quantidadeDesejada;
        printf("Compra realizada com sucesso!\n");
    }
}

void ordenarProdutos(Produto *produtos, int totalProdutos) {
    for (int i = 0; i < totalProdutos - 1; i++) {
        for (int j = 0; j < totalProdutos - i - 1; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                Produto temp = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = temp;
            }
        }
    }
}

void exibirProduto(const Produto *produto) {
    printf("\nID: %d\n", produto->id);
    printf("Nome: %s\n", produto->nome);
    printf("Descrição: %s\n", produto->descricao);
    printf("Preço Unitário: %.2f\n", produto->preco);
    printf("Quantidade em Estoque: %d\n", produto->quantidadeEstoque);
}
