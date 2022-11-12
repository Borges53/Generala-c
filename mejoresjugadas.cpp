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

void mostrarTop3 (nodo*);

//tomar información de un archivo y ordenarlo mediante listas
 void mejoresJugadas (){
    
    nodo* lista = NULL;
    FILE * f =fopen("JUGADAS.dat", "rb");
    Info a;
    while (fread(&a, sizeof(Info) ,1,f )){
        insertarOrdenado(lista, a); //genera ranking total
    }
    fclose(f);

    mostrarTop3(lista);

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

void mostrarTop3 (nodo *lista) {
    nodo* actual = new nodo();
    actual = lista;
    
    int i = 0;

    while (actual != NULL && i < 3){
        cout << "jugador con el puesto " << i+1 << " historico es: " << endl;

        cout << "Nombre: " << actual -> dato.nombre_jugador << endl ;

        cout << "El dia: " << actual -> dato.fecha << endl ;
        
        cout << "Con el puntaje: " << actual -> dato.puntaje << endl ;

        i++;
    
    actual = actual -> sig;
    }
   
}