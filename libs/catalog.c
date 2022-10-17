#include <stdio.h>
#include "catalog.h"
#include "cliente.h"
#include "produtos.h"
#include "estoque.h"
#include "interface.h"

//// Funções

//// initVenda() -> Dá início ao processo de realizar uma venda com o sistema.

void initVenda(void){
	char cpf[12];
	printf("    Informe o CPF do cliente: ");
	scanf("%s", cpf);
	if(verifCliente(cpf) == 0){
		printf("\n    Novo cliente!");
    cadCliente(cpf);
	} else {	
		int indexCliente = verifCliente(cpf) - 1;
		printf("    Cliente encontrado! Nome: %s \n", getNomeAt(indexCliente));
	}
  int qtd, idsVenda[10], unids, unidsEstoque;
  printf("\n    Informe a quantidade de itens a serem comprados (max. 10 itens diferentes): ");
  scanf("%d", &qtd);
  for(int i = 0; i < qtd; i++){
    printf("    Informe o %d Id: ", i + 1);
    scanf("%d", &idsVenda[i]);
    unidsEstoque = verifEstoque(idsVenda[i]);
    char* marca, * modelo;
    marca = getMarca(idsVenda[i]);
    modelo = getModelo(idsVenda[i]);
    printf("    Quantas unidades do %s %s serao vendidas? ", modelo, marca);
    scanf("%d", &unids);
    if(unidsEstoque >= unids){
      setEstoq(idsVenda[i], unidsEstoque - unids);
      printf("\n     Venda realizada com sucesso!");
    }else{
      printf("\n     Falta de item em estoque!");
    }
  }
  getchar();
  printf("\n    Aperte enter para continuar...");
  getchar();
  catalog();
}

//// catalog() -> Exibe a tela principal do módulo de catálogo.

int catalog(void){
  int opcao;
  menuCatalogo();

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
