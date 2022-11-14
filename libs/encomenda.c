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
                addEnc();
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
                printf("\n\n    O pedido está sendo realizado pelo cliente %s, confirmar? (S para confirmar) ", pCli->nome);
                scanf("%c", &resp);
                getchar();
                free(pCli);
                break;
            case 2:
                ClientePj* pCliPj = getClibyCnpj(pEnc->idCliente);
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
        time_t* timer = (time_t*) malloc(sizeof(time_t));
        time(timer);
        Time* now = localtime(timer);
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
        free(timer);
        getMat(pEnc->mat, pEnc->qtd);
        pEnc->status = 'e';
        gravaEnc(pEnc);
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
