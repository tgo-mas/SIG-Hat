#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "hat.h"

//// validaTec(int tecido) -> Verifica se o tecido informado é válido e informa ao usuário, além de retornar 0 em caso de invalidez.

int validaTec(int tecido){
    switch(tecido){
        case 1:
            printf("\n  Tecido selecionado: Poliéster.");
            return 5;
        case 2:
            printf("\n  Tecido selecionado: Algodão.");
            return 7;
        default:
            printf("\n  Erro: O tecido escolhido não consta nas opções!");
            return 0;
    }
}

int validaBord(int bordado){
    switch(bordado){
        case 1:
            printf("\n  Estilo de bordado: Simples.");
            return 5;
        case 2:
            printf("\n  Estilo de bordado: Moderado.");
            return 7;
        case 3:
            printf("\n  Estilo de bordado: Complexo.");
            return 9;
        default: 
            printf("\n  Erro: O estilo selecionado não consta nas opções!");
            return 0;
    }
}

int validaMod(int modelo){
   switch(modelo){
        case 1:
            printf("\n Modelo escolhido: Aba curva.");
            return 5;
        case 2:
            printf("\n  Modelo escolhido: Aba reta.");
            return 6;
        case 3:
            printf("\n  Modelo escolhido: Polo.");
            return 7;
        default:
            printf("\n  Erro: O modelo selecionado não consta nas opções!");
            return 0;
    }
}

int validaFecho(int fecho){
   switch(fecho){
        case 1:
            printf("\n Fecho escolhido: Plástico.");
            return 8;
        case 2:
            printf("\n  Fecho escolhido: Velcro.");
            return 10;
        case 3:
            printf("\n  Fecho escolhido: Tecido.");
            return 12;
        default:
            printf("\n  Erro: O fecho selecionado não consta nas opções!");
            return 0;
    }
}
