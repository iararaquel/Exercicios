#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef struct {
    int n;
    double valor;
} MemoEntry;

double algoritmo_original(int n) {
    if (n <= 1) return n;
    return algoritmo_original(n-1) + algoritmo_original(n-2);
}

double algoritmo_otimizado(int n, MemoEntry *memo, int *memo_size) {
    
    for (int i = 0; i < *memo_size; i++) {
        if (memo[i].n == n) {
            return memo[i].valor;
        }
    }
    
    if (n <= 1) {
        return n;
    }
    
    double valor = algoritmo_otimizado(n-1, memo, memo_size) + 
                   algoritmo_otimizado(n-2, memo, memo_size);
    
    memo[*memo_size].n = n;
    memo[*memo_size].valor = valor;
    (*memo_size)++;
    
    return valor;
}

double medir_tempo(double (*algoritmo)(int), int n, int repeticoes) {
    clock_t inicio, fim;
    double tempo_total = 0;
    
    MemoEntry *memo = NULL;
    int memo_size = 0;
    
    if (algoritmo == algoritmo_otimizado) {
        memo = malloc(n * sizeof(MemoEntry));
    }
    
    for (int i = 0; i < repeticoes; i++) {
        inicio = clock();
        
        if (algoritmo == algoritmo_otimizado) {
            algoritmo_otimizado(n, memo, &memo_size);
        } else {
            algoritmo_original(n);
        }
        
        fim = clock();
        tempo_total += ((double)(fim - inicio)) / CLOCKS_PER_SEC;
        
        if (algoritmo == algoritmo_otimizado) {
            memo_size = 0;
        }
    }
    
    if (memo != NULL) {
        free(memo);
    }
    
    return tempo_total / repeticoes;
}

// Função para gerar o gráfico
void gerar_grafico() {
    FILE *dados_original = fopen("dados_original.dat", "w");
    FILE *dados_otimizado = fopen("dados_otimizado.dat", "w");
    
    const int repeticoes = 10;
    const int max_n_original = 30;  // Limite para o original
    const int max_n_otimizado = 50; // Limite maior para o otimizado
    
    printf("Calculando tempos para o algoritmo original...\n");
    for (int n = 1; n <= max_n_original; n++) {
        double tempo = medir_tempo(algoritmo_original, n, repeticoes);
        fprintf(dados_original, "%d %.6f\n", n, tempo);
        printf("n=%d: original=%.6fs\n", n, tempo);
    }
    
    printf("\nCalculando tempos para o algoritmo otimizado...\n");
    for (int n = 1; n <= max_n_otimizado; n += 2) {  
        double tempo = medir_tempo((double (*)(int))algoritmo_otimizado, n, repeticoes);
        fprintf(dados_otimizado, "%d %.6f\n", n, tempo);
        printf("n=%d: otimizado=%.6fs\n", n, tempo);
    }
    
    fclose(dados_original);
    fclose(dados_otimizado);
    
    FILE *gnuplot = fopen("script.gnu", "w");
    fprintf(gnuplot, "set terminal pngcairo enhanced font 'arial,10' size 1000,600\n");
    fprintf(gnuplot, "set output 'algoritmo_otimizado1.png'\n");
    fprintf(gnuplot, "set title 'Comparação: Algoritmo Original vs Otimizado (Recursão com Memoização)'\n");
    fprintf(gnuplot, "set xlabel 'Valor de n'\n");
    fprintf(gnuplot, "set ylabel 'Tempo médio de execução (segundos)'\n");
    fprintf(gnuplot, "set grid\n");
    fprintf(gnuplot, "set key left top\n");
    fprintf(gnuplot, "plot 'dados_original.dat' with lines lw 2 lt rgb 'blue' title 'Original (Recursivo)', \\\n");
    fprintf(gnuplot, "     'dados_otimizado.dat' with lines lw 2 lt rgb 'red' title 'Otimizado (Recursão com Memoização)'\n");
    fclose(gnuplot);
    
    system("gnuplot script.gnu");
    printf("\nGr\xa0fico gerado com sucesso: 'algoritmo_otimizado1.png'\n");
}

int main() {
    printf("=== Análise de Desempenho: Algoritmo Recursivo Otimizado ===\n");
    gerar_grafico();
    return 0;
}