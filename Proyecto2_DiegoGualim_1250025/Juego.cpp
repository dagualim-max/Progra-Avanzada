#include "Juego.h"

Juego::Juego(int _intervalo, int tamanho): laberinto(tamanho, tamanho),jugador(laberinto.getInicio()),intervalo(_intervalo),tiempoInicial(time(nullptr))
{
    enemigos.push_back(Enemigo(laberinto.getInicio()));
}

void Juego::iniciar()
{
    cout << "Se ha generado un Laberinto de forma aleatoria" << endl;

    bool jugando = true;

    Pos salida = laberinto.getSalida();

    Pos posGuardian = salida;

    if (salida.fila > 0)
    {
        posGuardian.fila -= 1;
    }
    else if (salida.fila < laberinto.getFilas() - 1)
    {
        posGuardian.fila += 1;
    }

    enemigos.clear();
    enemigos.push_back(Enemigo(posGuardian));

    laberinto.getCelda(posGuardian.fila, posGuardian.columna)->tipo = ENEMIGO;

    while (jugando)
    {
        time_t ahora = time(nullptr);
        int tiempoRestante = intervalo - static_cast<int>(difftime(ahora, tiempoInicial));

        if (tiempoRestante <= 0)
        {
            cout << "Generando un nuevo laberinto" << endl;
            laberinto.regenerar();

            jugador.setPos(laberinto.getInicio());
            tiempoInicial = time(nullptr);
            tiempoRestante = intervalo;

            salida = laberinto.getSalida();
            posGuardian = salida;

            if (salida.fila > 0)
            {
                posGuardian.fila -= 1;
            }
            else if (salida.fila < laberinto.getFilas() - 1)
            {
                posGuardian.fila += 1;
            }

            enemigos.clear();
            enemigos.push_back(Enemigo(posGuardian));
            laberinto.getCelda(posGuardian.fila, posGuardian.columna)->tipo = ENEMIGO;
        }

        cout << "Tiempo restante: " << tiempoRestante << " segundos" << endl;
        cout << "Jugador en (" << jugador.getPos().fila << ", " << jugador.getPos().columna << ")" << endl;
        cout << "Vida: " << jugador.getVida() << endl;

        laberinto.mostrar(jugador.getPos());

        turnoJugador();

        if (jugando)
        {
            turnoEnemigos();
        }

        if (jugador.getPos() == laberinto.getSalida())
        {
            std::cout << "Has logrado escapar del laberinto" << endl;
            jugando = false;
        }
        else if (jugador.getVida() <= 0)
        {
            std::cout << "Has muerto. Fin del juego" << endl;
            jugando = false;
        }

        if (jugando)
        {
            system("pause");
            system("cls");
        }
    }
}

void Juego::turnoJugador() {
    std::cout << "Movimiento (W/A/S/D), U para deshacer, I para inventario, Q para salir: ";
    char tecla = toupper(_getch());

    Pos posActual = jugador.getPos();
    Pos nueva = posActual;

    switch (tecla)
    {
    case 'W': 
        nueva.fila--;
        break;
    case 'S':
        nueva.fila++;
        break;
    case 'A':
        nueva.columna--;
        break;
    case 'D':
        nueva.columna++;
        break;
    case 'U':
        if (jugador.deshacerMovimiento())
        {
            cout << "Movimiento deshecho" << endl;
        }
        else
        {
            cout << "No se pudo deshacer" << endl;
        }
        return;
    case 'I':
        jugador.mostrarInventario();
        return;
    case 'Q':
        cout << "Saliendo del juego";
        exit(0);
    default:
        cout << "Tecla inválida" << endl;
        return;
    }

    if (laberinto.esValido(nueva.fila, nueva.columna))
    {
        jugador.mover(nueva);
        cout << "Te moviste a (" << nueva.fila << ", " << nueva.columna << ")" << endl;

        bool jugando = true;
        laberinto.interactuar(nueva, jugador, jugando);
    }
    else {
        cout << "No puedes moverte ahí (pared o fuera del laberinto)" << endl;
    }
}

void Juego::turnoEnemigos()
{
    cout << "Turno del Guardián" << endl;

    if (!enemigos.empty())
    {
        enemigos[0].patrullar(laberinto);

        if (enemigos[0].getPosicion() == jugador.getPos())
        {
            cout << "El Guardián te atac, pierdes 20 de vida" << endl;
            jugador.setVida(jugador.getVida() - 20);
        }
    }
}

void Juego::verificarEventos()
{
    Evento e;
    while (!eventos.estaVacia())
    {
        if (eventos.desencolar(e))
        {
            std::cout << "Evento: " << e.descripcion << endl;
        }
    }
}