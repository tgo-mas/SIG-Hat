#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "validacoes.h"
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
    int telInt[12];
    convertToInt(tel, telInt);
    if(validaTel(telInt) == 1 && validaEmail(email) == 1){
        strcpy(fornecedores[index].razao, nome);
        strcpy(fornecedores[index].cnpj, cnpj);
        strcpy(fornecedores[index].tel, tel);
        strcpy(fornecedores[index].email, email);
        gravaFornec(fornecedores[index]);
    }else{
        printf("\n    Erro: Informações inválidas! Tente Novamente.");
        menuFornec();
    }
}

////    exibFornec(&fornec) -> Exibe as informações do Fornecedor passado por parâmetro.

void exibFornec(Fornecedor* fornec){
    printf("\n    Razão social: %s", fornec->razao);
    printf("\n    Razão social: %s", fornec->cnpj);
    printf("\n    Razão social: %s", fornec->tel);
    printf("\n    Razão social: %s", fornec->email);
}


////    findFornec() -> Procura um fornecedor pelo seu cnpj.



////    gravaFornec(fornec) -> Grava as informações do fornecedor em arquivo fornecedores.dat

void gravaFornec(Fornecedor fornec){
	FILE* pFor;
	pFor = fopen("./data/fornecedores.dat", "ab");
	if(pFor == NULL){
		printf("	Arquivo não encontrado.");
	}else{
		fwrite(&fornec, sizeof(Fornecedor), 1, pFor);
		fclose(pFor);
	}
}

////    getDadosFornec() -> Atualiza a lista de fornecedores com os dados gravados.

void getDadosFornec(void){
	FILE* pFor;
	Fornecedor* fornec;
	fornec = (Fornecedor*) malloc(sizeof(Fornecedor));
	int index = 0;
	pFor = fopen("./data/fornecedores.dat", "rb");
	if(pFor == NULL){
		printf("	Arquivo não encontrado.");
	}else{
		while(!feof(pFor)){
			fread(fornec, sizeof(Fornecedor), 1, pFor);
			if(fornec != NULL){
				fornecedores[index] = *fornec;
				idFornec[index] = index + 1;
				index++;
			}
		}
	}
	fclose(pFor);
	free(fornec);
}
