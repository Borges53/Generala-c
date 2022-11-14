#include "jugar.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "constants.h"
#include <cstring>

using namespace std;

Combinacion jugar(int juego[], int tableroJugadas[][MAX_POSIBLES_COMBINACIONES], int actualPlayer)
{
    nodoCombinacion *lista = NULL;
    obtenerCombinacion(juego, lista, tableroJugadas[actualPlayer][COMB_GENERALA_DOBLE - 1]);

    Combinacion comb = seleccionarCombinacion(lista, tableroJugadas, actualPlayer);
    tableroJugadas[actualPlayer][comb.tipo - 1] = 1; // guardar que ya se jugo esa jugada

    return comb;
}

Combinacion seleccionarCombinacion(nodoCombinacion *&lista, int tableroJugadas[][MAX_POSIBLES_COMBINACIONES], int actualPlayer)
{
    nodoCombinacion *aux1 = lista;
    Combinacion comb;

    cout << "Elegi una combinacion: " << endl;
    int aux = 1;
    int indexComb;
    nodoCombinacion *aux2= NULL;
    while (aux1 != NULL)
    {
        if (tableroJugadas[actualPlayer][aux1->dato.tipo - 1] == 0)
        {
            cout << "[" << aux << "] " << aux1->dato.nombre << endl;
            cout << "Puntos: " << aux1->dato.puntos << endl;
            cout << "Tipo: " << aux1->dato.tipo << endl;
            cout << "----------------------------" << endl;

            aux++;
            aux1 = aux1->sig;
        }
        else
        {
            aux2 = aux1->sig;
            eliminarNodo(lista, aux1->dato.tipo);
            aux1 = aux2;

        }
    }

    indexComb = -1;

    while (indexComb < 0 || indexComb > aux)
    {
        cout << "Selecciona una combinacion: " << endl;
        cin >> indexComb;
    }

    aux1 = lista;
    for (int i = 0; i < indexComb - 1; i++)
    {
        aux1 = aux1->sig;
    }
    comb = aux1->dato;

    cout << "----------------------------" << endl;
    cout << "Combinacion elegida: " << endl;
    cout << "Nombre: " << comb.nombre << endl;
    cout << "Puntos: " << comb.puntos << endl;
    cout << "Tipo: " << comb.tipo << endl;
    cout << "----------------------------" << endl;

    return comb;
}

// obtener combinaciones de generala
Combinacion obtenerCombinacion(int juego[], nodoCombinacion *&lista, int generalaDoble)
{
    int repetidos[6] = {0, 0, 0, 0, 0, 0};
    // crear lista de combinacion

    obtenerRepeticiones(juego, repetidos);

    // GENERALA
    if (existeCombinacion(repetidos, 5))
    {
        Combinacion comb;
        comb.puntos = VALUE_GENERALA;
        comb.tipo = COMB_GENERALA;
        strcpy(comb.nombre, "Generala");

        insertarNodoLista(lista, comb);
    }

    if(generalaDoble == 1 && existeCombinacion(repetidos, 5))
    {
        Combinacion comb;
        comb.puntos = VALUE_GENERALA_DOBLE;
        comb.tipo = COMB_GENERALA_DOBLE;
        strcpy(comb.nombre, "Generala Doble");

        insertarNodoLista(lista, comb);
    }
    

    // POKER
    if (existeCombinacion(repetidos, 4))
    {
        Combinacion comb;
        comb.puntos = VALUE_POKER;
        comb.tipo = COMB_POKER;
        strcpy(comb.nombre, "Poker");

        insertarNodoLista(lista, comb);
    }

    // FULL
    if (existeCombinacion(repetidos, 3) && existeCombinacion(repetidos, 2))
    {
        Combinacion comb;
        comb.puntos = 30;
        comb.tipo = VALUE_FULL;
        strcpy(comb.nombre, "Full");

        insertarNodoLista(lista, comb);
    }

    // ESCALERA
    if (isStairway(juego))
    {
        Combinacion comb;
        comb.puntos = VALUE_ESCALERA;
        comb.tipo = COMB_ESCALERA;
        strcpy(comb.nombre, "Escalera");

        insertarNodoLista(lista, comb);
    }

    // Recorrer repetidos y revisar cuales tienen 2 o 3 repeticiones
    for (int i = 0; i < 6; i++)
    {
        if (repetidos[i] == 3)
        {
            Combinacion comb;
            comb.puntos = (i + 1) * 3;
            comb.tipo = i + 1;
            strcpy(comb.nombre, "Tercia");

            insertarNodoLista(lista, comb);
        }
        else if (repetidos[i] == 2)
        {
            Combinacion comb;
            comb.puntos = (i + 1) * 2;
            comb.tipo = i + 1;
            strcpy(comb.nombre, "Doble");

            insertarNodoLista(lista, comb);
        }
        else if (repetidos[i] == 1)
        {
            Combinacion comb;
            comb.puntos = i + 1;
            comb.tipo = i + 1;
            strcpy(comb.nombre, "Unica");

            insertarNodoLista(lista, comb);
        }
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

    return result;
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
}

void eliminarNodo(nodoCombinacion*& lista, int v) // ELIMINAR POR TIPO
{
        nodoCombinacion* actual = lista;
        nodoCombinacion* ant = NULL;

        while(actual!=NULL && actual->dato.tipo != v) 
        {
            ant = actual;
            actual = actual->sig;
        }

        if(actual->dato.tipo !=v)             //no lo encontro
        {
            return; 
        }                       
        if(ant != NULL)
        {
           ant->sig = actual->sig;     //si no es el primer nodo
        }                     
        else 
        {                               //si se elimina el primero
            lista = actual->sig;        //actualiza puntero al inicio
        }
        delete actual;
        return;
}
