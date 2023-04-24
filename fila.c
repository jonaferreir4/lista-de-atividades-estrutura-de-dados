#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no * prox;
}NO;

NO * inicio = NULL;
NO * fim = NULL;
int tam = 0;


void add(int valor){
    
        NO * novo = malloc(sizeof(NO));
        novo->valor = valor;
        novo->prox = NULL;

        if(inicio == NULL){//fila esta vazia
            inicio = novo;
            fim = novo;
         
        }else {  //fim
                fim->prox = novo;
                fim = novo;
        }
        tam++;
    
}

void imprimir(){
    
     NO * aux = inicio;
                   
    for(int i = 0; i<tam; i++){
        printf("valor: %d\n", aux->valor);
        aux = aux->prox;
    }
    
    
}

int remover(){
   
        if(tam > 0){ //inicio
            
            NO *lixo = inicio;
            int valor = inicio->valor;
            inicio = inicio->prox;
            free(lixo);
            tam--;
            return valor;
        }else{
            printf("Pilha vazia! \n :(");
            return -1;
        }
    
    return 0;
}

int main(){
    add(18);
    add(19);
    add(17);
    add(28);
    add(39);
    add(45);
    imprimir();
    return 0;
}


