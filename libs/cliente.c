#include <stdio.h>
#include "cliente.h"
#include "produtos.h"
#include "interface.h"
#include "validacoes.h"
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
		if(strcmp("", cpfs[i]) == 0){
			return i;
		}
	}
	return 10;
}

//// listClientes() -> Lista as informações dos clientes.

void listClientes(void){
	clrScrn();
	cabecListaClientes();
	int opcao, index;
	index = getIndexCliente();	
	for(int i = 0; i < index; i++){
		printf("\n    CPF: %s", cpfs[i]);
		printf("\n    Nome: %s", nomes[i]);
		printf("\n    Numero de compras: %d", numCompras[i]);
		printf("\n    R$ comprados: %.2f\n", totalCompras[i]);
		printf("\n#####################################################\n\n");
	}
	printf("    Digite 0 e aperte enter para continuar... ");
	scanf("%d", &opcao);
	menuCliente();
}

//// findCliente() -> Mostra a tela de pesquisa de cliente e chama exibCliente().

void findCliente(void){
	clrScrn();
	char cpf;
	cabecFindClientes();
	printf("    Informe o CPF do cliente que deseja consultar: ");
	scanf("%s", &cpf);
	exibCliente(&cpf);
}

//// exibCliente() -> Exibe as informações do cliente com o CPF passado por parâmetro.

void exibCliente(char* cpf){
	int index = verifCliente(cpf);
	if(index == 0){
		printf("\n    Cliente inexistente! Digite 0 e aperte enter para continuar... ");
		scanf("%d", &index);
		menuCliente();
	}else{
		index -= 1;
		printf("\n    Cliente encontrado! \n");
		printf("    Nome: %s\n", nomes[index]);
		printf("    CPF: %s\n", cpfs[index]);
		printf("    Num. de compras: %d\n", numCompras[index]);
		printf("    R$ comprados: %.2f\n\n", totalCompras[index]);
		printf("#####################################################\n");
		printf("    Digite 0 e aperte enter para continuar... ");
	}
}

//// deleteCliente() -> Deleta as informações do cliente de cpf informado.

void deleteCliente(void){

	
}

//// relatVendas() -> Mostra um relatório das vendas por mês, dia ou ano.

void relatVendas(int type){
	//// type: 1 - dia; 2 - mes; 3 - ano.


}

//// addCliente() -> Adiciona as informações na lista de clientes.

void addCliente(char cpf[12], char nome[20]){
	if(validaCPF(cpf) == 1){
		int index;
		index = getIndexCliente();
		strcpy(cpfs[index],cpf);
		strcpy(nomes[index],nome);
	}else{
		printf("O CPF informado é inválido! Tente novamente.");
	}
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
	telaMenuClientes();
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
			relatVendas(0);
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
