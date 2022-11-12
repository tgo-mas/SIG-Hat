#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validacoes.h"
#include "hat.h"

//// validaTec(tecido) -> Verifica se o tecido informado é válido e informa ao usuário, além de retornar o incremento do preço unitário.

int validaTec(int tecido){
    switch(tecido){
        case 1:
            printf("\n  Tecido selecionado: Poliéster.");
            return 5;
        case 2:
            printf("\n  Tecido selecionado: Algodão.");
            return 7;
        default:
            printf("\n  Erro: O tecido escolhido não consta nas opções!");
            return 0;
    }
}

//// validaBord(bordado) -> Verifica se o bordado informado é válido e informa ao usuário, além de retornar o incremento do preço unitário.

int validaBord(int bordado){
    switch(bordado){
        case 1:
            printf("\n  Estilo de bordado: Simples.");
            return 5;
        case 2:
            printf("\n  Estilo de bordado: Moderado.");
            return 7;
        case 3:
            printf("\n  Estilo de bordado: Complexo.");
            return 9;
        default: 
            printf("\n  Erro: O estilo selecionado não consta nas opções!");
            return 0;
    }
}

//// validaMod(modelo) -> Verifica se o tipo de aba informado é válido e informa ao usuário, além de retornar o incremento do preço unitário.

int validaMod(int modelo){
   switch(modelo){
        case 1:
            printf("\n  Modelo escolhido: Aba curva.");
            return 5;
        case 2:
            printf("\n  Modelo escolhido: Aba reta.");
            return 6;
        case 3:
            printf("\n  Modelo escolhido: Polo.");
            return 7;
        default:
            printf("\n  Erro: O modelo selecionado não consta nas opções!");
            return 0;
    }
}

//// validaFecho(fecho) -> Verifica se o fecho informado é válido e informa ao usuário, além de retornar o incremento do preço unitário.

int validaFecho(int fecho){
   switch(fecho){
        case 1:
            printf("\n  Fecho escolhido: Plástico.");
            return 8;
        case 2:
            printf("\n  Fecho escolhido: Velcro.");
            return 10;
        case 3:
            printf("\n  Fecho escolhido: Tecido.");
            return 12;
        default:
            printf("\n  Erro: O fecho selecionado não consta nas opções!");
            return 0;
    }
}

//// validaCpf() -> Retorna 0 para um CPF inválido e 1 para válido.

int validaCpf(char* cpf){     /////    Função original por @eduardoedson, com aprimorações derivadas do código de @kugland (GitHub)
    int i, j, digito1 = 0, digito2 = 0;
    if(strlen(cpf) != 11){
        return 0;
    }else{
        for (i = 1; i < 11 && cpf[i] == cpf[0]; i++){    //// Verifica se os números são iguais.
            if (i == 10){
                return 0;}}
        for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--){       ////    Multiplica os números de 10 a 2 e soma os resultados dentro de digito1
            digito1 += (cpf[i]-48) * j;}
        digito1 %= 11;
        if(digito1 < 2){
            digito1 = 0;
        }else{
            digito1 = 11 - digito1;}
        if((cpf[9]-48) != digito1){
            return 0;      ////   Se o digito 1 não for o mesmo que o da validação CPF é inválido
        }else{
            for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--)      ////   Multiplica os números de 11 a 2 e soma os resultados dentro de digito2
                    digito2 += (cpf[i]-48) * j;
            digito2 %= 11;
            if(digito2 < 2){
                digito2 = 0;
            }else{
                digito2 = 11 - digito2;}
            if((cpf[10]-48) != digito2)
                return 0;       ////   Se o digito 2 não for o mesmo que o da validação CPF é inválido
        }
    }
    return 1;
}      

//// validaCnpj() -> Retorna 0 para um CNPJ inválido e 1 para válido.

int validaCnpj(char* cnpj){
    int sm, i, r, num, mult;
    char dig13, dig14;
    if(strlen(cnpj) != 14) return 0;

    // calcula o 1o. digito verificador do CNPJ
    sm = 0; mult = 2;
    for (i=11; i>=0; i--) {
        num = cnpj[i] - 48;	// transforma o caracter '0' no inteiro 0
        sm = sm + (num * mult);
        mult = mult + 1;
        if (mult == 10) mult = 2;
    }
    r = sm % 11;
    if ((r == 0) || (r == 1))
        dig13 = '0';
    else
        dig13 = (11 - r) + 48;

    // calcula o 2o. digito verificador do CNPJ
    sm = 0; mult = 2;
    for (i=12; i>=0; i--) {
        num = cnpj[i] - 48;
        sm = sm + (num * mult);
        mult = mult + 1;
        if (mult == 10)
        mult = 2;
    }
    r = sm % 11;
    if ((r == 0) || (r == 1))
        dig14 = '0';
    else
        dig14 = (11 - r) + 48;

    // compara os dígitos calculados com os dígitos informados
    if ((dig13 == cnpj[12]) && (dig14 == cnpj[13]))
        return 1;
    else
        return 0;
}

//// isPForPJ(cpfCnpj) -> Retorna 0 para invalidez, 1 para pessoa física (CPF) e 2 para pessoa jur. (CNPJ);

int isPForPJ(char* cpfCnpj){
    if(validaCnpj(cpfCnpj) == 0 && validaCpf(cpfCnpj) == 1){
        return 1;
    }else if(validaCnpj(cpfCnpj) == 1 && validaCpf(cpfCnpj) == 0){
        return 2;
    }else{
        return 0;
    }
}

int validaEmail(char* email){
    char ant, atual;   /// ant - anterior; variáveis usadas para verificar repetição de pontos.
    int i, arroba, contPonto;

    for(i = 0; i < strlen(email); i++){
        atual = email[i];
        if(atual == '@'){
            arroba = 1;
        }else if(arroba == 1){
            if(ant == '.' && atual == '.'){
                return 0;
            }else if(atual == '.'){
                contPonto++;
            }
        }
        ant = atual;
    }
    if(arroba == 0 || contPonto == 0){
        return 0;
    }
    return 1;
}

int validaTel(char *telChar){
    int tel[11];

    if(strlen(telChar) != 11){
        return 0;
    }

    for(int i = 0; i < strlen(telChar); i++){
        tel[i] = (int) telChar[i] - 48;
    }

    if(tel[0] != 1 && tel[0] != 4 && tel[0] != 6 && tel[0] != 8 && tel[0] != 9){
        return 0;
    }else{
        if(tel[1] < 1 && tel[1] > 9){
            return 0;
        }
    }            ///// Verificação dos DDD's existentes

    if(tel[2] == 9){         //// se o número inicia em 9, é um celular.
        if(tel[3] == 0){
            return 0;
        }else{
            for(int i = 3; i < 7; i++){
                if(tel[i] < 0 || tel[i] > 9){
                    return 0;
                }
            }
        }
    }else if(tel[2] >= 2 && tel[2] <= 8){         //// se não inicia em 9, é um tel. fixo. (número entre 2 e 8)
        for(int i = 3; i < 6; i++){
            if(tel[i] < 0 || tel[i] > 9){
                return 0;
            }
        }
    }
    
    return 1;

}