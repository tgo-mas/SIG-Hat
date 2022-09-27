#include "produtos.h"
#include "cliente.h"
#include "catalog.h"
#include "estoque.h"
#include "controle.h"
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
void menu(void);

//// Funções

int infos(void){
  printf("\n");
  printf("#####################################################\n");
  printf("##                                                 ##\n");
  printf("##        = = = = = S I G - H a t = = = = =        ##\n");
  printf("##                                                 ##\n");
  printf("##   Desenvolvido por: Thomas Almeida              ##\n");
  printf("##   E-mail: thomas.almeida.109@ufrn.br            ##\n");
  printf("##   Redes sociais: @tgomas.asf                    ##\n");
  printf("##   Git: https://github.com/tgo-mas/SIG-Hat.git   ##\n");
  printf("##                                                 ##\n");
  printf("##   Projeto da disciplina de Programacao          ##\n");
  printf("##   Docente: Flavius Gorgonio                     ##\n");
  printf("##   Universidade Federal do Rio Grande do Norte   ##\n");
  printf("##                                                 ##\n");
  printf("#####################################################\n");
  printf("\n");
  int opcao;
  printf("    Digite 0 e aperte enter para continuar... ");
  scanf("%d", &opcao);
  return opcao;
}

void menu(void){
	int opcao;
  printf("\n");
  printf("#####################################################\n");
  printf("##                                                 ##\n");
  printf("##        = = = = = S I G - H a t = = = = =        ##\n");
  printf("##                                                 ##\n");
  printf("##        1 - Catalogo de Bones e Chapeus          ##\n");
  printf("##            2 - Controle de Estoque              ##\n");
  printf("##            3 - Painel de Controle               ##\n");
  printf("##                                                 ##\n");
  printf("##                                                 ##\n");
  printf("##       9 - Informacoes sobre o programa          ##\n");
  printf("##                    0 - Sair                     ##\n");
  printf("##                                                 ##\n");
  printf("#####################################################\n");
  printf("\n");
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
    default:
      opcao = 0;
      printf("Escolha uma opção válida! Tente novamente. \n");
      break;
	}
  if(opcao == 0) menu();
}

int main(int argc, char *argv[]) {
  
	menu();
	
	return 0;
}

