# Makefile utilizada para compilar no Linux
all: Calculadora-primos

Calculadora-primos: Calculadora-primos.o
	 gcc -o Calculadora-primos Calculadora-primos.o

Calculadora-primos.o: Calculadora-primos.c Calculadora-primos.h
	 gcc -c Calculadora-primos.c
     
clean:
	 rm Calculadora-primos.o Calculadora-primos