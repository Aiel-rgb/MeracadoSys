#ifndef ESTOQUE_H
#define ESTOQUE_H

#include "tipos.h"

void adicionarEstoque(Produto *p, int quantidade);
int removerEstoque(Produto *p, int quantidade);
void verificarEstoque(Produto *p);

#endif
