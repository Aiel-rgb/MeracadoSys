#include <stdio.h>
#include <string.h>
#include "../headers/tipos.h"

Venda realizarVenda(Produto *p, int quantidade){
	Venda v;
	strcpy(v.nomeProduto, p->nome);
	v.quantidade = quantidade;
	v.total = p->preco * quantidade;
	v.comissao = v.total * 0.05;
	p->quantidade -= quantidade;
	return v;
}

void exibirVenda(Venda v){
	printf("\n--- VENDA ---\n");
	printf("Produto: %s\n", v.nomeProduto);
	printf("Qtd: %d\n", v.quantidade);
	printf("Total: R$ %.2f\n", v.total);
	printf("Comissão: R$ %.2f\n", v.comissao);
}

void relatorioVendas(Venda *vendas, int totalVendas){
	float totalGeral = 0, comissaoGeral = 0;
	printf("\n========= Relatorio de Vendas =========\n");
	for (int i=0;i<totalVendas; i++){
		exibirVenda(vendas[i]);
		totalGeral += vendas[i].total;
		comissaoGeral += vendas[i].comissao;
	}
	printf("\nTotal vendido R$ %.2f\n", totalGeral);
	printf("Total comissão: R$ %.2f\n", comissaoGeral);
	printf("=======================================\n");
}
