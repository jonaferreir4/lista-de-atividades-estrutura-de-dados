// 4) Implemente uma calculadora pós-fixada, contendo as operações básicas (+, -, *, /). Dica: notação
// pós-fixada é aquela que se digita primeiro os numero depois os operandos (1 2 - 4 5 + * = -9).
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct no
{
    float valor;
    struct no *prox;
} NO;

NO* empilhar(NO *pilha,float num){
    NO *novo = malloc(sizeof(NO));
    
    if (novo != NULL){
        novo->valor = num;
        novo->prox = pilha;
        return novo;
    }
    else{
        printf("ERRO");
    }
        return NULL;
}

NO * desempilhar(NO **pilha){
    NO *remover = NULL;

    if(*pilha){
        remover = *pilha;
        *pilha = remover->prox;
    } else {
        printf("A lista está vazia");
    }
        return remover;
}

float operacao(float a, float b, char x){
    switch (x){
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '/':
        return a / b;
        break;
    case '*':
        return a * b;
        break;
    default:
        return 0.0;
        break;
    }
}

float resolver_expressao(char x[]){
    char *pt;
    float num;
    NO *n1, *n2, * pilha = NULL;

    pt = strtok(x," ");
    while(pt){
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
            n1  = desempilhar(&pilha);
            n2 = desempilhar(&pilha);
            num = operacao(n2->valor, n1->valor, pt[0]);
            pilha = empilhar(pilha, num) ;
            free(n1);
            free(n2);
            
        } else {
            num = strtol(pt, NULL, 10);
            pilha = empilhar(pilha, num);
        }
            pt = strtok(NULL," ");
    }
    n1 = desempilhar(&pilha);
    num = n1->valor;
    free(n1);
    return num;
}

int main(){
    char exp[50] = ("51 13 12 * +");
    printf("resultado de %s\n", exp);
    printf("%f\n", resolver_expressao(exp));
}