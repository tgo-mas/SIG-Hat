#include <stdio.h>
#include <stdlib.h>

//////////////////
///
///  SIG-Hat
///
///  Desenvolvido por: Thomas Almeida
///  Projeto da disciplina de Programação
///  Docente: Flavius Gorgônio
///  Universidade Federal do Rio Grande do Norte
///
//////////////////


void infos(void){
	
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##   Desenvolvido por: Thomas Almeida              ##\n");
    printf("##   E-mail: thomas.almeida.109@ufrn.br            ##\n");
    printf("##   Redes sociais: @tgomas.asf                    ##\n");
    printf("##   Git: https://github.com/tgo-mas/SIG-Hat.git   ##\n");
    printf("##                                                 ##\n");
	printf("##   Projeto da disciplina de Programacao          ##\n");
	printf("##   Docente: Flavius Gorgonio                     ##\n");
	printf("##   Universidade Federal do Rio Grande do Norte   ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
	
}

void menu(void){
	
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##        1 - Catalogo de Bones e Chapeus          ##\n");
    printf("##            2 - Controle de Estoque              ##\n");
    printf("##            3 - Painel de Controle               ##\n");
    printf("##                                                 ##\n");
    printf("##                                                 ##\n");
    printf("##       9 - Informacoes sobre o programa          ##\n");
    printf("##                    0 - Sair                     ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
	
}

int main(int argc, char *argv[]) {
	
	menu();
	
	int opcao;
	printf("Escolha uma opcao: ");
	scanf("%d", &opcao);
	
	switch(opcao){
		case 9:
			infos();
			break;
	}
	
	return 0;
}

