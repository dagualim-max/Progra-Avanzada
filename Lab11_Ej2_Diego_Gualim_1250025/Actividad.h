#pragma once
#include <iostream>
#include <string>

using namespace std;

class Actividad
{
	public: 
		string nombre;
		string descripcion;
		int hora;

		Actividad()
		{
			nombre = "";
			descripcion = "";
			hora = 0;
		}

		Actividad(string _nombre, string _descripcion, int _hora)
		{
			nombre = _nombre;
			descripcion = _descripcion;
			hora = _hora;
		}

		void mostrar() const
		{
			cout << "Hora: " << hora << ":00" << endl;
			cout << "Nombre: " << nombre << endl;
			cout << "Descripción: " << descripcion << endl;
		}

};

