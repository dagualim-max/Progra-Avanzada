#ifndef ENEMIGO_H
#define ENEMIGO_H

#include "Pos.h"
#include "Celda.h"
#include <iostream>
#include <cstdlib>

using namespace std;

class Laberinto;

class Enemigo {
private:
    Pos posicion;

public:
    Enemigo(Pos inicio = Pos()) : posicion(inicio) {}

    Pos getPosicion() const { return posicion;}
    void setPosicion(Pos _posicion) { posicion = _posicion; }

    void patrullar(Laberinto& laberinto);
};

#include "Laberinto.h"

inline void Enemigo::patrullar(Laberinto& laberinto)
{
    Pos actual = getPosicion();
    Pos nueva = actual;
    bool movido = false;

    for (int intento = 0; intento < 2 && !movido; ++intento)
    {
        int direccion = rand() % 4;
        nueva = actual;

        switch (direccion)
        {
        case 0: nueva.fila -= 1; break;
        case 1: nueva.fila += 1; break;
        case 2: nueva.columna -= 1; break;
        case 3: nueva.columna += 1; break;
        }

        if (laberinto.esValido(nueva.fila, nueva.columna))
        {
            auto destino = laberinto.getCelda(nueva.fila, nueva.columna);
            if (destino->tipo == VACIO || destino->tipo == POCION || destino->tipo == LLAVE)
            {
                laberinto.getCelda(actual.fila, actual.columna)->tipo = VACIO;
                setPosicion(nueva);
                destino->tipo = ENEMIGO;
                cout << "El guardián se movió a la posicion ("<< nueva.fila << ", " << nueva.columna << ")" << endl;
                movido = true;
            }
        }
    }

    if (!movido)
    {
        cout << "El guardian no se ha movido" << endl;
    }
}
#endif