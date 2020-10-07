# Makefile utilizada para compilar o programa
all: Calculadora-primos

# Compilar o programa inteiro
Calculadora-primos: Calculadora-primos.o
	 gcc -o Calculadora-primos Calculadora-primos.o

# Compilar object file do arquivo principal
Calculadora-primos.o: Calculadora-primos.c Calculadora-primos.h
	 gcc -c Calculadora-primos.c
     
# Excluir arquivos gerados pelos outros comandos
# Não funciona no Windows
clean:
	 rm Calculadora-primos.o Calculadora-primos