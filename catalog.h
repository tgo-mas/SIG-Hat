#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#else

#endif

//// Dados dos produtos
int ids[10] = {1, 2, 3};
int estoq[10] = {4, 5, 0};
char modelos[10][15] = {"bone", "chapeu", "viseira"};
char marcas[10][15] = {"Nike", "artesanal", "adidas"};
float precos[10] = {40.00, 15.0, 120.0};

//// Assinatura das funções
void clrScrn(void);
int findIndex(int ids[10]);
void listProds(void);
void exibProd(int index);
void cadastrarProd(void);
void findProd(void);
void exibirID(int id);
void buscaModelo(char modelo[15]);
void remover(int id);
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

//// findIndex(ids) -> Encontra o proximo item vazio na lista de produtos
int findIndex(int ids[10]){
	int i;
	
	for(i = 0; i < 10; i++){
		if(ids[i] == 0){
			return i;
		}
	}
}

//// listProds() -> Lista todos os produtos, chamando exibProd para cada
void listProds(void){
	int index;
	index = findIndex(ids);
	int i;
	for(i = 0; i < index; i++){
		exibProd(i);
	}
}

//// exibProd(indice) -> Exibe as infos do produto no indice indicado
void exibProd(int index){
	printf("\n    ID: %d", ids[index]);
	printf("\n    Modelo: %s", modelos[index]);
	printf("\n    Marca: %s", marcas[index]);
	printf("\n    Preco: %f", precos[index]);
	printf("\n    Em estoque: %d\n\n", estoq[index]);
	printf("#####################################################\n");
}

//// exibirID(id) -> Mesmo que exibProd() mas usa o id do produto em vez do indice
void exibirID(int id){
	int index, i;
	index = findIndex(ids);
	for(i = 0; i < index; i++){
		if(ids[i] == id){
			exibProd(i);
		}
	}
}

//// cadastrarProd() -> Cadastra as infos do produto nas listas
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
	printf("\n    Qtd em estoque: ");
  	scanf("%d", &estoq[index]);
  	
  	catalog();
}

//// findProd() -> Abre o menu de busca de produto
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
	
	int id;
	char modelo[15];

	switch(opcao){
		case 1:
			printf("    Digite o ID do produto: ");
			scanf("%d", &id);
			exibirID(id);
			break;
		case 2:
			printf("   Informe o modelo do produto: ");
			scanf("%s", &modelo);
			buscaModelo(modelo);
			break;
		default:
			printf("\n    Selecione uma opção válida!\n    Aperte enter para continuar...");
			scanf("%d", &id);
			break;
	}
	int no;
	printf("\n    Digite 0 para continuar...");
	scanf("%d", no);
	catalog();
}

//// buscaModelo(modelo) -> Busca o produto pelo modelo dele
void buscaModelo(char modelo[15]){
	int index, i;
	index = findIndex(ids);
	for(i = 0; i < index; i++){
		if(strcmp(modelos[i], modelo) == 0){
			exibProd(i);
		}
	}
}

//// deleteProd() -> Abre o menu para remover produto, chama remove()
void deleteProd(void){
	
	int id;
  	printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##        = R E M O V E R   P R O D U T O =        ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");

	printf("	Remocao por ID: ");
	scanf("%d", &id);
	
	remover(id);
	
	catalog();
}

//// remove(id) ->  Remove o produto com o id indicado
void remover(int id){
	int index, i, newIds[10];
	char newModelos[10][15], newMarcas[10][15];
	float newPrecos[10];
	index = findIndex(ids);
	
	for(i = 0; i < index; i++){
		if(ids[i] != id){
			newIds[i] = ids[i];
			strcpy(newModelos[i], modelos[i]);
			strcpy(newMarcas[i], marcas[i]);
			newPrecos[i] = precos[i];
		}else{
			for(int j = i; j < index; j++){
				newIds[j] = ids[j+1];	
				strcpy(newModelos[j], modelos[j+1]);
				strcpy(newMarcas[j], marcas[j+1]);
				newPrecos[j] = precos[j+1];
			}
			break;
		}
	}
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
  printf("#####################################################\n");
  listProds();
  printf("##                                                 ##\n");
  printf("##             1 - Cadastrar produto               ##\n");
  printf("##             2 - Pesquisar produto               ##\n");
  printf("##              3 - Excluir produto                ##\n");
  printf("##                                                 ##\n");
  printf("##                    0 - Sair                     ##\n");
  printf("##                                                 ##\n");
  printf("#####################################################\n");
  printf("\n");

  scanf("%d", &opcao);
  clrScrn();
	
  switch(opcao){
    case 1:
      cadastrarProd();
      break;
    case 2:
      findProd();
      break;
    case 3:
      deleteProd();
      break;
    case 0:
    	break;
    default:
      printf("Escolha uma opção válida! Tente novamente. \n");
      catalog();
      break;
  }
  return opcao;
}
