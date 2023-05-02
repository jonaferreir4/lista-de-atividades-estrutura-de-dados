// Fila de Pilhas

#include <stdio.h>
#include <stdlib.h>

typedef struct no {
   int valor;
   struct no *prox;
}NO;

typedef struct pilha {
   NO * topo;
   int tam;
   struct pilha *prox;
}PILHA;

typedef struct fila {
   PILHA *inicio;
   PILHA *fim;
   int tam;
}FILA;

void add_na_pilha(int valor, PILHA *p){
   NO *novo = malloc(sizeof(NO));
   novo->valor = valor;
   novo->prox = NULL;

   if(p->topo == NULL){
      p->topo = novo;
   }
   else {
      novo->prox = p->topo;
      p->topo = novo;
   }
   p->tam++;
}

void add_na_fila(PILHA *p, FILA *f){
   if(f->inicio == NULL){
      f->inicio = p;
      f->fim = p;
      f->tam++;
   }
   else {
      f->fim->prox = p;
      f->fim = p;
      p->prox = NULL;
      f->tam++;
   }
}

int remover_pilha(PILHA *p){
   if(p->tam > 0){
      NO * lixo = p->topo;
      int valor = p->topo->valor;
      p->topo = p->topo->prox;
      p->tam--;
      free(lixo);
      return valor;
   }
   else {
      printf("Pilha Vazia.\n");
      return -1;
   }
   return 0;
} 

PILHA * inicia(){
   PILHA *aux = malloc(sizeof(PILHA));
   aux->prox = NULL;
   aux->tam = 0;
   return aux;
}

FILA *iniciaF(){
   FILA *aux = malloc(sizeof(FILA));
   aux->inicio = NULL;
   aux->fim = NULL;
   aux->tam = 0;
   return aux;
}

void imprimir_pilha(PILHA *p){
   NO *aux = p->topo;
   for (int i = 0; i < p->tam; i++){
      printf("Valor: %d\n", aux->valor);
      aux = aux->prox;   
   }
}

void imprimir_fila(FILA *f){
   PILHA * aux = f->inicio;
   printf("-------FILA------\n");
   for (int i = 0; i < aux->tam; i++){
      printf("Pilha: %d\n", i);
      imprimir_pilha(aux);
      aux = aux->prox;
   }
}

int main (){

   PILHA *p1 = inicia();   
   add_na_pilha(10, p1);
   add_na_pilha(20, p1);

   PILHA *p2 = inicia();
   add_na_pilha(30, p2);
   add_na_pilha(40, p2);

   FILA *f1 = iniciaF();
   add_na_fila(p1, f1);
   add_na_fila(p2, f1);

   imprimir_pilha(p1);
   imprimir_pilha(p2);
   imprimir_fila(f1);
   
}