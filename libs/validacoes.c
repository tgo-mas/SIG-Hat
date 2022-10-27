#include "validacoes.h"
#include <stdio.h>
#include <string.h>
#include <inttypes.h>

///// validaCPF(cpf) -> Retorna 0 para um cpf inválido e 1 para válido.

int validaCPF(char* cpf){
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
}      /////     Funções original por @eduardoedson, com aprimorações derivadas do código de @kugland (GitHub)

//// validaEmail(email) -> Retorna 0 para um formato de email inválido e 1 para válido.

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

////  validaTel(telefone) -> Retorna 1 para um telefone válido e 0 para inválido.

int validaTel(int *tel){
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

