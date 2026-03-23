#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/produtos.h"

void cadastrarProdutos(Produto **produtos, int *total, int quantosAdicionar){
	Produto *temp = realloc(*produtos ,(*total + quantosAdicionar) * sizeof(Produto));
	
	if (temp == NULL){
		printf("Erro ao alocar memória");
		free(*produtos);
		return;
	}
	
	*produtos = temp;
	
	for (int i = *total; i < *total + quantosAdicionar; i++){
		printf("\n--- Produto %d ---\n", i+1);
		
		printf("Nome: ");
		scanf("%s", (*produtos)[i].nome);
		
		printf("Preço: ");
		scanf("%f", &(*produtos)[i].preco);
		
		printf("Quantidade");
		scanf("%d", &(*produtos)[i].quantidade);
	}
	*total += quantosAdicionar;
}

int buscarProduto(Produto *produtos, int total, char *nome){
	for (int i = 0; i < total; i++){
		if(strcmp(produtos[i].nome, nome)==0)
			return i;
		}
		return -1;
	}

void listarProdutos(Produto *produtos, int total){
	if (total == 0){
		printf("Nenhum produto cadastrado \n");
		return;
	}
	
	printf("\n%-20s %-10s %-10s\n", "NOME", "PRECO", "ESTOQUE");
    printf("------------------------------------------\n");

	for (int i =0; i<total;i++){
		printf("%-20s R$%-9.2f %-10d\n",
			produtos[i].nome,
			produtos[i].preco,
			produtos[i].quantidade);
		}
	}
	float valorTotalEstoque(Produto *produtos, int total) {
		float soma = 0;
		for (int i = 0;i<total; i++){
			soma += produtos[i].preco * produtos[i].quantidade;
		}
		return soma;
	}
