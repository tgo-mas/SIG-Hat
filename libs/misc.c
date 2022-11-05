#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "misc.h"
#ifdef __linux__
	#include <unistd.h>
#elif _WIN32
	#include <windows.h>
#else

#endif

//// clrScrn() -> Limpa a tela do console
void clrScrn(void){
	#ifdef __linux__
		system("clear");	
	#elif _WIN32
		system("cls");
	#else
	
	#endif	
}

//// getIndex(ids) -> Encontra o proximo item vazio na lista de ids passada. Retorna -1 em caso de erro.
int getIndex(int* ids){
	int i;
	for(i = 0; i < 10; i++){
		if(ids[i] == 0){
			return i;
		}
	}
	return -1;
}

////  convertToInt(str) -> Converte a string passada por parâmetro para um vetor de inteiros, cujo endereço também é passado.

void convertToInt(char* str, int* result){
    for(int i = 0; i < strlen(str) - 1; i++){
        result[i] = (int) (str[i] - 48);
    }
}
