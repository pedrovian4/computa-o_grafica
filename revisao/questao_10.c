#include <stdio.h>

double produto_escalar(double A[3], double B[3]) {
    return A[0] * B[0] + A[1] * B[1] + A[2] * B[2];
}

void projecao_ortogonal(double A[3], double B[3], double proj[3]) {
    double produto_ab = produto_escalar(A, B);
    double produto_bb = produto_escalar(B, B);
    double escalar = produto_ab / produto_bb;

    proj[0] = escalar * B[0];
    proj[1] = escalar * B[1];
    proj[2] = escalar * B[2];
}

int main() {
    double A[3], B[3], proj[3];

    printf("Insira os componentes do vetor A (A1 A2 A3): ");
    for (int i = 0; i < 3; i++) {
        scanf("%lf", &A[i]);
    }

    printf("Insira os componentes do vetor B (B1 B2 B3): ");
    for (int i = 0; i < 3; i++) {
        scanf("%lf", &B[i]);
    }

    projecao_ortogonal(A, B, proj);

    printf("A projeção ortogonal de A sobre B é: %.2lf %.2lf %.2lf\n", proj[0], proj[1], proj[2]);

    return 0;
}
