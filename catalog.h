#include <stdio.h>

void listProd(void){
  
}

void cadastrarProd(void){
  
}

void findProd(void){
  
}

void deleteProd(void){
  
}

int catalog(void){
  int opcao;
  printf("\n");
  printf("#####################################################\n");
  printf("##                                                 ##\n");
  printf("##        = = = = = S I G - H a t = = = = =        ##\n");
  printf("##                                                 ##\n");
  printf("##       = = = = = C A T A L O G O = = = = =       ##\n");
  printf("##                                                 ##\n");
  printf("##              1 - Listar produtos                ##\n");
  printf("##             2 - Cadastrar produto               ##\n");
  printf("##             3 - Pesquisar produto               ##\n");
  printf("##              4 - Excluir produto                ##\n");
  printf("##                    0 - Sair                     ##\n");
  printf("##                                                 ##\n");
  printf("#####################################################\n");
  printf("\n");

  scanf("%d", &opcao);

  switch(opcao){
    case 1:
      listProd();
      break;
    case 2:
      cadastrarProd();
      break;
    case 3:
      findProd();
      break;
    case 4:
      deleteProd();
      break;
    case 0:
      return 0;
    default:
      printf("Escolha uma opção válida! Tente novamente. \n");
      catalog();
      break;
  }
  return opcao;
}
