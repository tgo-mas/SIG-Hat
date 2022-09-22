#include <stdio.h>
#include <string.h>

//// Varíáveis referentes a Clientes

char cpfs[10][11] = {"10616486460", "12345678910"};
char nomes[10][20] = {"Bruno", "Roberto"};
float totalCompras[10] = {45.0, 30.0};
int numCompras[10] = {3, 2};

//// Assinatura das funções

int getIndexCliente(void);
void addCliente(char cpf[11], char nome[20]);
int verifCliente(char cpf[11]);

//// Funções

int getIndexCliente(void){
	for(int i = 0; i < 10; i++){
		if(cpfs[i] == 0){
			return i;
		}
	}
	return 10;
}

void addCliente(char cpf[11], char nome[20]){
	int index;
	index = getIndexCliente();
	strcpy(cpfs[index],cpf);
	strcpy(nomes[index],nome);
}

int verifCliente(char cpf[11]){
	for(int i = 0; i < 10; i++){
		if(strcmp(cpfs[i], cpf) == 0){
			return i + 1;
		}
	}
	return 0;
}