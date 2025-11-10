#ifndef JUGADOR_H
#define JUGADOR_H
#include "Pos.h"
#include "Pila.h"
#include "Lista.h"
#include <iostream>
using namespace std;

class Jugador {
private:
    Pos posicion;
    int vida;
    Lista inventario;
    Pila historial;
    int movimientosDeshechos;

public:
    Jugador(Pos inicio = Pos()) : posicion(inicio), vida(100), movimientosDeshechos(0)
    {
    }

    Pos getPos() const { return posicion; }
    void setPos(Pos _posicion) { posicion = _posicion; }
    int getVida() const { return vida; }
    void setVida(int v) { vida = v; }

    void mover(Pos nuevaPos)
    {
        historial.push(posicion);
        posicion = nuevaPos;
    }

    bool deshacerMovimiento()
    {
        if (movimientosDeshechos >= 2)
        {
            cout << "Ya no puedes deshacer más movimientos" << endl;
            return false;
        }
        Pos anterior;
        if (historial.pop(anterior))
        {
            posicion = anterior;
            movimientosDeshechos++;
            cout << "Movimiento deshecho. Volviste a ("<< posicion.fila << ", " << posicion.columna << ")" << endl;
            return true;
        }
        cout << "No hay movimientos anteriores para deshacer" << endl;
        return false;
    }

    void agregarObjeto(const std::string& obj)
    {
        inventario.agregar(obj);
        cout << "Objeto agregado al inventario: " << obj << endl;
    }

    void mostrarInventario() const {
        std::cout << "Inventario:" << endl;
        inventario.mostrar();
    }

    bool tieneObjeto(const std::string& obj) const
    {
        return inventario.contiene(obj);
    }
};
#endif