#include <stdio.h>
#include <stdlib.h>
#include "headers/produtos.h"

int main(){
	int total = 0;
	
	Produto *produtos = malloc(sizeof(Produto));
	if (produtos == NULL){
		printf("Error em alocar a memória!\n");
		return 1;
	}
	int quantos;
	printf("Quantos produtos deseja cadastrar?");
	scanf("%d", &quantos);
	
	cadastrarProdutos(&produtos, &total, quantos);
	listarProdutos(produtos, total);
	printf("\nValor total em estoque: R$ %.2f\n", valorTotalEstoque(produtos, total));
	
	free(produtos);
	produtos = NULL;
	 return 0;
}

