#include "fileManage.h"
#include <iostream>
#include <fstream>
#include "constants.h"

 void cargarArchivo(FILE *f, Combinacion matriz[][ROUNDS], int cantidadJugadores,char nombreJugadores[][20])
{
	// ACA VA LA LOGICA DE CARGAR
	int i = 0;
	Info variable;

	for(int x = 0; x < cantidadJugadores; x++)
	{
		for(int y = 0; y < ROUNDS; y++)
		{
			strcpy(variable.nombre_jugador, nombreJugadores[x]);
			variable.puntaje = matriz[x][y].puntos;
			fwrite(&variable, sizeof(Info), 1, f);
		}
	}

    fseek(f, sizeof(Info), SEEK_END);
    fread(&variable, sizeof(Info), 1, f);
    cout << variable.nombre_jugador << " " << variable.puntaje << endl;

    cout << "______________________________ " << endl;
    while (!feof(f))
    {
        Info variable;
        fread(&variable, sizeof(Info), 1, f);
        cout << variable.nombre_jugador << " " << variable.puntaje << endl;
        cout << "______________________________ " << endl;
    }

} 
