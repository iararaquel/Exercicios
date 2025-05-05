#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

int main(){
    setlocale (LC_ALL, "portuguese");
    
    int matriz1 [3][3], matriz2 [3][3], soma [3][3];

    printf ("digite os elementos da matriz1 3x3:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf ("elemento [%d][%d]:", i, j);
            scanf("%d", &matriz1[i][j]);
        }
    }

    printf("digite os elementoss da matriz2 3x3:\n");
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf ("elemento [%d][%d]:", i, j);
            scanf ("%d", &matriz2[i][j]);
        }
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            soma [i][j] = matriz1[i][j]+matriz2[i][j];

        }
    }

    printf ("\n matriz resultante da soma :\n");
    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            printf ("%4d", soma [i][j]);
        }
        
    }

    return 0;
} 