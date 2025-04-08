// Laboratório 4 - Implementação de Duas Variações do Algoritmo de Ordenação QuickSort 

#include <stdio.h>

typedef int TipoIndice;

typedef struct {
    int Chave;
} TipoItem;

void Particao(TipoIndice Esq, TipoIndice Dir, TipoIndice *i, TipoIndice *j, TipoItem A[]) {
    TipoItem x, w;
    *i = Esq;
    *j = Dir;
    x = A[(*i + *j) / 2]; // obtém o pivô x

    do {
        while (x.Chave > A[*i].Chave) (*i)++;
        while (x.Chave < A[*j].Chave) (*j)--;

        if (*i <= *j) {
            w = A[*i];
            A[*i] = A[*j];
            A[*j] = w;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void Ordena(TipoIndice Esq, TipoIndice Dir, TipoItem *A) {
    TipoIndice i, j;
    Particao(Esq, Dir, &i, &j, A);
    if (Esq < j) Ordena(Esq, j, A);
    if (i < Dir) Ordena(i, Dir, A);
}

// Função do quicksort
void QuickSort(TipoItem *A, TipoIndice n) {
    Ordena(0, n - 1, A); // ajustado para começar do índice 0
}

void ImprimeVetor(TipoItem A[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i].Chave);
    }
    printf("\n");
}


int main() {
    TipoItem A[] = {{9}, {1}, {4}, {2}, {3}, {8}, {7}, {6}};
    int n = sizeof(A) / sizeof(A[0]);

    printf("vetor inicial:\n");
    ImprimeVetor(A, n);

    QuickSort(A, n);

    printf("vetor ordenado:\n");
    ImprimeVetor(A, n);

    return 0;
}