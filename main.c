#include <stdio.h>
#include <stdlib.h>
#include "headers/produtos.h"
#include "headers/vendas.h"
#include "headers/estoque.h"

// Cores
#define VERDE   "\033[1;32m"
#define VERMELHO "\033[1;31m"
#define CIANO   "\033[1;36m"
#define RESET   "\033[m"

void limparTela(){
    system("clear");
}

void menuPrincipal(){
    printf(CIANO "========================================\n" RESET);
    printf(CIANO "         SISTEMA DE MERCADO             \n" RESET);
    printf(CIANO "========================================\n" RESET);
    printf(VERDE "[1]" RESET " Cadastrar produtos\n");
    printf(VERDE "[2]" RESET " Listar produtos\n");
    printf(VERDE "[3]" RESET " Realizar venda\n");
    printf(VERDE "[4]" RESET " Ver estoque de um produto\n");
    printf(VERDE "[5]" RESET " Adicionar estoque\n");
    printf(VERDE "[6]" RESET " Relatorio de vendas\n");
    printf(VERMELHO "[0]" RESET " Sair\n");
    printf(CIANO "========================================\n" RESET);
    printf("Escolha uma opcao: ");
}

int main(){
    int total = 0;
    int totalVendas = 0;

    Produto *produtos = malloc(sizeof(Produto));
    Venda *vendas = malloc(sizeof(Venda));

    if (produtos == NULL || vendas == NULL){
        printf("Erro ao alocar memoria!\n");
        return 1;
    }

    int opcao;

    do {
        limparTela();
        menuPrincipal();

        if (scanf("%d", &opcao) != 1){
            opcao = -1;
        }

        limparTela();

        if (opcao == 1){
            int quantos;
            printf("Quantos produtos deseja cadastrar? ");
            scanf("%d", &quantos);
            cadastrarProdutos(&produtos, &total, quantos);

        } else if (opcao == 2){
            listarProdutos(produtos, total);
            printf("\nValor total em estoque: R$ %.2f\n", valorTotalEstoque(produtos, total));

        } else if (opcao == 3){
            if (total == 0){
                printf(VERMELHO "Nenhum produto cadastrado!\n" RESET);
            } else {
                listarProdutos(produtos, total);
                char nome[100];
                printf("\nNome do produto: ");
                scanf("%s", nome);
                int idx = buscarProduto(produtos, total, nome);
                if (idx == -1){
                    printf(VERMELHO "Produto nao encontrado!\n" RESET);
                } else {
                    int qtd;
                    printf("Quantidade: ");
                    scanf("%d", &qtd);
                    if (removerEstoque(&produtos[idx], qtd)){
                        Venda *temp = realloc(vendas, (totalVendas + 1) * sizeof(Venda));
                        if (temp != NULL){
                            vendas = temp;
                            vendas[totalVendas] = realizarVenda(&produtos[idx], qtd);
                            // desfaz o desconto duplo
                            produtos[idx].quantidade += qtd;
                            exibirVenda(vendas[totalVendas]);
                            totalVendas++;
                        }
                    }
                }
            }

        } else if (opcao == 4){
            char nome[100];
            printf("Nome do produto: ");
            scanf("%s", nome);
            int idx = buscarProduto(produtos, total, nome);
            if (idx == -1)
                printf(VERMELHO "Produto nao encontrado!\n" RESET);
            else
                verificarEstoque(&produtos[idx]);

        } else if (opcao == 5){
            char nome[100];
            printf("Nome do produto: ");
            scanf("%s", nome);
            int idx = buscarProduto(produtos, total, nome);
            if (idx == -1){
                printf(VERMELHO "Produto nao encontrado!\n" RESET);
            } else {
                int qtd;
                printf("Quantas unidades adicionar? ");
                scanf("%d", &qtd);
                adicionarEstoque(&produtos[idx], qtd);
            }

        } else if (opcao == 6){
            relatorioVendas(vendas, totalVendas);

        } else if (opcao != 0){
            printf(VERMELHO "Opcao invalida!\n" RESET);
        }

        if (opcao != 0){
            printf("\nPressione ENTER para continuar...");
            getchar();
            getchar();
        }

    } while (opcao != 0);

    printf(CIANO "Saindo... Ate logo!\n" RESET);
    free(produtos);
    free(vendas);
    produtos = NULL;
    vendas = NULL;
    return 0;
}
