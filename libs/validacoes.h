//// Assinaturas das funções de validação do sistema. Todas retornam 1 para válido e 0 para inválido, a não ser as exceções.

int validaTec(int tecido); 
int validaBord(int bordado); 
int validaMod(int modelo); 
int validaFecho(int fecho); 
int validaCpf(char* cpf);
int validaCnpj(char* cnpj);
int isPForPJ(char* cpfCnpj);    // Retorna 1 para pessoa física (CPF válido), 2 para pessoa jur. (CNPJ válido) e 0 para ambos inválidos.
int validaEmail(char* email);
int validaTel(char* tel);

