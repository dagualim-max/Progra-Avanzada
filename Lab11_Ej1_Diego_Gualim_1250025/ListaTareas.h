#pragma once
#include <iostream>
#include <string>
#include "Nodo.h"

using namespace std;

class ListaTareas
{

	private:

		Nodo* cabeza;
		Nodo* cola;

	public:

		ListaTareas();
		void agregarTarea();
		void eliminarTarea();
		void buscarTarea();
		void mostrarTodasTareas();
		void tareasEnInverso();

};