// 3) Uma empilhadeira carrega caixas de 7, 5, 3 toneladas. Há três pilhas A, B, C. A pilha A é onde se
// encontram todas as caixas que chegam no depósito. Com um detalhe: caixas maiores não podem ser
// empilhadas sobre caixas menores. Elabore um programa que efetue o controle das caixas, de forma
// que caso uma caixa de maior peso do que uma que já está em A deva ser empilhada, então, todas as
// caixas que estão em A são movidas para as pilhas auxiliares B (contendo somente caixa de 5
// toneladas) e C (contendo somente caixas de 3 toneladas) até que se possa empilhar a nova caixa.
// Depois, todas as caixas são movidas de volta para a pilha A.

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int peso;
    struct no *prox;
} NO;

typedef struct Pilha {
    NO *inicio;
    NO *tam;
}PILHA;

void add(int peso, PILHA *p){

    NO *novo = malloc(sizeof(NO));
    novo->peso = peso;
    novo->prox = NULL;

    if(p->inicio == NULL){
        p->inicio = novo;
    } else {
        novo->prox = p->inicio;
        p->inicio = novo;
    }
    p->tam++;
}

int remover(PILHA *p){
    NO *lixo = p->inicio;
    int peso_retorado = -1;

    if(p->inicio != NULL){
        peso_retorado = p->inicio->peso;
        p->inicio = p->inicio->prox;
        free(lixo);
        p->tam--;
    }
    return peso_retorado;

}

PILHA *inicia(){
    PILHA *p = malloc(sizeof(PILHA));
    p->inicio = NULL;
    p->tam = 0;
}


void Select(int pesoNovo){

    PILHA *A = inicia();
    PILHA *B = inicia();
    PILHA *C = inicia();

    if(A->inicio->peso == NULL || pesoNovo <= A->inicio->peso  ){
        add(pesoNovo, A);
    }
    else {
        
        if(pesoNovo == 5){
            int auxValor = remover(A); // 3
            add(auxValor, C);
            add(pesoNovo, A);
        }
        else if( pesoNovo == 3){
             int auxValor = remover(A); // 3
            add(auxValor, B);
            add(pesoNovo, A);
        }
    }
    
    
}

int main (){

    Select(7);
    Select(3);
    Select(5);
}