#include "Spinning.h"

Spinning::Spinning(string _instructor, double _precio, int _cupo) : Gimnasio("Spinning", _instructor, _precio, _cupo)
{

}

void Spinning::mostrarInfo() const
{
	cout << "Clase de Spinning";
	Gimnasio::mostrarInfo();
}