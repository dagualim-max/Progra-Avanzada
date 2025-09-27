#include "Boxeo.h"

Boxeo::Boxeo(string _instructor, double _precio, int _cupo) : Gimnasio("Boxeo", _instructor, _precio, _cupo) 
{

}

void Boxeo::mostrarInfo() const
{
	cout << "Clase de Boxeo";
	Gimnasio::mostrarInfo();
}