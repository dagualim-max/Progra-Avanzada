#ifndef PILA_H
#define PILA_H

#include "Pos.h"
#include <iostream>

using namespace std;

struct NodoPila {
    Pos dato;
    NodoPila* siguiente;
};

class Pila {
private:
    NodoPila* tope;
    int cantidad;

public:
    Pila() : tope(nullptr), cantidad(0) {}
    ~Pila() { limpiar(); }

    void push(Pos valor) {
        NodoPila* nuevo = new NodoPila{ valor, tope };
        tope = nuevo;
        cantidad++;
    }

    bool pop(Pos& valor) {
        if (estaVacia()) return false;
        NodoPila* temp = tope;
        valor = temp->dato;
        tope = temp->siguiente;
        delete temp;
        cantidad--;
        return true;
    }

    bool peek(Pos& valor) const {
        if (estaVacia()) return false;
        valor = tope->dato;
        return true;
    }

    bool estaVacia() const { return tope == nullptr; }

    void limpiar() {
        NodoPila* actual = tope;
        while (actual) {
            NodoPila* temp = actual;
            actual = actual->siguiente;
            delete temp;
        }
        tope = nullptr;
        cantidad = 0;
    }

    int size() const { return cantidad; }
};

#endif