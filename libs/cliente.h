
//// Estruturas referentes a Cliente

typedef struct{
    char cpf[12];
    char nome[20];
    char email[30];
    char tel[11];
    float totalComprado;
    int numCompras;
    char status;    //   'a' - ativo; 'r' - removido.
} Cliente;

//// Assinatura das funções

void listClientes(void);
void findCliente(void);
void exibCliente(char* cpf);
void deleteCliente(void);
void relatVendas(int type);
void cadCliente(char* cpf);
int addCliente(char cpf[12], char nome[20], char email[30], char tel[12]);
int verifCliente(char cpf[12]);
char* getNomeAt(int index);
int menuCliente(void);
void gravaCliente(Cliente* cli);
void getDadosCli(void);
