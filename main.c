#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "catalog.h"

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

void infos(void){
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
      if(opcao == 0){
        menu();
      }
      break;
		case 9:
			infos();
			break;
    case 0:
      return;
    default:
      printf("Escolha uma opção válida! Tente novamente. \n");
      menu();
      break;
	}
}

int main(int argc, char *argv[]) {
  
	menu();
	
	return 0;
}

