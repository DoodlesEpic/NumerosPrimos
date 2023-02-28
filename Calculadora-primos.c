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

#include <argp.h>
#include <fcntl.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "Calculadora-primos.h"

const char *argp_program_version = "numeros_primos 1.1";
const char *argp_program_bug_address = "<moraes.eduardo@proton.me>";
static char doc[] = " Calculadora de números primos em C, saiba quais números "
                    "primos existem até certo número.";
static char args_doc[] = "";
static struct argp_option options[] = {
    {"live", 'l', 0, 0,
     "Printar valores em tempo real ao invés de esperar cálculo acabar.", 0},
    {0}};

struct argumentos {
  bool modoLive;
};

static error_t parse_opt(int key, char *arg, struct argp_state *state) {
  struct argumentos *argumentos = state->input;
  switch (key) {
  case 'l':
    argumentos->modoLive = true;
    break;
  case ARGP_KEY_ARG:
    return 0;
  default:
    return ARGP_ERR_UNKNOWN;
  }
  return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc, 0, 0, 0};

int main(int argc, char *argv[]) {
  // Alterar locale para suportar UTF-8
  setlocale(LC_ALL, "pt_BR.UTF-8");

  struct argumentos argumentos;

  argumentos.modoLive = false;

  argp_parse(&argp, argc, argv, 0, 0, &argumentos);

  wprintf(L"Vamos calcular todos os números primos até um certo valor, insira "
          L"o número: ");
  unsigned int numero;
  scanf("%u", &numero);

  //
  // MODO LIVE: Os números são printados ao serem calculados, e não são salvos
  // em um arquivo
  //
  if (argumentos.modoLive) {
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
    bool *numerosPrimos = (bool *)malloc(sizeof(bool) * numero);
    if (!numerosPrimos) {
      wprintf(L"Não foi possível alocar o array de números primos. Saindo.");
      return 1;
    }

    // Calcular todos os números primos até o numero
    for (unsigned int i = 2; i < numero; i++) {
      numerosPrimos[i] = ePrimo(i);
    }

    // Abrir arquivo para salvar os números calculados
    FILE *fptr = fopen("numeros_primos.txt", "w");
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
bool ePrimo(unsigned int numero) {
  for (unsigned int i = 2; i < numero; i++) {
    if (numero % i == 0) {
      return false;
    }
  }
  return true;
}
