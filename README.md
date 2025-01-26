# Super Trunfo Futebol

O Super Trunfo é um divertido jogo de cartas onde cada carta possui vários atributos numéricos. Os jogadores competem escolhendo um atributo de suas cartas, e quem tiver o maior valor nesse atributo ganha a rodada e fica com as cartas dos adversários. O objetivo é ser o primeiro a ficar com todas as cartas do baralho.

Para este trabalho, faremos algumas adaptações para simplificar a programação do jogo:

Haverá apenas dois competidores.
Cada jogador receberá quatro cartas aleatórias de um conjunto de cartas.
Os jogadores se alternarão na escolha dos atributos em cada rodada.
A cada rodada, um novo par de cartas será selecionado.
Cada vitória vale dois pontos, e os empates valem um ponto.
Ao final de quatro rodadas, o jogador com mais pontos será o vencedor.
O trabalho consiste em criar dois programas separados:

Gerador de Cartas
Jogo

## Como Jogar

1. Compile o jogo usando o Makefile:
    ```sh
    make
    ```

2. Execute o jogo:
    ```sh
    ./super_trunfo_futebol
    ```

3. Siga as instruções na tela para jogar.

## Estrutura do Projeto

- `src/`: Arquivos de código-fonte.
- `include/`: Arquivos de cabeçalho.
- `Makefile`: Arquivo para compilação do projeto.
- `README.md`: Documentação do projeto.
- `.gitignore`: Arquivo para ignorar arquivos e diretórios no Git.
