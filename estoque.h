#include <stdio.h>

int idProds[10];
int qtds[10];

int menuEstoque(void);

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
	
	return opcao;
}



