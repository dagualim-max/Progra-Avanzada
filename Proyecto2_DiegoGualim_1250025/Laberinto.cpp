#include "Laberinto.h"

Laberinto::Laberinto(int f, int c) : filas(f), columnas(c)
{ 
    ((unsigned)time(nullptr)); matriz = new Celda * [filas];
    for (int i = 0; i < filas; ++i)
    {
        matriz[i] = new Celda[columnas];
    }
    generar();
}

Laberinto::~Laberinto()
{
    liberarMemoria();
}

void Laberinto::liberarMemoria()
{
    if (!matriz) return;
    for (int i = 0; i < filas; ++i)
    {
        delete[] matriz[i];
    }
    delete[] matriz;
    matriz = nullptr;
}

bool Laberinto::hayCamino(Pos actual, Pos destino, bool** visitado)
{
    if (actual.fila < 0 || actual.columna < 0 || actual.fila >= filas || actual.columna >= columnas) return false;

    if (matriz[actual.fila][actual.columna].tipo == PARED || visitado[actual.fila][actual.columna]) return false;

    if (actual.fila == destino.fila && actual.columna == destino.columna) return true;

    visitado[actual.fila][actual.columna] = true;

    Pos movs[4] = 
    {
        {actual.fila - 1, actual.columna},
        {actual.fila + 1, actual.columna},
        {actual.fila, actual.columna - 1},
        {actual.fila, actual.columna + 1}
    };

    for (auto m : movs)
        if (hayCamino(m, destino, visitado))
            return true;

    return false;
}

bool Laberinto::validarCamino() {
    bool** visitado = new bool* [filas];
    for (int i = 0; i < filas; ++i)
        visitado[i] = new bool[columnas] {false};

    bool ok = hayCamino(inicio, salida, visitado);

    for (int i = 0; i < filas; ++i)
        delete[] visitado[i];
    delete[] visitado;
    return ok;
}

Pos Laberinto::obtenerCeldaLibreAleatoria() {
    while (true) {
        int f = rand() % filas;
        int c = rand() % columnas;
        if (matriz[f][c].tipo == VACIO)
            return { f, c };
    }
}

void Laberinto::colocarElementosAleatorios(TipoCelda tipo, int cantidad) {
    for (int i = 0; i < cantidad; ++i) {
        Pos p = obtenerCeldaLibreAleatoria();
        matriz[p.fila][p.columna].tipo = tipo;
        if (tipo == ENEMIGO)
            enemigos.push_back(p);
    }
}

void Laberinto::generar() {
    enemigos.clear();
    bool valido = false;

    while (!valido) {
        
        for (int f = 0; f < filas; ++f)
            for (int c = 0; c < columnas; ++c)
                matriz[f][c] = Celda((rand() % 100 < 30) ? PARED : VACIO);

        inicio = { 0, 0 };
        salida = { filas - 1, columnas - 1 };
        matriz[inicio.fila][inicio.columna].tipo = INICIO;
        matriz[salida.fila][salida.columna].tipo = SALIDA;

        valido = validarCamino();
    }

    int total = filas * columnas;
    int enemigosCant = total * 0.10;
    int objetos = total * 0.15;
    int trampas = total * 0.06;

    colocarElementosAleatorios(ENEMIGO, enemigosCant);
    colocarElementosAleatorios(LLAVE, objetos / 2);
    colocarElementosAleatorios(POCION, objetos / 2);
    colocarElementosAleatorios(TRAMPA, trampas);
}

void Laberinto::mostrar(Pos jugador) const {
    for (int f = 0; f < filas; ++f) {
        for (int c = 0; c < columnas; ++c) {
            if (jugador.fila == f && jugador.columna == c) {
                cout << " P ";
                continue;
            }

            char ch = '?';
            switch (matriz[f][c].tipo) {
            case PARED: ch = '#'; break;
            case VACIO: ch = '.'; break;
            case INICIO: ch = 'I'; break;
            case SALIDA: ch = 'S'; break;
            case ENEMIGO: ch = 'E'; break;
            case LLAVE: ch = 'K'; break;
            case POCION: ch = '+'; break;
            case TRAMPA: ch = 'T'; break;
            default: ch = '?'; break;
            }
            cout << ' ' << ch << ' ';
        }
        cout << endl;
    }
}

bool Laberinto::esValido(int fila, int columna) const {
    return fila >= 0 && columna >= 0 &&
        fila < filas && columna < columnas &&
        matriz[fila][columna].tipo != PARED;
}

Celda* Laberinto::getCelda(int fila, int columna) {
    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas)
        return nullptr;
    return &matriz[fila][columna];
}

Pos Laberinto::getInicio() const { return inicio; }
Pos Laberinto::getSalida() const { return salida; }

void Laberinto::regenerar() {
    cout << "El laberinto ha cambiado de forma" << endl;
    generar();
}



void Laberinto::interactuar(Pos jugadorPos, Jugador& jugador, bool& jugando) {
    Celda* celdaActual = getCelda(jugadorPos.fila, jugadorPos.columna);
    if (!celdaActual) return;

    switch (celdaActual->tipo) {
    case ENEMIGO:
        std::cout << "Te has encontrado con un enemigo! Pierdes 20 de vida" << endl;
        jugador.setVida(jugador.getVida() - 20);
        if (jugador.getVida() <= 0)
        {
            std::cout << "Has muerto en combate" << endl;
            jugando = false;
        }
        celdaActual->tipo = VACIO;
        break;

    case TRAMPA:
        std::cout << "Caíste en una trampa, pierdes 10 de vida" << endl;
        jugador.setVida(jugador.getVida() - 10);
        if (jugador.getVida() <= 0)
        {
            cout << "Has muerto en combate" << endl;
            jugando = false;
        }
        celdaActual->tipo = VACIO;
        break;

    case POCION:
        std::cout << "Encontraste una poción. Recuperas 10 puntos de vida" << endl;
        {
            int nuevaVida = jugador.getVida() + 10;
            jugador.setVida(nuevaVida);
        }
        celdaActual->tipo = VACIO;
        break;

    case LLAVE:
        std::cout << "Encontraste una llave! Podrá abrir una puerta más adelante" << endl;
        jugador.agregarObjeto("Llave");
        celdaActual->tipo = VACIO;
        break;

    case SALIDA:
        std::cout << "Has logrado escaar del laberinto" << endl;
        jugando = false;
        break;

    default:
        break;
    }
}