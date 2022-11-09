#ifndef jugar_H
#define jugar_H
#include "constants.h"

Combinacion jugar(int juego[]);
int obtenerCombinacion(int juego[]);
int obtenerRepeticiones(int juego[], int repeticiones[]);
bool existeCombinacion(int repeticiones[], int cantidad);

#include "jugar.cpp"
#endif // a_H