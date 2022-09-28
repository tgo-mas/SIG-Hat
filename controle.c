#include <stdio.h>
#include "controle.h"
#include "produtos.h"
#include "cliente.h"

//// painelControle() -> Exibe o menu do módulo de Controle.
int painelControle(void){
	clrScrn();
	printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##     = P A I N E L   D E   C O N T R O L E =     ##\n");
	printf("##                                                 ##\n");
	printf("##       Aqui voce gerencia seus clientes e        ##\n");
	printf("##                   fornecedores.                 ##\n");
	printf("##                                                 ##\n");
	printf("##             1 - Gerenciar clientes              ##\n");
	printf("##           2 - Gerenciar fornecedores            ##\n");
	printf("##                                                 ##\n");
	printf("##                   0 - Voltar                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
	int opcao;
	printf("    Escolha uma opcao: ");
	scanf("%d", &opcao);
	switch(opcao){
		case 1:
			menuCliente();
			break;
		case 2:
			printf("\n    Menu Fornecedor: Trabalho em progresso!\n    Digite 0 e aperte enter para continuar...");
			scanf("%d", &opcao);
			painelControle();
	}
	return opcao;
}