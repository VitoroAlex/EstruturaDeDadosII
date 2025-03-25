// Laboratório 1 - Implementação do Método de Ordenação por Seleção (2025/1)

#include <stdio.h>

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int diasDoMes[31];
    for (int i = 0; i < 31; i++) {
        diasDoMes[i] = i + 1;
    }
    
    selectionSort(diasDoMes, 31);
    
    printf("Dias do mes ordenados: ");
    printArray(diasDoMes, 31);
    
    printf("Maior dia: %d\n", diasDoMes[31]);
    
    return 0;
}
