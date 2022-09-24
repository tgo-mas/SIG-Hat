#include <stdio.h>
#include "catalog.h"
#include "cliente.h"
#include "produtos.h"

//// Funções

//// initVenda() -> Dá início ao processo de realizar uma venda com o sistema.

void initVenda(void){
	char cpf, nome;
  char nomes[10][20] = {"Bruno", "Roberto"};
	printf("\n    Informe o CPF do cliente: ");
	scanf("%s", &cpf);
	if(verifCliente(&cpf) == 0){
		printf("\n    Novo cliente! \n    Nome: ");
		scanf("%s", &nome);
		addCliente(&cpf, &nome);
	} else {	
		int indexCliente = verifCliente(&cpf);
		printf("\n    Cliente encontrado! Nome: %s", nomes[indexCliente]);
	}
}

//// catalog() -> Exibe a tela principal do módulo de catálogo.

int catalog(void){
  int opcao;
  printf("\n");
  printf("#####################################################\n");
  printf("##                                                 ##\n");
  printf("##        = = = = = S I G - H a t = = = = =        ##\n");
  printf("##                                                 ##\n");
  printf("##       = = = = = C A T A L O G O = = = = =       ##\n");
  printf("##                                                 ##\n");
  printf("#####################################################\n");
  listProds();
  printf("##                                                 ##\n");
  printf("##                1 - Iniciar venda                ##\n");
  printf("##                                                 ##\n");
  printf("##                    0 - Sair                     ##\n");
  printf("##                                                 ##\n");
  printf("#####################################################\n");
  printf("\n");

  scanf("%d", &opcao);
  clrScrn();
  switch(opcao){
    case 1:
    	initVenda();
    case 0:
    	break;
    default:
      	printf("Escolha uma opção válida! Tente novamente. \n");
        catalog();
        break;
  }
  return opcao;
}
