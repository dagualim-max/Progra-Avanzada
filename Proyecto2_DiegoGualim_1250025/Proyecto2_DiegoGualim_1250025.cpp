#include "Juego.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int tamanho;

    do
    {
        cout << "Laberinto Dinamico";
        cout << "Elige el tamaño del laberinto es posible de 7*7 a 12*12: ";
        cin >> tamanho;

        if (tamanho < 7 || tamanho > 12)
        {
            cout << "Tamaño inválido. Debe estar entre 7 y 12.\n";
        }
    } while (tamanho < 7 || tamanho > 12);

    Juego juego(60, tamanho);
    juego.iniciar();

    return 0;
}