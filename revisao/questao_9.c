#include <stdio.h>
#include <math.h>

void calcular_circunferencia(double x1, double y1, double x2, double y2, double x3, double y3, double *h, double *k, double *r) {
    double D = 2 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
    if (D == 0) {
        printf("Os pontos são colineares e não definem uma circunferência.\n");
        return;
    }

    *h = ((x1 * x1 + y1 * y1) * (y2 - y3) + (x2 * x2 + y2 * y2) * (y3 - y1) + (x3 * x3 + y3 * y3) * (y1 - y2)) / D;
    *k = ((x1 * x1 + y1 * y1) * (x3 - x2) + (x2 * x2 + y2 * y2) * (x1 - x3) + (x3 * x3 + y3 * y3) * (x2 - x1)) / D;
    *r = sqrt((*h - x1) * (*h - x1) + (*k - y1) * (*k - y1));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    double h, k, r;

    printf("Insira as coordenadas do ponto A (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);

    printf("Insira as coordenadas do ponto B (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);

    printf("Insira as coordenadas do ponto C (x3 y3): ");
    scanf("%lf %lf", &x3, &y3);

    calcular_circunferencia(x1, y1, x2, y2, x3, y3, &h, &k, &r);

    printf("A equação da circunferência é: (x - %.2lf)^2 + (y - %.2lf)^2 = %.2lf^2\n", h, k, r);

    return 0;
}
