#include <stdio.h>
#include <string.h>
#include "fornecedor.h"
#include "interface.h"
#include "misc.h"

////   Dados relativos a fornecedores

int idFornec[10];
Fornecedor fornecedores[10];

////     menuFornec() -> Exibe a tela principal do módulo de fornecedor.

void menuFornec(void){
    int opcao;
    telaMenuFornecedor();
    printf("\n    Selecione uma opção: ");
    scanf("%d", &opcao);
    switch(opcao){
        case 0:
            break;
        default:
            getchar();
            printf("\n    Selecione uma opção válida!");
            getchar();
            break;
    }

}

////    addFornec(nome, cnpj, tel, email) -> Adiciona um fornecedor às listas dos dados.

void addFornec(char* nome, char* cnpj, char* tel, char* email){
    int index;
    index = getIndex(idFornec);
    strcpy(fornecedores[index].razao, nome);
    strcpy(fornecedores[index].cnpj, cnpj);
    strcpy(fornecedores[index].tel, tel);
    strcpy(fornecedores[index].email, email);
    gravaFornec(fornecedores[index]);
}

////    gravaFornec(fornec) -> Grava as informações do fornecedor em arquivo fornecedores.dat

void gravaFornec(Fornecedor fornec){
	FILE* pFor;
	pFor = fopen("./data/fornecedores.dat", "ab");
	if(pCli == NULL){
		printf("	Arquivo não encontrado.");
	}else{
		fwrite(cli, sizeof(Cliente), 1, pCli);
		fclose(pCli);
	}
}
