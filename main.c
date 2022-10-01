#include "produtos.h"
#include "cliente.h"
#include "catalog.h"
#include "estoque.h"
#include "controle.h"
#include "interface.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#else

#endif

//////////////////
///
///  SIG-Hat
///
///  Desenvolvido por: Thomas Almeida
///  Projeto da disciplina de Programação
///  Docente: Flavius Gorgônio
///  Universidade Federal do Rio Grande do Norte
///
//////////////////

//// Assinatura das funções
int infos(void);
int menu(void);

//// Funções

int infos(void){
  infosProjeto();
  int opcao;
  printf("    Digite 0 e aperte enter para continuar... ");
  scanf("%d", &opcao);
  return opcao;
}

int menu(void){
  int opcao;
  menuPrincipal();
  printf("Escolha uma opcao: ");
  scanf("%d", &opcao);

  clrScrn();  
  switch(opcao){
    case 1:	
      opcao = catalog();
      if(opcao == 0) menu();
      break;
    case 2:
      opcao = menuEstoque();
      if(opcao == 0) menu();
      break;
    case 3:
      opcao = painelControle();
      if(opcao == 0) menu();
      break;
    case 9:
      opcao = infos();
      if(opcao == 0) menu();
      break;
    case 0:
      return 1;
    default:
      opcao = 0;
      printf("Escolha uma opção válida! Tente novamente. \n");
      break;
	}
  return 0;
}

int main(int argc, char *argv[]) {
  int opcao = menu();
  while(opcao == 0){
    opcao = menu();
  }
	
	return 0;
}

