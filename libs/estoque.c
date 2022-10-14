#include <stdio.h>
#include "estoque.h"
#include "catalog.h"
#include "produtos.h"
#include "interface.h"

//// Variáveis referentes ao estoque
int idProds[10];
int qtds[10];

//// attEstoque() -> Atualiza as informações do estoque.

void attEstoque(void){
	int *ids, *qtd;
	ids = getIds();
	qtd = getEstoq();
	for(int i = 0; i < 10; i++){
		idProds[i] = ids[i];
		qtds[i] = qtd[i];
	}
}

//// menuEstoque() -> Exibe a tela principal do módulo de estoque

int menuEstoque(void){
	clrScrn();
	attEstoque();
	telaMenuEstoque();
	int opcao;
	
	printf("    Selecione uma opcao: ");
	scanf("%d", &opcao);

	int* ids;
	ids = getIds();
	
	switch(opcao){
		case 1:
			exibEstoque(ids);
			break;
		case 2:
      		cadastrarProd();
      		break;
	    case 3:
	      	findProd();
	      	break;
	    case 4:
	      	deleteProd();
	      	break;
		case 5:
			entrada();
			break;	
	    case 0:
	    	break;
	    default:
	      	printf("Escolha uma opção válida! Tente novamente. \n");
			menuEstoque();
	      	break;
	}
	
	return opcao;
}

//// exibEstoque() -> Lista os produtos mostrando as informações de estoque

void exibEstoque(int ids[10]){
	clrScrn();
	printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##     = C O N T R O L E  D E  E S T O Q U E =     ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	for(int i = 0; i < 10; i++){
		if(ids[i] != 0){
			exibProd(i);
		}
	}
	getchar();
	printf("\n    Aperte enter para voltar...");
	getchar();
	menuEstoque();

}

//// verifEstoque() -> Verifica a disponibilidade do item em estoque, retornando a quantidade do mesmo

int verifEstoque(int id){
	attEstoque();
	for(int i = 0; i < 10; i++){
		if(idProds[i] == id){
			return qtds[i];
		}
	}
	return -1; // Id não encontrado.
}

//// entrada() -> Inicia o protocolo para registrar a entrada de algum produto no estoque.

void entrada(void){
	int id, qtd;
	char *modeloProduto, *marcaProduto;
	printf("\n    Informe o ID do item a ser reabastecido: ");
	scanf("%d", &id);
	marcaProduto = getMarca(id);
	modeloProduto = getModelo(id);
	qtd = verifEstoque(id);
	if(qtd == -1){
		printf("\n    O ID informado nao corresponde a nenhum produto.");
	} else {
		printf("\n    Informe quantas unidades de %s %s foram reabastecidas: ", modeloProduto, marcaProduto);
		scanf("%d", &qtd);
		qtd += verifEstoque(id);
		setEstoq(id, qtd);
		printf("    Estoque renovado com sucesso!");
	}
	printf("\n    Pressione enter para continuar... ");
	getchar();
	menuEstoque();
}

