#include <stdio.h>

void produto_vetorial(double vetor_a[3], double vetor_b[3], double vetor_c[3]) {
    vetor_c[0] = vetor_a[1] * vetor_b[2] - vetor_a[2] * vetor_b[1];
    vetor_c[1] = vetor_a[2] * vetor_b[0] - vetor_a[0] * vetor_b[2];
    vetor_c[2] = vetor_a[0] * vetor_b[1] - vetor_a[1] * vetor_b[0];
}

int main() {
    double vetor_a[3], vetor_b[3], vetor_c[3];

    printf("Insira os componentes do vetor A (A1 A2 A3): ");
    for (int i = 0; i < 3; i++) {
        scanf("%lf", &vetor_a[i]);
    }

    printf("Insira os componentes do vetor B (B1 B2 B3): ");
    for (int i = 0; i < 3; i++) {
        scanf("%lf", &vetor_b[i]);
    }

    produto_vetorial(vetor_a, vetor_b, vetor_c);

    printf("O vetor resultante do produto vetorial é: %.2lf %.2lf %.2lf\n", vetor_c[0], vetor_c[1], vetor_c[2]);

    return 0;
}
