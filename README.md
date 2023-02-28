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
./Calculadora-primos
```

ou para iniciar no modo ao vivo:

```shell
./Calculadora-primos -l
```

## Compilar

Para compilar tenha gcc, clang ou msvc configurado no seu sistema.
É necessário usar o build system [Meson](https://mesonbuild.com/) para compilar.

### Debug

Para desenvolvimento utilize os comandos:

```shell
meson setup build -Dbuildtype=debugoptimized
cd build
meson compile
```

### Prod

Para criar um binário otimizado utilize:

```shell
meson setup prod -Dbuildtype=release
cd build
meson compile
```

## Licença

Esse repositório está licenciado na licença MIT, cheque o arquivo ["LICENSE"](LICENSE) para mais informações.

## Projetos relacionados

Essa calculadora também está em disponível em outras linguagens, aqui está uma lista dos outros repositórios:
[Repositório calculadora de números primos em JavaScript][1]

[1]: https://github.com/DoodlesEpic/Calculadora-numeros-primos-js "Repositório calculadora de números primos em JavaScript"
