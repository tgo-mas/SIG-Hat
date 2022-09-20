#include <stdio.h>
#include <string.h>

char cpfs[10];
char nomes[10];
float totalCompras[10];
int numCompras[10];

int getIndexCliente(void);
void addCliente(char cpf[9], char nome[20]);
int verifCliente(void);

int getIndexCliente(void){
	for(int i = 0; i < 10; i++){
		if(cpfs[i] == 0){
			return i;
		}
	}
	return 10;
}

void addCliente(char cpf[9], char nome[20]){
	int index;
	index = getIndexCliente();
	cpfs[index] = *cpf;
	nomes[index] = *nome;
}

int verifCliente(char cpf[9]){
	for(int i = 0; i < 10; i++){
		if(strcmp(cpfs[i], cpf) == 0){
			return i;
		}
	}
	return getIndexCliente();
}