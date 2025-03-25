// Laboratório 2 - Implementação do Método de Ordenação por inserção (2025/1)

#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int carros[20];
    for (int i = 0; i < 20; i++) {
        carros[i] = i + 1;
    }
    
    insertionSort(carros, 20);
    
    printf("Ordem dos carros na corrida: ");
    printArray(carros, 20);
    
    printf("O maior número de carro é: %d\n", carros[19]);
    
    return 0;
}