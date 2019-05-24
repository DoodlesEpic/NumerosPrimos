#include <stdio.h>
#include <fcntl.h>
#include <io.h>

#ifndef __cplusplus
typedef unsigned char bool;
static const bool false = 0;
static const bool true = 1;
#endif

bool ePrimo(unsigned int numero);
bool numerosPrimos[sizeof(unsigned int)];

int main(int argc)
{
    wprintf(L"Memoria alocada!\n");

    if (argc > 1) { 
        wprintf(L"Iniciado no modo de debug ao vivo!\n");
    }

    _setmode(_fileno(stdout), 0x00040000);
    wprintf(L"Modo de texto definido para UTF-8!\n");

    wprintf(L"Vamos calcular todos os números primos até um certo valor, insira o número: ");
    unsigned int numero;
    scanf("%u", &numero);

    if (argc > 1) {
        for (unsigned int i = 0; i <= numero; i++) {
            if (ePrimo(i) == true) {
                wprintf(L"O número %u é primo\n", i);
            }
        }
    } 
    
    if (argc <= 1){
        for (unsigned int i = 0; i <= numero; i++) {
            if (ePrimo(i) == true) {
                numerosPrimos[i] = true;
            } else {
                numerosPrimos[i] = false;
            }
        }

        FILE* fptr = _wfopen(L"números_primos.txt", L"w");
        fwprintf(fptr, L"Os seguintes números são primos:\n");
        wprintf(L"Os seguintes números são primos:\n");
        for (unsigned int i = 0; i < numero; i++) {
            if (numerosPrimos[i] == true) {
                wprintf(L"%u, ", i);
                fprintf(fptr, "%u, ", i);
            }
        }
        fclose(fptr);
    }

    wprintf(L"Calculados!\n");

    return 0;
}

bool ePrimo(unsigned int numero) {
    for (unsigned int i = 2; i < numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}