#include <stdio.h>
#include <stdlib.h>
#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#else

#endif

int catalog(void);

void clrScrn(void){
	#ifdef __linux__
		system("clear");	
	#elif _WIN32
		system("cls");
	#else
	
	#endif	
}

void listProd(void){
  
}

void cadastrarProd(void){
	int id;
	char modelo, marca, cor[5], tamanho[4];
	float preco;
	
	printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##    = C A D A S T R O   D E   P R O D U T O =    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");

	printf("	ID: ");
  	scanf("%d", &id);
  	printf("	Modelo: ");
  	scanf("%d", &modelo);
  	printf("	Marca: ");
  	scanf("%d", &marca);
  	printf("	Preco: ");
  	scanf("%d", &preco);
  	
  	catalog();
}

void findProd(void){
  	int opcao;
	
	printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##      = B U S C A   P O R   P R O D U T O =      ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");

	printf("	1 - Busca por ID");
	printf("	2 - Busca por modelo");
	
	printf("\n    Selecione o tipo de busca: ");
	scanf("%d", opcao);
	
	catalog();
}

void deleteProd(void){
  
}

int catalog(void){
  int opcao;
  clrScrn();
  printf("\n");
  printf("#####################################################\n");
  printf("##                                                 ##\n");
  printf("##        = = = = = S I G - H a t = = = = =        ##\n");
  printf("##                                                 ##\n");
  printf("##       = = = = = C A T A L O G O = = = = =       ##\n");
  printf("##                                                 ##\n");
  printf("##              1 - Listar produtos                ##\n");
  printf("##             2 - Cadastrar produto               ##\n");
  printf("##             3 - Pesquisar produto               ##\n");
  printf("##              4 - Excluir produto                ##\n");
  printf("##                    0 - Sair                     ##\n");
  printf("##                                                 ##\n");
  printf("#####################################################\n");
  printf("\n");

  scanf("%d", &opcao);
  clrScrn();
	
  switch(opcao){
    case 1:
      listProd();
      break;
    case 2:
      cadastrarProd();
      break;
    case 3:
      findProd();
      break;
    case 4:
      deleteProd();
      break;
    case 0:
      return 0;
    default:
      printf("Escolha uma opção válida! Tente novamente. \n");
      catalog();
      break;
  }
  return opcao;
}
