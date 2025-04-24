// Laboratório 5 - Implementação do Método de Ordenação Bubble Sort
#include <stdio.h>
#include <stdbool.h>  // biblioteca para funções booleanas

void bubbleSort(int arr[], int n) {
    bool trocaFeita; // variável booleana para verificar se houve troca no sistema
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        trocaFeita = false; 

        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                trocaFeita = true; // verifica se há troca
            }
        }

        
        if (!trocaFeita) {
            break; //programa encerra se não há mais troca necessária
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int array[] = {2, 9, 8, 5, 1, 4, 3, 7, 6, 4};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array inicial: ");
    printArray(array, n);

    bubbleSort(array, n);

    printf("Array ordenado: ");
    printArray(array, n);

    return 0;
}
