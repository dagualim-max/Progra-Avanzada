#ifndef LISTA_H
#define LISTA_H

#include <string>
#include <iostream>

using namespace std;

struct NodoLista {
    std::string objeto;
    NodoLista* siguiente;
};

class Lista {
private:
    NodoLista* cabeza;
    int cantidad;

public:
    Lista() : cabeza(nullptr), cantidad(0) {}
    ~Lista() { limpiar(); }

    void agregar(const std::string& nombre) {
        NodoLista* nuevo = new NodoLista{ nombre, nullptr };
        if (!cabeza) cabeza = nuevo;
        else {
            NodoLista* temp = cabeza;
            while (temp->siguiente) temp = temp->siguiente;
            temp->siguiente = nuevo;
        }
        cantidad++;
    }

    void mostrar() const {
        NodoLista* temp = cabeza;
        std::cout << "Inventario: [";
        while (temp) {
            std::cout << temp->objeto;
            if (temp->siguiente) std::cout << ", ";
            temp = temp->siguiente;
        }
        std::cout << "]\n";
    }

    bool contiene(const std::string& nombre) const {
        NodoLista* temp = cabeza;
        while (temp) {
            if (temp->objeto == nombre) return true;
            temp = temp->siguiente;
        }
        return false;
    }

    void limpiar() {
        NodoLista* temp = cabeza;
        while (temp) {
            NodoLista* borrar = temp;
            temp = temp->siguiente;
            delete borrar;
        }
        cabeza = nullptr;
        cantidad = 0;
    }

    int size() const { return cantidad; }
};

#endif