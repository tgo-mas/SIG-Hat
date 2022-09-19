#include <stdio.h>

long cpfs[10];
char nomes[10][20];
float totalCompras[10];
int numCompras[10];

int getIndexCliente(void){
	for(int i = 0; i < 10; i++){
		if(cpfs[i] == 0){
			return i;
		}
	}
	return 10;
}

void addCliente(int cpf, char nome[20]){
	int index;
	index = getIndexCliente();
	cpfs[index] = cpf;
	nomes[index] = nome;
}