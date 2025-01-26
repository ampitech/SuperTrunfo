#ifndef CARTA_H
#define CARTA_H

typedef struct {
    char nome[50];
    char posicao[50];
    int atributos[3]; // Gols, Assistências, Defesas
} Carta;

void imprimir_carta(Carta carta);

#endif // CARTA_H
