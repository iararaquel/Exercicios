#include <stdio.h>
#include <string.h>

#define MAX_CONTATOS 100

typedef struct {
    char nome[50];
    char telefone[20];
    char email[50];
} Contato;

Contato agenda[MAX_CONTATOS];
int totalContatos = 0;

void adicionarContato() {
    if (totalContatos >= MAX_CONTATOS) {
        printf("Agenda cheia!\n");
        return;
    }

    Contato c;
    printf("Digite o nome: ");
    scanf(" %[^\n]", c.nome);

    printf("Digite o telefone: ");
    scanf(" %[^\n]", c.telefone);

    printf("Digite o email: ");
    scanf(" %[^\n]", c.email);

    agenda[totalContatos++] = c;

    printf("Contato adicionado com sucesso!\n");
}

void buscarContato() {
    char nomeBusca[50];
    printf("Digite o nome do contato para buscar: ");
    scanf(" %[^\n]", nomeBusca);

    int encontrado = 0;
    for (int i = 0; i < totalContatos; i++) {
        if (strcmp(agenda[i].nome, nomeBusca) == 0) {
            printf("Contato encontrado:\n");
            printf("Nome: %s\n", agenda[i].nome);
            printf("Telefone: %s\n", agenda[i].telefone);
            printf("Email: %s\n", agenda[i].email);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

void exibirContatos() {
    if (totalContatos == 0) {
        printf("Nenhum contato na agenda.\n");
        return;
    }

    printf("\nLista de Contatos:\n");
    for (int i = 0; i < totalContatos; i++) {
        printf("--------------------------\n");
        printf("Nome: %s\n", agenda[i].nome);
        printf("Telefone: %s\n", agenda[i].telefone);
        printf("Email: %s\n", agenda[i].email);
    }
    printf("--------------------------\n");
}

int main() {
    int opcao;

    do {
        printf("\nMenu:\n");
        printf("1 - Adicionar Contato\n");
        printf("2 - Buscar Contato por Nome\n");
        printf("3 - Exibir Todos os Contatos\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato();
                break;
            case 2:
                buscarContato();
                break;
            case 3:
                exibirContatos();
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