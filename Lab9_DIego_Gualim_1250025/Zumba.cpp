#include "Zumba.h"

Zumba::Zumba(string _instructor, double _precio, int _cupo) : Gimnasio("Zumba", _instructor, _precio, _cupo)
{

}

void Zumba::mostrarInfo() const
{
	cout << "Clase de Zumba";
	Gimnasio::mostrarInfo();
}