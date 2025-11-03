#include "Videojuego.h"

Videojuego::Videojuego()
{
	precio = 0;
	añoLanzamiento = 0;
}

Videojuego::Videojuego(string _titulo, string _genero, double _precio, int _añoLanzamiento)
{
	titulo = _titulo;
	genero = _genero;
	precio = _precio;
	añoLanzamiento = _añoLanzamiento;
}

void Videojuego :: mostrar() const
{
	cout << "Título: " << titulo << endl;
	cout << "Genero: " << genero << endl;
	cout << "Precio: $" << setprecision(2) << precio << endl;
	cout << "Año de Lanzamiento: " << añoLanzamiento << endl;
}