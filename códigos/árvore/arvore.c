#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    int dado;
    struct No* esquerdo;
    struct No* direito;
} No;

No* criarNo(int c) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo != NULL) {
        novo->dado = c;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

No* inserir(No* raiz, int c) {
    if (raiz == NULL) return criarNo(c);
    if (c < raiz->dado)
        raiz->esquerdo = inserir(raiz->esquerdo, c);
    else if (c > raiz->dado)
        raiz->direito = inserir(raiz->direito, c);
    return raiz;
}

No* buscar(No* raiz, int c) {
    if (raiz == NULL || raiz->dado == c) return raiz;
    if (c < raiz->dado)
        return buscar(raiz->esquerdo, c);
    else
        return buscar(raiz->direito, c);
}

void removerArvore(No* raiz) {
    if (raiz != NULL) {
        removerArvore(raiz->esquerdo);
        removerArvore(raiz->direito);
        free(raiz);
    }
}

void inOrdem(No* raiz) {
    if (raiz != NULL) {
        inOrdem(raiz->esquerdo);
        printf("%d ", raiz->dado);
        inOrdem(raiz->direito);
    }
}

void preOrdem(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->dado);
        preOrdem(raiz->esquerdo);
        preOrdem(raiz->direito);
    }
}

void posOrdem(No* raiz) {
    if (raiz != NULL) {
        posOrdem(raiz->esquerdo);
        posOrdem(raiz->direito);
        printf("%d ", raiz->dado);
    }
}

// Altura
int altura(No* raiz) {
    if (raiz == NULL) return -1;
    int he = altura(raiz->esquerdo);
    int hd = altura(raiz->direito);
    return (he > hd ? he : hd) + 1;
}

// Profundidade
int profundidade(No* raiz, int valor, int nivel) {
    if (raiz == NULL) return -1;
    if (raiz->dado == valor) return nivel;
    if (valor < raiz->dado)
        return profundidade(raiz->esquerdo, valor, nivel + 1);
    else
        return profundidade(raiz->direito, valor, nivel + 1);
}

// Soma
int soma(No* raiz) {
    if (raiz == NULL) return 0;
    return raiz->dado + soma(raiz->esquerdo) + soma(raiz->direito);
}


int nivel(No* raiz, int valor) {
    return profundidade(raiz, valor, 0);
}

// Contar os nós
int contarNos(No* raiz) {
    if (raiz == NULL) return 0;
    return 1 + contarNos(raiz->esquerdo) + contarNos(raiz->direito);
}

// Contar as folhas
int contarFolhas(No* raiz) {
    if (raiz == NULL) return 0;
    if (raiz->esquerdo == NULL && raiz->direito == NULL)
        return 1;
    return contarFolhas(raiz->esquerdo) + contarFolhas(raiz->direito);
}

//ÁRVORE BINÁRIA DE ALUNOS 

typedef struct Aluno {
    char nome[50];
    int matricula;
    float nota;
    struct Aluno* esquerdo;
    struct Aluno* direito;
} Aluno;

// Criar 
Aluno* criarAluno(char* nome, int matricula, float nota) {
    Aluno* novo = (Aluno*)malloc(sizeof(Aluno));
    if (novo != NULL) {
        strcpy(novo->nome, nome);
        novo->matricula = matricula;
        novo->nota = nota;
        novo->esquerdo = NULL;
        novo->direito = NULL;
    }
    return novo;
}

// Inserir o aluno (ordenado pelo nome)
Aluno* inserirAluno(Aluno* raiz, char* nome, int matricula, float nota) {
    if (raiz == NULL) return criarAluno(nome, matricula, nota);
    if (strcmp(nome, raiz->nome) < 0)
        raiz->esquerdo = inserirAluno(raiz->esquerdo, nome, matricula, nota);
    else if (strcmp(nome, raiz->nome) > 0)
        raiz->direito = inserirAluno(raiz->direito, nome, matricula, nota);
    return raiz;
}

// Buscar o aluno por nome
Aluno* buscarAluno(Aluno* raiz, char* nome) {
    if (raiz == NULL || strcmp(nome, raiz->nome) == 0) return raiz;
    if (strcmp(nome, raiz->nome) < 0)
        return buscarAluno(raiz->esquerdo, nome);
    else
        return buscarAluno(raiz->direito, nome);
}

// Imprimir os alunos in-ordem
void imprimirAlunos(Aluno* raiz) {
    if (raiz != NULL) {
        imprimirAlunos(raiz->esquerdo);
        printf("Nome: %s | Matrícula: %d | Nota: %.2f\n", raiz->nome, raiz->matricula, raiz->nota);
        imprimirAlunos(raiz->direito);
    }
}

// Remover árvore de alunos
void removerArvoreAlunos(Aluno* raiz) {
    if (raiz != NULL) {
        removerArvoreAlunos(raiz->esquerdo);
        removerArvoreAlunos(raiz->direito);
        free(raiz);
    }
}

// Calcular média das notas
void calcularMedia(Aluno* raiz, float* soma, int* cont) {
    if (raiz != NULL) {
        *soma += raiz->nota;
        (*cont)++;
        calcularMedia(raiz->esquerdo, soma, cont);
        calcularMedia(raiz->direito, soma, cont);
    }
}

//FUNÇÃO PRINCIPAL

int main() {
    printf("==== ÁRVORE DE INTEIROS ====\n");
    No* raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    for (int i = 0; i < 7; i++)
        raiz = inserir(raiz, valores[i]);

    printf("In-ordem: "); inOrdem(raiz); printf("\n");
    printf("Pré-ordem: "); preOrdem(raiz); printf("\n");
    printf("Pós-ordem: "); posOrdem(raiz); printf("\n");

    printf("Altura: %d\n", altura(raiz));
    printf("Profundidade do nó 40: %d\n", profundidade(raiz, 40, 0));
    printf("Nível do nó 40: %d\n", nivel(raiz, 40));
    printf("Soma dos nós: %d\n", soma(raiz));
    printf("Total de nós: %d\n", contarNos(raiz));
    printf("Total de folhas: %d\n", contarFolhas(raiz));
    removerArvore(raiz);

    printf("\n==== ÁRVORE DE ALUNOS ====\n");
    Aluno* turma = NULL;
    turma = inserirAluno(turma, "Joao", 123, 7.5);
    turma = inserirAluno(turma, "Ana", 456, 9.0);
    turma = inserirAluno(turma, "Carlos", 789, 8.2);
    turma = inserirAluno(turma, "Beatriz", 321, 6.8);

    imprimirAlunos(turma);

    char busca[] = "Carlos";
    Aluno* achado = buscarAluno(turma, busca);
    if (achado)
        printf("\nAluno encontrado: %s | Matrícula: %d | Nota: %.2f\n", achado->nome, achado->matricula, achado->nota);
    else
        printf("\nAluno %s não encontrado.\n", busca);

    float somaNotas = 0;
    int totalAlunos = 0;
    calcularMedia(turma, &somaNotas, &totalAlunos);
    if (totalAlunos > 0)
        printf("\nMédia das notas: %.2f\n", somaNotas / totalAlunos);

    removerArvoreAlunos(turma);

    return 0;
}