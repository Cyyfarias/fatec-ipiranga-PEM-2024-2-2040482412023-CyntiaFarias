 
 /*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Simular o sistema de uma loja  *
* Data - 01/11/2024                                              * 
* Autor: Cyntia Farias Ruffo *
*--------------------------------------------------------*/
 
 
 
 
#include <stdio.h>
#include <string.h>

#define NOME_MAX 50
#define MAX_PRODUTOS 100

// Estrutura do produto
typedef struct {
    int id;
    char nome[NOME_MAX];
    int quantidade;
    double valor;
} produto;

// Declaração das funções
void exibirMenu();
void cadastrarProduto(produto *produtos, int *total);
void alterarProduto(produto *produtos, int total);
void consultarProduto(produto *produtos, int total);
void excluirProduto(produto *produtos, int *total);
void imprimirProduto(const produto *produto);

int main() {
    produto produtos[MAX_PRODUTOS];
    int totalProdutos = 0;
    int opcao;

    do {
        printf("=========Mercadinho=========\n");
        exibirMenu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        printf("============================\n");

        switch(opcao) {
            case 1:
                cadastrarProduto(produtos, &totalProdutos);
                break;
            case 2:
                alterarProduto(produtos, totalProdutos);
                break;
            case 3:
                consultarProduto(produtos, totalProdutos);
                break;
            case 4:
                excluirProduto(produtos, &totalProdutos);
                break;
            case 5:
                printf("Saindo....\n");
                break;
            default:
                printf("Opção Inválida!\n");
                break;
        }
    } while(opcao != 5);

    return 0;
}

// Função para exibir o menu
void exibirMenu() {
    printf("[1] Cadastrar produto.\n");
    printf("[2] Alterar Produto cadastrado.\n");
    printf("[3] Consultar um produto.\n");
    printf("[4] Excluir produto cadastrado.\n");
    printf("[5] Sair do programa.\n");
}

// Função para cadastrar um produto
void cadastrarProduto(produto *produtos, int *total) {
    if (*total >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    produto *p = &produtos[*total];
    printf("Digite o código do produto: ");
    scanf("%d", &p->id);
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p->nome); // Lê a string incluindo espaços
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &p->quantidade);
    printf("Digite o valor do produto: ");
    scanf("%lf", &p->valor); // %lf para ler double

    (*total)++;
    printf("Produto cadastrado com sucesso!\n");
}

// Função para alterar um produto por ID
void alterarProduto(produto *produtos, int total) {
    int id;
    printf("Informe o ID do produto que deseja alterar: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++) {
        if (produtos[i].id == id) {
            printf("Novo nome: ");
            scanf(" %[^\n]", produtos[i].nome);
            printf("Nova quantidade: ");
            scanf("%d", &produtos[i].quantidade);
            printf("Novo valor: ");
            scanf("%lf", &produtos[i].valor); // %lf para ler double
            printf("Produto alterado!\n");
            return;
        }
    }
    printf("Produto não encontrado!\n");
}

// Função para consultar um produto por ID
void consultarProduto(produto *produtos, int total) {
    int id;
    printf("Digite o ID do produto que deseja consultar: ");
    scanf("%d", &id);

    for (int i = 0; i < total; i++) {
        if (produtos[i].id == id) {
            imprimirProduto(&produtos[i]);
            return;
        }
    }
    printf("Produto não encontrado!\n");
}

// Função para excluir um produto por ID
void excluirProduto(produto *produtos, int *total) {
    int id, index = -1;
    printf("Digite o ID do produto que deseja excluir: ");
    scanf("%d", &id);

    for (int i = 0; i < *total; i++) {
        if (produtos[i].id == id) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Produto não encontrado!\n");
        return;
    }

    // Remover o produto deslocando os elementos do array
    for (int i = index; i < *total - 1; i++) {
        produtos[i] = produtos[i + 1];
    }
    (*total)--;
    printf("Produto excluído com sucesso!\n");
}

// Função para imprimir os dados de um produto
void imprimirProduto(const produto *produto) {
    printf("\n--- Dados do Produto ---\n");
    printf("ID: %d\n", produto->id);
    printf("Nome: %s\n", produto->nome);
    printf("Quantidade: %d\n", produto->quantidade);
    printf("Valor: %.2f\n", produto->valor);
}
