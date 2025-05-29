#include <stdio.h>

int main() {
    int matriz[4][4];
    int somaDiagonal = 0;

    printf("Digite os elementos da matriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

            if (i == j) {
                somaDiagonal += matriz[i][j];
            }
        }
    }

    printf("\nMatriz 4x4:\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nSoma da diagonal principal: %d\n", somaDiagonal);

    return 0;
}