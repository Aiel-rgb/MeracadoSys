#ifndef VENDAS_H
#define VENDAS_H

#include "tipos.h"

Venda realizarVenda(Produto *p, int quantidade);
void exibirVenda(Venda v);
void relatorioVendas(Venda *vendas, int totalVendas);

#endif
