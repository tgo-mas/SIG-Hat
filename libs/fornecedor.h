
////    Estrutura dos dados do Fornecedor

typedef struct{
    char razao[30];
    char cnpj[14];
    char tel[12];
    char email[30];
} Fornecedor;

////    Assinatura das Funções 

void menuFornec(void);
void cadFornec(void);
void addFornec(char* nome, char* cnpj, char* tel, char* email);
void exibFornec(Fornecedor* fornec);
void listFornec(void);
void gravaFornec(Fornecedor fornec);
void getDadosFornec(void);
