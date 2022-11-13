
//// Definição das estruturas para cliente de pessoa física ou jurídica.

typedef struct{
    char cpf[12];
    char nome[15];
    char tel[12];
    char email[30];
    char status;
} ClientePf;

typedef struct{
    char cnpj[15];
    char nome[15];
    char tel[12];
    char email[30];
    char status;
} ClientePj;

//// Assinaturas das funções do módulo Cliente.

void menuCliente(void);
void addCliente(void);
void gravaCliPf(ClientePf* pCli);
void gravaCliPj(ClientePj* pCli);
void exibeCliPf(ClientePf* pCli);
void exibeCliPj(ClientePj* pCli);
void listarClientes(void);
void buscaCliente(void);
ClientePf* getCliPf(char* nome);
ClientePj* getCliPj(char* nome);
void deleteCliente(void);
