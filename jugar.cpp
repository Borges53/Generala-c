#include "jugar.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "constants.h"

using namespace std;

Combinacion jugar(int juego[])
{
    cout << "Jugando..." << endl;
    Combinacion comb = obtenerCombinacion(juego);
    return comb;
}

// obtener combinaciones de generala
Combinacion obtenerCombinacion(int juego[])
{
    int repetidos[6] = {0, 0, 0, 0, 0, 0};
    int aux[DICES] = {1, 2, 3, 4, 5};
    // crear lista de combinacion
    nodoCombinacion *lista = NULL;

    obtenerRepeticiones(aux, repetidos);

    for (int i = 0; i < 6; i++)
    {
        cout << "Repeticiones de " << i + 1 << ": " << repetidos[i] << endl;
    }

    // GENERALA
    if (existeCombinacion(repetidos, 5))
    {
        Combinacion comb;
        comb.puntos = VALUE_GENERALA;
        comb.tipo = COMB_GENERALA;

        insertarNodoLista(lista, comb);
    }

    // POKER
    if (existeCombinacion(repetidos, 4))
    {
        Combinacion comb;
        comb.puntos = VALUE_POKER;
        comb.tipo = COMB_POKER;

        insertarNodoLista(lista, comb);
    }

    // FULL
    if (existeCombinacion(repetidos, 3) && existeCombinacion(repetidos, 2))
    {
        Combinacion comb;
        comb.puntos = 30;
        comb.tipo = VALUE_FULL;

        insertarNodoLista(lista, comb);
    }

    if (isStairway(aux))
    {
        Combinacion comb;
        comb.puntos = VALUE_ESCALERA;
        comb.tipo = COMB_ESCALERA;

        insertarNodoLista(lista, comb);
    }

    // Recorrer la lista
    nodoCombinacion *aux1 = lista;

    while (aux1 != NULL)
    {
        cout << "Puntos: " << aux1->dato.puntos << endl;
        cout << "Tipo: " << aux1->dato.tipo << endl;
        aux1 = aux1->sig;
    }
}

bool isStairway(int juego[DICES])
{

    bool isAscendant = true;
    int lastNumber = juego[0];
    int dice = 1;
    while (dice < DICES && isAscendant)
    {
        if (juego[dice] != lastNumber + 1)
        {
            isAscendant = false;
        }
        lastNumber = juego[dice];
        dice++;
    }

    int lastNumber2 = juego[DICES - 1];
    int dice2 = DICES - 2;
    bool isDescendant = true;

    while (dice2 >= 0 && isDescendant && !isAscendant)
    {
        if (juego[dice2] != lastNumber2 + 1)
        {
            isDescendant = false;
        }
        lastNumber2 = juego[dice2];
        dice2--;
    }

    bool result = isAscendant || isDescendant;

    return  result;
}

int obtenerRepeticiones(int juego[], int repeticiones[])
{
    for (int i = 1; i < 7; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == juego[j])
            {
                repeticiones[i - 1]++;
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