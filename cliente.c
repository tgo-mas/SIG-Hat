#include <stdio.h>
#include "cliente.h"
#include <string.h>

//// Varíáveis referentes a Clientes

char cpfs[10][11] = {"10616486460", "12345678910"};
char nomes[10][20] = {"Bruno", "Roberto"};
float totalCompras[10] = {45.0, 30.0};
int numCompras[10] = {3, 2};

//// Funções

//// getIndexCliente() -> Retorna índice do primeiro item vazio na lista de clientes (onde ID == 0).

int getIndexCliente(void){
	for(int i = 0; i < 10; i++){
		if(cpfs[i] == 0){
			return i;
		}
	}
	return 10;
}

//// addCliente() -> Adiciona as informações na lista de clientes.

void addCliente(char cpf[12], char nome[20]){
	int index;
	index = getIndexCliente();
	strcpy(cpfs[index],cpf);
	strcpy(nomes[index],nome);
}

//// verifCliente() -> Verifica se o cliente existe. Se existir, retorna o índice + 1, se não, retorna 0.

int verifCliente(char cpf[12]){
	for(int i = 0; i < 11; i++){
		if(strcmp(cpfs[i], cpf) == 0){
			return i + 1;
		}
	}
	return 0;
}

//// getNomes() -> Retorna um ponteiro para o local onde os nomes dos clientes estão armazenados.

char* getNomes(void){
	return *nomes;
}

//// menuCliente() -> Exibe a tela de menu para controle e gerenciamento dos clientes da loja.
int menuCliente(void){
	printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##   = C O N T R O L E   D E   C L I E N T E S =   ##\n");
	printf("##                                                 ##\n");
	printf("##         1 - Listar clientes cadastrados         ##\n");
	printf("##              2 - Pesquisar cliente              ##\n");
	printf("##               3 - Remover cliente               ##\n");
	printf("##          4 - Gerar relatório de vendas          ##\n");
	printf("##                                                 ##\n");
	printf("##                     0 - Sair                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
	int opcao;
	printf("     Selecione uma opcao: ");
	scanf("%d", &opcao);
	switch(opcao){
		case 1:
			listClientes();
			break;
		case 2:
			findCliente();
			break;
		case 3:
			deleteCliente();
			break;
		case 4:
			relatVendas();
		case 0: 
			break;
		default:
			printf("    Digite uma opcao valida! Tente novamente.");
			menuCliente();
			break;
	}
	if(opcao == 0){
		return opcao;
	}else{
		menuCliente();
	}
	return 0;
}
