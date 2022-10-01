#include <stdio.h>
#include "controle.h"
#include "produtos.h"
#include "cliente.h"
#include "interface.h"

//// painelControle() -> Exibe o menu do módulo de Controle.
int painelControle(void){
	clrScrn();
	menuControle();
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