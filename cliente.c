#include <stdio.h>
#include <string.h>

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

void addCliente(char cpf[11], char nome[20]){
	int index;
	index = getIndexCliente();
	strcpy(cpfs[index],cpf);
	strcpy(nomes[index],nome);
}

//// verifCliente() -> Verifica se o cliente existe. Se existir, retorna o índice + 1, se não, retorna 0.

int verifCliente(char cpf[11]){
	for(int i = 0; i < 10; i++){
		if(strcmp(cpfs[i], cpf) == 0){
			return i + 1;
		}
	}
	return 0;
