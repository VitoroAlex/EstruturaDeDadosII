// 24/04 - Laboratório 6 - Pesquisa Binária e Sequencial (2025/1)

#include <stdio.h>

// 1. Pesquisa Sequencial
int buscaSequencial(int vetor[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == alvo) {
            return i;
        }
    }
    return -1;
}

// 2. Pesquisa Binária Iterativa (Estruturada)
int buscaBinariaIterativa(int vetor[], int tamanho, int alvo) {
    int inicio = 0, fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = (inicio + fim) / 2;

        if (vetor[meio] == alvo) {
            return meio;
        } else if (vetor[meio] < alvo) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

// 3. Pesquisa Binária Recursiva
int buscaBinariaRecursiva(int vetor[], int inicio, int fim, int alvo) {
    if (inicio > fim) {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (vetor[meio] == alvo) {
        return meio;
    } else if (vetor[meio] < alvo) {
        return buscaBinariaRecursiva(vetor, meio + 1, fim, alvo);
    } else {
        return buscaBinariaRecursiva(vetor, inicio, meio - 1, alvo);
    }
}

// Função principal para teste
int main() {
    int vetor[] = {1, 3, 5, 7, 9, 11, 13};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int alvo = 7;

    printf("Busca Sequencial: indice = %d\n", buscaSequencial(vetor, tamanho, alvo));
    printf("Busca Binária Iterativa: indice = %d\n", buscaBinariaIterativa(vetor, tamanho, alvo));
    printf("Busca Binária Recursiva: indice = %d\n", buscaBinariaRecursiva(vetor, 0, tamanho - 1, alvo));

    return 0;
}