#include <time.h>

//// Definição da estrutura Encomenda:

typedef struct tm Time;

typedef struct {
    char idCliente[15]; // Pode ser cpf ou cnpj.
    char nomeModelo[15];
    int qtd;
    double prcFinal;
    Time dataReg;
    Time dataLimite;
    int mat[4];    // Trata-se da estimação dos materiais necessários. [tecido, linha, botoes/abas, viés];
    char status;   // 'e' - espera; 'p' - produção; 'c' - concluida; 'x' - cancelada.
} Encomenda;

void menuEncomenda(void);
void addEnc(void);
void getMat(int* mat, int qtd);
void printTime(Time* time);
void gravaEnc(Encomenda* pEnc);