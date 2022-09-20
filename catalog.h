#include <stdio.h>
#include <stdlib.h>
#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#else

#endif

//// Assinatura das funções
void initVenda(void);
int catalog(void);

//// Funções

void initVenda(void){
	char cpf[9];
	printf("\n    Informe o CPF do cliente: ");
	scanf("%s", &cpf);
	verifCliente(cpf);
	
}

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
