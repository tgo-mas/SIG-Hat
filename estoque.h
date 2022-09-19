#include <stdio.h>

//// Variáveis referentes ao estoque
int idProds[10];
int qtds[10];

//// Assinatura das funções
int menuEstoque(void);
void exibEstoque(void);
void entrada(void);

int menuEstoque(void){
	clrScrn();
	printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##     = C O N T R O L E  D E  E S T O Q U E =     ##\n");
	printf("##                                                 ##\n");
	printf("##              1 - Conferir estoque               ##\n");
	printf("##             2 - Registrar entradas              ##\n");
	printf("##                                                 ##\n");
	printf("##                   0 - Voltar                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
	int opcao;
	
	printf("    Selecione uma opcao: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 1:
			exibEstoque();
			break;
		case 2:
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

void exibEstoque(void){
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

