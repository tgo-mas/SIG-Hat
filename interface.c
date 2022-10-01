#include <stdio.h>
#include "produtos.h"
#include "interface.h"

//// menuPrincipal() -> Exibe a tela do menu principal do sistema;

void menuPrincipal(void){
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

//// infosProjeto() -> Exibe a tela de informações sobre o projeto.

void infosProjeto(void){       
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

//// menuCatalogo() -> Exibe o menu do módulo de catálogo (vendas).

void menuCatalogo(void){
    printf("\n");
    printf("#####################################################\n");
    printf("##                                                 ##\n");
    printf("##        = = = = = S I G - H a t = = = = =        ##\n");
    printf("##                                                 ##\n");
    printf("##       = = = = = C A T A L O G O = = = = =       ##\n");
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
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##   = C O N T R O L E   D E   C L I E N T E S =   ##\n");
	printf("##                                                 ##\n");
	printf("##         1 - Listar clientes cadastrados         ##\n");
	printf("##              2 - Pesquisar cliente              ##\n");
	printf("##               3 - Remover cliente               ##\n");
	printf("##          4 - Gerar relatório de vendas          ##\n");
	printf("##                                                 ##\n");
	printf("##                     0 - Sair                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
}

//// menuControle() -> Exibe a tela principal do painel de controle de clientes e fornecedores.

void menuControle(void){
    printf("\n");
	printf("#####################################################\n");
	printf("##                                                 ##\n");
	printf("##        = = = = = S I G - H a t = = = = =        ##\n");
	printf("##                                                 ##\n");
	printf("##   = C O N T R O L E   D E   C L I E N T E S =   ##\n");
	printf("##                                                 ##\n");
	printf("##         1 - Listar clientes cadastrados         ##\n");
	printf("##              2 - Pesquisar cliente              ##\n");
	printf("##               3 - Remover cliente               ##\n");
	printf("##          4 - Gerar relatório de vendas          ##\n");
	printf("##                                                 ##\n");
	printf("##                     0 - Sair                    ##\n");
	printf("##                                                 ##\n");
	printf("#####################################################\n");
	printf("\n");
}

//// telaMenuEstoque() -> Exibe a tela do menu de controle de estoque.

void telaMenuEstoque(void){
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
