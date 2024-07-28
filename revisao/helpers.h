#include <stdio.h>
#include <stdlib.h>


int** inicializa_matriz(int n) {
    // Alocação de memória dinâmica
    int** matriz = (int**)malloc(n * sizeof(int*));
    
    // Alocação dinâmica dos arrays de arrays
    for (int i = 0; i < n; i++) {
        matriz[i] = (int*)malloc(n * sizeof(int));   
    }

    // Solicita os valores ao usuário para preencher a matriz
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Insira o valor para matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    return matriz;
}


int ** inicializa_matriz_colunas_e_linhas(int linhas, int colunas)
{   
    int ** matriz  = (int**)malloc(linhas * sizeof(int*));

    for(int i = 0; i < linhas; i ++){
        matriz[i] = (int *)malloc(linhas*sizeof(int));
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++){
            printf("Insira o valor para matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    return matriz;
}


void limpa_memoria_array_bidimensional_inteiro(int **matriz, int n) {
    for(int i = 0; i < n; i++){
        free(matriz[i]);
    }
    free(matriz);
}


void mostrar_matriz_bidimensional(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void get_submatriz_bidimensional(int **matriz, int **submatriz, int n, int col) {
    int subi = 0;
    for(int i = 1; i < n; i++){
        int subj = 0;
        for(int j = 0; j < n; j++){
            if(j == col) {
                continue;
            }
            submatriz[subi][subj] = matriz[i][j];
            subj++;
        }
        subi++;
    }
}

void limpar_cli() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear"); 
    #endif
}

int **multiplica_matrizes_int(int **matriz_a, int linhas_a, int colunas_a, int **matriz_b, int colunas_b) {
    int **matriz_c = inicializa_matriz_colunas_e_linhas(linhas_a, colunas_b);
    
    for (int i = 0; i < linhas_a; i++) {
        for (int j = 0; j < colunas_b; j++) {
            matriz_c[i][j] = 0;
            for (int k = 0; k < colunas_a; k++) {
                matriz_c[i][j] += matriz_a[i][k] * matriz_b[k][j];
            }
        }
    }
    return matriz_c;
}