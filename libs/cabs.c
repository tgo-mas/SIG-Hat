#include <stdio.h>
#include <stdlib.h>
#include "cabs.h"
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
}

//// cabecBuscaHat() -> Exibe o cabeçalho da tela de pesquisar modelo de boné.
void cabecBuscaHat(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##       = P E S Q U I S A R   M O D E L O =       ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
}

//// cabecApagaHat() -> Exibe o cabeçalho da tela de apagar modelo de boné.
void cabecApagaHat(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##          = A P A G A R   M O D E L O =          ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
}

//// cabecAddCliente() => Exibe o cabeçalho da tela de cadastrar cliente.
void cabecAddCliente(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##      = C A D A S T R A R   C L I E N T E =      ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
}

//// cabListaPf() -> Exibe o cabeçalho da lista de clientes Pessoa Fisica.
void cabListaPf(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##      = L I S T A   D E   C L I E N T E S =      ##\n");
    printf("##            P e s s o a   F í s i c a            ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
}

//// cabListaPj() -> Exibe o cabeçalho da lista de clientes Pessoa Jurídica.
void cabListaPj(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##      = L I S T A   D E   C L I E N T E S =      ##\n");
    printf("##          P e s s o a   J u r í d i c a          ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
}

//// cabecBuscaPf() => Exibe o cabeçalho da tela de cadastrar cliente.
void cabecBuscaPf(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##    = P E S Q U I S A   D E   C L I E N T E =    ##\n");
    printf("##                 (Pessoa Física)                 ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
}

//// cabecBuscaPj() => Exibe o cabeçalho da tela de cadastrar cliente.
void cabecBuscaPj(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##    = P E S Q U I S A   D E   C L I E N T E =    ##\n");
    printf("##                (Pessoa Jurídica)                ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
}

//// cabecDeleteCliente() => Exibe o cabeçalho da tela de cadastrar cliente.
void cabecDeleteCliente(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##    = E X C L U S Ã O   D E   C L I E N T E =    ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
}

//// cabCadEnc() -> Exibe o cabeçalho de cadastro de encomenda.
void cabCadEnc(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##               = C A D A S T R O =               ##\n");
    printf("##                       d e                       ##\n");
    printf("##              = E N C O M E N D A =              ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
}

//// cabListaEnc() -> Exibe o cabeçalho da lista de Encomendas.
void cabListaEnc(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##       = L I S T A   D E   P E D I D O S =       ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
}

//// cabBuscaEnc() -> Exibe o cabeçalho da busca de Encomendas.
void cabBuscaEnc(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##       = B U S C A   D E   P E D I D O S =       ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
}

//// cabEditaEnc() => Exibe o cabeçalho da tela de editar encomenda.
void cabEditaEnc(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##       = E D I T A R   E N C O M E N D A =       ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
}

//// cabEditaEnc() => Exibe o cabeçalho da tela de editar encomenda.
void cabCancEnc(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##     = C A N C E L A R   E N C O M E N D A =     ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
}
