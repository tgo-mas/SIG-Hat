#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "menus.h"

//// menuPrincipal() -> Exibe a tela do menu principal do sistema;

void menuPrincipal(void){
    clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##      1 - Gerenciar modelos personalizados;      ##\n");
    printf("##             2 - Gerenciar clientes;             ##\n");
    printf("##            3 - Gerenciar encomendas;            ##\n");
    printf("##              4 - Gerar relatórios;              ##\n");
    printf("##                                                 ##\n");
    printf("##       9 - Informações sobre o programa          ##\n");
    printf("##                    0 - Sair                     ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
}

//// infosProjeto() -> Exibe a tela de informações sobre o projeto.

void infosProjeto(void){  
	clrScrn();     
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##   Desenvolvido por: Thomas Almeida              ##\n");
    printf("##   E-mail: thomas.almeida.109@ufrn.br            ##\n");
    printf("##   Redes sociais: @tgomas.asf                    ##\n");
    printf("##   Git: https://github.com/tgo-mas/SIG-Hat.git   ##\n");
    printf("##   Versão atual do sistema: 0.1.0                ##\n");
    printf("##                                                 ##\n");
    printf("##   Projeto da disciplina de Programação          ##\n");
    printf("##   Docente: Flavius Gorgônio                     ##\n");
    printf("##   Universidade Federal do Rio Grande do Norte   ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
}

//// telaMenuHat(void) -> Exibe a tela de menu do módulo Hat.

void telaMenuHat(void){
    clrScrn();
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##     = C O N T R O L E  D E  M O D E L O S =     ##\n");
	printf("##                                                 ##\n");
	printf("##              1 - Listar modelos                 ##\n");
  	printf("##             2 - Cadastrar modelo                ##\n");
  	printf("##             3 - Pesquisar modelo                ##\n");
  	printf("##              4 - Excluir modelo                 ##\n");
	printf("##                                                 ##\n");
	printf("##                   0 - Voltar                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
}

//// telaMenuCliente() -> Exibe a tela de menu principal do módulo cliente;

void telaMenuCliente(void){
    clrScrn();
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##   = C O N T R O L E   D E   C L I E N T E S =   ##\n");
	printf("##                                                 ##\n");
	printf("##         1 - Listar clientes cadastrados         ##\n");
	printf("##              2 - Cadastrar cliente              ##\n");
	printf("##              3 - Pesquisar cliente              ##\n");
	printf("##               4 - Editar cliente                ##\n");
	printf("##               5 - Remover cliente               ##\n");
	printf("##                                                 ##\n");
	printf("##                     0 - Sair                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
}

void telaMenuEncomenda(void){
    clrScrn();
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##    = C O N T R O L E   D E   P E D I D O S =    ##\n");
	printf("##                                                 ##\n");
	printf("##              1 - Listar encomendas              ##\n");
	printf("##             2 - Cadastrar encomenda             ##\n");
	printf("##             3 - Pesquisar encomenda             ##\n");
	printf("##              4 - Editar encomenda               ##\n");
	printf("##        5 - Listar encomendas em produção        ##\n");
	printf("##          6 - Alt. status de encomenda           ##\n");
	printf("##             7 - Cancelar encomenda              ##\n");
	printf("##                                                 ##\n");
	printf("##                     0 - Sair                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
}

//// telaMenuRelat() -> Exibe a tela do menu do módulo de relatórios.

void telaMenuRelat(void){
    clrScrn();
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##             = R E L A T Ó R I O S =             ##\n");
	printf("##                                                 ##\n");
	printf("##      1 - Encomendas feitas no último mês        ##\n");
	printf("##    2 - Encomendas para entrega no pŕoximo mês   ##\n");
	printf("##           3 - Entregas para esta semana         ##\n");
	printf("##           4 - Relatório de vendas do mês        ##\n");
	printf("##                                                 ##\n");
	printf("##                     0 - Sair                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
}

//// clrScrn() -> Limpa a tela do console
void clrScrn(void){
	system("clear || cls");
}
