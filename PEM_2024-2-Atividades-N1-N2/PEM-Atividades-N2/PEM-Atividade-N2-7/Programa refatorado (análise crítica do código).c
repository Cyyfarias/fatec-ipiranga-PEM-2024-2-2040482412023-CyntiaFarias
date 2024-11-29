 /* /*--------------------------------------------------------*
* Disciplina: Programaçao Estruturada e Modular *
*          Prof. Carlos Veríssimo                                    *
*--------------------------------------------------------*
* Objetivo do Programa: Programa refatorado ( Análise crítica de codigo ) *
* Data - 28/11/2024                                              * 
* Autor: Cyntia Farias Ruffo*
*--------------------------------------------------------*/
 
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_PRODUTOS 100
#define NOME_MAX 50
#define DESCRICAO_MAX 100
#define ARQUIVO_PRODUTOS "produtos.dat"

typedef struct {
    int id;
    char nome[NOME_MAX];
    char descricao[DESCRICAO_MAX];
    float precoUnitario;
    int qteDispo;
} Produto;

void inserirProduto(Produto *produtos, int *cont);
void consultarProduto(Produto *produtos, int cont);
void alterarProduto(Produto *produtos, int cont);
void excluirProduto(Produto *produtos, int *cont);
void listarProdutos(Produto *produtos, int cont);
void comprarProduto(Produto *produtos, int cont);
void imprimirProduto(const Produto *produto);
int buscarProdutoPorID(Produto *produtos, int cont, int id);
void salvarProdutos(Produto *produtos, int cont);
void carregarProdutos(Produto *produtos, int *cont);

int main() {
    Produto produtos[MAX_PRODUTOS];
    int cont = 0;
    int opcao;

    carregarProdutos(produtos, &cont);

    do {
        printf("\nMenu:\n");
        printf("1. Inserir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Consultar produto\n");
        printf("4. Alterar produto\n");
        printf("5. Excluir produto\n");
        printf("6. Comprar produto\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirProduto(produtos, &cont);
                break;
            case 2:
                listarProdutos(produtos, cont);
                break;
            case 3:
                consultarProduto(produtos, cont);
                break;
            case 4:
                alterarProduto(produtos, cont);
                break;
            case 5:
                excluirProduto(produtos, &cont);
                break;
            case 6:
                comprarProduto(produtos, cont);
                break;
            case 7:
                salvarProdutos(produtos, cont);
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}

void inserirProduto(Produto *produtos, int *cont) {
    if (*cont >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido.\n");
        return;
    }

    Produto novoProduto;

    printf("Informe o ID do produto: ");
    scanf("%d", &novoProduto.id);

    if (buscarProdutoPorID(produtos, *cont, novoProduto.id) != -1) {
        printf("Erro: ID ja cadastrado.\n");
        return;
    }

    printf("Informe o nome do produto: ");
    scanf(" %[^\n]", novoProduto.nome);
    printf("Informe a descricao do produto: ");
    scanf(" %[^\n]", novoProduto.descricao);
    printf("Informe o preco unitario: ");
    scanf("%f", &novoProduto.precoUnitario);
    printf("Informe a quantidade disponivel: ");
    scanf("%d", &novoProduto.qteDispo);

    produtos[*cont] = novoProduto;
    (*cont)++;
    printf("Produto inserido com sucesso!\n");
}

void listarProdutos(Produto *produtos, int cont) {
    if (cont == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\nLista de Produtos:\n");
    for (int i = 0; i < cont; i++) {
        imprimirProduto(&produtos[i]);
    }
}

void imprimirProduto(const Produto *produto) {
    printf("ID: %d, Nome: %s, Descricao: %s, Preco: %.2f, Estoque: %d\n",
           produto->id, produto->nome, produto->descricao, produto->precoUnitario, produto->qteDispo);
}

void consultarProduto(Produto *produtos, int cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja consultar: ");
    scanf("%d", &idProduto);

    int index = buscarProdutoPorID(produtos, cont, idProduto);
    if (index != -1) {
        imprimirProduto(&produtos[index]);
    } else {
        printf("Produto inexistente.\n");
    }
}

void alterarProduto(Produto *produtos, int cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja alterar: ");
    scanf("%d", &idProduto);

    int index = buscarProdutoPorID(produtos, cont, idProduto);
    if (index != -1) {
        printf("Novo nome do produto: ");
        scanf(" %[^\n]", produtos[index].nome);
        printf("Nova descricao do produto: ");
        scanf(" %[^\n]", produtos[index].descricao);
        printf("Novo preco unitario: ");
        scanf("%f", &produtos[index].precoUnitario);
        printf("Nova quantidade disponivel: ");
        scanf("%d", &produtos[index].qteDispo);
        printf("Produto alterado com sucesso!\n");
    } else {
        printf("Produto inexistente.\n");
    }
}

void excluirProduto(Produto *produtos, int *cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja excluir: ");
    scanf("%d", &idProduto);

    int index = buscarProdutoPorID(produtos, *cont, idProduto);
    if (index != -1) {
        for (int i = index; i < *cont - 1; i++) {
            produtos[i] = produtos[i + 1];
        }
        (*cont)--;
        printf("Produto excluido com sucesso!\n");
    } else {
        printf("Produto inexistente.\n");
    }
}

void comprarProduto(Produto *produtos, int cont) {
    if (cont == 0) {
        printf("Nenhum produto cadastrado para compra.\n");
        return;
    }

    int idProduto, quantidade;
    printf("Informe o ID do produto que deseja comprar: ");
    scanf("%d", &idProduto);

    int index = buscarProdutoPorID(produtos, cont, idProduto);
    if (index != -1) {
        printf("Informe a quantidade que deseja comprar: ");
        scanf("%d", &quantidade);

        if (quantidade <= 0) {
            printf("Erro: Quantidade invalida.\n");
        } else if (quantidade > produtos[index].qteDispo) {
            printf("Estoque insuficiente. Apenas %d disponiveis.\n", produtos[index].qteDispo);
        } else {
            produtos[index].qteDispo -= quantidade;
            printf("Compra realizada com sucesso! Total: %.2f\n", produtos[index].precoUnitario * quantidade);
        }
    } else {
        printf("Produto inexistente.\n");
    }
}

int buscarProdutoPorID(Produto *produtos, int cont, int id) {
    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == id) {
            return i;
        }
    }
    return -1;
}

void salvarProdutos(Produto *produtos, int cont) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "wb");
    if (arquivo == NULL) {
        printf("Erro ao salvar os produtos.\n");
        return;
    }
    fwrite(produtos, sizeof(Produto), cont, arquivo);
    fclose(arquivo);
}

void carregarProdutos(Produto *produtos, int *cont) {
    FILE *arquivo = fopen(ARQUIVO_PRODUTOS, "rb");
    if (arquivo != NULL) {
        *cont = fread(produtos, sizeof(Produto), MAX_PRODUTOS, arquivo);
        fclose(arquivo);
    }
}
