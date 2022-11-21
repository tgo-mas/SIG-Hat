#include <time.h>

//// Definição das estruturas Time e Data:

typedef struct tm Time;

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

//// Definição da estrutura Encomenda:

typedef struct enc Encomenda;

struct enc {
    int idEnc;
    char idCliente[15]; // Pode ser cpf ou cnpj.
    char nomeModelo[15];
    int qtd;
    double prcFinal;
    Data dataReg;
    Data dataLimite;
    int mat[4];    // Trata-se da estimação dos materiais necessários. [tecido, linha, botoes/abas, viés];
    char status;   // 'e' - espera; 'p' - produção; 'c' - concluida; 'x' - cancelada.
    // Encomenda* prox;
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
void listaProducao(void);
Encomenda buscaEnc(void);
void editEnc(void);
void cancelarEnc(void);
void altStatus(void);
