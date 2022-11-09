#include "jugar.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include "constants.h"

using namespace std;

struct nodo{
    Info dato;
    nodo* sig;
};

nodo* insertarOrdenado(nodo*&, Info);

void mostrarPrimerElementoLista (nodo*);

//tomar información de un archivo y ordenarlo mediante listas
 void mejoresJugadas (){
    
    nodo* lista = NULL;
    FILE * f =fopen("JUGADAS.dat", "rb");
    Info a;
    while (fread(&a, sizeof(Info) ,1,f )){
        insertarOrdenado(lista, a);
    }
    fclose(f);

    int i = 0;
    while (i < 3){
        cout << "jugador con el puesto " << i+1 << " historico es: " << endl;
        mostrarPrimerElementoLista (lista);
        i++;
    }

    }

    nodo* insertarOrdenado(nodo*& lista, Info info){

    //armo el nodo con la info
    nodo* p = new nodo();
    p -> dato = info;
    p -> sig = NULL;

    //primeras dos situaciones
    if (lista == NULL || info.puntaje < lista -> dato.puntaje){
        p -> sig = lista;
        lista = p;
     }
    // los otros dos casos
    else
    {
        nodo* q = lista;
        while (q-> sig != NULL && q ->sig -> dato.puntaje < info.puntaje){
            q = q->sig;

        }
        p->sig = q->sig;
        q->sig = p;
    }
    
}

void mostrarPrimerElementoLista (nodo *lista) {
    nodo* actual = new nodo();
    actual = lista;
    while (actual != NULL){
        cout << "Jugador: " << actual -> dato.nombre_jugador << endl ;

        cout << "El día: " << actual -> dato.fecha << endl ;
        
        cout << "Con el puntaje" << actual -> dato.puntaje << endl ;
    }
    actual = actual -> sig;
}