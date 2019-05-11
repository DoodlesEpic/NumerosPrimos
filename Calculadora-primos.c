#include <stdio.h>
#include <fcntl.h>
#include <io.h>

#ifndef __cplusplus
typedef unsigned char bool;
static const bool false = 0;
static const bool true = 1;
#endif

bool ePrimo(int numero);
bool numerosPrimos[sizeof(int) * 2000000];

int main(int argc)
{
    wprintf(L"Memoria alocada!\n");

    if (argc > 1) { 
        wprintf(L"Iniciado no modo de debug ao vivo!\n");
    }

    _setmode(_fileno(stdout), 0x00040000);
    wprintf(L"Modo de texto definido para UTF-8!\n");

    wprintf(L"Vamos calcular todos os números primos até um certo valor, insira o número: ");
    int numero;
    scanf("%d", &numero);

    if (argc > 1) {
        for (int i = 0; i <= numero; i++) {
            if (ePrimo(i) == true) {
                wprintf(L"O número %d é primo\n", i);
            }
        }
    } 
    
    if (argc <= 1){
        for (int i = 0; i <= numero; i++) {
            if (ePrimo(i) == true) {
                numerosPrimos[i] = true;
            } else {
                numerosPrimos[i] = false;
            }
        }

        wprintf(L"Os seguintes números são primos:\n");
        for (int i = 0; i < numero; i++) {
            if (numerosPrimos[i] == true) {
                wprintf(L"%d, ", i);
            }
        }
    }

    wprintf(L"Calculados!\n");

    return 0;
}

bool ePrimo(int numero) {
    for (int i = 2; i < numero; i++) {
        if (numero % i == 0) {
            return false;
        }
    }
    return true;
}