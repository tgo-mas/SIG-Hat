#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
            case 1:
                listarHats();
                break;
            case 2: 
                addHat();
                break;
            case 3:
                buscaHat();
                break;
            case 4:
                apagaHat();
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
    printf("\n    Quase pronto! Escolha um nome para seu modelo: ");
    scanf("%14[^\n]", pHat->nome);
    getchar();
    pHat->idHat = getProxIdHat();
    printf("\n\n    O preço unitário do modelo escolhido será R$ %d,00.", precoUnit);
    getchar();
    pHat->precoUnit = precoUnit;
    pHat->status = 'c'; 
    gravaHat(pHat);
    free(pHat);
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

//// exibeHat(pHat) -> Exibe as informações do modelo passado por parâmetro.

void exibeHat(Hat* pHat){
    printf("\n#####################################################\n");
    printf("\n  Nome do modelo: %s", pHat->nome);
    printf("\n  Número do modelo: %d", pHat->idHat);
    validaTec(pHat->tecido);
    validaBord(pHat->pers);
    validaMod(pHat->model);
    validaFecho(pHat->fecho);
    printf("\n  Preço unitário: R$ %d,00", pHat->precoUnit);
    printf("\n\n#####################################################");
}

//// listarHats() -> Lista as informações dos modelos de bonés cadastrados.

void listarHats(){
    cabecListaHats();
    FILE* fHat;
    fHat = fopen("./data/hats.dat", "rb");
    if(fHat == NULL){
        printf("\n    FATAL: Arquivo hats.dat não encontrado.");
        exit(1);
    }
    Hat* pHat = (Hat*) malloc(sizeof(Hat));
    while(fread(pHat, sizeof(Hat), 1, fHat)){
        if(pHat->status == 'c') exibeHat(pHat);
    }
    getchar();
    fclose(fHat);
    free(pHat);
}

//// getProxIdHat() -> Retorna inteiro correspondente ao id do próximo boné a ser cadastrado, retorna 0 em caso de erro.

int getProxIdHat(void){
    FILE* fHat;
    int id = 0;
    fHat = fopen("./data/hats.dat", "rb");
    if(fHat == NULL){
        printf("\n    FATAL: Arquivo hats.dat não encontrado.");
        exit(1);
    }
    Hat* pHat = (Hat*) malloc(sizeof(Hat));
    while(fread(pHat, sizeof(Hat), 1, fHat) || feof(fHat)){
        if(pHat == NULL){
            id = 1;
        }else if(feof(fHat)){
            id = pHat->idHat + 1;
            break;
        }
    }
    fclose(fHat);
    free(pHat);
    return id;
}

//// buscaHat() -> Inicia o processo de buscar o modelo escolhido pelo nome.

Hat* buscaHat(void){
    FILE* fHat;
    Hat* pHat = (Hat*) malloc(sizeof(Hat));
    char nome[15];
    int achou = 0; 
    printf("\n    Digite o nome do modelo desejado: ");
    scanf("%14[^\n]", nome);
    getchar();
    fHat = fopen("./data/hats.dat", "rb");
    while(fread(pHat, sizeof(Hat), 1, fHat) && !achou){
        if(strcmp(pHat->nome, nome) == 0 && pHat->status == 'c'){
            achou = 1;
            exibeHat(pHat);
            printf("\n    A busca trouxe este resultado.");
            getchar();
            fclose(fHat);
            return pHat;
        }
    }
    printf("\n    Modelo de boné não encontrado!");
    getchar();
    fclose(fHat);
    free(pHat);
    return NULL;
}

//// apagaHat() -> Inicia o processo de apagar o modelo de boné escolhido (exclusão apenas lógica).

void apagaHat(void){
    Hat* pHat = buscaHat();
    FILE* fHat;
    fHat = fopen("./data/hats.dat", "r+b");
    if(fHat == NULL){
        printf("\n    FATAL: Arquivo hats.dat não encontrado!");
        exit(1);
    }
    char ctz;
    if(pHat != NULL){
        printf("\n    Tem certeza que deseja excluir este modelo? (s para confirmar) ");
        scanf("%c", &ctz);
        getchar();
        if(ctz == 's' || ctz == 'S'){
            pHat->status = 'x';
            fseek(fHat, (-1) * sizeof(Hat), SEEK_CUR);
            fwrite(pHat, sizeof(Hat), 1, fHat);
            printf("\n    Modelo excluído com sucesso!");
            getchar();
        }else{
            printf("\n    Operação cancelada!");
            getchar();
        }
    }
    fclose(fHat);
    free(pHat);
}

