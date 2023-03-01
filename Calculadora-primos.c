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

#include "Calculadora-primos.h"

static const char *version = "numeros_primos 1.3";
static void help(const char *name) {
  printf("Uso: %s [OPÇÃO] [NÚMERO]\n", name);
  printf("Calculadora de números primos em C, saiba quais números primos "
         "existem até certo número.\n\n");

  printf("Opções:\n");
  printf("  -l, --live     Printar valores em tempo real ao invés de esperar "
         "cálculo acabar.\n");
  printf("  -?, --help     Mostra essa ajuda.\n");
  printf("  -v, --version  Mostra a versão do programa.\n\n");

  printf("Reporte bugs para <moraes.eduardo@proton.me>.\n");
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
      printf("%s\n", version);
      return 0;
    default:
      fprintf(stderr, "Opção inválida: -%c\n", optopt);
      return 1;
    }
  }

  if (optind >= argc) {
    fprintf(stderr, "Número faltando.\n");
    printf("Uso: %s [OPÇÃO] [NÚMERO]\n", argv[0]);
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
        printf("O número %u é primo\n", i);
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
      printf("Não foi possível alocar o array de números primos. Saindo.");
      return 1;
    }

    // Calcular todos os números primos até o numero
    for (unsigned int i = 2; i < numero; i++) {
      numerosPrimos[i] = ePrimo(i);
    }

    // Abrir arquivo para salvar os números calculados
    FILE *const restrict fptr = fopen("numeros_primos.txt", "w");
    if (!fptr) {
      printf("Não foi possível abrir o arquivo numeros_primos.txt. Saindo.");
      return 1;
    }

    // Printar e salvar todos os números primos
    fprintf(fptr, "Os seguintes números são primos:\n");
    printf("Os seguintes números são primos:\n");
    for (unsigned int i = 2; i < numero; i++) {
      if (numerosPrimos[i]) {
        printf("%u, ", i);
        fprintf(fptr, "%u, ", i);
      }
    }

    // Salvar arquivo com os números primos
    fclose(fptr);

    // Liberar memória do array
    free(numerosPrimos);
  }

  printf("Calculados!\n");

  return 0;
}

// Retorna true caso numero seja primo, false caso não seja
bool ePrimo(const unsigned int numero) {
  if (numero < 2)
    return false;
  if (numero == 2 || numero == 3)
    return true;
  if (numero % 2 == 0 || numero % 3 == 0)
    return false;

  /*
    Todo número primo maior que 3 pode ser escrito na forma 6k±1, onde k é
    inteiro e positivo. Por exemplo, 5 = 6 × 1 - 1 e 7 = 6 × 1 + 1, e 11 = 6 × 2
    - 1.

    Ao testar se um número é primo, podemos pular testes de divisibilidade de
    números com fatores 2 ou 3 (que sabemos ser divisíveis) se testarmos apenas
    os números da forma 6k±1 (partindo de 5 e incrementando de 6 em 6).
  */
  for (unsigned int i = 5; i * i <= numero; i += 6) {
    if (numero % i == 0 || numero % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
