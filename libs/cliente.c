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
            case 3: 
                buscaCliente();
                break;
            case 4:
                editarCliente();
                break;
            case 5:
                deleteCliente();
            case 0:
                break;
            default:
                printf("\n    Selecione uma opção válida! Tente novamente.");
                getchar();
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
    printf("\n    Cliente registrado com sucesso!");
    getchar();
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
        if(pCli->status == 'c') exibeCliPf(pCli);
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

//// buscaCliente() -> Inicia o processo de buscar um cliente, chama as funções getCliPj e getCliPf.

void buscaCliente(void){
    int type;
    char nome[15];
    initBusca:
    printf("\n    Qual o tipo de cliente que deseja buscar? (1 - Pessoa física, 2 - Pessoa Jurídica.) ");
    scanf("%d", &type);
    getchar();
    printf("\n    Agora informe o nome do cliente que deseja buscar: ");
    scanf("%14[^\n]", nome);
    getchar();
    switch(type){
        case 1:
            ClientePf* cliPf = getCliPf(nome);
            getchar();
            if(cliPf != NULL){
                free(cliPf);
            }
            break;
        case 2:
            ClientePj* cliPj = getCliPj(nome);
            getchar();
            if(cliPj != NULL){
                free(cliPj);
            }
            break;
        default:
            printf("\n    Selecione um tipo válido! Tente novamente");
            goto initBusca;
    }
}

//// getCliPf(nome) -> Exibe e retorna o cliente de nome passado por parâmetro, em caso de não existente, informa ao usuário e retorna NULL.

ClientePf* getCliPf(char* nome){
    cabecBuscaPf();
    FILE* fCli;
    ClientePf* pCli = (ClientePf*) malloc(sizeof(ClientePf));
    fCli = fopen("./data/clientesPf.dat", "rb");
    if(fCli == NULL){
        printf("\n    FATAL: Arquivo clientesPf.dat não encontrado!");
        exit(1);
    }
    while(fread(pCli, sizeof(ClientePf), 1, fCli)){
        if(strcmp(pCli->nome, nome) == 0 && pCli->status == 'c'){
            exibeCliPf(pCli);
            fclose(fCli);
            return pCli;
        }
    }
    printf("\n    O cliente de nome informado não foi encontrado! Tente novamente.");
    fclose(fCli);
    free(pCli);
    return NULL;
}

//// getCliPj(nome) -> Exibe e retorna o cliente de nome passado por parâmetro, em caso de não existente, retorna NULL;

ClientePj* getCliPj(char* nome){
    cabecBuscaPj();
    FILE* fCli;
    ClientePj* pCli = (ClientePj*) malloc(sizeof(ClientePj));
    fCli = fopen("./data/clientesPj.dat", "rb");
    if(fCli == NULL){
        printf("\n    FATAL: Arquivo clientesPj.dat não encontrado!");
        exit(1);
    }
    while(fread(pCli, sizeof(ClientePj), 1, fCli)){
        if(strcmp(pCli->nome, nome) == 0 && pCli->status == 'c'){
            exibeCliPj(pCli);
            fclose(fCli);
            return pCli;
        }
    }
    printf("\n    O cliente de nome informado não foi encontrado! Tente novamente.");
    fclose(fCli);
    free(pCli);
    return NULL;
}

//// deleteCliente() -> Altera o status do cliente para 'x'.

void deleteCliente(void){
    cabecDeleteCliente();
    int type;
    char nome[15], resp;
    printf("\n    Que tipo de cliente deseja excluir? (1 - Pessoa física, 2 - Pessoa jurídica) ");
    scanf("%d", &type);
    getchar();
    printf("\n    Informe o nome do cliente que deseja excluir: ");
    scanf("%14[^\n]", nome);
    getchar();
    FILE* fCli;
    switch(type){
        case 1:
            fCli = fopen("./data/clientesPf.dat", "r+b");
            if(fCli == NULL){
                printf("\n    FATAL: Arquivo clientesPf.dat não encontrado!");
                exit(1);
            }
            ClientePf* cliPf = getCliPf(nome);
            if(cliPf != NULL){
                printf("\n    O cliente encontrado é este. Deseja realmente excluí-lo? (S para confirmar) ");
                scanf("%c", &resp);
                getchar();
                if(resp == 's' || resp == 'S'){
                    ClientePf* pCli = (ClientePf*) malloc(sizeof(ClientePf));
                    while(fread(pCli, sizeof(ClientePf), 1, fCli)){
                        if(strcmp(pCli->nome, cliPf->nome) == 0 && pCli->status == 'c'){
                            cliPf->status = 'x';
                            fseek(fCli, (-1) * sizeof(ClientePf), SEEK_CUR);
                            fwrite(cliPf, sizeof(ClientePf), 1, fCli);
                            printf("\n    Cliente excluído com sucesso!");
                            getchar();
                            fclose(fCli);
                            free(cliPf);
                            free(pCli);
                            break;
                        }
                    }
                }else{
                    printf("\n    Operação cancelada. ");
                    getchar();
                }
            }
            break;
        case 2:
            fCli = fopen("./data/clientesPj.dat", "r+b");
            if(fCli == NULL){
                printf("\n    FATAL: Arquivo clientesPj.dat não encontrado!");
                exit(1);
            }
            ClientePj* cliPj = getCliPj(nome);
            if(cliPj != NULL){
                printf("\n    O cliente encontrado é este. Deseja realmente excluí-lo? (S para confirmar) ");
                scanf("%c", &resp);
                getchar();
                if(resp == 's' || resp == 'S'){
                    ClientePj* pCli = (ClientePj*) malloc(sizeof(ClientePj));
                    while(fread(pCli, sizeof(ClientePj), 1, fCli)){
                        if(strcmp(pCli->nome, cliPj->nome) == 0 && pCli->status == 'c'){
                            cliPj->status = 'x';
                            fseek(fCli, (-1) * sizeof(ClientePj), SEEK_CUR);
                            fwrite(cliPj, sizeof(ClientePj), 1, fCli);
                            printf("\n    Cliente excluído com sucesso!");
                            getchar();
                            fclose(fCli);
                            free(cliPj);
                            free(pCli);
                        }
                    }
                }else{
                    printf("\n    Operação cancelada. ");
                    getchar();
                }
            }
            break;
        default:
            printf("\n    Opção inválida! Tente novamente.");
            getchar();
    }
}

//// editarCliente() -> Inicia o processo de alteração de um determinado cliente.

void editarCliente(void){
    FILE* fCli;
    char nome[15], resp;
    int tipo;
    printf("\n    Informe o nome do cliente que deseja editar: ");
    scanf("%s", nome);
    getchar();
    printf("\n    Informe o tipo do cliente que deseja editar: (1 - Pessoa Física, 2 - Pessoa Jurídica) ");
    scanf("%d", &tipo);
    getchar();
    switch(tipo){
        case 1:
            ClientePf* pCli = (ClientePf*) malloc(sizeof(ClientePf));
            ClientePf* newCli = (ClientePf*) malloc(sizeof(ClientePf));
            pCli = getCliPf(nome);
            if(pCli != NULL){
                printf("\n    É este o cliente que deseja editar? (S para confirmar) ");
                scanf("%c", &resp);
                getchar();
                if(resp == 's' || resp == 'S'){
                    fCli = fopen("./data/clientesPf.dat", "r+b");
                    while(fread(newCli, sizeof(ClientePf), 1, fCli)){
                        if(strcmp(pCli->nome,newCli->nome) == 0 && newCli->status == 'c'){
                            printf("\n    Informe o nome do cliente: "); 
                            scanf("%14[^\n]", newCli->nome);
                            getchar();
                            int valTel = 0, valEmail = 0;
                            do{
                                printf("\n    Informe o telefone de contato do cliente: ");   
                                scanf("%11[^\n]", newCli->tel);
                                valTel = validaTel(newCli->tel);
                                if(!valTel) printf("\n    O telefone informado é inválido! Tente novamente!");
                                getchar();
                            }while(!valTel);
                            do{
                                printf("\n    Informe o email do cliente: ");  
                                scanf("%29[^\n]", newCli->email);
                                valEmail = validaEmail(newCli->email);
                                if(!valEmail) printf("\n    O Email informado é inválido! Tente novamente!");
                                getchar();
                            }while(!valEmail);
                            fseek(fCli, (-1) * sizeof(ClientePf), SEEK_CUR);
                            fwrite(newCli, sizeof(ClientePf), 1, fCli);
                        }
                    }
                    fclose(fCli);
                    free(pCli);
                    free(newCli);
                }else{
                    printf("\n    Operação cancelada! ");
                    getchar();
                    return;
                }
                break;
            }
        case 2:
            ClientePj* pCliPj = (ClientePj*) malloc(sizeof(ClientePj));
            ClientePj* newCliPj = (ClientePj*) malloc(sizeof(ClientePj));
            pCliPj = getCliPj(nome);
            if(pCliPj != NULL){
                printf("\n    É este o cliente que deseja editar? (S para confirmar) ");
                scanf("%c", &resp);
                getchar();
                if(resp == 's' || resp == 'S'){
                    fCli = fopen("./data/clientesPj.dat", "r+b");
                    while(fread(newCliPj, sizeof(ClientePj), 1, fCli)){
                        if(strcmp(pCliPj->nome,newCliPj->nome) == 0 && newCliPj->status == 'c'){
                            printf("\n    Informe o nome do cliente: "); 
                            scanf("%14[^\n]", newCliPj->nome);
                            getchar();
                            int valTel = 0, valEmail = 0;
                            do{
                                printf("\n    Informe o telefone de contato do cliente: ");   
                                scanf("%11[^\n]", newCliPj->tel);
                                valTel = validaTel(newCliPj->tel);
                                if(!valTel) printf("\n    O telefone informado é inválido! Tente novamente!");
                                getchar();
                            }while(!valTel);
                            do{
                                printf("\n    Informe o email do cliente: ");  
                                scanf("%29[^\n]", newCliPj->email);
                                valEmail = validaEmail(newCliPj->email);
                                if(!valEmail) printf("\n    O Email informado é inválido! Tente novamente!");
                                getchar();
                            }while(!valEmail);
                            fseek(fCli, (-1) * sizeof(ClientePj), SEEK_CUR);
                            fwrite(newCliPj, sizeof(ClientePj), 1, fCli);
                        }
                    }
                    fclose(fCli);
                    free(pCliPj);
                    free(newCliPj);
                }else{
                    printf("\n    Operação cancelada! ");
                    getchar();
                    return;
                }
            }
    }
    printf("\n     Cliente editado com sucesso!");
    getchar();
}
