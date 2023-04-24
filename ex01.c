#include <stdio.h>
#include <stdlib.h>
// 1.1 Considere uma Pilha de elementos inteiros positivos onde é aceito a inserção de elementos iguais.
typedef struct no
{
    int valor;
    struct no *prox;
} NO;

NO *topo = NULL;
int tam = 0;
// Crie os seguintes funções:

// a) Adicionar um elemento na pilha;
void add(int valor)
{
    NO *novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if (topo == NULL) // pilha vazia
    { 
        topo = novo;
    }
    else
    {
        novo->prox = topo;
        topo = novo;
    }
    tam++;
}

// b) Remover um elemento da pilha;
int remover(){
    if(tam > 0){
    NO *lixo = topo;
    int valor = topo->valor;
    topo = topo->prox;
    free(lixo);
    tam--;
    return valor;
    }

    else {
        printf("A lista está vazia");
        return -1;
    }
}

// c) Imprimir os elementos da pilha;
void imprimir(){
    NO *aux = topo;
    for (int i = 0; i < tam; i++){
        printf("Valor = %d\n", aux->valor);
        aux = aux->prox;
    }
}

// d) Retornar o tamanho da pilha;*
int tamanho(){
    printf("Existem %d elementos na pilha\n", tam);
    return tam;
}

int main()
{
    add(10);
    add(50);
    add(30);
    add(20);
    remover();
    imprimir();
    tamanho();

}

//1.2) lista encadeada. Porque não vi a necessidade de usar lista duplamente encadeada para esse exercicio.
        // E entre lista encadeada e array, tenho mais familiariadade com lista encadeada. 
