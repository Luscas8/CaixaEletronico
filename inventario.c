#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUTOS 100

typedef struct {
    int id;
    char nome[50];
    float preco;
    int quantidade;
} Produto;

Produto estoque[MAX_PRODUTOS];
int totalProdutos = 0;

void cadastrarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Estoque cheio! Não é possível cadastrar mais produtos.\n");
        return;
    }

    Produto novoProduto;
    novoProduto.id = totalProdutos + 1; 
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]", novoProduto.nome);
    printf("Digite o preço do produto: ");
    scanf("%f", &novoProduto.preco);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novoProduto.quantidade);

    estoque[totalProdutos] = novoProduto;
    totalProdutos++;
    printf("Produto cadastrado com sucesso!\n");

    while (getchar() != '\n');
}

void salvarEstoqueCSV() {
    FILE *file = fopen("C:\Users\202402533843\Desktop\loja, "w"); 
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fprintf(file, "ID,Nome,Preço,Quantidade\n");
    for (int i = 0; i < totalProdutos; i++) {
        Produto p = estoque[i];
        fprintf(file, "%d,%s,%.2f,%d\n", p.id, p.nome, p.preco, p.quantidade);
    }

    fclose(file);
    printf("Estoque salvo em estoque.csv
	 com sucesso!\n");
}

void exibirProdutos() {
    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("Produtos cadastrados:\n");
    for (int i = 0; i < totalProdutos; i++) {
        Produto p = estoque[i];
        printf("ID: %d\nNome: %s\nPreço: %.2f\nQuantidade: %d\n", p.id, p.nome, p.preco, p.quantidade);
    }
}

void consultarProduto() {
    int id;
    printf("Digite o ID do produto: ");
    scanf("%d", &id);

    if (id < 1 || id > totalProdutos) {
        printf("Produto não encontrado.\n");
        return;
    }

    Produto p = estoque[id - 1];
    printf("ID: %d\nNome: %s\nPreço: %.2f\nQuantidade: %d\n", p.id, p.nome, p.preco, p.quantidade);
}

int main() {
    int opcao;

    do {
        printf("\nSistema de Controle de Inventário\n");
        printf("1. Cadastrar novo produto\n");
        printf("2. Consultar produto\n");
        printf("3. Exibir todos os produtos\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada inválida! Por favor, insira um número.\n");
            while (getchar() != '\n');
            opcao = 0;
        }

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 2:
                consultarProduto();
                break;
            case 3:
                exibirProdutos();
                break;
            case 4:
                salvarEstoqueCSV();
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

