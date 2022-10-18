#include <stdio.h>
#include "cliente.h"
#include "produtos.h"
#include "interface.h"
#include "validacoes.h"
#include <string.h>

//// Varíáveis referentes a Clientes

char cpfs[10][12] = {"10616486460", "12345678910"};
char nomes[10][20] = {"Bruno", "Roberto"};
char emails[10][30] = {"bruninho@gmail.com", "robrob@gmail.com"};
char telefones[10][12] = {"84999999999", "83999658545"};
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
	int index;
	index = getIndexCliente();	
	for(int i = 0; i < index; i++){
		printf("\n    CPF: %s", cpfs[i]);
		printf("\n    Nome: %s", nomes[i]);
		printf("\n    Email: %s", emails[i]);
		printf("\n    Numero de compras: %d", numCompras[i]);
		printf("\n    R$ comprados: %.2f\n", totalCompras[i]);
		printf("\n#####################################################\n\n");
	}
	getchar();
	printf("    Aperte enter para continuar... ");
	getchar();
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
		getchar();
		printf("\n    Cliente inexistente! Aperte enter para continuar... ");
		getchar();
		menuCliente();
	}else{
		getchar();
		index -= 1;
		printf("\n    Cliente encontrado! \n");
		printf("    Nome: %s\n", nomes[index]);
		printf("    CPF: %s\n", cpfs[index]);
		printf("    Email: %s\n", emails[index]);
		printf("    Num. de compras: %d\n", numCompras[index]);
		printf("    R$ comprados: %.2f\n\n", totalCompras[index]);
		printf("######################Nome###############################\n");
		printf("    Aperte enter para continuar... ");
		getchar();
	}
}

//// deleteCliente() -> Deleta as informações do cliente de cpf informado.

void deleteCliente(void){


}

//// relatVendas() -> Mostra um relatório das vendas por mês, dia ou ano.

void relatVendas(int type){
	//// type: 1 - dia; 2 - mes; 3 - ano.


}

//// cadCliente() -> Coleta os dados referentes a um novo cliente.

void cadCliente(char* cpf){
	int add = 0;
	do{
		char nome[20], email[30], tel[12];
		printf("\n    Nome: ");
		scanf("%s", nome);
		printf("    Email: ");
		scanf("%s", email);
		printf("    Telefone: ");
		scanf("%s", tel);
		add = addCliente(cpf, nome, email, tel);
		if(add == 1){
			printf("\n    Cliente adicionado com sucesso!");
		}else{
			printf("\n    CPF ou Email inválidos, tente novamente!");
		}
	}while(add == 0);
}

//// addCliente() -> Adiciona as informações na lista de clientes.

int addCliente(char cpf[12], char nome[20], char email[30], char tel[12]){
	int telInt[12];
	convertToInt(tel, telInt);
	if(validaCPF(cpf) == 1 && validaEmail(email) == 1 && validaTel(telInt) == 1){
		int index;
		index = getIndexCliente();
		strcpy(cpfs[index],cpf);
		strcpy(nomes[index],nome);
		strcpy(emails[index],email);
		strcpy(telefones[index],tel);
		return 1;
	}
	return 0;
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

//// getNomeAt(index) -> Retorna o nome do cliente com no indice passado por parâmetro.

char* getNomeAt(int index){
	return nomes[index];
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
			char cpf[12];
			printf("\n    Informe o CPF do cliente: ");
			scanf("%s", cpf);
			if(validaCPF(cpf) == 1) cadCliente(cpf);
			break;
		case 3:
			findCliente();
			break;
		case 4:
			deleteCliente();
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
