#ifndef TIPOS_H
#define TIPOS_H

typedef struct{
	char nome[100];
    float preco;
    int quantidade;
} Produto;

typedef struct {
    char nomeProduto[100];
    int quantidade;
    float total;
    float comissao;
} Venda;

#endif
