#include <stdio.h>
#include <stdlib.h>

struct caixa {
    int peso;
    struct caixa *prox;
};

void empilhar(struct caixa **pilha, int peso) {
    struct caixa *nova_caixa = (struct caixa*) malloc(sizeof(struct caixa));
    nova_caixa->peso = peso;
    nova_caixa->prox = *pilha;
    *pilha = nova_caixa;
}

void desempilhar(struct caixa **pilha) {
    if (*pilha != NULL) {
        struct caixa *caixa_removida = *pilha;
        *pilha = (*pilha)->prox;
        free(caixa_removida);
    }
}

void transferir(struct caixa **origem, struct caixa **destino) {
    while (*origem != NULL) {
        empilhar(destino, (*origem)->peso);
        desempilhar(origem);
    }
}

int main() {
    int n, caixa, maior_caixa = 0;
    struct caixa *pilha_A = NULL, *pilha_B = NULL, *pilha_C = NULL;

    printf("Quantas caixas deseja empilhar? ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Informe o peso da caixa %d: ", i+1);
        scanf("%d", &caixa);

        if (caixa > maior_caixa) {
            // move todas as caixas de A para B e C
            transferir(&pilha_A, &pilha_B);
            transferir(&pilha_A, &pilha_C);

            // empilha a nova caixa em A
            printf("Empilhando caixa de %d toneladas na pilha A\n", caixa);
            empilhar(&pilha_A, caixa);

            // move todas as caixas de B e C para A
            transferir(&pilha_B, &pilha_A);
            transferir(&pilha_C, &pilha_A);

            maior_caixa = caixa;
        } else {
            printf("Empilhando caixa de %d toneladas na pilha A\n", caixa);
            empilhar(&pilha_A, caixa);
        }
    }

    // desempilha todas as caixas de A (apenas para visualização)
    printf("Pilha A: ");
    while (pilha_A != NULL) {
        printf("%d ", pilha_A->peso);
        desempilhar(&pilha_A);
    }
    printf("\n");

    return 0;
}
