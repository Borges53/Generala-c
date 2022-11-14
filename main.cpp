
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tirar.h"
#include "jugar.h"
#include "constants.h"
#include "fileManage.h"
#include "mejoresJugadas.h"

using namespace std;

int getWinner(Combinacion[][ROUNDS], int);
void showResults(Combinacion[][ROUNDS], int);

int main()
{
    cout << "Bienvenido a la Generala" << endl;
    cout << "------------------------" << endl;
    cout << "Ingrese cantidad de jugadores: (entre 3 y 5)" << endl;
    int jugadores;
    cin >> jugadores;

    while (jugadores < 3 || jugadores > 5)
    {
        cout << "Cantidad de jugadores invalida. Ingrese cantidad de jugadores: (entre 3 y 5)" << endl;
        cin >> jugadores;
    };

    char nombreJugadores[jugadores][20];

    for (int i = 0; i < jugadores; i++)
    {
        cout << "Ingrese nombre del jugador " << i + 1 << ": " << endl;
        cin >> nombreJugadores[i];
    }

    int juego[5];
    Combinacion results[jugadores][ROUNDS];

    // matriz para ver si se ya se jugo una jugada // 0 = no jugo, 1 = jugo
    int tableroJugadas[jugadores][MAX_POSIBLES_COMBINACIONES] = {0};

    int turns = jugadores * ROUNDS;
    int actualPlayer = 0;
    int actualRound = 0;

    int generalWin = 0;

    for (int i = 0; i < turns; i++)
    {
        cout << "Turno del jugador " << actualPlayer + 1 << ": " << endl;

        int tiros = tirar(juego);
        results[actualPlayer][actualRound] = jugar(juego, tableroJugadas, actualPlayer);

        if (tiros == 1 && results[actualPlayer][actualRound].tipo == COMB_GENERALA)
        {
            generalWin = 1;
            cout << "Ganaste el juego!" << endl;
            break;
        }

        if (actualPlayer == jugadores - 1)
        {
            actualPlayer = 0;
            actualRound++;
        }
        else
        {
            actualPlayer++;
        }
    }

    if (generalWin == 1)
    {

        cout << "El ganador es: " << nombreJugadores[actualPlayer] << " PORQUE SACO GENERALA PERO NO SE GUARDO EN EL ARCHIVO" << endl;
        return 0;
    }

    int winner = getWinner(results, jugadores);
    showResults(results, jugadores);

    // Save Results  :  ACA VA LA LOGICA DE GUARDAR LOS RESULTADOS EN UN ARCHIVO
    FILE *f = fopen("jugadas.dat", "w+");
    cargarArchivo(f, results, jugadores, nombreJugadores);

    /*  Info variable;
    while (fread(&variable, sizeof(Info), 1, f))
    {
        cout << variable.nombre_jugador << " " << variable.puntaje << " " << variable.id_jugada << endl;
    }
     */
    fclose(f);

    cout << "El ganador es el jugador " << winner + 1 << "!!" << endl;

    cout << "____________________________________" << endl;

    mejoresJugadas();

    system("pause");

    return 0;
}

void showResults(Combinacion results[][ROUNDS], int jugadores)
{

    // REVISAR ESTO
    for (int i = 0; i < jugadores; i++)
    {
        for (int j = 0; j < ROUNDS; j++)
        {
            cout << "Jugador " << i + 1 << " Ronda " << j + 1 << " Puntos: " << results[i][j].puntos << endl;
        }
    }
}

int getWinner(Combinacion results[][ROUNDS], int jugadores)
{
    // REVISAR ESTO
    int winner = 0;
    int winnerPoints = 0;
    int actualPoints = 0;

    for (int i = 0; i < jugadores; i++)
    {
        for (int j = 0; j < ROUNDS; j++)
        {
            actualPoints += results[i][j].puntos;
        }
        if (actualPoints > winnerPoints)
        {
            winnerPoints = actualPoints;
            winner = i;
        }
        actualPoints = 0;
    }

    return winner;
}
