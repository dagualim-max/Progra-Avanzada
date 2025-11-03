#pragma once
#include <iostream>
#include <string>
#include <type_traits>
#include "Nodo.h"
#include "Videojuego.h"
#include "Cliente.h"
#include "Venta.h"
using namespace std;

template<typename T>

class Lista {
private:
    Nodo<T>* cabeza;

public:
    Lista()
    {
        cabeza = nullptr;
    }

    void agregarVideojuego(const T& dato)
    {
        Nodo<T>* nuevo_nodo = new Nodo<T>(dato);
        
        if (!cabeza)
        {
            cabeza = nuevo;
        }
        else
        {
            Nodo<T>* aux = cabeza;
            while (aux->siguiente)
            {
                aux = aux->siguiente;
            }
            aux->siguiente = nuevo;
        }
    }

    void eliminarVideojuego(const string& titulo)
    {
        if (!cabeza)
        {
            return;
        }

        Nodo<T>* actual = cabeza;
        Nodo<T>* anterior = nullptr;
        while (actual)
        {
            if constexpr (is_same<T, Videojuego>::value)
            {
                if (actual->dato.titulo == titulo)
                {
                    if (anterior)
                    {
                        anterior->siguiente = actual->siguiente;
                    }
                    else
                    {
                        cabeza = actual->siguiente;
                    }
                    delete actual;
                    return;
                }
            }
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    Nodo<T>* buscarVideojuegoTitulo(const string& titulo)
    {
        Nodo<T>* aux = cabeza;

        while (aux)
        {
            if constexpr (is_same<T, Videojuego>::value)
            {
                if (aux->dato.titulo == titulo)
                {
                    return aux;
                }
            }
            aux = aux->sig;
        }
        return nullptr;
    }

    Nodo<T>* buscarVideojuegoId(int id)
    {
        Nodo<T>* aux = cabeza;

        while (aux)
        {
            if constexpr (is_same<T, Cliente>::value)
            {
                if (aux->dato.id == id)
                {
                    return aux;

                }
            }
            aux = aux->sig;
        }
        return nullptr;
    }

    void mostrar() const
    {
        Nodo<T>* aux = cabeza;

        while (aux)
        {
            aux->dato.mostrar();
            aux = aux->siguiente;
        }
    }

    bool vacia() const
    {
        return cabeza == nullptr;
    }

    Nodo<T>* obtenerCabeza()
    {
        return cabeza;
    }
};