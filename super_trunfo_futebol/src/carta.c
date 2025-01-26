#include "carta.h"
#include <stdio.h>

void imprimir_carta(Carta carta) {
    printf("%s (%s) - Gols: %d, Assistências: %d, Defesas: %d\n",
           carta.nome, carta.posicao, carta.atributos[0], carta.atributos[1], carta.atributos[2]);
}
