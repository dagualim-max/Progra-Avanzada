#pragma once
#include <iostream>
#include "Actividad.h"

using namespace std;

class NodoCircular
{
	public:
		Actividad dato;
		NodoCircular *anterior;
		NodoCircular* siguiente;

		NodoCircular(Actividad A)
		{
			dato = A;
			anterior = nullptr;
			siguiente = nullptr;
		}

};

