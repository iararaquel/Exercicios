#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para criptografar uma mensagem usando a Cifra de César
void cifraDeCesar(char mensagem[], int deslocamento) {
    for (int i = 0; mensagem[i] != '\0'; i++) {
        char c = mensagem[i];

        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            mensagem[i] = (c - base + deslocamento) % 26 + base;
        }
    }
}

int main() {
    char mensagem[100];
    int deslocamento;

    printf("Digite a mensagem: ");
    scanf(" %[^\n]", mensagem);

    printf("Digite o valor do deslocamento: ");
    scanf("%d", &deslocamento);

    cifraDeCesar(mensagem, deslocamento);

    printf("Mensagem criptografada: %s\n", mensagem);

    return 0;
}