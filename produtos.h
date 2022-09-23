
//// Dados dos produtos
int ids[10] = {1, 2, 3};
int estoq[10] = {4, 5, 0};
char modelos[10][15] = {"bone", "chapeu", "viseira"};
char marcas[10][15] = {"Nike", "artesanal", "adidas"};
float precos[10] = {40.00, 15.0, 120.0};

//// Assinatura das Funções
void clrScrn(void);
int findIndex(int ids[10]);
void listProds(void);
void exibProd(int index);
void cadastrarProd(void);
void findProd(void);
void exibirID(int id);
void buscaModelo(char modelo[15]);
void remover(int id);
int menuEstoque(void);
