#include <stdio.h>
void aplicar_transformacao(double T[2][2], double *x, double *y) {
    double x_transformado = T[0][0] * (*x) + T[0][1] * (*y);
    double y_transformado = T[1][0] * (*x) + T[1][1] * (*y);
    *x = x_transformado;
    *y = y_transformado;
}

int main() {
    double T[2][2];
    int n;

    printf("Insira os elementos da matriz de transformação (2x2):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            scanf("%lf", &T[i][j]);
        }
    }

    printf("Insira o número de pontos: ");
    scanf("%d", &n);

    double pontos[n][2];
    printf("Insira as coordenadas dos pontos:\n");
    for (int i = 0; i < n; i++) {
        scanf("%lf %lf", &pontos[i][0], &pontos[i][1]);
    }

    printf("As coordenadas transformadas dos pontos são:\n");
    for (int i = 0; i < n; i++) {
        aplicar_transformacao(T, &pontos[i][0], &pontos[i][1]);
        printf("%.2lf %.2lf\n", pontos[i][0], pontos[i][1]);
    }

    return 0;
}
