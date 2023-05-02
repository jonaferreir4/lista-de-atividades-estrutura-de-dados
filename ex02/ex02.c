#include<stdio.h>
#include<stdlib.h>
// 2.2 Considere uma Fila de elementos inteiros positivos onde é aceito a inserção de elementos iguais.
typedef struct no {
    int valor;
    struct no *prox;
    struct no *ant;
} NO;
NO *inicio = NULL;
NO *fim = NULL;
int tam = 0;


// Crie os seguintes funções:
// a) Adicionar um elemento na fila;
void add(int valor){
    NO *novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;


    if(inicio == NULL){
        inicio = novo;
        fim  = novo;
    } else{
        novo->prox =inicio;
        inicio->ant = novo;
        inicio = novo;
    }
    tam++;
}
// b) Remover um elemento da fila;
int remover(){
    if(tam > 0){
        NO *lixo = fim;
        int valor = fim->valor;
        fim = fim->ant;
        free(lixo);
        tam--;
        return valor;
    }
    else {
        printf("A lista está vazia.");
        return -1;
    }
}
// c) Imprimir os elementos da fila;

void imprimir(){
    NO * aux = inicio;
    for(int i = 0; i < tam; i++){
        printf("Valor = %d\n", aux->valor);
        aux = aux->prox;
    }
}
// d) Retornar o tamanho da fila;
int tamanho(){
    printf("A fila tem %d elementos.\n", tam);
    return tam;
}
int main(){
    add(10);
    add(100);
    add(30);
    add(40);
    imprimir();
    tamanho();
    remover();
    imprimir();
    tamanho();

}

// 2.2)Encadeamento duplo. Para exercitar meu conhecimento
    // e para ter mais opções de uso caso o código tenha que passar por novas adições de funcões.