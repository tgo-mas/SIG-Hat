#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
            case 2:
                listaProxMes();
                break;
            case 3:
                listaSemana();
                break;
            case 4:
                relatVendasMes();
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
    Time tm;
    tm = *localtime(&timer);
    Data data;
    data.dia = tm.tm_mday;
    data.mes = tm.tm_mon + 1;
    data.ano = tm.tm_year + 1900;
    Encomenda* pEnc = (Encomenda*) malloc(sizeof(Encomenda));
    int achou = 0;
    while(fread(pEnc, sizeof(Encomenda), 1, fEnc)){
        if((difdias(pEnc->dataReg, data) <= 30)){
            exibeEnc(pEnc);
            achou++;
        }
    }
    if(!achou){
        printf("\n    Não há encomenda com o filtro especificado! ");
    }
    getchar();
    free(pEnc);
    fclose(fEnc);
}

//// listaProxMes() -> Exibe uma lista das encomendas que possuem data de entrega para o mês seguinte

void listaProxMes(void){
    FILE* fEnc;
    fEnc = fopen("./data/encomendas.dat", "rb");
    if(fEnc == NULL){
        printf("\n    FATAL: O arquivo Encomendas.dat não foi encontrado! ");
        exit(1);
    }
    time_t timer = time(NULL);
    Time tm;
    tm = *localtime(&timer);
    Data now;
    now.dia = tm.tm_mday;
    now.mes = tm.tm_mon + 1;
    now.ano = tm.tm_year + 1900;
    Encomenda* pEnc = (Encomenda*) malloc(sizeof(Encomenda));
    int achou = 0;
    while(fread(pEnc, sizeof(Encomenda), 1, fEnc)){
        if(difdias(now,pEnc->dataLimite) <= 30){
            exibeEnc(pEnc);
            achou++;
        }
    }
    if(!achou){
        printf("\n    Não há encomenda com o filtro especificado! ");
    }
    getchar();
    free(pEnc);
    fclose(fEnc);
}

//// listaSemana() -> Exibe uma lista das encomendas que possuem data de entrega para até 8 dias a frente.

void listaSemana(void){
    FILE* fEnc;
    fEnc = fopen("./data/encomendas.dat", "rb");
    if(fEnc == NULL){
        printf("\n    FATAL: O arquivo Encomendas.dat não foi encontrado! ");
        exit(1);
    }
    time_t timer = time(NULL);
    Time tm;
    tm = *localtime(&timer);
    Data now;
    now.dia = tm.tm_mday;
    now.mes = tm.tm_mon + 1;
    now.ano = tm.tm_year + 1900;
    Encomenda* pEnc = (Encomenda*) malloc(sizeof(Encomenda));
    int achou = 0;
    while(fread(pEnc, sizeof(Encomenda), 1, fEnc)){
        if(difdias(now,pEnc->dataLimite) <= 8){
            exibeEnc(pEnc);
            achou++;
        }
    }
    if(!achou){
        printf("\n    Não há encomenda com o filtro especificado! ");
    }
    getchar();
    free(pEnc);
    fclose(fEnc);
}

//// relatVendasMes() -> Exibe um relatório das vendas do último mês (encomendas que foram concluídas).

void relatVendasMes(void){
    FILE* fEnc;
    fEnc = fopen("./data/encomendas.dat", "rb");
    if(fEnc == NULL){
        printf("\n    FATAL: Arquivo encomendas.dat não encontrado!");
        exit(1);
    }
    printf("\n    Encomendas concluídas há até 30 dias: \n");
    double total;
    Encomenda* pEnc = (Encomenda*) malloc(sizeof(Encomenda));
    while(fread(pEnc, sizeof(Encomenda), 1, fEnc)){
        if(pEnc->status == 'c'){
            exibEnc(pEnc);
            total += pEnc->prcFinal;
        }
    }
    printf("\n    Total vendido no último mês: R$ %.2f\n", total);
    getchar();
}

//// difdias(antes, depois) -> Retorna a diferença de dias entre as duas datas passadas por parêmetro.

int difdias(Data antes, Data depois){
    int dias = 0;
    if(antes.ano == depois.ano){
        if(antes.mes == depois.mes){
            dias = depois.dia - antes.dia;
        }else if(antes.mes == depois.mes - 1){
            dias = (30 - antes.dia) + depois.dia;
        }else if(antes.mes < depois.mes - 1){
            dias = (30 - antes.dia) + depois.dia;
            int m = depois.mes - antes.mes - 1;
            dias += m * 30;
        }else{
            return -1;
        }
    }else{
        dias = 30 - antes.dia;
        for(int m = antes.mes; m != depois.mes; m++){
            dias += 30;
            if(m == 12) m = 1;
        }
        dias += depois.dia;
    }
    return dias;
}
