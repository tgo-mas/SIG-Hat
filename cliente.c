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

char* getNomes(void){
	return *nomes;
}
