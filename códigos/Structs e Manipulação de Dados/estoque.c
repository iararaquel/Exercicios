#include <stdio.h>
#include <string.h>
#include <locale.h> 

#define MAX_PRODUTOS 100

typedef struct {
    char nome[50];
    int codigo;
    int quantidade;
    float preco;
} Produto;

Produto estoque[MAX_PRODUTOS];
int totalProdutos = 0;

void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite de produtos atingido!\n");
        return;
    }

    Produto p;
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", p.nome);

    printf("Digite o código do produto: ");
    scanf("%d", &p.codigo);

    printf("Digite a quantidade: ");
    scanf("%d", &p.quantidade);

    printf("Digite o preço: ");
    scanf("%f", &p.preco);

    estoque[totalProdutos++] = p;

    printf("Produto cadastrado com sucesso!\n");
}

void buscarProduto() {
    int codigo;
    printf("Digite o código do produto que deseja buscar: ");
    scanf("%d", &codigo);

    for (int i = 0; i < totalProdutos; i++) {
        if (estoque[i].codigo == codigo) {
            printf("Produto encontrado:\n");
            printf("Nome: %s\n", estoque[i].nome);
            printf("Código: %d\n", estoque[i].codigo);
            printf("Quantidade: %d\n", estoque[i].quantidade);
            printf("Preço: R$%.2f\n", estoque[i].preco);
            return;
        }
    }

    printf("Produto não encontrado.\n");
}

void listarProdutos() {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Lista de Produtos:\n");
    for (int i = 0; i < totalProdutos; i++) {
        printf("----------------------\n");
        printf("Nome: %s\n", estoque[i].nome);
        printf("Código: %d\n", estoque[i].codigo);
        printf("Quantidade: %d\n", estoque[i].quantidade);
        printf("Preço: R$%.2f\n", estoque[i].preco);
    }
    printf("----------------------\n");
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Cadastrar Produto\n");
        printf("2 - Buscar Produto\n");
        printf("3 - Listar Produtos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                buscarProduto();
                break;
            case 3:
                listarProdutos();
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}