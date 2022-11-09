#ifndef constants_H
#define constants_H

const int DICES = 5;
const int ROUNDS = 11;


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
    int puntos;
    int tipo;
    int numero;
};

struct Info{
	
	int id_jugada;
	char nombre_jugador[20+1];
	int fecha;
	int puntaje;
};

#endif // a_H