#include "baralho.h"
#include <stdlib.h>
#include <time.h>

void adicionar_carta(Baralho *baralho, Carta carta) {
    baralho->cartas = realloc(baralho->cartas, (baralho->tamanho + 1) * sizeof(Carta));
    baralho->cartas[baralho->tamanho] = carta;
    baralho->tamanho++;
}

void embaralhar(Baralho *baralho) {
    for (int i = baralho->tamanho - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = baralho->cartas[i];
        baralho->cartas[i] = baralho->cartas[j];
        baralho->cartas[j] = temp;
    }
}

Carta* distribuir_cartas(Baralho *baralho, int num_jogadores, int *tamanhos_maos) {
    Carta *maos = malloc(num_jogadores * baralho->tamanho * sizeof(Carta));
    for (int i = 0; i < baralho->tamanho; i++) {
        maos[i] = baralho->cartas[i];
        tamanhos_maos[i % num_jogadores]++;
    }
    return maos;
}
