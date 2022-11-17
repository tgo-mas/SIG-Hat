#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "encomenda.h"
#include "cliente.h"
#include "hat.h"
#include "menus.h"
#include "validacoes.h"

//// menuEncomenda() -> Exibe o menu do módulo de encomendas e pede uma opção ao usuário.

void menuEncomenda(void){
    int opcao;
    do{
        telaMenuEncomenda();
        printf("\n    Selecione uma opção: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
                listarEncomendas();
                break;
            case 2:
                addEnc();
                break;
            case 3:
                buscaEnc();
                break;
            case 0:
                break;
            default:
                printf("\n    Selecione uma opção válida! Tente novamente. ");
                getchar();
        }
    }while(opcao != 0);
}

//// addEnc() -> Inicia o processo de cadastro de uma nova encomenda.

void addEnc(void){
    Encomenda* pEnc = (Encomenda*) malloc(sizeof(Encomenda));
    int pfpj = 0;
    char resp;
    do{
        printf("\n    Primeiro informe o CPF ou CNPJ do cliente que está realizando o pedido: ");
        scanf("%14[^\n]", pEnc->idCliente);
        getchar();
        pfpj = isPForPJ(pEnc->idCliente);
        switch(pfpj){
            case 1:
                ClientePf* pCli = getClibyCpf(pEnc->idCliente);
                exibeCliPf(pCli);
                printf("\n\n    O pedido está sendo realizado pelo cliente %s, confirmar? (S para confirmar) ", pCli->nome);
                scanf("%c", &resp);
                getchar();
                free(pCli);
                break;
            case 2:
                ClientePj* pCliPj = getClibyCnpj(pEnc->idCliente);
                exibeCliPj(pCliPj);
                printf("\n\n    O pedido está sendo realizado pelo cliente %s, confirmar? (S para confirmar) ", pCliPj->nome);
                scanf("%c", &resp);
                getchar();
                free(pCliPj);
                break;
            case 0:
                printf("\n    O CPF ou CNPJ informado é inválido! Tente novamente. ");
                getchar();
        }
    }while(!pfpj);
    if(resp == 's' || resp == 'S'){ 
        Hat* pHat = (Hat*) malloc(sizeof(Hat));
        do{
            printf("\n    Agora informe o nome do modelo do boné a ser fabricado: ");
            scanf("%14[^\n]", pEnc->nomeModelo);
            getchar();
            pHat = getHatbyName(pEnc->nomeModelo);
            printf("\n\n    É esse o modelo que deseja fabricar? (S para confirmar) ");
            scanf("%c", &resp);
            getchar();
        }while(pHat == NULL || !(resp == 's' || resp == 'S'));
        qtdInv: printf("\n    Informe a quantidade de bonés que serão produzidos: ");
        scanf("%d", &pEnc->qtd);
        getchar();
        if(pEnc->qtd < 30 && pEnc->qtd > 0){
            pEnc->prcFinal = pEnc->qtd * pHat->precoUnit;
        }else if(pEnc->qtd >= 30 && pEnc->qtd < 300){
            pEnc->prcFinal = (pEnc->qtd * pHat->precoUnit) - ((pEnc->qtd * 0.001) * (pEnc->qtd * pHat->precoUnit));
        }else if(pEnc->qtd >=300){
            pEnc->prcFinal = (pEnc->qtd * pHat->precoUnit) - (0.3 * (pEnc->qtd * pHat->precoUnit));
        }else{
            printf("\n    Quantidade inválida! Tente novamente. ");
            getchar();
            goto qtdInv;
        }
        time_t timer;
        timer = time(NULL);
        Time* now = localtime(&timer);
        Time* dataEnt = (Time*) malloc(sizeof(Time));
        pEnc->dataReg = *now;
        printf("\n    Informe agora a data de entrega da encomenda: ");
        printf("\n      Dia: ");
        scanf("%d", &dataEnt->tm_mday);
        getchar();
        printf("\n      Mês: ");
        scanf("%d", &dataEnt->tm_mon);
        getchar();
        printf("\n      Ano: ");
        scanf("%d", &dataEnt->tm_year);
        getchar();
        printf("\n    Data de entrega: ");
        printTime(dataEnt);
        getchar();
        pEnc->dataLimite = *dataEnt;
        free(dataEnt);
        getMat(pEnc->mat, pEnc->qtd);
        pEnc->status = 'e';
        gravaEnc(pEnc);
        exibeEnc(pEnc);
        getchar();
        free(pEnc);
    }
}

//// printTime(time) -> Exibe na tela a data da variável time passada por parâmetro.

void printTime(Time* time){
    printf("%d/%d/%d", time->tm_mday, time->tm_mon, time->tm_year);
}

//// getMat(mat, qtd) -> Altera os valores armaz. em mat de acordo com a qtd informada, calculando as estimativas de materiais.

void getMat(int* mat, int qtd){
    mat[0] = (int) (qtd / 2);
    mat[1] = (int) (qtd / 25);
    mat[2] = (int) (qtd);
    mat[3] = (int) (qtd / 15);
}

//// gravaEnc(pEnc) -> Grava as informações da encomenda em arquivo.

void gravaEnc(Encomenda* pEnc){
    FILE* fEnc;
    fEnc = fopen("./data/encomendas.dat", "ab");
    if(fEnc == NULL){
        printf("\n    FATAL: Arquivo encomendas.dat não encontrado! ");
        exit(1);
    }
    fwrite(pEnc, sizeof(Encomenda), 1, fEnc);
    fclose(fEnc);
}

//// exibeEnc(pEnc) -> Exibe as informações da encomenda passada por parâmetro na tela.

void exibeEnc(Encomenda* pEnc){
    int pfpj = isPForPJ(pEnc->idCliente);
    printf("\n#####################################################\n");
    switch(pfpj){
        case 1:
            printf("\n  Nome do cliente: %s", getClibyCpf(pEnc->idCliente)->nome);
            break;
        case 2:
            printf("\n  Nome do cliente: %s", getClibyCnpj(pEnc->idCliente)->nome);
            break;
    }
    printf("\n  Modelo escolhido: %s", pEnc->nomeModelo);
    printf("\n  Quantidade: %d", pEnc->qtd);
    printf("\n  Valor do pedido: R$ %.2f", pEnc->prcFinal);
    printf("\n  Data de registro: ");
    printTime(&pEnc->dataReg);
    printf("\n  Data limite: ");
    printTime(&pEnc->dataLimite);
    printf("\n  Materiais estimados: \n");
    printf("    %d m² do tecido do modelo escolhido;", pEnc->mat[0]);
    printf("\n    %d rolos de linha;", pEnc->mat[1]);
    printf("\n    %d botões e abas;", pEnc->mat[2]);
    printf("\n    %d rolos de viés.\n", pEnc->mat[3]);
    switch(pEnc->status){
        case 'e':
            printf("\n  Status do pedido: Em espera.");
            break;
        case 'p':
            printf("\n  Status do pedido: Em produção.");
            break;
        case 'c':
            printf("\n  Status do pedido: Entregue.");
            break;
        case 'x':
            printf("\n  Status do pedido: Cancelado.");
            break;
    }
    printf("\n\n#####################################################");
}

//// exibEnc(pEnc) -> Exibe a encomenda de forma resumida.

void exibEnc(Encomenda* pEnc){
    int pfpj = isPForPJ(pEnc->idCliente);
    printf("\n#####################################################\n");
    printf("  Nº do pedido: %d", pEnc->idEnc);
    switch(pfpj){
        case 1:
            printf("\n  Nome do cliente: %s", getClibyCpf(pEnc->idCliente)->nome);
            break;
        case 2:
            printf("\n  Nome do cliente: %s", getClibyCnpj(pEnc->idCliente)->nome);
            break;
    }
    printf("\n  Modelo escolhido: %s", pEnc->nomeModelo);
    printf("\n  Quantidade: %d", pEnc->qtd);
    printf("\n  Valor do pedido: R$ %.2f", pEnc->prcFinal);
    printf("\n  Data de registro: ");
    printTime(&pEnc->dataReg);
    printf("\n  Data limite: ");
    printTime(&pEnc->dataLimite);
    printf("\n#####################################################\n\n");
}

//// listarEncomendas() -> Exibe todas as encomendas, exceto as canceladas.

void listarEncomendas(void){
    FILE* fEnc;
    Encomenda* pEnc = (Encomenda*) malloc(sizeof(Encomenda));
    fEnc = fopen("./data/encomendas.dat", "rb");
    if(fEnc == NULL){
        printf("\n    FATAL: Arquivo encomendas.dat não encontrado!");
        exit(1);
    }
    while(fread(pEnc, sizeof(Encomenda), 1, fEnc)){
        if(pEnc->status == 'e' || pEnc->status == 'p'){
            exibeEnc(pEnc);
        }
    }
    fclose(fEnc);
    free(pEnc);
    getchar();
}

//// buscaEnc() -> Inicia o processo de buscar encomendas, exibindo todas as encomendas ativas do cliente informado.

Encomenda* buscaEnc(void){
    char nome[15];
    printf("\n    Primeiro, digite o nome do cliente que fez a encomenda desejada: ");
    scanf("%14[^\n]", nome);
    getchar();
    FILE* fEnc;
    Encomenda* pEnc = (Encomenda*) malloc(sizeof(Encomenda));
    int achou = 0, opcao = 0;
    fEnc = fopen("./data/encomendas.dat", "rb");
    if(fEnc == NULL){
        printf("\n    FATAL: Arquivo encomendas.dat não encontrado!");
        exit(1);
    }
    while(fread(pEnc, sizeof(Encomenda), 1, fEnc)){
        int pfpj = isPForPJ(pEnc->idCliente);
        switch(pfpj){
            case 1:
                if(strcmp(getClibyCpf(pEnc->idCliente)->nome, nome) == 0 && (pEnc->status == 'c' || pEnc->status == 'e' || pEnc->status == 'p')){
                    exibEnc(pEnc);
                    achou++;
                }
                break;
            case 2:
                if(strcmp(getClibyCnpj(pEnc->idCliente)->nome, nome) == 0 && (pEnc->status == 'c' || pEnc->status == 'e' || pEnc->status == 'p')){
                    exibEnc(pEnc);
                    achou++;
                }
        }
    }
    Encomenda encontradas[achou];
    rewind(fEnc);
    for(int i = 0; i < achou; i++){
        fread(pEnc, sizeof(Encomenda), 1, fEnc);
        int pfpj = isPForPJ(pEnc->idCliente);
        switch(pfpj){
            case 1:
                if(strcmp(getClibyCpf(pEnc->idCliente)->nome, nome) == 0 && (pEnc->status == 'c' || pEnc->status == 'e' || pEnc->status == 'p')){
                    pEnc->idEnc = (i + 1);
                    encontradas[i] = *pEnc;
                }
                break;
            case 2:
                if(strcmp(getClibyCnpj(pEnc->idCliente)->nome, nome) == 0 && (pEnc->status == 'c' || pEnc->status == 'e' || pEnc->status == 'p')){
                    pEnc->idEnc = (i + 1);
                    encontradas[i] = *pEnc;
                }
        }
    }
    if(!achou){
        printf("\n    Não foi encontrada nenhuma encomenda para este cliente!");
    }else{
        do{
            printf("\n    Escolha uma encomenda para ampliar (0 para pular): ");
            scanf("%d", &opcao);
            getchar();
            if(opcao != 0){
                if(opcao <= achou){
                    exibeEnc(&encontradas[opcao - 1]);
                }else{
                    printf("\n    Opção inválida! Tente novamente. ");
                }
            }}while(opcao != 0);
    }
    fclose(fEnc);
    if(pEnc != NULL){
        return pEnc;
    }else{
        free(pEnc);
        return NULL;
    }
}
