#include <time.h>

//// Definição da estrutura Time:

typedef struct tm Time;

//// Definição da estrutura Encomenda:

typedef struct enc Encomenda;

struct enc {
    int idEnc;
    char idCliente[15]; // Pode ser cpf ou cnpj.
    char nomeModelo[15];
    int qtd;
    double prcFinal;
    Time dataReg;
    Time dataLimite;
    int mat[4];    // Trata-se da estimação dos materiais necessários. [tecido, linha, botoes/abas, viés];
    char status;   // 'e' - espera; 'p' - produção; 'c' - concluida; 'x' - cancelada.
    Encomenda* prox;
};

void menuEncomenda(void);
void addEnc(void);
Encomenda getDadosEnc(void);
int getLastEnc(void);
void printTime(Time* time);
void getMat(int* mat, int qtd);
void gravaEnc(Encomenda* pEnc);
void exibeEnc(Encomenda* pEnc);
void exibEnc(Encomenda* pEnc);
void listarEncomendas(void);
void printLista(Encomenda* lista);
Encomenda buscaEnc(void);
void editEnc(void);
void cancelarEnc(void);
Encomenda* getListabyId(void);
