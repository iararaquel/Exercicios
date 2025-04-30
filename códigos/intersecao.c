#include <stdio.h>
#include <stdbool.h>
#include <locale.h> 

int main(){
    setlocale (LC_ALL, "portuguese");
    int vetor1[] = {1,2,3,4,5};
    int vetor2 [] = {3,4,5,6,7};
    int tamanho1 = sizeof (vetor1) / sizeof (vetor1[0]);
    int tamanho2 = sizeof (vetor2) / sizeof (vetor2 [0]);
    
    printf ("elementos comuns:\n");

    for (int i = 0; i < tamanho1; i++){
        for (int j = 0; j < tamanho2; j++){
            if (vetor1[i] == vetor2[j]){
                printf ("%d", vetor1[i]);
                break;
            }
        }
    }

    printf ("\n");
    return 0;
}
    