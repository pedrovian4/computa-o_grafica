#include <stdio.h>
#include <stdlib.h>
#include "helpers.h"

void eliminacao_gauss(int n, double mat[n][n+1], double result[n]) {
    // Transformar a matriz aumentada em uma matriz triangular superior
    for (int i = 0; i < n; i++) {
        // Encontrar o pivô
        int max = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(mat[k][i]) > abs(mat[max][i])) {
                max = k;
            }
        }

        // Trocar a linha atual com a linha do pivô
        for (int k = i; k <= n; k++) {
            double tmp = mat[max][k];
            mat[max][k] = mat[i][k];
            mat[i][k] = tmp;
        }

        // Eliminação
        for (int k = i + 1; k < n; k++) {
            double factor = mat[k][i] / mat[i][i];
            for (int j = i; j <= n; j++) {
                mat[k][j] -= factor * mat[i][j];
            }
        }
    }

    // Substituição regressiva
    for (int i = n - 1; i >= 0; i--) {
        result[i] = mat[i][n];
        for (int j = i + 1; j < n; j++) {
            result[i] -= mat[i][j] * result[j];
        }
        result[i] /= mat[i][i];
    }
}
int main(){
    int n;
    printf("Insira o número de equações: ");
    scanf("%d", &n);

    double mat[n][n+1];
    double resultado[n];

    printf("Insira a matriz aumentada (n linhas com n+1 colunas):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            printf("matriz[%d][%d]: ", i, j);
            scanf("%lf", &mat[i][j]);
        }
    }
    eliminacao_gauss(n, mat, resultado);
    printf("Soluções:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2lf ", resultado[i]);
    }
    printf("\n");
}