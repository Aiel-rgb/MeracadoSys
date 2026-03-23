#ifndef PRODUTOS_H
#define PRODUTOS_H

#include "tipos.h"

// Cadastra N produtos no array (usando realloc)
void cadastrarProdutos(Produto **produtos, int *total, int quantosAdicionar);

// Busca pelo nome, retorna índice ou -1
int buscarProduto(Produto *produtos, int total, char *nome);

// Lista todos na tela
void listarProdutos(Produto *produtos, int total);

// Soma preco * quantidade de todos
float valorTotalEstoque(Produto *produtos, int total);

#endif
