#include <stdio.h>
#include "produtos.h"
#include "interface.h"

//// menuPrincipal() -> Exibe a tela do menu principal do sistema;

void menuPrincipal(void){
	clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##        1 - Catálogo de Bonés e Chapéus          ##\n");
    printf("##            2 - Controle de Estoque              ##\n");
    printf("##            3 - Painel de Controle               ##\n");
    printf("##                                                 ##\n");
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
    printf("##                                                 ##\n");
    printf("##   Projeto da disciplina de Programação          ##\n");
    printf("##   Docente: Flavius Gorgônio                     ##\n");
    printf("##   Universidade Federal do Rio Grande do Norte   ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
}

//// menuCatalogo() -> Exibe o menu do módulo de catálogo (vendas).

void menuCatalogo(void){
	clrScrn();
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##       = = = = = C A T Á L O G O = = = = =       ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    listProds();
    printf("##                                                 ##\n");
    printf("##                1 - Iniciar venda                ##\n");
    printf("##                                                 ##\n");
    printf("##                    0 - Sair                     ##\n");
    printf("##                                                 ##\n");
    printf("#####################################################\n");
    printf("\n");
}

//// cabecListaClientes() -> Exibe o cabeçalho da tela de listar clientes.

void cabecListaClientes(void){
	clrScrn();
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##      = L I S T A   D E   C L I E N T E S =      ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
}

//// cabecFindClientes() -> Exibe o cabeçalho da tela de pesquisar cliente.

void cabecFindClientes(void){
	clrScrn();
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##      = P E S Q U I S A   C L I E N T E S =      ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
}

//// telaMenuClientes() -> Exibe a tela de menu do módulo de clientes.

void telaMenuClientes(void){
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
	printf("##               4 - Remover cliente               ##\n");
	printf("##          5 - Gerar relatório de vendas          ##\n");
	printf("##                                                 ##\n");
	printf("##                     0 - Sair                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
}

//// menuControle() -> Exibe a tela principal do painel de controle de clientes e fornecedores.

void menuControle(void){
	clrScrn();
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##     = P A I N E L   D E   C O N T R O L E =     ##\n");
	printf("##                                                 ##\n");
	printf("##              1 - Menu de Clientes               ##\n");
	printf("##            2 - Menu de Fornecedores             ##\n");
	printf("##                                                 ##\n");
	printf("##                     0 - Sair                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
}

//// telaMenuEstoque() -> Exibe a tela do menu de controle de estoque.

void telaMenuEstoque(void){
	clrScrn();
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##     = C O N T R O L E  D E  E S T O Q U E =     ##\n");
	printf("##                                                 ##\n");
	printf("##              1 - Conferir estoque               ##\n");
  	printf("##             2 - Cadastrar produto               ##\n");
  	printf("##             3 - Pesquisar produto               ##\n");
  	printf("##              4 - Excluir produto                ##\n");
	printf("##             5 - Registrar entradas              ##\n");
	printf("##                                                 ##\n");
	printf("##                   0 - Voltar                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
}

//// telaRemovProduto() -> Exibe o cabeçalho da tela de remover produto.

void telaRemovProduto(void){
	clrScrn();
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##        = R E M O V E R   P R O D U T O =        ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
}

//// telaBuscaProduto() -> Exibe o cabeçalho da tela de buscar produto.

void telaBuscaProduto(void){
	clrScrn();
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##      = B U S C A   P O R   P R O D U T O =      ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
}

//// telaAddProduto() -> Exibe o cabeçalho da tela de cadastrar produto

void telaAddProduto(void){
	clrScrn();
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##    = C A D A S T R O   D E   P R O D U T O =    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
}

//// telaMenuFornecedor() -> Exibe a tela de menu de Fornecedor.

void telaMenuFornecedor(void){
	clrScrn();
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##            = C O N T R O L E   D E =            ##\n");
	printf("##           = F O R N E C E D O R E S =           ##\n");
	printf("##                                                 ##\n");
	printf("##       1 - Listar fornecedores cadastrados       ##\n");
	printf("##            2 - Cadastrar fornecedor             ##\n");
	printf("##            3 - Pesquisar fornecedor             ##\n");
	printf("##             4 - Remover fornecedor              ##\n");
	printf("##                                                 ##\n");
	printf("##                     0 - Sair                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
}
