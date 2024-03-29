#include "tirar.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "constants.h"

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

void tirarUnaVez(int juego[])
{
   srand(time(NULL));
   for (int i = 0; i < 5; i++)
   {
      juego[i] = rand() % 6 + 1;
      displayDice(juego[i]);
   }
}

void tirarDeNuevo(int juego[])
{
   // Tirar de nuevo ciertos dados y actualizar el array
   char respuesta[10 + 1];
   int i = 0;
   srand(time(NULL));

   cout << "Que dado/s desea volver a tirar? (Ingrese 1,2,3 si desea volver a tirar el dado 1, 2 y 3 respectivamente)" << endl;
   cin >> respuesta;
   // validar respuesta
   if (respuesta == NULL)
   {
      cout << "Ingrese un dado por favor" << endl;
      cin >> respuesta;
   }
   int lenghtRespuesta = strlen(respuesta);
   if (lenghtRespuesta == 1)
   {
      // convert entire char to int
      int respuestaInt = respuesta[0] - '0';
      if (respuestaInt > 5 || respuestaInt < 1)
      {
         cout << "Ingrese un dado valido por favor" << endl;
         cin >> respuesta;
      }
      juego[respuestaInt - 1] = rand() % 6 + 1;
      for (int i = 0; i < 5; i++)
      {
         displayDice(juego[i]);
      }
   }
   else
   {
      while (respuesta[i] != '\0')
      {
         if (respuesta[i] != ',')
         {
            int respuestaInt = respuesta[i] - '0';
            if (respuestaInt > 5 || respuestaInt < 1)
            {
               cout << "Ingrese un dado valido por favor" << endl;
               cin >> respuesta;
            }
            juego[respuestaInt - 1] = rand() % 6 + 1;
            cout << "Volviendo a tirar dado " << respuestaInt << "..." << endl;
         }
         i++;
      }
      for (int i = 0; i < 5; i++)
      {
         displayDice(juego[i]);
      }
   }
}

int tirar(int juego[])
{
   int tiradas = 1;
   char respuesta;
   tirarUnaVez(juego);
   bool termino = false;
   while (tiradas < MAX_TIRADAS && !termino)
   {
      cout << "Desea tirar de nuevo? (s/n): ";
      cin >> respuesta;
      if (respuesta != 's' && respuesta != 'n')
      {
         cout << "Ingrese una respuesta valida por favor" << endl;
         cin >> respuesta;
      }
      if (respuesta == 's')
      {
         tirarDeNuevo(juego);
         tiradas++;
      }
      else
      {
         termino = true;
      }
   }
   return tiradas;
}