#include <stdio.h>
#include <stdlib.h>

typedef struct caixa {
    int peso;
    struct caixa *prox;
    struct caixa *ant;
} CX;

CX *topo_A = NULL;
CX *topo_B = NULL;
CX *topo_C = NULL;

int tam_a = 0;
int tam_b = 0;
int tam_c = 0;

void empilhar(int peso)
{
    CX *novaCaixa = malloc(sizeof(CX));
    novaCaixa->peso = peso;
    novaCaixa->prox = NULL;
    novaCaixa->ant = NULL;

    if (topo_A == NULL) {
        topo_A = novaCaixa;
        tam_a++;
    }
    else if (topo_A->peso >= novaCaixa->peso) {
        novaCaixa->prox = topo_A;
        topo_A->ant = novaCaixa;
        topo_A = novaCaixa;
        tam_a++;
    }
    else if (novaCaixa->peso == 5) {
        if (topo_A->peso == 3) {
            if (topo_C == NULL) {
                topo_C = topo_A;
                topo_A = topo_A->prox;
                tam_a--;
                tam_c++;
            }
        }
        
        else {
            novaCaixa->prox = topo_A;
            topo_A->ant = novaCaixa;
            topo_A = novaCaixa;
            tam_a++;
        }
    }
    else if (novaCaixa->peso == 3) {
        for (CX *caixa = topo_A; caixa != NULL; caixa = caixa->prox) {
            if (caixa->peso == 5) {
                CX *caixaAnterior = caixa->ant;
                CX *caixaPosterior = caixa->prox;

                if (caixaAnterior != NULL) {
                    caixaAnterior->prox = caixaPosterior;
                }
                else {
                    topo_A = caixaPosterior;
                }

                if (caixaPosterior != NULL) {
                    caixaPosterior->ant = caixaAnterior;
                }

                caixa->ant = NULL;
                caixa->prox = NULL;

                if (topo_C == NULL) {
                    topo_C = caixa;
                }
                else {
                    CX *ultimaCaixa = topo_C;
                    while (ultimaCaixa->prox != NULL) {
                        ultimaCaixa = ultimaCaixa->prox;
                    }
                    ultimaCaixa->prox = caixa;
                    caixa->ant = ultimaCaixa;
                }

                tam_a--;
                tam_c++;
            }
        }
        novaCaixa->prox = topo_A;
        topo_A->ant = novaCaixa;
        topo_A = novaCaixa;
        tam_a++;
    }
}

void imprimir() {
    CX *aux_a = topo_A;
    CX *aux_b = topo_B;
    CX *aux_c = topo_C;
 printf("A - %d, B - %d, C - %d\n", tam_a, tam_b, tam_c);

    for (int i = 0; i < tam_a; i++)
    {
        printf("A - Valor = %d\n", aux_a->peso);
        aux_a = aux_a->prox;
    }
    for (int i = 0; i < tam_b; i++)
    {
        printf("B - Valor = %d\n", aux_b->peso);
        aux_b = aux_b->prox;
    }
    for (int i = 0; i < tam_c; i++)
    {
        printf("C - Valor = %d\n", aux_c->peso);
        aux_c = aux_c->prox;
    }
}

int main()
{
    empilhar(3);
    empilhar(5);
    empilhar(7);
    imprimir();
}