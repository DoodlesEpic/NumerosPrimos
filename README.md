# Calculadora de Números Primos

Uma calculadora que consegue todos os números primos até certo número inserido, distribuida em diversas linguagens, esse é o repositório C.

## Baixar e testar

Caso queira apenas testar o programa em sua máquina, você apenas precisar baixar o projeto indo em Releases na interface do GitHub e escolhendo o executável do seu respectivo sistema.
Como alternativa você pode utilizar o comando `git clone https://github.com/DoodlesEpic/Calculadora-numeros-primos.git` no terminal/cmd para baixar o repositório, e compilar direto da fonte.

### Windows

Para iniciar apenas abra o prompt de comando na pasta em que está o arquivo. Inicie utilizando:

```shell
Calculadora-primos.exe
```

ou para iniciar no modo ao vivo:

```shell
Calculadora-primos.exe -l
```

### Linux

Para iniciar apenas abra o terminal na pasta em que está o arquivo. Inicie utilizando:

```shell
./Calculadora-primos.bin
```

ou para iniciar no modo ao vivo:

```shell
./Calculadora-primos.bin -l
```

## Compilar

Utilizamos o [gcc](https://gcc.gnu.org/ "Website do gcc") para compilar o software, com a flag -Os ou -O2.

### Windows

Para compilar no Windows será necessário o compilador gcc que não pode ser instalado nativamente. O pacote recomendado é o [Mingw-w64](http://mingw-w64.org/doku.php/start "GCC for Windows 64 & 32 bits"), um fork do projeto [MinGW](http://www.mingw.org/ "Minimalist GNU for Windows") (Minimalist GNU for Windows).
Após [baixar e instalar](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe/download "Download Sourceforge") e adicionar ao PATH o comando para compilar será:

```shell
gcc Calculadora-primos.c -Os -o Calculadora-primos.exe
```

### Linux

No Linux o processo de compilação é mais simples, apenas é necessário ter o [gcc](https://gcc.gnu.org/ "Website do gcc") instalado. A instalação pode ser feita de diferentes formas dependendo de sua distro, muitas vezes já vem incluido.
Para compilar utilize o comando:

```shell
gcc Calculadora-primos.c -Os -o Calculadora-primos.bin
```

## Licença

Esse repositório está licenciado na licença MIT, cheque o arquivo ["LICENSE"](LICENSE) para mais informações.

## Projetos relacionados

Essa calculadora também está em disponível em outras linguagens, aqui está uma lista dos outros repositórios:
[Repositório calculadora de números primos em JavaScript][1]

[1]: https://github.com/DoodlesEpic/Calculadora-numeros-primos-js "Repositório calculadora de números primos em JavaScript"
