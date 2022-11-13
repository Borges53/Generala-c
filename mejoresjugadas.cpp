#include "mejoresJugadas.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "constants.h"

using namespace std;

// tomar información de un archivo y ordenarlo mediante listas
void mejoresJugadas()
{

    nodo *lista = NULL;
    FILE *f = fopen("JUGADAS.dat", "r+");
    Info a;
    while (fread(&a, sizeof(Info), 1, f))
    {
        insertarOrdenado(lista, a); // genera ranking total
    }
    fclose(f);

    mostrarTop3(lista);
}

nodo *insertarOrdenado(nodo *&lista, Info info)
{

    // armo el nodo con la info
    nodo *p = new nodo();
    p->dato = info;
    p->sig = NULL;

    // primeras dos situaciones
    if (lista == NULL || info.puntaje > lista->dato.puntaje)
    {
        p->sig = lista;
        lista = p;
    }
    // los otros dos casos
    else
    {
        nodo *q = lista;
        while (q->sig != NULL && q->sig->dato.puntaje > info.puntaje)
        {
            q = q->sig;
        }

        if (q->sig == NULL) // NO HAY OTRO ADELANTE
        {
            q->sig = p;
        }
        else if (q->sig->dato.puntaje >= info.puntaje) // MENOR O IGUAL
        {
            p->sig = q->sig;
            q->sig = p;
        }
        else
        { // ES MAYOR
            p->sig = q->sig;
            q->sig = p;
        }
    }
}

void mostrarTop3(nodo *&lista)
{
    nodo *actual = lista;

    int i = 0;

    while (actual != NULL && i < 3)
    {
        cout << "jugador con el puesto " << i + 1 << " historico es: " << endl;

        cout << "Nombre: " << actual->dato.nombre_jugador << endl;

        cout << "El dia: " << actual->dato.fecha << endl;

        cout << "Con el puntaje: " << actual->dato.puntaje << endl;

        i++;

        actual = actual->sig;
    }
}