#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
   int valor;
   struct pilha* prox;
} Pilha;

typedef struct fila {
   Pilha* inicio;
   Pilha* fim;
} Fila;

Fila* criar_fila() {
   Fila* f = (Fila*) malloc(sizeof(Fila));
   f->inicio = NULL;
   f->fim = NULL;
   return f;
}

void enfileirar(Fila* f, int valor) {
   Pilha* nova_pilha = (Pilha*) malloc(sizeof(Pilha));
   nova_pilha->valor = valor;
   nova_pilha->prox = NULL;
   if (f->inicio == NULL) {
      f->inicio = nova_pilha;
      f->fim = nova_pilha;
   } else {
      f->fim->prox = nova_pilha;
      f->fim = nova_pilha;
   }
}

int desenfileirar(Fila* f) {
   if (f->inicio == NULL) {
      printf("A fila está vazia.\n");
      return -1;
   }
   int valor = f->inicio->valor;
   Pilha* pilha_removida = f->inicio;
   f->inicio = f->inicio->prox;
   if (f->inicio == NULL) {
      f->fim = NULL;
   }
   free(pilha_removida);
   return valor;
}

int main() {
   Fila* minha_fila = criar_fila();
   enfileirar(minha_fila, 10);
   enfileirar(minha_fila, 20);
   enfileirar(minha_fila, 30);

   printf("%d\n", desenfileirar(minha_fila));

   return 0;
}
