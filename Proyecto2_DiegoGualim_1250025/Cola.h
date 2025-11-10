#ifndef COLA_H
#define COLA_H
#include <string>
#include <iostream>
using namespace std;

struct Evento {
    string descripcion;
};

struct NodoCola {
    Evento dato;
    NodoCola* siguiente;
};

class Cola {
private:
    NodoCola* frente;
    NodoCola* final;
    int cantidad;
public:
    Cola() : frente(nullptr), final(nullptr), cantidad(0) {}
    ~Cola() { limpiar(); }

    void encolar(const Evento& e) {
        NodoCola* nuevo = new NodoCola{ e, nullptr };
        if (final) final->siguiente = nuevo;
        else frente = nuevo;
        final = nuevo;
        cantidad++;
    }

    bool desencolar(Evento& e) {
        if (estaVacia()) return false;
        NodoCola* temp = frente;
        e = temp->dato;
        frente = frente->siguiente;
        if (!frente) final = nullptr;
        delete temp;
        cantidad--;
        return true;
    }

    bool estaVacia() const { return frente == nullptr; }

    void limpiar() {
        Evento e;
        while (desencolar(e));
    }

    int size() const { return cantidad; }
};
#endif