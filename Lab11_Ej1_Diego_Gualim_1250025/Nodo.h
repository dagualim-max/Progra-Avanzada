#pragma once
#include <iostream>
#include "Tarea.h"

using namespace std;

class Nodo
{
	public:
		Nodo* anterior;
		Tarea dato;
		Nodo* siguiente;

		Nodo(Tarea t)
		{
			dato = t;
			anterior = nullptr;
			siguiente = nullptr;
		}
};

