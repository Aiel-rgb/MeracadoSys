#include <stdio.h>

/*Controle de estoque*/
typedef struct{
	int atual, quantidade;
} Estoque;

Estoque adicionarEstoque(Estoque e){
	e.atual = e.atual + e.quantidade;
	return e;
}
Estoque removerEstoque(Estoque e){
	if(e.atual - e.quantidade < 0){
		printf("Estoque esgotado já");
	}else{
		e.atual = e.atual - e.quantidade;
	}
	return e;
}
void verificarEstoque(Estoque e){
	if (e.atual > 10){
		printf("Estoque Ok!\n");
	}else{
		printf("Estoque abaixo de 10\n");
	}
}
