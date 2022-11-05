#include <stdio.h>
#include <stdlib.h>
#include "misc.h"
#include "cliente.h"
#include "produtos.h"
#include "interface.h"
#include "validacoes.h"
#include <string.h>

//// Varíáveis referentes a Clientes

int idsCliente[10];
Cliente clientes[10];

//// Funções

//// listClientes() -> Lista as informações dos clientes.

void listClientes(void){
	clrScrn();
	cabecListaClientes();
	int index;
	index = getIndex(idsCliente);	
	for(int i = 0; i < index; i++){
		printf("    CPF: %d", *clientes[i].cpf);
		printf("\n    Nome: %s", clientes[i].nome);
		printf("\n    Email: %s", clientes[i].email);
		printf("\n    Telefone: %s", clientes[i].tel);
		printf("\n    Numero de compras: %d", clientes[i].numCompras);
		printf("\n    R$ comprados: %.2f\n", clientes[i].totalComprado);
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
		printf("    Nome: %s\n", clientes[index].nome);
		printf("    CPF: %d\n", *clientes[index].cpf);
		printf("    Email: %s\n", clientes[index].email);
		printf("    Num. de compras: %d\n", clientes[index].numCompras);
		printf("    R$ comprados: %.2f\n\n", clientes[index].totalComprado);
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
		getchar();
		if(add == 1){
			printf("\n    Cliente adicionado com sucesso!");
			printf("\n    Aperte enter para continuar... ");
			getchar();
		}else{
			printf("\n    CPF ou Email inválidos, tente novamente!");
			printf("\n    Aperte enter para continuar... ");
			getchar();
		}
	}while(add == 0);
}

//// addCliente() -> Adiciona as informações na lista de clientes.

int addCliente(char cpf[12], char nome[20], char email[30], char tel[12]){
	int telInt[12];
	convertToInt(tel, telInt);
	if(validaCPF(cpf) == 1 && validaEmail(email) == 1 && validaTel(telInt) == 1){
		Cliente cli;
		int index;
		index = getIndex(idsCliente);
		idsCliente[index] = idsCliente[index] == 0 ? 1 : idsCliente[index] + 1;
		strcpy(cli.cpf, cpf);
		strcpy(cli.nome,nome);
		strcpy(cli.email,email);
		strcpy(cli.tel, tel);
		cli.totalComprado = 0.0;
		cli.numCompras = 0;
		clientes[index] = cli;
		gravaCliente(&cli);
		return 1;
	}
	return 0;
}

//// verifCliente() -> Verifica se o cliente existe. Se existir, retorna o índice + 1, se não, retorna 0.

int verifCliente(char cpf[12]){
	int cpfInt[12];
	convertToInt(cpf, cpfInt);
	for(int i = 0; i < 11; i++){
		if(*clientes[i].cpf == *cpfInt){
			return i + 1;
		}
	}
	return 0;
}

//// getNomeAt(index) -> Retorna o nome do cliente com no indice passado por parâmetro.

char* getNomeAt(int index){
	return clientes[index].nome;
}

//// menuCliente() -> Exibe a tela de menu para controle e gerenciamento dos clientes da loja.
int menuCliente(void){
	getDadosCli();
	telaMenuClientes();
	int opcao;
	printf("     Selecione uma opcao: ");
	scanf("%d", &opcao);
	switch(opcao){
		case 1:
			listClientes();
			break;
		case 2:
			inv: char cpf[12];
			printf("\n    Informe o CPF do cliente: ");
			scanf("%s", cpf);
			if(validaCPF(cpf) == 1) cadCliente(cpf); 
			else {
				printf("    Informe um CPF válido! Tente novamente.");
				goto inv;
			};
			break;
		case 3:
			findCliente();
			break;
		case 4:
			deleteCliente();
		case 5:
		 	printf("    Em desenvolvimento. Aguarde para futuras atualizações...\n");
			getchar();
			printf("    Aperte enter para continuar... ");
			getchar();
			menuCliente();
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

//// gravaCliente(&cli) -> Grava as informações de clientes no arquivo clientes.dat

void gravaCliente(Cliente* cli){
	FILE* pCli;
	pCli = fopen("./data/clientes.dat", "ab");
	if(pCli == NULL){
		printf("	Arquivo não encontrado.");
	}else{
		fwrite(cli, sizeof(Cliente), 1, pCli);
		fclose(pCli);
	}
}

//// getDadosCli() -> Retorna a lista de clientes com os dados extraidos do arquivo clientes.dat

void getDadosCli(void){
	FILE* pCli;
	Cliente* cli;
	cli = (Cliente*) malloc(sizeof(Cliente));
	int index = 0;
	pCli = fopen("./data/clientes.dat", "rb");
	if(pCli == NULL){
		printf("	Arquivo não encontrado.");
	}else{
		while(!feof(pCli)){
			fread(cli, sizeof(Cliente), 1, pCli);
			clientes[index] = *cli;
			idsCliente[index] = index + 1;
			index++;
		}
	}
	fclose(pCli);
	free(cli);
}
