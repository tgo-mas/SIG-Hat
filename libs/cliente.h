
//// Estruturas referentes a Cliente

typedef struct{
    int cpf[11];
    char nome[20];
    char email[30];
    int tel[11];
    float totalComprado;
    int numCompras;
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
