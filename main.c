#include <stdio.h>
#include <stdlib.h>
#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#endif
#include <string.h>
#include "./libs/hat.h"
#include "./libs/menus.h"
#include "./libs/cliente.h"
#include "./libs/encomenda.h"
#include "./libs/relatorios.h"

int main(void){
    int opcao = 0;
    do{
        menuPrincipal();
        printf("    Selecione uma opção: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 1:
                menuHat();
                break;
            case 2:
                menuCliente();
                break;
            case 3:
                menuEncomenda();
                break;
            case 4:
                menuRelat();
                break;
            case 9:
                infosProjeto();
                getchar();
                break;
            case 0:
                break;
            default:
                printf("\n  Selecione uma opção válida! Tente novamente. ");
                getchar();
                break;
        }
    }while(opcao != 0);
}