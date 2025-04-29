#include <stdio.h>
#include <stdbool.h>
#include <locale.h> 

bool ehPrimo (int n){
    
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++){
        if (n % i == 0)
            return false;
    }
    return true;
}
 
int main(){
    
    int comeco, final;
    printf ("digite o comeco do intervalo:");
    scanf ("%d" , &comeco);

    printf ("digite o final do intervalo:");
    scanf ("%d" , &final);

    printf("os números primos entre %d e %d são:\n", comeco, final);

    for(int i = comeco; i <= final; i++){
        if (ehPrimo (i)){
            printf ("%d", i);
        }
    }
    printf ("\n");
    return 0;
}

    