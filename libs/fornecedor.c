#include <stdio.h>
#include "fornecedor.h"
#include "interface.h"

////     menuFornec() -> Exibe a tela principal do módulo de fornecedor.

void menuFornec(void){
    int opcao;
    telaMenuFornecedor();
    printf("\n    Selecione uma opção: ");
    scanf("%d", &opcao);
    switch(opcao){
        case 0:
            break;
        default:
            getchar();
            printf("\n    Selecione uma opção válida!");
            getchar();
            break;
    }

}
