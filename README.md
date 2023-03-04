# Calculadora de Números Primos

Uma calculadora que consegue todos os números primos até certo número inserido, distribuida em diversas linguagens, esse é o repositório C.

## Baixar e testar

Caso queira apenas testar o programa em sua máquina, você apenas precisar baixar o projeto indo em Releases na interface do GitHub e escolhendo o executável do seu respectivo sistema.

Alternativamente clonar o repositório via: `git clone https://github.com/DoodlesEpic/NumerosPrimos.git` no terminal para baixar o repositório, e compilar direto da fonte.

### Comandos

```
Calculadora de números primos em C, saiba quais números primos existem até certo número.

Exemplos de uso:
./NumerosPrimos 1000                  Calcular todos primos até 1000
./NumerosPrimos -m brute 1000         Calcular usando bruteforce
./NumerosPrimos -m live 1000          Exibir primos imediatamente

Opções:
  -m, --metodo <metodo>  Escolher estratégia de cálculo.
  -h, --help             Mostra essa ajuda.
  -v, --version          Mostra a versão do programa.

Reporte bugs para <moraes.eduardo@proton.me>.
```

## Compilar

Para compilar tenha gcc, clang ou msvc configurado no seu sistema.
É necessário usar o build system [Meson](https://mesonbuild.com/) para compilar.

### Debug

A build de debug habilita o address sanitizer para tentar encontrar erros no uso de memória, mas mantém as otimizações -O2 habilitadas.

Para desenvolvimento utilize os comandos:

```shell
meson setup build -Dbuildtype=debugoptimized -Db_sanitize=address
cd build
meson compile
```

### Release

A build de release desabilita símbolos, address sanitizer e utiliza -O3 como flag de otimização.

Para criar um binário otimizado utilize:

```shell
meson setup prod -Dbuildtype=release
cd prod
meson compile
```

## Licença

Esse repositório está licenciado na licença MIT, cheque o arquivo ["LICENSE"](LICENSE) para mais informações.

## Projetos relacionados

Essa calculadora também está em disponível em outras linguagens, aqui está uma lista dos outros repositórios:
[Repositório calculadora de números primos em JavaScript][1]

[1]: https://github.com/DoodlesEpic/Calculadora-numeros-primos-js "Repositório calculadora de números primos em JavaScript"
