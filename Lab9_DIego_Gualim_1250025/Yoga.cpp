#include "Yoga.h"

Yoga::Yoga(string _instructor, double _precio, int _cupo) : Gimnasio("Yoga", _instructor, _precio, _cupo)
{

}

void Yoga::mostrarInfo() const
{
	cout << "Clase de Yoga";
	Gimnasio::mostrarInfo();
}