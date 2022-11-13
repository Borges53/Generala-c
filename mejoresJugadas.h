#ifndef mejoresJugadas_H
#define mejoresJugadas_H
#include "constants.h"

struct nodo{
    Info dato;
    nodo* sig;
};

nodo* insertarOrdenado(nodo*&, Info);

void mostrarTop3 (nodo*&);

#include "mejoresJugadas.cpp"
#endif // a_H