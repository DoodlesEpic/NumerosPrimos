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

#include "eratostenes.h"
#include <stdio.h>
#include <stdlib.h>

int eratostenes(const unsigned long numero) {
  bool *numeros = (bool *)malloc(sizeof *numeros * numero);
  if (!numeros) {
    printf("Não foi possível alocar o array de números primos. Saindo.");
    return 1;
  }

  for (unsigned long i = 2; i < numero; i++) {
    numeros[i] = true;
  }

  for (unsigned long i = 2; i * i < numero; i++) {
    if (numeros[i]) {
      for (unsigned long j = i * 2; j < numero; j += i) {
        numeros[j] = false;
      }
    }
  }

  FILE *const restrict fptr = fopen("numeros_primos.txt", "w");
  if (!fptr) {
    printf("Não foi possível abrir o arquivo numeros_primos.txt. Saindo.");
    return 1;
  }

  for (unsigned long i = 2; i < numero; i++) {
    if (numeros[i]) {
      printf("%lu, ", i);
      fprintf(fptr, "%lu, ", i);
    }
  }

  free(numeros);
  fclose(fptr);

  return 0;
}
