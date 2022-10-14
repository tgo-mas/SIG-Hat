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
	printf("    Escolha uma opção: ");
	scanf("%d", &opcao);
	switch(opcao){
		case 1:
			menuCliente();
			break;
		case 2:
			getchar();
			printf("\n    Menu Fornecedor: Trabalho em progresso!\n    Aperte enter para continuar...");
			getchar();
			painelControle();
	}
	return opcao;
}