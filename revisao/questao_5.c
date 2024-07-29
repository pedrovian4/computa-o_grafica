#include <stdio.h>

// Função para calcular o ponto de interseção usando a fórmula de Cramer
int calcular_intersecao(double a1, double b1, double c1, double a2, double b2, double c2, double *x, double *y) {
    double determinante = a1 * b2 - a2 * b1;
    if (determinante == 0) {
        return 0; // As retas são paralelas ou coincidentes
    }

    *x = (b2 * c1 - b1 * c2) / determinante;
    *y = (a1 * c2 - a2 * c1) / determinante;
    return 1;
}

int main() {
    double a1, b1, c1, a2, b2, c2;
    double x, y;

    printf("Insira os coeficientes da Reta 1 (a1 b1 c1): ");
    scanf("%lf %lf %lf", &a1, &b1, &c1);

    printf("Insira os coeficientes da Reta 2 (a2 b2 c2): ");
    scanf("%lf %lf %lf", &a2, &b2, &c2);

    if (calcular_intersecao(a1, b1, c1, a2, b2, c2, &x, &y)) {
        printf("O ponto de interseção é: %.2lf %.2lf\n", x, y);
    } else {
        printf("As retas são paralelas ou coincidentes e não há ponto de interseção único.\n");
    }

    return 0;
}
