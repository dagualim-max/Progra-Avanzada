#ifndef CELDA_H
#define CELDA_H

#include "Pos.h"
#include <iostream>
#include <string>

using namespace std;

enum TipoCelda {
    VACIO,
    PARED,
    ENEMIGO,
    TRAMPA,
    POCION,
    LLAVE,
    SALIDA,
    INICIO
};

struct Celda {
    TipoCelda tipo;
    bool visitada;
    string descripcion;

    Celda(TipoCelda _tipo = VACIO, string _descripcion = "") : tipo(_tipo), visitada(false), descripcion(_descripcion) {}
};

#endif