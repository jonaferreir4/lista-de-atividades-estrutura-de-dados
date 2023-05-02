// 6) Utilizando somente operações de empilhar e desempilhar, escreva um programa que remove um
// item com chave c fornecida pelo usuário da pilha. Ao final da execução da função, a pilha deve ser
// igual à original, exceto pela ausência do item removido.
#include <stdio.h>
#include <stdlib.h>
typedef struct no
{
    int valor;
    struct no *prox;
} NO;

NO *topo = NULL;
int tam = 0;

void add(int valor)
{
    NO *novo = malloc(sizeof(NO));
    novo->valor = valor;
    novo->prox = NULL;

    if (topo == NULL) 
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

int remover(int Val){
    NO* atual = topo;
    NO* anterior = NULL;
    int Valor_guardado;
while (atual != NULL) {
        if (atual->valor == Val) {
            if (anterior == NULL) {
                topo = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            Valor_guardado = atual->valor;
            free(atual);
            return Valor_guardado ;
        }
        anterior = atual;
        atual = atual->prox;
    }

   
}

void imprimir(){
    NO *aux = topo;
    for (int i = 0; i < tam; i++){
        printf("Valor = %d\n", aux->valor);
        aux = aux->prox;
    }
}

int main()
{
    add(10);
    add(50);
    add(30);
    add(20);
    remover(50);
    imprimir();
}

