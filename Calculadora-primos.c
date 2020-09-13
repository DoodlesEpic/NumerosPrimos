#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

bool ePrimo(unsigned int numero);
bool numerosPrimos[sizeof(unsigned int)];

int main(int argc)
{
    wprintf(L"Memoria alocada!\n");

    // Ao receber argumentos o programa inicia no modo live
    if (argc > 1)
    {
        wprintf(L"Iniciado no modo de debug ao vivo!\n");
    }

    // Alterar modo de output de stdout para suportar UTF-8
    _setmode(_fileno(stdout), 0x00040000);
    wprintf(L"Modo de texto definido para UTF-8!\n");

    wprintf(L"Vamos calcular todos os números primos até um certo valor, insira o número: ");
    unsigned int numero;
    scanf("%u", &numero);

    //
    // MODO LIVE: Os números são printados ao serem calculados, e não são salvos em um arquivo
    //
    if (argc > 1)
    {
        for (unsigned int i = 0; i <= numero; i++)
        {
            if (ePrimo(i))
            {
                wprintf(L"O número %u é primo\n", i);
            }
        }
    }

    //
    // MODO PADRÃO: Os números são printados após todos serem calculados, e são salvos em um arquivo
    //
    if (argc <= 1)
    {
        // Calcular todos os números primos até o numero
        for (unsigned int i = 0; i <= numero; i++)
        {
            numerosPrimos[i] = ePrimo(i);
        }

        // Abrir arquivo para salvar os números calculados
        FILE *fptr = _wfopen(L"números_primos.txt", L"w,ccs=UTF-8");
        if (!fptr)
        {
            wprintf(L"Não foi possível abrir o arquivo números_primos.txt. Saindo.");
            return 1;
        }

        // Printar e salvar todos os números primos
        fwprintf(fptr, L"Os seguintes números são primos:\n");
        wprintf(L"Os seguintes números são primos:\n");
        for (unsigned int i = 0; i < numero; i++)
        {
            if (numerosPrimos[i])
            {
                wprintf(L"%u, ", i);
                fwprintf(fptr, L"%u, ", i);
            }
        }

        // Salvar arquivo com os números primos
        fclose(fptr);
    }

    wprintf(L"Calculados!\n");

    return 0;
}

// Retorna true caso numero seja primo, false caso não seja
bool ePrimo(unsigned int numero)
{
    for (unsigned int i = 2; i < numero; i++)
    {
        if (numero % i == 0)
        {
            return false;
        }
    }
    return true;
}