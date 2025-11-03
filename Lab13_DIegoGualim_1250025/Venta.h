#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include "Videojuego.h"
using namespace std;

class Venta {
public:
    Videojuego videojuego;
    int clienteId;
    string fecha;
    double monto;

    Venta();
    Venta(Videojuego, int, string, double);
    void mostrar() const;
};