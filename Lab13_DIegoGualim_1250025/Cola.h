#pragma once
#include <iostream>
#include <stdexcept>
#include "Nodo.h"
using namespace std;

template<typename T>

class Cola
{
private:
    Nodo<T>* frente;
    Nodo<T>* fin;
public:
    Cola()
    {
        frente = nullptr;
        fin = nullptr;
    }

    void push(const T& dato)
    {
        Nodo<T>* nuevo_nodo = new Nodo<T>(dato);

        if (!frente)
        {
            frente = fin = nuevo;
        }
        else
        {
            fin->siguiente = nuevo;
            fin = nuevo;
        }
    }

    bool empty() const
    {
        return frente == nullptr;
    }

    T pop()
    {
        if (empty())
        {
            throw runtime_error("Cola vacía");
        }
        
        Nodo<T>* aux = frente;

        frente = frente->siguiente;
        T dato = aux->dato;
        delete aux;
        if (!frente)
        {
            fin = nullptr;
        }

        return dato;
    }

    void mostrar() const
    {
        Nodo<T>* aux = frente;

        while (aux)
        {
            cout << aux->dato << endl;
            aux = aux->sig;
        }
    }
};