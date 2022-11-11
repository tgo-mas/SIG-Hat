#include <stdio.h>
#include <stdlib.h>
#include "menus.h"

//// cabecAddHat() => Exibe o cabeçalho da tela de cadastrar boné.
void cabecAddHat(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##       = C A D A S T R A R   M O D E L O =       ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
}

//// cabecListaHats() -> Exibe o cabeçalho da tela de lista de bonés.
void cabecListaHats(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##       = L I S T A   D E   M O D E L O S =       ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
}
