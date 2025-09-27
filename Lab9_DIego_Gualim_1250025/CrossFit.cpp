#include "CrossFit.h"

CrossFit::CrossFit(string _instructor, double _precio, int _cupo) : Gimnasio("CrossFit", _instructor, _precio, _cupo)
{

}

void CrossFit::mostrarInfo() const
{
	cout << "Clase de CrossFit";
	Gimnasio::mostrarInfo();
}