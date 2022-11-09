
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tirar.h"
#include "jugar.h"

using namespace std;

int main()
{
    int juego[5];
    int jugadores;
    cout << "Ingrese cantidad de jugadores: ";
    cin >> jugadores;

    int resultados[jugadores][11];
    //[0] = 1 - [1] = 2 - [2] = 3 - [3] = 4 - [4] = 5 - [5] = 6
    //[6] = Escalera - [7] = Full - [8] = Poker - [9] = Generala - [10] = Generala Doble

    tirar(juego);
    jugar(juego);

    return 0;
}
