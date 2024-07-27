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

void limpa_memoria_array_bidimensional_inteiro(int **matriz, int n) {
    for(int i = 0; i < n; i++){
        free(matriz[i]);
    }
    free(matriz);
}

void mostrar_matriz(int **matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void get_submatriz(int **matriz, int **submatriz, int n, int col) {
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

int determinante(int **matriz, int n) {
    // Para uma matriz 1x1, o determinante é o próprio elemento.
    if(n == 1){
        return matriz[0][0];
    }
    // Quando o N é 2, o determinante é calculado diretamente.
    if(n == 2 ){
        return matriz[0][0] * matriz[1][1] - matriz[0][1] * matriz[1][0];
    }
    
    int det = 0;
    int **submatriz = (int**)malloc((n-1) * sizeof(int*));
    for(int i = 0; i < (n-1); i++){
        submatriz[i] = (int*)malloc((n-1) * sizeof(int));
    }
    
    for(int i = 0; i < n; i++){
        get_submatriz(matriz, submatriz, n, i);
        int sub_matriz_determinante = determinante(submatriz, n-1);
        det += (i % 2 == 0 ? 1 : -1) * matriz[0][i] * sub_matriz_determinante;
    }
    
    for(int i = 0; i < (n-1); i++){
        free(submatriz[i]);
    }
    free(submatriz);

    return det;
}

int main() {
    int n;

    printf("Insira um valor entre 1 e 10: ");
    scanf("%d", &n);

    if (n < 1 || n > 10) {
        printf("Número inválido\n");
        return 0;
    }

    int** matriz = inicializa_matriz(n);

    int det = determinante(matriz, n);

    printf("Matriz:\n");
    mostrar_matriz(matriz, n);

    printf("\nDeterminante: %d\n", det);

    limpa_memoria_array_bidimensional_inteiro(matriz, n);

    return 0;
}
