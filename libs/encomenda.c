#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "encomenda.h"

//// menuEncomenda() -> Exibe o menu do módulo de encomendas e pede uma opção ao usuário.

void menuEncomenda(void){
    int opcao;
    do{
        telaMenuEncomenda();
        printf('\n    Selecione uma opção: ');
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
    printf("\n    Primeiro informe o CPF ou CNPJ do cliente que está realizando o pedido: ");
    scanf("%14[^\n]", pEnc->idCliente);
    getchar();
    int pfpj = isPForPJ(pEnc->idCliente);
    switch(pfpj){
        
    }
}
