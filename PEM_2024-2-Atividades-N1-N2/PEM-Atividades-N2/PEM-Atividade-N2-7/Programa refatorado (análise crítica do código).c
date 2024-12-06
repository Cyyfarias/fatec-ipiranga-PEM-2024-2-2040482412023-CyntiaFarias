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

#define MAX_PRODUTOS 100
#define NOME_MAX 50
#define DESCRICAO_MAX 100

typedef struct {
    int id;
    char nome[NOME_MAX];
    char descricao[DESCRICAO_MAX];
    double precoUnitario; // Tipo double para o preço
    int qteDispo;
} Produto;


void inserirProduto(Produto *produtos, int *cont);
void consultarProduto(Produto *produtos, int cont);
void alterarProduto(Produto *produtos, int cont);
void excluirProduto(Produto *produtos, int *cont);
void listarProdutos(Produto *produtos, int cont);
void venderProduto(Produto *produtos, int cont);
void imprimirProduto(const Produto *produto); // Utiliza ponteiro para a estrutura

// Função principal
int main() {
    Produto produtos[MAX_PRODUTOS];
    int cont = 0; // Contador de produtos
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1. Incluir produto\n");
        printf("2. Listar produtos\n");
        printf("3. Consultar produto\n");
        printf("4. Alterar produto\n");
        printf("5. Excluir produto\n");
        printf("6. Vender produto\n");
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
                venderProduto(produtos, cont);
                break;
            case 7:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (opcao != 7);

    return 0;
}

// Implementações CRUD

void inserirProduto(Produto *produtos, int *cont) {
    if (*cont < MAX_PRODUTOS) {
        Produto novoProduto;

        printf("Informe o ID do produto: ");
        scanf("%d", &novoProduto.id);
        printf("Informe o nome do produto: ");
        scanf(" %[^\n]", novoProduto.nome);
        printf("Informe a descricao do produto: ");
        scanf(" %[^\n]", novoProduto.descricao);
        printf("Informe o preco unitario: ");
        scanf("%lf", &novoProduto.precoUnitario);
        printf("Informe a quantidade disponivel: ");
        scanf("%d", &novoProduto.qteDispo);

        produtos[*cont] = novoProduto;
        (*cont)++;
        printf("Produto inserido com sucesso!\n");
    } else {
        printf("Limite de produtos atingido.\n");
    }
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
    printf("ID: %d, Nome: %s, Descricao: %s, Preco: %.2lf, Estoque: %d\n",
           produto->id, produto->nome, produto->descricao, produto->precoUnitario, produto->qteDispo);
}

void consultarProduto(Produto *produtos, int cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja consultar: ");
    scanf("%d", &idProduto);

    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == idProduto) {
            imprimirProduto(&produtos[i]);
            return;
        }
    }
    printf("Produto inexistente.\n");
}

void alterarProduto(Produto *produtos, int cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja alterar: ");
    scanf("%d", &idProduto);

    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == idProduto) {
            printf("Novo nome do produto: ");
            scanf(" %[^\n]", produtos[i].nome);
            printf("Nova descricao do produto: ");
            scanf(" %[^\n]", produtos[i].descricao);
            printf("Novo preco unitario: ");
            scanf("%lf", &produtos[i].precoUnitario);
            printf("Nova quantidade disponivel: ");
            scanf("%d", &produtos[i].qteDispo);
            printf("Produto alterado com sucesso!\n");
            return;
        }
    }
    printf("Produto inexistente.\n");
}

void excluirProduto(Produto *produtos, int *cont) {
    int idProduto;
    printf("Informe o ID do produto que deseja excluir: ");
    scanf("%d", &idProduto);

    for (int i = 0; i < *cont; i++) {
        if (produtos[i].id == idProduto) {
            for (int j = i; j < *cont - 1; j++) {
                produtos[j] = produtos[j + 1];
            }
            (*cont)--;
            printf("Produto excluido com sucesso!\n");
            return;
        }
    }
    printf("Produto inexistente.\n");
}

void venderProduto(Produto *produtos, int cont) {
    if (cont == 0) {
        printf("Nenhum produto cadastrado para venda.\n");
        return;
    }

    int idProduto, quantidade;
    double desconto = 0.0;

    printf("Informe o ID do produto que deseja vender: ");
    scanf("%d", &idProduto);

    for (int i = 0; i < cont; i++) {
        if (produtos[i].id == idProduto) {
            printf("Informe a quantidade que deseja vender: ");
            scanf("%d", &quantidade);

            if (quantidade > produtos[i].qteDispo) {
                printf("Estoque insuficiente. Apenas %d disponiveis.\n", produtos[i].qteDispo);
            } else {
                printf("Informe o desconto (em %%): ");
                scanf("%lf", &desconto);

                if (desconto < 0 || desconto > 100) {
                    printf("Desconto invalido. Nenhum desconto sera aplicado.\n");
                    desconto = 0.0;
                }

                double totalSemDesconto = produtos[i].precoUnitario * quantidade;
                double totalComDesconto = totalSemDesconto * (1 - desconto / 100);

                produtos[i].qteDispo -= quantidade;

                printf("Venda realizada com sucesso!\n");
                printf("Total sem desconto: %.2lf\n", totalSemDesconto);
                printf("Desconto aplicado: %.2lf%%\n", desconto);
                printf("Total com desconto: %.2lf\n", totalComDesconto);
            }
            return;
        }
    }
    printf("Produto inexistente.\n");
}
