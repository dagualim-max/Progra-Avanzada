#pragma once
#include <iostream>
#include "NodoCircular.h"

using namespace std;

class RelojActividades
{
	private:

		NodoCircular* cabeza;
		NodoCircular* actual;
		int horaActual;

	public:

        RelojActividades();
        void establecerHoraActual();
        void agregarActividad();
        void eliminarActividad();
        void mostrarActividadActual();
        void avanzarBloqueSiguiente();
        void retrocederBloqueAnterior();
        void recorrerEnBucle();
};

