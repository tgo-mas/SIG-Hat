#include <stdio.h>
#include <stdlib.h>
#include "hat.h"
#include "validacoes.h"
#include "menus.h"
#include "cabs.h"

//// menuHat() -> Chama a função telaMenuHat() e inicia algum processo escolhido.

void menuHat(void){
    int opcao;
    do{
        telaMenuHat();
        printf("\n  Selecione uma opção: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao){
            case 2: 
                addHat();
            case 0:
                break;
            default:
                printf("\n  Selecione uma opção válida!");
                getchar();
    }}while(opcao != 0);
}

//// addHat() -> Cadastra um novo modelo de boné.

void addHat(void){
    cabecAddHat();
    char conf;
    do{    
        Hat* pHat;
        pHat = (Hat*) malloc(sizeof(Hat));
        int precoUnit = 0;
        do{
            printf("\n    Escolha o tipo de tecido:\n      1 - Poliéster;\n      2 - Algodão."); // 5 e 7
            scanf("%d", &pHat->tecido);
            getchar();
            precoUnit += validaTec(pHat->tecido);
        }while(!precoUnit);
        do{
            printf("\n    Nossos estilos possuem três categorias de bordado:\n      1 - Simples;\n      2 - Moderado;\n      3 - Complexo.");  // 5, 7 e 9
            scanf("%d", &pHat->pers);
            getchar();
            precoUnit += validaBord(pHat->pers);
        }while(precoUnit < 10);
        do{
            printf("\n    Os bonés possuem diferentes modelagens:\n      1 - Aba curva;\n      2 - Aba reta;\n      3 - Boné polo.");   // 5, 6 e 7
            scanf("%d", &pHat->model);
            getchar();
            precoUnit += validaMod(pHat->model);
        }while(precoUnit < 15);
        do{
            printf("\n    O fecho é a parte de trás que regula o tamanho do boné. Selecione:\n      1 - Plástico;\n      2 - Velcro;\n      3 - Tecido.");   //8, 10, 12.
            scanf("%d", &pHat->fecho);
            getchar();
            precoUnit += validaFecho(pHat->fecho);
        }while(precoUnit < 23);
        printf("\n\n    O preço unitário do modelo escolhido será R$ %d,00. Deseja confirmar?", precoUnit);
        scanf("%c", &conf);
        getchar();
        pHat->precoUnit = precoUnit;
        gravaHat(pHat);
        free(pHat);
    }while(!(conf == 's' || conf == 'S'));
}

//// gravaHat(pHat) -> Grava as informações de pHat em arquivo.

void gravaHat(Hat* pHat){
    FILE* fHat;
    fHat = fopen("./data/hats.dat", "ab");
    if(fHat == NULL){
        printf("\n    FATAL: Arquivo hats.dat não encontrado.");
        exit(1);
    }
    fwrite(pHat, sizeof(Hat), 1, fHat);
    fclose(fHat);
    printf("\n    Modelo de Boné salvo com sucesso!");
    getchar();
}

