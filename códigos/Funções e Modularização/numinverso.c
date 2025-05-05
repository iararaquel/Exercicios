#include <stdio.h>
#include <stdbool.h>
#include <locale.h> 

int inverternumero (int num){
    int invertido = 0;

    while (num !=0){
        int digito = num %10;
        invertido = invertido *10 + digito;
        num /= 10;
    }
    return invertido;
}

int main(){
    setlocale (LC_ALL, "portuguese");
    
    int num;

    printf ("digite um numero:");
    scanf ("%d", &num);

    int numinvertido = inverternumero (num);
    printf ("o numero invertido: %d\n", numinvertido);
    return 0;
}