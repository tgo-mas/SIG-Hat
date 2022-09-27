#include <stdio.h>
#include "estoque.h"
#include "catalog.h"
#include "produtos.h"

//// Variáveis referentes ao estoque
int idProds[10];
int qtds[10];

//// attEstoque() -> Atualiza as informações do estoque.

void attEstoque(void){
	*idProds = *getIds();
	*qtds = *getEstoq();
}

//// menuEstoque() -> Exibe a tela principal do módulo de estoque

int menuEstoque(void){
	clrScrn();
	attEstoque();
	printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##     = C O N T R O L E  D E  E S T O Q U E =     ##\n");
	printf("##                                                 ##\n");
	printf("##              1 - Conferir estoque               ##\n");
  	printf("##             2 - Cadastrar produto               ##\n");
  	printf("##             3 - Pesquisar produto               ##\n");
  	printf("##              4 - Excluir produto                ##\n");
	printf("##             5 - Registrar entradas              ##\n");
	printf("##                                                 ##\n");
	printf("##                   0 - Voltar                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
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
	      	catalog();
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
	int opcao;
	printf("\n    Digite 0 e aperte enter para voltar...");
	scanf("%d", &opcao);
	menuEstoque();
}

void entrada(void){
	
}

