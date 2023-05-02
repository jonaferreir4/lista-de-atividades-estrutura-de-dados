// 7) Como você implementaria uma fila de pilhas? Uma pilha de filas? Uma fila de filas? Escreva
// métodos para implementar as operações corretas para cada uma destas estruturas de dados.
#include <stdio.h>
#include <stdlib.h>


typedef struct no {
   int valor;
   struct no *prox;
   struct no
    *ant;
}NO;

typedef struct fila {
   NO * inicio;
   NO * fim;
   int tam;
   struct fila *prox;
}FILA;

typedef struct pilha {
   FILA *topo;
   int tam;
}PILHA;

void add_na_fila(int valor, FILA *f){
   NO *novo = malloc(sizeof(NO));
   novo->valor = valor;
   novo->prox = NULL;
   novo->ant = NULL;

   if(f->inicio == NULL){
      f->inicio = novo;
      f->fim = novo;
   }
   else {
     novo->prox = f->inicio;
     f->inicio->ant = novo;
     f->inicio = novo;
   }
   f->tam++;
}

void add_na_pilha(FILA *f, PILHA *p){
   if(p->topo == NULL){
      p->topo = f;
      p->tam++;
   }
   else {
      f->prox = p->topo;
      p->topo = f;
      p->tam++;
   }
}

int remover_Fila(FILA *f){
   if (f->tam > 0){
      NO *lixo = f->fim;
      int valor = f->fim->valor;
      f->fim = f->fim->ant;
      f->tam--;
      free(lixo);
      return valor;
   }
}

FILA * inicia(){
   FILA *aux = malloc(sizeof(FILA));
   aux->inicio = NULL;
   aux->fim = NULL;
   aux->prox = NULL;
   aux->tam = 0;
}

PILHA *iniciaP (){
   PILHA *aux = malloc(sizeof(PILHA));
   aux->topo == NULL;
   aux->tam = 0;
}

void imprimir_fila(FILA *f){
   NO *aux = f->inicio;
   for (int i = 0; i < f->tam; i++){
      printf("Valor: %d\n", aux->valor);
      aux = aux->prox;   
   }
}

void imprimir_pilha(PILHA *p){
   FILA *aux = p->topo;
   printf("--- PILHA ---\n");
   for (int i = 0; i < p->tam; i++){
      printf("Fila: %d\n", i);
      imprimir_fila(aux);
      aux = aux->prox;
   }
}

int main(){
   FILA *f1 = inicia();
   FILA *f2 = inicia();
   add_na_fila(10, f1);
   add_na_fila(20, f1);
   add_na_fila(30, f2);
   add_na_fila(40, f2);
   imprimir_fila(f1);
   imprimir_fila(f2);

   PILHA *p1 = iniciaP();
   PILHA *p2 = iniciaP();
   add_na_pilha(f1, p1);
   add_na_pilha(f2, p1);
   add_na_pilha(f1, p2);
   add_na_pilha(f2, p2);
   imprimir_pilha(p1);
   remover_Fila(f1);
   imprimir_pilha(p2);
}


