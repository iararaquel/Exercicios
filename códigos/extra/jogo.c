#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TAM_MAX 30
#define MAX_TENTATIVAS 6

int main() {
    char palavraSecreta[TAM_MAX] = "computador"; 
    char palavraOculta[TAM_MAX];
    int tamanho = strlen(palavraSecreta);
    int tentativas = 0;
    int letrasRestantes = tamanho;
    char letra;
    int acertou;

    for (int i = 0; i < tamanho; i++) {
        palavraOculta[i] = '_';
    }
    palavraOculta[tamanho] = '\0';

    printf("=== Jogo da Forca ===\n");

    while (tentativas < MAX_TENTATIVAS && letrasRestantes > 0) {
        printf("\nPalavra: ");
        for (int i = 0; i < tamanho; i++) {
            printf("%c ", palavraOculta[i]);
        }

        printf("\nTentativas restantes: %d", MAX_TENTATIVAS - tentativas);
        printf("\nDigite uma letra: ");
        scanf(" %c", &letra);
        letra = tolower(letra); 

        acertou = 0;
        for (int i = 0; i < tamanho; i++) {
            if (palavraSecreta[i] == letra && palavraOculta[i] == '_') {
                palavraOculta[i] = letra;
                letrasRestantes--;
                acertou = 1;
            }
        }

        if (!acertou) {
            tentativas++;
            printf("Letra incorreta!\n");
        } else {
            printf("Boa! Você acertou uma letra.\n");
        }
    }

    if (letrasRestantes == 0) {
        printf("\nParabéns! Você acertou a palavra: %s\n", palavraSecreta);
    } else {
        printf("\nFim de jogo! A palavra era: %s\n", palavraSecreta);
    }

    return 0;
}