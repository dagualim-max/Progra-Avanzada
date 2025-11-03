#pragma once
#include <iostream>
#include <stdexcept>
#include "Nodo.h"
using namespace std;

template<typename T>

class Pila
{
private:
    Nodo<T>* tope;
public:
    Pila()
    {
        tope = nullptr;
    }

    void push(const T& dato)
    {
        Nodo<T>* nuevo_nodo = new Nodo<T>(dato);
        nuevo_nodo->sig = tope;
        tope = nuevo_nodo;
    }

    bool empty() const
    {
        return tope == nullptr;
    }

    T pop()
    {
        if (empty())
        {
            throw runtime_error("Pila vacía");
        }
        Nodo<T>* aux = tope;

        tope = tope->sig;
        
        T dato = aux->dato;
        delete aux;
        return dato;
    }

    void mostrar() const
    {
        Nodo<T>* aux = tope;
        while (aux)
        {
            aux->dato.mostrar();
            aux = aux->sig;
        }
    }
};