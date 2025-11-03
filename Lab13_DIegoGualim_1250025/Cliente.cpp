#include "Cliente.h"

Cliente::Cliente()
{
	id = 0;
	compras = 0;
}

Cliente::Cliente(string _nombre, int _id, string _correo)
{
	nombre = _nombre;
	id = _id;
	correo = _correo;
	compras = 0;
}

void Cliente::mostrar() const
{
	cout << "ID: " << id << endl;
	cout << "Nombre: " << nombre << endl;
	cout << "Correo: " << correo << endl;
	cout << "Compras: " << compras << endl;
}