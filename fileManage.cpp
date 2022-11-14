#include "fileManage.h"
#include <iostream>
#include <fstream>
#include "constants.h"
#include <ctime>

void cargarArchivo(FILE *f, Combinacion matriz[][ROUNDS], int cantidadJugadores, char nombreJugadores[][20])
{
	// ACA VA LA LOGICA DE CARGAR
	int i = 0;
	Info variable;
	int id;

	// obtener ultima jugada y revisar si existe
	fseek(f, -sizeof(Info), SEEK_END);

	// si existe la variable, tomar el id y sumarle 1

	if (fread(&variable, sizeof(Info), 1, f) != NULL)
	{
		cout << "Ultima jugada: " << variable.id_jugada << endl;
		id = variable.id_jugada + 1;
	}
	else
	{
		id = 1;
	}

	// Volver al inicio del archivo

	fseek(f, 0, SEEK_SET);

	int puntaje = 0;
	time_t now = time(0);
	tm *ltm = localtime(&now);

	for (int x = 0; x < cantidadJugadores; x++)
	{
		strcpy(variable.nombre_jugador, nombreJugadores[x]);
		// variable.puntaje = matriz[x][y].puntos;
		variable.id_jugada = id;
		for (int y = 0; y < ROUNDS; y++)
		{
			puntaje += matriz[x][y].puntos;
		}
		variable.puntaje = puntaje;
		variable.fecha = (1900 + ltm->tm_year) * 10000 + (ltm->tm_mon + 1) * 100 + ltm->tm_mday;
		fwrite(&variable, sizeof(Info), 1, f);
		id++;
		puntaje = 0;
	}
}
