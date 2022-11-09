#include "jugar.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

const int CANTIDAD = 5;

const int COMB_1 = 1;
const int COMB_2 = 2;
const int COMB_3 = 3;
const int COMB_4 = 4;
const int COMB_5 = 5;
const int COMB_6 = 6;
const int COMB_ESCALERA = 7;
const int COMB_FULL = 8;
const int COMB_POKER = 9;
const int COMB_GENERALA = 10;
const int COMB_GENERALA_DOBLE = 11;
const int COMB_GENERALA_SERVIDA = 12;
const int COMB_NADA = 0;

struct Combinacion
{
    int id;
    int puntos;
    int tipo;
    int numero;
};

// crear estructura lista de combinaciones

struct nodoCombinacion
{
    Combinacion dato;
    nodoCombinacion *sig;
};

void insertarNodoLista(nodoCombinacion *&lista, Combinacion dato)
{
    nodoCombinacion *nuevoNodo = new nodoCombinacion();
    nuevoNodo->dato = dato;
    nodoCombinacion *aux1 = lista;
    nodoCombinacion *aux2;
    while ((aux1 != NULL))
    {
        aux2 = aux1;
        aux1 = aux1->sig;
    }
    if (lista == aux1)
    {
        lista = nuevoNodo;
        nuevoNodo->sig = aux1;
    }
    else
    {
        aux2->sig = nuevoNodo;
        nuevoNodo->sig = aux1;
    }
    cout << "El dato se ha insertado" << endl;
}

int jugar(int juego[])
{
    cout << "Jugando..." << endl;
    obtenerCombinacion(juego);
}

// obtener combinaciones de generala
int obtenerCombinacion(int juego[])
{
    int repetidos[6] = {0, 0, 0, 0, 0, 0};
    int aux[CANTIDAD] = {1, 1, 2, 2, 2};
    // crear lista de combinacion
    nodoCombinacion *lista = NULL;

    obtenerRepeticiones(aux, repetidos);

    for (int i = 0; i < 6; i++)
    {
        cout << "Repeticiones de " << i + 1 << ": " << repetidos[i] << endl;
    }

    if (existeCombinacion(repetidos, 5))
    {
        cout << "generala" << endl;
        Combinacion comb;
        comb.id = 1;
        comb.puntos = 50;
        comb.tipo = COMB_GENERALA;
        comb.numero = 0;

        // agregar a la lista
        insertarNodoLista(lista, comb);
    }

    if (existeCombinacion(repetidos, 4))
    {
        cout << "poker" << endl;
        Combinacion comb;
        comb.id = 2;
        comb.puntos = 40;
        comb.tipo = COMB_POKER;
        comb.numero = 0;

        // agregar a la lista
        insertarNodoLista(lista, comb);
    }

    
    if (existeCombinacion(repetidos, 3) && existeCombinacion(repetidos, 2))
    {
        cout << "full" << endl;
        Combinacion comb;
        comb.id = 3;
        comb.puntos = 30;
        comb.tipo = COMB_FULL;
        comb.numero = 0;

        // agregar a la lista
        insertarNodoLista(lista, comb);
    }

    // Recorrer la lista
    nodoCombinacion *aux1 = lista;

    while (aux1 != NULL)
    {
        cout << "ENTRE AL WHILE" << endl;
        cout << "ID: " << aux1->dato.id << endl;
        cout << "Puntos: " << aux1->dato.puntos << endl;
        cout << "Tipo: " << aux1->dato.tipo << endl;
        cout << "Numero: " << aux1->dato.numero << endl;
        aux1 = aux1->sig;
    }
}

int obtenerRepeticiones(int juego[], int repeticiones[])
{
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == juego[j])
            {
                repeticiones[juego[i] - 1]++;
            }
        }
    }
}

bool existeCombinacion(int repeticiones[], int cantidad)
{
    bool exists = false;
    for (int i = 0; i < 6; i++)
    {
        if (repeticiones[i] == cantidad)
        {
            exists = true;
        }
    }
    return exists;
}