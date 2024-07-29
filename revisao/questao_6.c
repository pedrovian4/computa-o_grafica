#include <stdio.h>
#include <math.h>

double calcular_distancia(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

int main() {
    double x1, y1, z1, x2, y2, z2;
    double distancia;

    printf("Insira as coordenadas do ponto P1 (x1 y1 z1): ");
    scanf("%lf %lf %lf", &x1, &y1, &z1);

    printf("Insira as coordenadas do ponto P2 (x2 y2 z2): ");
    scanf("%lf %lf %lf", &x2, &y2, &z2);

    distancia = calcular_distancia(x1, y1, z1, x2, y2, z2);

    printf("A distância entre os pontos é: %.2lf\n", distancia);

    return 0;
}
