#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void jugar(int juego[])
{
    bool generalaServida = false;
    for (int i = 0; i < 5; i++)
    {
        if (juego[i] == juego[i + 1])
        {
            // Si hay 5 dados iguales, es generala servida.
        }
    }
    if (generalaServida == true)
    {
    }
}