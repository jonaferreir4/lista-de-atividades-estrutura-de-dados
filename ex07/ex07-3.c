// Fila de Filas
#include <stdio.h>
#include <stdlib.h>


typedef struct no {
   int valor;
   struct no *prox;
   struct no*ant;
}NO;

typedef struct fila {
   NO * inicio;
   NO * fim;
   int tam;
   struct fila *prox;
}FILA;

typedef struct FilaDasFilas {
   FILA *inicioFilas;
   FILA *fimFilas;
   int tam;
}FDF;


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

void add_fila_filas(FILA *f, FDF *fdf){
   if(fdf->inicioFilas == NULL){
      fdf->inicioFilas = f;
      fdf->fimFilas = f;
      fdf->tam++;
   }
   else {
      fdf->fimFilas->prox = f;
      fdf->fimFilas = f;
      f->prox = NULL;
      fdf->tam++;
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

FILA *inicia(){
   FILA *aux = malloc(sizeof(FILA));
   aux->inicio = NULL;
   aux->fim = NULL;
   aux->prox = NULL;
   aux->tam = 0;
}

FDF * iniciaFDF(){
   FDF *aux = malloc(sizeof(FDF));
   aux->inicioFilas = NULL;
   aux->fimFilas = NULL;
   aux->tam = 0;
}

void imprimir_fila(FILA *f){
   NO *aux = f->inicio;
   for (int i = 0; i < f->tam; i++){
      printf("Valor: %d\n", aux->valor);
      aux = aux->prox;
   }
}

void imprimir_fila_de_filas(FDF *fdf){
   FILA *aux = fdf->inicioFilas;
   printf("---- Fila de Filas ----\n");
   for( int i = 0; i < fdf->tam; i++){
      printf("Fila de Filas %d:\n", i);
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

   FDF * fdf1 = iniciaFDF();
   add_fila_filas(f1, fdf1);
   add_fila_filas(f2, fdf1);
   remover_Fila(f2);
   imprimir_fila_de_filas(fdf1);
}