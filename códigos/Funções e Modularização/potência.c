#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int potencia (int base, int expoente){
    int resultado = 1;
    for (int i = 0; i < expoente; i++){
        resultado *= base;
    }
    return resultado;
}

int main() {
    setlocale (LC_ALL, "portuguese");

    int base, expoente;

    printf ("digite o valor da base:");
    scanf ("%d", &base);

    printf ("digite o valor do expoente:");
    scanf ("%d", &expoente);

    int resultado = potencia (base, expoente);
    printf ("%d elevado a %d: %d \n", base, expoente, resultado);

    return 0;
}