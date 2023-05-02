// 3) Uma empilhadeira carrega caixas de 7, 5, 3 toneladas. Há três pilhas A, B, C. A pilha A é onde se
// encontram todas as caixas que chegam no depósito. Com um detalhe: caixas maiores não podem ser
// empilhadas sobre caixas menores. Elabore um programa que efetue o controle das caixas, de forma
// que caso uma caixa de maior peso do que uma que já está em A deva ser empilhada, então, todas as
// caixas que estão em A são movidas para as pilhas auxiliares B (contendo somente caixa de 5
// toneladas) e C (contendo somente caixas de 3 toneladas) até que se possa empilhar a nova caixa.
// Depois, todas as caixas são movidas de volta para a pilha A.

#include <stdio.h>
#include <stdlib.h>

typedef struct no
{
    int peso;
    struct no *prox;
} NO;

typedef struct Pilha
{
    NO *inicio;
    int tam;
} PILHA;


PILHA *A;
PILHA *B;
PILHA *C;

PILHA *inicia()
{
    PILHA *p = malloc(sizeof(PILHA));
    p->inicio = NULL;
    p->tam = 0;
}


void add(int peso, PILHA *p)
{

    NO *novo = malloc(sizeof(NO));
    novo->peso = peso;
    novo->prox = NULL;

    if (p->inicio == NULL)
    {
        p->inicio = novo;
    }
    else
    {
        novo->prox = p->inicio;
        p->inicio = novo;
    }
    p->tam++;
}

int remover(PILHA *p)
{
    NO *lixo = p->inicio;
    int peso_retornado = -1;

    if (p->inicio != NULL)
    {
        peso_retornado = p->inicio->peso;
        p->inicio = p->inicio->prox;
        free(lixo);
        p->tam--;
    }
    return peso_retornado;
}

void Selection(int pesoNovo) {// 5 3 7 3 5
    if (A->inicio == NULL) {
        add(pesoNovo, A);
    }

    else if (A->inicio->peso >= pesoNovo){
        add(pesoNovo, A);
    }
    else{

        while (A->inicio != NULL && A->inicio->peso < pesoNovo){

            if (A->inicio->peso == 5){
                int valor = remover(A);
                add(valor, B);
            }

            else if (A->inicio->peso == 3){
                int valor = remover(A);
                add(valor, C);
            }
        }
        add(pesoNovo, A);

        while (B->inicio != NULL && A->inicio->peso >= B->inicio->peso){   
            int valorB = remover(B);
            add(valorB, A);
        }

        }
        while (C->inicio != NULL && A->inicio->peso >= C->inicio->peso){
            int valorC = remover(C);
            add(valorC, A);
        }
    }

void imprimir(){
    PILHA *aux = A;

    printf("Tamanho de A: %d\n", A->tam);
    printf("Tamanho de B: %d\n", B->tam);
    printf("Tamanho de C: %d\n\n", C->tam);

    for (int i = 0; i < aux->tam; i++){
        printf("A - Peso: %d\n", aux->inicio->peso);
        aux->inicio = aux->inicio->prox;
    }
}

int main(){

    A = inicia();
    B = inicia();
    C = inicia();

    Selection(3);
    Selection(5);
    Selection(7);
    Selection(7);
    Selection(5);
    Selection(3);
    Selection(5);
    
    imprimir();
}