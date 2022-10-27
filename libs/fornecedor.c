#include <stdio.h>
#include <string.h>
#include "fornecedor.h"
#include "interface.h"

////   Dados relativos a fornecedores
char razoes[10][30];
int cnpjs[10][14];
int telsForn[10][12];
char emailsForn[10][30];

////     getIndexFornec() -> Retorna o índice do primeiro campo vazio nas listas de fornecedor. Retorna -1 para caso de erro.

int getIndexFornec(){
    for(int i = 0; i < 10; i++){
        if(*razoes[i] == 0){
            return i;
        }
    }
    return -1;
}

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

void addFornec(char* nome, int* cnpj, int* tel, char* email){
    int index;
    index = getIndexFornec();
    strcpy(razoes[index], nome);
    *cnpjs[index] = *cnpj;
    *telsForn[index] = *tel;
    strcpy(emailsForn[index], email);
}
