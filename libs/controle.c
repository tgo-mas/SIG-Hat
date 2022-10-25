#include <stdio.h>
#include "controle.h"
#include "produtos.h"
#include "cliente.h"
#include "interface.h"
#include "fornecedor.h"

//// painelControle() -> Exibe o menu do módulo de Controle.
int painelControle(void){
	clrScrn();
	menuControle();
	int opcao;
	printf("    Escolha uma opção: ");
	scanf("%d", &opcao);
	switch(opcao){
		case 1:
			menuCliente();
			break;
		case 2:
			menuFornec();
		case 0:
			break;
		default:
            getchar();
            printf("\n    Selecione uma opção válida!");
            getchar();
			break;
	}
	return opcao;
}