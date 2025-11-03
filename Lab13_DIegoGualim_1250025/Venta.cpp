#include "Venta.h"

Venta::Venta()
{
	clienteId = 0;
	monto = 0;
}

Venta::Venta(Videojuego _videojuego, int _clienteId, string _fecha, double _monto)
{
	videojuego = _videojuego;
	clienteId = _clienteId;
	fecha = _fecha;
	monto = _monto;
}

void Venta::mostrar() const
{
	cout << "Fecha de Venta: " << fecha << endl;
	cout << "Cliente ID: " << clienteId << endl;
	cout << "Monto: $" << setprecision(2) << monto << endl;
	videojuego.mostrar();
}