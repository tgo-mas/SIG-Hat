#include <stdio.h>
#include <stdlib.h>
#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#else

#endif

//// Dados dos produtos
int ids[10];
char modelos[10][15];
char marcas[10][15];
float precos[10];

//// Assinatura das funções
void clrScrn(void);
int findIndex(int ids[10]);
void listProd(void);
void cadastrarProd(void);
void findProd(void);
int catalog(void);

//// Funções
void clrScrn(void){
	#ifdef __linux__
		system("clear");	
	#elif _WIN32
		system("cls");
	#else
	
	#endif	
}

int findIndex(int ids[10]){
	int i;
	
	for(i = 0; i < 10; i++){
		if(ids[i] == 0){
			return i;
		}
	}
}

void listProd(void){
	int index;
	index = findIndex(ids);
  	printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##      = L I S T A   D E   P R O D U T O s =      ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
	int i;
	for(i = 0; i < index; i++){
		printf("\n    ID: %d", ids[i]);
		printf("\n    Modelo: %s", modelos[i]);
		printf("\n    Marca: %s", marcas[i]);
		printf("\n    Preco: %f\n", precos[i]);
		printf("\n#####################################################\n");
	}
}

void cadastrarProd(void){
	int index;
	index = findIndex(ids);
	printf("%d", index);
	
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
  	scanf("%d", &ids[index]);
  	printf("	Modelo: ");
  	scanf("%s", &modelos[index]);
  	printf("	Marca: ");
  	scanf("%s", &marcas[index]);
  	printf("	Preco: ");
  	scanf("%f", &precos[index]);
  	
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
	scanf("%d", &opcao);
	
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
