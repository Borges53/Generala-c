
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "tirar.h"
#include "jugar.h"
#include "constants.h"
#include "fileManage.h"

using namespace std;

int getWinner(Combinacion[][ROUNDS]);
void showResults(Combinacion[][ROUNDS], int);

struct info
{
    int id_jugada;
    char nombre_jugador[20 + 1];
    int fecha;
    int puntaje;
};

int main()
{
    int juego[5];
    int jugadores = 1;

    Combinacion results[jugadores][ROUNDS];

    int turns = jugadores * ROUNDS;
    int actualPlayer = 0;
    int actualRound = 0;

    for (int i = 0; i < 1; i++)
    {
        tirar(juego);
        cout << "GAME ACTUALIZADO: " << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << juego[j] << endl;
        }
        results[i][actualRound] = jugar(juego);
        actualPlayer++;
        if (actualPlayer == jugadores)
        {
            actualPlayer = 0;
            actualRound++;
        }
    }

    int winner = getWinner(results);
    showResults(results, jugadores);

    // Save Results  :  ACA VA LA LOGICA DE GUARDAR LOS RESULTADOS EN UN ARCHIVO
    FILE *f = fopen("JUGADAS.dat", "wb+");
    cargarArchivo(f, results, jugadores);

    cout << "El ganador es el jugador " << winner << endl;

    return 0;
}

void showResults(Combinacion results[][ROUNDS], int jugadores)
{

    // REVISAR ESTO
    for (int i = 0; i < jugadores; i++)
    {
        for (int j = 0; j < ROUNDS; j++)
        {
            cout << "Jugador " << i << " Ronda " << j << " Puntos: " << results[i][j].puntos << endl;
        }
    }
}

int getWinner(Combinacion results[][ROUNDS])
{
    // REVISAR ESTO
    int winner = 0;
    int winnerPoints = 0;
    int actualPoints = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 11; j++)
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
