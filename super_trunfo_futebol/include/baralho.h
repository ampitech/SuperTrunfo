#ifndef BARALHO_H
#define BARALHO_H

#include "carta.h"

typedef struct {
    Carta *cartas;
    int tamanho;
} Baralho;

void adicionar_carta(Baralho *baralho, Carta carta);
void embaralhar(Baralho *baralho);
Carta* distribuir_cartas(Baralho *baralho, int num_jogadores, int *tamanhos_maos);

#endif // BARALHO_H
