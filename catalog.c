#include <stdio.h>
#include "catalog.h"
#include "cliente.h"
#include "produtos.h"

//// Funções

//// initVenda() -> Dá início ao processo de realizar uma venda com o sistema.

void initVenda(void){
	char cpf, nome;
  char nomes[10][20] = {"Bruno", "Roberto"};
	printf("    Informe o CPF do cliente: ");
	scanf("%s", &cpf);
	if(verifCliente(&cpf) == 0){
		printf("\n    Novo cliente! \n    Nome: ");
		scanf("%s", &nome);
		addCliente(&cpf, &nome);
	} else {	
		int indexCliente = verifCliente(&cpf) - 1;
		printf("    Cliente encontrado! Nome: %s \n", nomes[indexCliente]);
	}
  int qtd, idsVenda[10];
  printf("\n    Informe a quantidade de itens a serem comprados (max. 10 itens diferentes): ");
  scanf("%d", &qtd);
  for(int i = 0; i < qtd; i++){
    printf("    Informe o %d Id: ", i + 1);
    scanf("%d", &idsVenda[i]);
    printf("    Quantas unidades do %s %s serao vendidas? ");
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
