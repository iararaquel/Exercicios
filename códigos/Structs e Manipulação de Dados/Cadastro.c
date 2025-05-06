#include <stdio.h>
#include <locale.h> 
#include <stdlib.h> 

#define TAM_NOME 100

typedef struct {
    char nome [TAM_NOME];
    int matricula;
    float media;
} Aluno;

int main(){
    setlocale (LC_ALL, "portuguese");
    int n;
    printf ("quantos alunos deseja cadastrar?");
    scanf ("%d", &n);

    Aluno *aluno = (Aluno *)malloc(n*sizeof(Aluno));
    if (aluno == NULL){
        printf ("Erro ao alocar memoria. \n");
        return 1;
    }

    for (int i = 0; i < n; i++){
        printf ("\nAluno %d\n", i + 1);
        printf ("nome: ");
        getchar ();
        fgets (aluno[i].nome, TAM_NOME, stdin);
        printf ("matricula: ");
        scanf ("%d", &aluno[i].matricula);
        printf ("media: ");
        scanf ("%f", &aluno[i].media);
    }

    printf ("\nAlunos aprovados (media >= 7.0):\n");
    for (int i = 0; i < n; i++){
        if (aluno[i].media >= 7.0){
            printf ("nome: %s", aluno[i].nome);
            printf ("matricula: %d\n", aluno[i].matricula);
            printf ("media: %2f\n\n", aluno[i].media);
        }
    }
    free(aluno);
    return 0;

}