// 7) Como você implementaria uma fila de pilhas? Uma pilha de filas? Uma fila de filas? Escreva
// métodos para implementar as operações corretas para cada uma destas estruturas de dados.
#include <stdio.h>
#include <stdlib.h>

typedef struct fila {
    int valor;
    struct fila *prox;
}FILA;


typedef struct pilha {
    FILA *topo;
}PILHA;

PILHA * criar_pilhas(){
PILHA* p = malloc(sizeof(PILHA));
p->topo = NULL;
   return p;
}

void empilhar(PILHA* p,int valor) {
   FILA* nova_fila =  malloc(sizeof(FILA));
   nova_fila->valor = valor;
   nova_fila->prox = p->topo;
   p->topo = nova_fila;
}

int desempilhar(PILHA* p) {
   if (p->topo == NULL) {
      printf("A pilha esta vazia.\n");
      return -1;
   }
   int valor = p->topo->valor;
   FILA* fila_removida = p->topo;
   p->topo = p->topo->prox;
   free(fila_removida);
   return valor;
}


int main(){

     PILHA* minha_pilha = criar_pilhas();
   empilhar(minha_pilha, 10);
   empilhar(minha_pilha, 20);
   empilhar(minha_pilha, 30);

   printf("%d\n", minha_pilha->topo->valor);
   printf("%d\n", minha_pilha->topo->prox->valor);
   printf("%d\n", minha_pilha->topo->prox->prox->valor);


   return 0;
}
