#include <stdio.h>
#include <stdlib.h>


double calcular_area_triangulo(double x1, double y1, double x2, double y2, double x3, double y3) {
    return 0.5 * fabs(x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2));
}

int main() {
    double x1, y1, x2, y2, x3, y3;
    double area;

    printf("Insira as coordenadas do vértice A (x1 y1): ");
    scanf("%lf %lf", &x1, &y1);

    printf("Insira as coordenadas do vértice B (x2 y2): ");
    scanf("%lf %lf", &x2, &y2);

    printf("Insira as coordenadas do vértice C (x3 y3): ");
    scanf("%lf %lf", &x3, &y3);

    area = calcular_area_triangulo(x1, y1, x2, y2, x3, y3);

    printf("A área do triângulo é: %.2lf\n", area);

    return 0;
}