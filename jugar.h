#ifndef jugar_H
#define jugar_H
#include "constants.h"

Combinacion jugar(int juego[]);
Combinacion obtenerCombinacion(int juego[],nodoCombinacion *&lista);
int obtenerRepeticiones(int juego[], int repeticiones[]);
bool isStairway(int juego[]);

bool existeCombinacion(int repeticiones[], int cantidad);
void insertarNodoLista(nodoCombinacion *&lista, Combinacion dato);
void eliminarNodo(nodoCombinacion*& lista, int v);

Combinacion seleccionarCombinacion(nodoCombinacion *&lista);

#include "jugar.cpp"
#endif // a_H