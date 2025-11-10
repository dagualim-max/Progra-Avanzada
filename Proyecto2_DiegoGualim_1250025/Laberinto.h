#ifndef LABERINTO_H
#define LABERINTO_H
#include "Celda.h"
#include "Pos.h"
#include "Jugador.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class Laberinto {
private:
    int filas;
    int columnas;
    Celda** matriz;
    Pos inicio;
    Pos salida;
    vector<Pos> enemigos;

    void liberarMemoria();
    bool hayCamino(Pos actual, Pos destino, bool** visitado);
    bool validarCamino();
    Pos obtenerCeldaLibreAleatoria();
    void colocarElementosAleatorios(TipoCelda tipo, int cantidad);
public:
    Laberinto(int f = 7, int c = 7);
    ~Laberinto();

    void generar();
    void mostrar(Pos jugador) const;
    bool esValido(int fila, int columna) const;
    Celda* getCelda(int fila, int columna);
    Pos getInicio() const;
    Pos getSalida() const;
    int getFilas() const { return filas; }
    int getColumnas() const { return columnas; }
    void regenerar();
    void interactuar(Pos jugador, Jugador& jugadorObj, bool& jugando);
};
#endif