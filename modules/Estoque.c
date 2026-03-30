#include <stdio.h>
#include "../headers/tipos.h"

void adicionarEstoque(Produto *p, int quantidade){
    p->quantidade += quantidade;
    printf("Estoque atualizado: %d unidades\n", p->quantidade);
}

int removerEstoque(Produto *p, int quantidade){
    if (p->quantidade - quantidade < 0){
        printf("Estoque insuficiente! Disponivel: %d\n", p->quantidade);
        return 0;
    }
    p->quantidade -= quantidade;
    return 1;
}

void verificarEstoque(Produto *p){
    if (p->quantidade == 0)
        printf("[%s] SEM ESTOQUE!\n", p->nome);
    else if (p->quantidade < 10)
        printf("[%s] Estoque baixo: %d unidades\n", p->nome, p->quantidade);
    else
        printf("[%s] Estoque OK: %d unidades\n", p->nome, p->quantidade);
}
