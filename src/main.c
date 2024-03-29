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

#include "bruteforce.h"
#include "eratostenes.h"
#include "main.h"

static const char *version = "numeros_primos 2.0";
static void help(const char *name) {
  printf("Calculadora de números primos em C, saiba quais números primos "
         "existem até certo número.\n\n");

  printf("Exemplos de uso: \n");
  printf("%s 1000                  Calcular todos primos até 1000\n", name);
  printf("%s -m brute 1000         Calcular usando bruteforce\n", name);
  printf("%s -m live 1000          Exibir primos imediatamente\n\n", name);

  printf("Opções:\n");
  printf("  -m, --metodo <metodo>  Escolher estratégia de cálculo.\n");
  printf("  -h, --help             Mostra essa ajuda.\n");
  printf("  -v, --version          Mostra a versão do programa.\n\n");

  printf("Reporte bugs para <moraes.eduardo@proton.me>.\n");
}

static const struct option options[] = {
    {"metodo", required_argument, NULL, 'm'},
    {"help", no_argument, NULL, '?'},
    {"version", no_argument, NULL, 'v'},
};

enum modo {
  LIVE,
  BRUTEFORCE,
  ERATOSTENES,
};

int main(int argc, char *argv[]) {
  setlocale(LC_ALL, "pt_BR.UTF-8");

  int option_index = 0;
  enum modo modo = ERATOSTENES;

  for (int c = 0;
       (c = getopt_long(argc, argv, "m:v:h", options, &option_index)) != -1;) {
    switch (c) {
    case 'm':
      if (optarg) {
        if (strcmp(optarg, "live") == 0)
          modo = LIVE;

        if (strcmp(optarg, "brute") == 0)
          modo = BRUTEFORCE;

        if (strcmp(optarg, "eratostenes") == 0)
          modo = ERATOSTENES;
      }

      break;
    case 'h':
      help(argv[0]);
      return 0;
    case 'v':
      printf("%s\n", version);
      return 0;
    default:
      fprintf(stderr, "Opção inválida: -%c\n", optopt);
      return 1;
    }
  }

  if (optind >= argc) {
    fprintf(stderr, "Erro: Número faltando.\n\n");
    printf("Exemplo correto:\n %s 1000  \n", argv[0]);
    return 1;
  }

  // Pegar o número até onde os números primos serão calculados
  const unsigned long numero = strtoul(argv[optind], NULL, 10);
  if (numero <= 1) {
    fprintf(stderr, "O número deve ser maior que 1.\n");
    return 1;
  }

  switch (modo) {
  case LIVE:
    live(numero);
    break;
  case BRUTEFORCE:
    bruteforce(numero);
    break;
  case ERATOSTENES:
    eratostenes(numero);
    break;
  default:
    fprintf(stderr, "Modo inválido.\n");
    return 1;
  }

  printf("\n");
  return 0;
}
