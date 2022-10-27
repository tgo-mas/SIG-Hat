#include <stdio.h>
#include <string.h>
#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#else

#endif
#include <stdio.h>
#include <stdlib.h>
#include "misc.h"
#include "produtos.h"
#include "interface.h"

//// Dados dos produtos
int ids[10] = {1, 2, 3};
int estoq[10] = {4, 5, 0};
char modelos[10][15] = {"bne", "chapeu", "viseira"};
char marcas[10][15] = {"Nike", "artesanal", "adidas"};
float precos[10] = {40.00, 15.0, 120.0};

//// Funções

//// listProds() -> Lista todos os produtos, chamando exibProd para cada
void listProds(void){
	int index;
	index = getIndex(ids);
	int i;
	for(i = 0; i < index; i++){
		exibProd(i);
	}
}

//// exibProd(indice) -> Exibe as infos do produto no indice indicado
void exibProd(int index){
	printf("\n    ID: %d", ids[index]);
	printf("\n    Modelo: %s", modelos[index]);
	printf("\n    Marca: %s", marcas[index]);
	printf("\n    Preco: %f", precos[index]);
	printf("\n    Em estoque: %d\n\n", estoq[index]);
	printf("#####################################################\n");
}

//// exibirID(id) -> Mesmo que exibProd() mas usa o id do produto em vez do indice
void exibirID(int id){
	int index, i;
	index = getIndex(ids);
	for(i = 0; i < index; i++){
		if(ids[i] == id){
			exibProd(i);
		}
	}
}

//// cadastrarProd() -> Cadastra as infos do produto nas listas
void cadastrarProd(void){
	int index;
	index = getIndex(ids);
	printf("%d", index);
	
	telaAddProduto();
	
	char modelo[15], marca[15];

	printf("	ID: ");
  	scanf("%d", &ids[index]);
  	printf("	Modelo: ");
  	scanf("%s", modelo);
  	printf("	Marca: ");
  	scanf("%s", marca);
	strcpy(modelos[index],modelo);
	strcpy(marcas[index],marca);
  	printf("	Preco: ");
  	scanf("%f", &precos[index]);
	printf("\n    Qtd em estoque: ");
  	scanf("%d", &estoq[index]);
  	
  	menuEstoque();
}

//// findProd() -> Abre o menu de busca de produto
void findProd(void){
  	int opcao;
	
	telaBuscaProduto();

	printf("	1 - Busca por ID");
	printf("	2 - Busca por modelo");
	
	printf("\n    Selecione o tipo de busca: ");
	scanf("%d", &opcao);
	
	int id;
	char modelo[15];

	switch(opcao){
		case 1:
			printf("    Digite o ID do produto: ");
			scanf("%d", &id);
			exibirID(id);
			break;
		case 2:
			printf("   Informe o modelo do produto: ");
			scanf("%s", modelo);
			buscaModelo(modelo);
			break;
		default:
			printf("\n    Selecione uma opção válida!\n    Aperte enter para continuar...");
			scanf("%d", &id);
			break;
	}
	getchar();
	printf("\n    Aperte enter para continuar...");
	getchar();
	menuEstoque();
}

//// buscaModelo(modelo) -> Busca o produto pelo modelo dele
void buscaModelo(char modelo[15]){
	int index, i;
	index = getIndex(ids);
	for(i = 0; i < index; i++){
		if(strcmp(modelos[i], modelo) == 0){
			exibProd(i);
		}
	}
}

//// deleteProd() -> Abre o menu para remover produto, chama remove()
void deleteProd(void){
	
	int id;
  	telaRemovProduto();

	printf("	Remocao por ID: ");
	scanf("%d", &id);
	
	remover(id);
	
	menuEstoque();
}

//// remove(id) ->  Remove o produto com o id indicado
void remover(int id){
	int index, i;
	index = getIndex(ids);
	
	for(i = 0; i < index; i++){
		if(ids[i] == id){
			ids[i] = 0;
			strcpy(modelos[i], "");
			strcpy(marcas[i], "");
			precos[i] = 0.0;
		}
	}
}

//// getIndexById(id) -> Retorna o indice do item de Id correspondente na lista de produtos.
int getIndexById(int id){
	for(int i = 0; i < 10; i++){
		if(ids[i] == id){
			return i;
		}
	}
	return -1;
}

//// getIds() -> Retorna ponteiro para a lista de Ids dos produtos.
int* getIds(void){
	return ids;
}

//// getMarca(id) -> Retorna a marca do item de Id informado
char* getMarca(int id){
	int index = getIndexById(id);
	return marcas[index];
}

//// getModelo(id) -> Retorna o modelo do item de Id informado
char* getModelo(int id){
	int index = getIndexById(id);
	return modelos[index];
}

//// getEstoq() -> Retorna o vetor de quantidades dos itens em estoque.
int* getEstoq(){
	return estoq;
}

//// setEstoq(id, qtd) -> Atualiza a informação de estoque do produto informado.

void setEstoq(int id, int qtd){
	for(int i = 0; i < 10; i++){
		if(ids[i] == id){
			estoq[i] = qtd;
		}
	}
}

