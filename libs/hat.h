
////    Estrutura da variável hat:

typedef struct {
    int idHat;
    char nome[15];
    int tecido;
    int pers;
    int model;
    int fecho;
    int precoUnit;
} Hat;

//// Assinatura das funções:

void addHat(void);
void menuHat(void);
void gravaHat(Hat* pHat);
void exibeHat(Hat* pHat);
void listarHats(void);
int getProxIdHat(void);
