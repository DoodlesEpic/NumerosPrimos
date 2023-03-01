/*
MIT License

Copyright (c) 2020 Eduardo

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <getopt.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "Calculadora-primos.h"

static const char *version = "numeros_primos 1.2";
static void help(const char *name) {
  wprintf(L"Uso: %s [OPÇÃO] [NÚMERO]\n", name);
  wprintf(L"Calculadora de números primos em C, saiba quais números primos "
          L"existem até certo número.\n\n");

  wprintf(L"Opções:\n");
  wprintf(L"  -l, --live     Printar valores em tempo real ao invés de esperar "
          "cálculo acabar.\n");
  wprintf(L"  -?, --help     Mostra essa ajuda.\n");
  wprintf(L"  -v, --version  Mostra a versão do programa.\n\n");

  wprintf(L"Reporte bugs para <moraes.eduardo@proton.me>.\n");
}

static const struct option options[] = {
    {"live", no_argument, NULL, 'l'},
    {"help", no_argument, NULL, '?'},
    {"version", no_argument, NULL, 'v'},
};

int main(int argc, char *argv[]) {
  // Alterar locale para suportar UTF-8
  setlocale(LC_ALL, "pt_BR.UTF-8");

  // Inicializar argumentos passados por linha de comando
  bool modoLive = false;
  for (int c = 0; (c = getopt_long(argc, argv, "vl?", options, NULL)) != -1;) {
    switch (c) {
    case 'l':
      modoLive = true;
      break;
    case '?':
      help(argv[0]);
      return 0;
    case 'v':
      wprintf(L"%s\n", version);
      return 0;
    default:
      fwprintf(stderr, L"Opção inválida: -%c\n", optopt);
      return 1;
    }
  }

  if (optind >= argc) {
    fwprintf(stderr, L"Número faltando.\n");
    wprintf(L"Uso: %s [OPÇÃO] [NÚMERO]\n", argv[0]);
    return 1;
  }

  const unsigned int numero = atoi(argv[optind]);

  // Pegar o número até onde os números primos serão calculados
  if (numero <= 1) {
    fprintf(stderr, "O número deve ser maior que 1.\n");
    return 1;
  }

  //
  // MODO LIVE: Os números são printados ao serem calculados, e não são salvos
  // em um arquivo
  //
  if (modoLive) {
    for (unsigned int i = 2; i <= numero; i++) {
      if (ePrimo(i)) {
        wprintf(L"O número %u é primo\n", i);
      }
    }
  }

  //
  // MODO PADRÃO: Os números são printados após todos serem calculados, e são
  // salvos em um arquivo
  //
  else {
    // Alocar array para salvar os números primos
    bool *const restrict numerosPrimos = (bool *)malloc(sizeof(bool) * numero);
    if (!numerosPrimos) {
      wprintf(L"Não foi possível alocar o array de números primos. Saindo.");
      return 1;
    }

    // Calcular todos os números primos até o numero
    for (unsigned int i = 2; i < numero; i++) {
      numerosPrimos[i] = ePrimo(i);
    }

    // Abrir arquivo para salvar os números calculados
    FILE *const restrict fptr = fopen("numeros_primos.txt", "w");
    if (!fptr) {
      wprintf(L"Não foi possível abrir o arquivo numeros_primos.txt. Saindo.");
      return 1;
    }

    // Printar e salvar todos os números primos
    fwprintf(fptr, L"Os seguintes números são primos:\n");
    wprintf(L"Os seguintes números são primos:\n");
    for (unsigned int i = 2; i < numero; i++) {
      if (numerosPrimos[i]) {
        wprintf(L"%u, ", i);
        fwprintf(fptr, L"%u, ", i);
      }
    }

    // Salvar arquivo com os números primos
    fclose(fptr);

    // Liberar memória do array
    free(numerosPrimos);
  }

  wprintf(L"Calculados!\n");

  return 0;
}

// Retorna true caso numero seja primo, false caso não seja
bool ePrimo(const unsigned int numero) {
  for (unsigned int i = 2; i < numero; i++) {
    if (numero % i == 0) {
      return false;
    }
  }
  return true;
}
