#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    int prioridade;
    struct no *prox;
}NO;

NO *inicio = NULL;

void add(int item, int prioridade) {
    NO *novo = malloc(sizeof(NO));
    novo->valor = item;
    novo->prioridade = prioridade;
    
    if (inicio == NULL || prioridade < inicio->prioridade) {
        novo->prox = inicio;
        inicio = novo;
    } else {
        NO *aux = inicio;
        while (aux->prox != NULL && aux->prox->prioridade <= prioridade) {
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}

int remover() {
    if (inicio == NULL) {
        printf("Fila vazia.\n");
        return -1;
    }
    int item = inicio->valor;
    struct no *aux = inicio;
    inicio = inicio->prox;
    free(aux);
    return item;
}

void imprimir() {
    if (inicio == NULL) {
        printf("Fila vazia.\n");
        return;
    }
    NO *aux = inicio;
    printf("Fila: ");
    while (aux != NULL) {
        printf("(%d, %d) ", aux->valor, aux->prioridade);
        aux = aux->prox;
    }
    printf("\n");
}

int main() {
    add(5, 2);
    add(2, 1);
    add(7, 3);
    add(1, 1);
    
    imprimir(); 
    remover(); 
    imprimir(); 
    
    return 0;
}
