/*
MIT License

Copyright (c) 2023 Eduardo

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

#include "bruteforce.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void live(const unsigned long numero) {
  printf("Os seguintes números são primos:");
  for (unsigned long i = 2; i <= numero; i++) {
    if (ePrimo(i)) {
      printf("\n%lu", i);
    }
  }
}

int bruteforce(const unsigned long numero) {
  // Alocar array para salvar os números primos
  bool *const restrict numerosPrimos = (bool *)malloc(sizeof(bool) * numero);
  if (!numerosPrimos) {
    fprintf(stderr,
            "Não foi possível alocar o array de números primos. Saindo.");
    return 1;
  }

  // Calcular todos os números primos até o numero
  for (unsigned long i = 2; i < numero; i++) {
    numerosPrimos[i] = ePrimo(i);
  }

  // Abrir arquivo para salvar os números calculados
  FILE *const restrict fptr = fopen("numeros_primos.txt", "w");
  if (!fptr) {
    fprintf(stderr,
            "Não foi possível abrir o arquivo numeros_primos.txt. Saindo.");
    return 1;
  }

  // Printar e salvar todos os números primos
  fprintf(fptr, "Os seguintes números são primos:\n");
  printf("Os seguintes números são primos:\n");
  for (unsigned long i = 2; i < numero; i++) {
    if (numerosPrimos[i]) {
      printf("%lu, ", i);
      fprintf(fptr, "%lu, ", i);
    }
  }

  free(numerosPrimos);
  fclose(fptr);

  return 0;
}

// Retorna true caso numero seja primo, false caso não seja
bool __attribute__((const)) ePrimo(const unsigned long numero) {
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
  for (unsigned long i = 5; i * i <= numero; i += 6) {
    if (numero % i == 0 || numero % (i + 2) == 0) {
      return false;
    }
  }
  return true;
}
