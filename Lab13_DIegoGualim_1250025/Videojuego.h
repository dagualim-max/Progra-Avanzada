#pragma once
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Videojuego {
public:
    string titulo;
    string genero;
    double precio;
    int añoLanzamiento;

    Videojuego();
    Videojuego(string, string, double, int);

    void mostrar() const;
};