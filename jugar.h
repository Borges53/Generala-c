#ifndef jugar_H
#define jugar_H
#include "constants.h"

Combinacion jugar(int juego[DICES], int tableroJugadas[][MAX_POSIBLES_COMBINACIONES], int actualPlayer);
Combinacion obtenerCombinacion(int juego[DICES],nodoCombinacion *&lista,int generalaDoble);
int obtenerRepeticiones(int juego[DICES], int repeticiones[]);
bool isStairway(int juego[DICES]);

bool existeCombinacion(int repeticiones[], int cantidad);
void insertarNodoLista(nodoCombinacion *&lista, Combinacion dato);
void eliminarNodo(nodoCombinacion*& lista, int v);

void BurbujaDados(int juego[DICES]);

Combinacion seleccionarCombinacion(nodoCombinacion *&lista, int tableroJugadas[][MAX_POSIBLES_COMBINACIONES], int actualPlayer);

#include "jugar.cpp"
#endif // a_H