#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "encomenda.h"
#include "relatorios.h"
#include "menus.h"

//// menuRelat() -> Exibe a tela de menu do módulo de relatórios.

void menuRelat(void){
    int opcao;
    do{
        telaMenuRelat();
        printf("\n    Selecione uma opção: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
                listaMes();
                break;
            case 0:
                break;
            default:
                printf("\n    Selecione uma opção válida! Tente novamente. ");
                getchar();
        }
    }while(opcao != 0);
}

//// listaMes() -> Exibe uma lista das encomendas feitas nos últimos 30 dias.

void listaMes(void){
    FILE* fEnc;
    fEnc = fopen("./data/encomendas.dat", "rb");
    if(fEnc == NULL){
        printf("\n    FATAL: O arquivo Encomendas.dat não foi encontrado! ");
        exit(1);
    }
    time_t timer;
    timer = time(NULL);
    Encomenda* pEnc = (Encomenda*) malloc(sizeof(Encomenda));
    while(fread(pEnc, sizeof(Encomenda), 1, fEnc)){
        time_t timeEnc;
        timeEnc = mktime(&pEnc->dataReg);
        if((difftime(timer, timeEnc) <= 2592000)){
            exibeEnc(pEnc);
        }
    }
    getchar();
    free(pEnc);
    fclose(fEnc);
}
