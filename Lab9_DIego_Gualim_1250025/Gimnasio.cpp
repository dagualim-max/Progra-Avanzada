#include "Gimnasio.h"

Gimnasio::Gimnasio(std::string _nombre, std::string _instructor, double _precio, int _cupo)
{
	nombre = _nombre;
	instructor = _instructor;
	precio = _precio;
	cupo = _cupo;
}

Gimnasio::~Gimnasio()
{

}

std::string Gimnasio::getNombre() const
{
	return nombre;
}

double Gimnasio::getPrecio() const
{
	return precio;
}

void Gimnasio::mostrarInfo() const
{
	std::cout << "Clase: " << nombre << endl;
	std::cout << "Instructor: " << instructor << endl;
	std::cout << "Precio: $" << precio << endl;
	std::cout << "Cupo: " << cupo << endl;
}