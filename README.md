# Calculadora-numeros-primos

Uma calculadora que consegue todos os números primos até certo número inserido, distribuida em diversas linguagens, esse é o repositório C

## Baixar e testar

Caso queira apenas testar o programa em sua máquina, você apenas precisar baixar o projeto indo em Code -> Download ZIP na interface do GitHub.
Como alternativa você pode utilizar o comando `git clone https://github.com/DoodlesEpic/Calculadora-numeros-primos.git` no terminal/cmd e terá o repositório baixado (isso requer git instalado).

### Windows

Para iniciar apenas abra o prompt de comando, utilize `cd pasta` para chegar na pasta em que está o arquivo. E inicie utilizando:

```shell
Calculadora-primos.exe
```

ou para iniciar no modo ao vivo:

```shell
Calculadora-primos.exe -l
```

### Linux

Para iniciar apenas abra o terminal, utilize `cd pasta` para chegar na pasta em que está o arquivo. E inicie utilizando:

```shell
./Calculadora-primos.bin
```

ou para iniciar no modo ao vivo:

```shell
./Calculadora-primos.bin -l
```

## Compilar

Utilizamos o GCC para compilar o software, com a flag -Os ou -O2.

### Windows

Para compilar no Windows será necessário o compilador gcc que não pode ser instalado nativamente. O pacote recomendado é o Mingw-w64, um fork do projeto MinGW (Minimalist GNU for Windows).
Após instalar e adicionar ao PATH o comando para compilar será:

```shell
gcc Calculadora-primos.c -Os -o Calculadora-primos.exe
```

### Linux

No Linux o processo de compilação é mais simples, apenas é necessário ter o gcc instalado.
Para compilar utilize o comando:

```shell
gcc Calculadora-primos.c -Os -o Calculadora-primos.bin
```

## Licença

Esse repositório está licenciado na licença MIT, cheque o arquivo "LICENSE" para mais informações

## Projetos relacionados

Essa calculadora também está em disponível em outras linguagens, aqui está uma lista dos outros repositórios:
[Repositório calculadora de números primos em JavaScript][1]

[1]: https://github.com/DoodlesEpic/Calculadora-numeros-primos-js "Repositório calculadora de números primos em JavaScript"
