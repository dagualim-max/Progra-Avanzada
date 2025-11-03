#pragma once
#include <iostream>

using namespace std;

template<typename T>

struct Nodo
{
    T dato;
    Nodo* siguiente;
    Nodo(T _dato)
    {
        dato = _dato;
        siguiente = nullptr;
    }
};