#include "jogo.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Carta* comparar_cartas(Carta *carta1, Carta *carta2, int atributo) {
    if (carta1->atributos[atributo] > carta2->atributos[atributo]) {
        return carta1;
    } else if (carta1->atributos[atributo] < carta2->atributos[atributo]) {
        return carta2;
    } else {
        return NULL; // Empate
    }
}

void jogar() {
    srand(time(NULL));

    // Criando cartas
    Carta carta1 = {"Messi", "Atacante", {50, 30, 10}};
    Carta carta2 = {"Ronaldo", "Atacante", {45, 25, 15}};
    Carta carta3 = {"Neymar", "Meio-campo", {30, 40, 20}};
    Carta carta4 = {"Ramos", "Defensor", {10, 15, 45}};

    // Criando o baralho e adicionando cartas
    Baralho baralho = {NULL, 0};
    adicionar_carta(&baralho, carta1);
    adicionar_carta(&baralho, carta2);
    adicionar_carta(&baralho, carta3);
    adicionar_carta(&baralho, carta4);

    // Embaralhando e distribuindo cartas
    embaralhar(&baralho);
    int num_jogadores = 2;
    int tamanhos_maos[num_jogadores] = {0};
    Carta *maos = distribuir_cartas(&baralho, num_jogadores, tamanhos_maos);

    // Exibindo as mãos dos jogadores
    for (int i = 0; i < num_jogadores; i++) {
        printf("Mão do Jogador %d:\n", i + 1);
        for (int j = 0; j < tamanhos_maos[i]; j++) {
            imprimir_carta(maos[i * baralho.tamanho / num_jogadores + j]);
        }
    }

    // Jogando
    while (tamanhos_maos[0] > 0 && tamanhos_maos[1] > 0) {
        int atributo_escolhido;
        printf("Escolha um atributo (0: Gols, 1: Assistências, 2: Defesas): ");
        scanf("%d", &atributo_escolhido);

        Carta *carta_vencedora = comparar_cartas(&maos[0], &maos[1], atributo_escolhido);
        if (carta_vencedora) {
            printf("A carta vencedora é: ");
            imprimir_carta(*carta_vencedora);
            if (carta_vencedora == &maos[0]) {
                maos[0] = maos[1];
                tamanhos_maos[0]++;
                tamanhos_maos[1]--;
            } else {
                maos[1] = maos[0];
                tamanhos_maos[1]++;
                tamanhos_maos[0]--;
            }
        } else {
            printf("Empate!\n");
        }

        // Exibindo as mãos dos jogadores
        for (int i = 0; i < num_jogadores; i++) {
            printf("Mão do Jogador %d:\n", i + 1);
            for (int j = 0; j < tamanhos_maos[i]; j++) {
                imprimir_carta(maos[i * baralho.tamanho / num_jogadores + j]);
            }
        }
    }

    // Determinando o vencedor
    if (tamanhos_maos[0] > 0) {
        printf("Jogador 1 venceu!\n");
    } else {
        printf("Jogador 2 venceu!\n");
    }

    free(baralho.cartas);
    free(maos);
}
