#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "menus.h"

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

}
