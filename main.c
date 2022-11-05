#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./libs/misc.h"
#include "./libs/produtos.h"
#include "./libs/cliente.h"
#include "./libs/catalog.h"
#include "./libs/estoque.h"
#include "./libs/controle.h"
#include "./libs/interface.h"
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
  getchar();
  printf("    Aperte enter para continuar... ");
  getchar();
  return 0;
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

