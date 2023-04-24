 else if (novaCaixa->peso == 3) {
        for (CX *caixa = topo_A; caixa != NULL; caixa = caixa->prox) {
            if (caixa->peso == 5) {
                CX *caixaAnterior = caixa->ant;
                CX *caixaPosterior = caixa->prox;

                if (caixaAnterior != NULL) {
                    caixaAnterior->prox = caixaPosterior;
                }
                else {
                    topo_A = caixaPosterior;
                }

                if (caixaPosterior != NULL) {
                    caixaPosterior->ant = caixaAnterior;
                }

                caixa->ant = NULL;
                caixa->prox = NULL;

                if (topo_C == NULL) {
                    topo_C = caixa;
                }
                else {
                    CX *ultimaCaixa = topo_C;
                    while (ultimaCaixa->prox != NULL) {
                        ultimaCaixa = ultimaCaixa->prox;
                    }
                    ultimaCaixa->prox = caixa;
                    caixa->ant = ultimaCaixa;
                }

                tam_a--;
                tam_c++;
            }
        }