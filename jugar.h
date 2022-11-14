#ifndef jugar_H
#define jugar_H
#include "constants.h"

Combinacion jugar(int juego[], int tableroJugadas[][MAX_POSIBLES_COMBINACIONES], int actualPlayer);
Combinacion obtenerCombinacion(int juego[],nodoCombinacion *&lista,int generalaDoble);
int obtenerRepeticiones(int juego[], int repeticiones[]);
bool isStairway(int juego[]);

bool existeCombinacion(int repeticiones[], int cantidad);
void insertarNodoLista(nodoCombinacion *&lista, Combinacion dato);
void eliminarNodo(nodoCombinacion*& lista, int v);

void BurbujaDados(int juego[]);

Combinacion seleccionarCombinacion(nodoCombinacion *&lista, int tableroJugadas[][MAX_POSIBLES_COMBINACIONES], int actualPlayer);

#include "jugar.cpp"
#endif // a_H