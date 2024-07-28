#include <stdio.h>
#include "helpers.h"



int main(){
    /** 
     * Matriz A
     * **/
    printf("Insira quantidade de linhas da matriz A: ");
    int linhas_matriz_a;
    scanf("%d", &linhas_matriz_a);
    printf("Insira quantidade de colunas da matriz A: ");
    int colunas_matriz_a;
    scanf("%d", &colunas_matriz_a);
    int ** matriz_a = inicializa_matriz_colunas_e_linhas(linhas_matriz_a, colunas_matriz_a);
    /** 
     * Matriz B
     * **/
    printf("Insira quantidade de linhas da matriz B: ");
    int linhas_matriz_b;
    scanf("%d", &linhas_matriz_b);

    if(colunas_matriz_a != linhas_matriz_b){
        limpar_cli();
        printf("\n\n\033[1;31mO número de colunas da Matriz A deve ser igual ao número de linhas da Matriz B\033[0m\n");        
        return -1;
    }

    printf("Insira quantidade de colunas da matriz B: ");
    int colunas_matriz_b;
    scanf("%d", &colunas_matriz_b);
    int ** matriz_b = inicializa_matriz_colunas_e_linhas(linhas_matriz_b, colunas_matriz_b);
    int **matriz_c =  multiplica_matrizes_int(matriz_a, linhas_matriz_a, colunas_matriz_a, matriz_b, colunas_matriz_b);
    limpar_cli();
    printf("Produto: \n");
    mostrar_matriz_bidimensional(matriz_c, linhas_matriz_a);

    limpa_memoria_array_bidimensional_inteiro(matriz_a, linhas_matriz_a);
    limpa_memoria_array_bidimensional_inteiro(matriz_b, linhas_matriz_b);
    limpa_memoria_array_bidimensional_inteiro(matriz_c, linhas_matriz_a);

    return 0;
}
