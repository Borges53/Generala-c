#include "tirar.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

void displayDice(int dice)
{
   if (dice == 1)
   {
      cout << "+-------+" << endl;
      cout << "| |" << endl;
      cout << "| @ |" << endl;
      cout << "| |" << endl;
      cout << "+-------+" << endl;
   }
   else if (dice == 2)
   {
      cout << "+-------+" << endl;
      cout << "| @ |" << endl;
      cout << "| |" << endl;
      cout << "| @ |" << endl;
      cout << "+-------+" << endl;
   }
   else if (dice == 3)
   {
      cout << "+-------+" << endl;
      cout << "| @ |" << endl;
      cout << "| @ |" << endl;
      cout << "| @ |" << endl;
      cout << "+-------+" << endl;
   }
   else if (dice == 4)
   {
      cout << "+-------+" << endl;
      cout << "| @ @ |" << endl;
      cout << "| |" << endl;
      cout << "| @ @ |" << endl;
      cout << "+-------+" << endl;
   }
   else if (dice == 5)
   {
      cout << "+-------+" << endl;
      cout << "| @ @ |" << endl;
      cout << "| @ |" << endl;
      cout << "| @ @ |" << endl;
      cout << "+-------+" << endl;
   }
   else if (dice == 6)
   {
      cout << "+-------+" << endl;
      cout << "| @ @ |" << endl;
      cout << "| @ @ |" << endl;
      cout << "| @ @ |" << endl;
      cout << "+-------+" << endl;
   }
}

float suma(float A, float B)
{
   return A + B;
}
float resta(float A, float B)
{
   return A - B;
}
float multiplicacion(float A, float B)
{
   return A * B;
}

// generate trully random numbers

int tirar(int juego[])
{

   // Generar numero al azar para los dados
   srand(time(NULL));
   for (int i = 0; i < 5; i++)
   {
      juego[i] = rand() % 6 + 1;
      displayDice(juego[i]);
   }


   return 0;
}