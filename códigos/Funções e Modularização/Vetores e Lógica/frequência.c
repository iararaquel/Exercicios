#include <stdio.h>
#include <stdbool.h>
#include <locale.h> 

int main(){
    setlocale (LC_ALL, "portuguese");
    int numeros [10];
    int frequencia [10];
    int i, j;

    printf ("digite 10 numeros inteiros:\n");
    for (i = 0; i < 10; i++){
        scanf ("%d", &numeros [i]);
        frequencia [i] = 1;
    }

    for (i = 0; i < 10; i++){
        if (numeros [i] == -99999) continue;

        for (j = i+1; j < 10; j++){
            if (numeros [i] == numeros [j]){
                frequencia [i]++;
                numeros [j] = -99999;
            }
        }
    }
    
    printf ("\n frequencia dos numeros: \n");
    for ( i = 0; i < 10; i++){
        if (numeros [i]!= -99999){
            printf ("%d aparece %d vezes \n", numeros [i], frequencia [i]);
        }
    }

    return 0;
}
  