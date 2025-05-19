//  Laboratório 7 - Implementação da Tabela Hash

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STR 20

typedef struct Nodo {
    char str[MAX_STR];
    struct Nodo* prox;
} Nodo;

typedef struct {
    Nodo** tabela;
    int tamanho;
    int colisoes;
} HashTable;

// função hash simples
int hash(char* str, int M) {
    int h = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        h = (31 * h + str[i]) % M;
    }
    return h;
}

// tabela criada
HashTable* criaHash(int M) {
    HashTable* h = malloc(sizeof(HashTable));
    h->tabela = calloc(M, sizeof(Nodo*));
    h->tamanho = M;
    h->colisoes = 0;
    return h;
}

void insere(HashTable* h, char* str) {
    int idx = hash(str, h->tamanho);
    Nodo* atual = h->tabela[idx];
    
    if (atual != NULL) {
        h->colisoes++;
    }

    Nodo* novo = malloc(sizeof(Nodo));
    strcpy(novo->str, str);
    novo->prox = h->tabela[idx];
    h->tabela[idx] = novo;
}

void geraString(char* str, int tam) {
    for (int i = 0; i < tam - 1; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[tam - 1] = '\0';
}

void liberaHash(HashTable* h) {
    for (int i = 0; i < h->tamanho; i++) {
        Nodo* atual = h->tabela[i];
        while (atual) {
            Nodo* temp = atual;
            atual = atual->prox;
            free(temp);
        }
    }
    free(h->tabela);
    free(h);
}

int main() {
    srand(time(NULL));
    
    int M = 79; // tamanho da tabela
    int N = 1000; // número de strings

    HashTable* h = criaHash(M);

    clock_t inicio = clock();
    
    for (int i = 0; i < N; i++) {
        char str[MAX_STR];
        geraString(str, 10); 
        insere(h, str);
    }

    clock_t fim = clock();
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("M: %d | N: %d\n", M, N);
    printf("Colisoes: %d\n", h->colisoes);
    printf("Tempo de execucao: %.6f segundos\n", tempo);

    liberaHash(h);
    return 0;
}
