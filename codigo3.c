// Laboratório 3 - Implementando o Método de Ordenação Shell Sort 

#include <stdio.h>

void ImprimeVetor(int A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Shellsort(int A[], int n) {
    int i, j, h = 1, x;
    do {
        h = h * 3 + 1;
    } while (h < n);

    do {
        h /= 3;
        for (i = h; i < n; i++) {
            x = A[i];
            j = i;
            while (j >= h && A[j - h] > x) {
                A[j] = A[j - h];
                j -= h;
            }
            A[j] = x;
        }
        printf("vetor %d (ordenado): \n", h);
        ImprimeVetor(A, n);
    } while (h > 1);
}



int main() {
    int A[8] = {1, 8, 3, 6, 5, 7, 2, 4};
    int n = 8;

    printf("vetor inicial: \n");
    ImprimeVetor(A, n);
    Shellsort(A, n);

    printf("vetor ordenado: \n");
    ImprimeVetor(A, n);

    return 0;
}
