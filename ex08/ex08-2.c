#include <stdio.h>
#include <stdlib.h>

typedef struct elemento {
    int valor;
    int prioridade;
} Elemento;

typedef struct no {
    Elemento elemento;
    struct no *prox;
} No;

typedef struct {
    No *inicio;
    No *fim;
} FilaDePrioridade;

void inicia(FilaDePrioridade *fila) {
    fila->inicio = fila->fim = NULL;
}

void add(FilaDePrioridade *fila, int valor, int prioridade) {
    Elemento novoElemento = {valor, prioridade};
    No *novoNo = (No*)malloc(sizeof(No));
    novoNo->elemento = novoElemento;
    novoNo->prox = NULL;
    if (fila->fim == NULL) {
        fila->inicio = fila->fim = novoNo;
    } else {
        fila->fim->prox = novoNo;
        fila->fim = novoNo;
    }
}

int remover(FilaDePrioridade *fila) {
    if (fila->inicio == NULL) {
        printf("Fila vazia!\n");
        return -1;
    }
    No *noRemovido = fila->inicio;
    No *noAnterior = NULL;
    No *noAtual = fila->inicio;
    No *noMax = fila->inicio;
    while (noAtual != NULL) {
        if (noAtual->elemento.prioridade > noMax->elemento.prioridade) {
            noMax = noAtual;
            noAnterior = noRemovido;
        }
        noRemovido = noAnterior == NULL ? fila->inicio : noAnterior->prox;
        noAtual = noRemovido == NULL ? NULL : noRemovido->prox;
    }
    int valorRemovido = noMax->elemento.valor;
    if (noMax == fila->inicio) {
        fila->inicio = noMax->prox;
    } else {
        noAnterior->prox = noMax->prox;
    }
    free(noMax);
    return valorRemovido;
}

void imprimir(FilaDePrioridade fila) {
    printf("Fila de Prioridade:\n");
    No *noAtual = fila.inicio;
    while (noAtual != NULL) {
        printf("(%d, %d) ", noAtual->elemento.valor, noAtual->elemento.prioridade);
        noAtual = noAtual->prox;
    }
    printf("\n");
}

int main() {
    FilaDePrioridade fila;
    inicia(&fila);
    add(&fila, 1, 5);
    add(&fila, 2, 2);
    add(&fila, 3, 7);
    add(&fila, 4, 1);
    add(&fila, 5, 9);
    imprimir(fila);
    int valorRemovido = remover(&fila);
    printf("Valor removido: %d\n", valorRemovido);
    imprimir(fila);
    return 0;
}
