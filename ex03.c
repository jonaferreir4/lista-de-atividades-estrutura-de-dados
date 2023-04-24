// 3) Uma empilhadeira carrega caixas de 7, 5, 3 toneladas. Há três pilhas A, B, C. A pilha A é onde se
// encontram todas as caixas que chegam no depósito. Com um detalhe: caixas maiores não podem ser
// empilhadas sobre caixas menores. Elabore um programa que efetue o controle das caixas, de forma
// que caso uma caixa de maior peso do que uma que já está em A deva ser empilhada, então, todas as
// caixas que estão em A são movidas para as pilhas auxiliares B (contendo somente caixa de 5
// toneladas) e C (contendo somente caixas de 3 toneladas) até que se possa empilhar a nova caixa.
// Depois, todas as caixas são movidas de volta para a pilha A.

#include <stdio.h>
#include <stdlib.h>

typedef struct caixa
{
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

void empilhar(int peso){
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
    else {
        // Enquanto existirem caixas em A com peso menor que a nova caixa
        while (topo_A != NULL && topo_A->peso < novaCaixa->peso) {
            // Verifica se a caixa do topo de A é maior que 5
            if (topo_A->peso == 5) {
                // Move todas as caixas de A para B, exceto a caixa do topo
                while (topo_A != NULL && topo_A->peso == 5) {
                }
            }
         
            // Empilha a nova caixa em A
            novaCaixa->prox = topo_A;
            topo_A->ant = novaCaixa;
            topo_A = novaCaixa;
            tam_a++;
        }
    }
}

void imprimir()
{
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
    empilhar(5);
    empilhar(3);
    imprimir();
}