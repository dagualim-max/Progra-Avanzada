#pragma once
#include <iostream>

using namespace std;

class Tarea
{

	public:

		string nombre;
		string descripcion;
		string fechaLimite;
		int prioridad = 0;

		Tarea()
		{ }

		Tarea(string _nombre, string _descripcion, string _fechaLimite, int _prioridad)
		{
			nombre = _nombre;
			descripcion = _descripcion;
			fechaLimite = _fechaLimite;
			prioridad = _prioridad;
		}

		void mostrarTarea()
		{
			cout << "Nombre: " << nombre << endl;
			cout << "Descripción: " << descripcion << endl;
			cout << "Fecha límite: " << fechaLimite << endl;
			cout << "Prioridad: ";

			if (prioridad == 1)
			{
				cout << "Alta";
			}
			else if (prioridad == 2)
			{
				cout << "Media";
			}
			else
			{
				cout << "Baja";
			}
			cout << endl;
		}
};

