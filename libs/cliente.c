#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "menus.h"
#include "cabs.h"
#include "validacoes.h"

//// menuCliente() -> Exibe o menu do módulo de clientes e pede que o cliente escolha uma operação a seguir.

void menuCliente(void){
    int opcao;
    do{
        telaMenuCliente();
        printf("\n    Selecione uma opção: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
                listarClientes();
                break;
            case 2:
                addCliente();
                break;
            case 0:
                break;
            default:
                printf("\n    Selecione uma opção válida! Tente novamente.");
                break;
        }
    }while(opcao != 0);
}

//// addCliente() -> Inicia o processo de cadastro de um novo cliente.

void addCliente(void){
    cabecAddCliente();
    char nome[15];
    printf("\n    Informe o nome do cliente: "); 
    scanf("%14[^\n]", nome);
    getchar();
    ClientePf* pCliPf = (ClientePf*) malloc(sizeof(ClientePf));
    ClientePj* pCliPj = (ClientePj*) malloc(sizeof(ClientePj));
    int PfPj = 0;
    do{
        char cpfCnpj[15];
        printf("\n    Informe o CPF ou CNPJ do cliente: "); 
        scanf("%14[^\n]", cpfCnpj);
        getchar();
        PfPj = isPForPJ(cpfCnpj);
        if(PfPj == 1){
            printf("\n    O cliente a ser registrado é uma pessoa física. ");
            strcpy(pCliPf->nome,nome);
            strcpy(pCliPf->cpf,cpfCnpj);
            free(pCliPj);
        }else if(PfPj == 2){
            printf("\n    O cliente a ser registrado é uma pessoa jurídica. ");
            strcpy(pCliPj->nome,nome);
            strcpy(pCliPj->cnpj,cpfCnpj);
            free(pCliPf);
        }else{
            printf("\n    CPF ou CNPJ inválido! Tente novamente.");
        }
        getchar();
    }while(!PfPj);
    int valTel = 0;
    do{
        printf("\n    Informe o telefone de contato do cliente: ");   
        if(PfPj == 1){
            scanf("%11[^\n]", pCliPf->tel);
            valTel = validaTel(pCliPf->tel);
        }else if(PfPj == 2){
            scanf("%11[^\n]", pCliPj->tel);
            valTel = validaTel(pCliPj->tel);
        }
        if(!valTel) printf("\n    O telefone informado é inválido! Tente novamente!");
        getchar();
    }while(!valTel);
    int valEmail = 0;
    do{
        printf("\n    Informe o email do cliente: ");  
        if(PfPj == 1){
            scanf("%29[^\n]", pCliPf->email);
            valEmail = validaEmail(pCliPf->email);
        }else if(PfPj == 2){
            scanf("%29[^\n]", pCliPj->email);
            valEmail = validaEmail(pCliPj->email);
        } 
        getchar();
    }while(!valEmail);
    if(PfPj == 1){
        pCliPf->status = 'c'; 
        gravaCliPf(pCliPf);
    }else if(PfPj == 2){
        pCliPj->status = 'c'; 
        gravaCliPj(pCliPj);
    }
}

//// gravaCliPf() e gravaCliPj() -> Gravam as informações do cliente em arquivos específicos para pessoa física ou jurídica.

void gravaCliPf(ClientePf* pCli){
    FILE* fCli;
    fCli = fopen("./data/clientesPf.dat", "ab");
    if(fCli == NULL){
        printf("\n    FATAL: Arquivo clientesPf.dat não encontrado!");
        exit(1);
    }
    fwrite(pCli, sizeof(ClientePf), 1, fCli);
    fclose(fCli);
    free(pCli);
}

void gravaCliPj(ClientePj* pCli){
    FILE* fCli;
    fCli = fopen("./data/clientesPj.dat", "ab");
    if(fCli == NULL){
        printf("\n    FATAL: Arquivo clientesPj.dat não encontrado!");
        exit(1);
    }
    fwrite(pCli, sizeof(ClientePj), 1, fCli);
    fclose(fCli);
    free(pCli);
}

//// exibeCliPf(pCli) e exibeCliPj(pCli) -> Exibe as informações do cliente passado por parâmetro. O procedimento muda de acordo com o tipo.

void exibeCliPf(ClientePf* pCli){
    printf("\n#####################################################\n");
    printf("\n  Nome: %s", pCli->nome);
    printf("\n  CPF: %s", pCli->cpf);
    printf("\n  Telefone: %s", pCli->tel);
    printf("\n  Email: %s", pCli->email);
    printf("\n\n#####################################################");
}

void exibeCliPj(ClientePj* pCli){
    printf("\n#####################################################\n");
    printf("\n  Nome: %s", pCli->nome);
    printf("\n  CNPJ: %s", pCli->cnpj);
    printf("\n  Telefone: %s", pCli->tel);
    printf("\n  Email: %s", pCli->email);
    printf("\n\n#####################################################");
}

//// listarClientes() -> Exibe uma lista de todos os clientes cadastrados, separando-os por pessoa física e jurídica.

void listarClientes(void){
    printf("\n    Clientes Pessoa Física: ");
    FILE* fCli;
    ClientePf* pCli = (ClientePf*) malloc(sizeof(ClientePf));
    fCli = fopen("./data/clientesPf.dat", "rb");
    while(fread(pCli, sizeof(ClientePf), 1, fCli)){
        exibeCliPf(pCli);
    }
    fclose(fCli);
    free(pCli);
    printf("\n    Clientes Pessoa Jurídica: ");
    ClientePj* pCliPj = (ClientePj*) malloc(sizeof(ClientePj));
    fCli = fopen("./data/clientesPj.dat", "rb");
    while(fread(pCliPj, sizeof(ClientePj), 1, fCli)){
        exibeCliPj(pCliPj);
    }
    fclose(fCli);
    free(pCliPj);
    getchar();
}
