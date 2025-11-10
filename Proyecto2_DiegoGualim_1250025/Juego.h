#ifndef JUEGO_H
#define JUEGO_H
#include "Laberinto.h"
#include "Jugador.h"
#include "Enemigo.h"
#include "Cola.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <conio.h>
#include <cstdlib>
using namespace std;

class Juego
{
private:
    Laberinto laberinto;
    Jugador jugador;
    vector<Enemigo> enemigos;
    Cola eventos;
    int intervalo;
    time_t tiempoInicial;

    void turnoJugador();
    void turnoEnemigos();
    void verificarEventos();

public:
    Juego(int, int);
    void iniciar();
};
#endif