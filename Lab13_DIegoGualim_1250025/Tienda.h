#pragma once
#include <iostream>
#include "Lista.h"
#include "Pila.h"
#include "Cola.h"
#include "Videojuego.h"
#include "Cliente.h"
#include "Venta.h"
using namespace std;

class Tienda {
private:
    Lista<Videojuego> catalogo;
    Lista<Cliente> clientes;
    Lista<Venta> historial;
    Pila<Venta> devoluciones;
    Cola<string> solicitudes; // simplificada para ejemplo
    int siguienteId = 1;

public:
    void agregarVideojuego(Videojuego v)
    {
        catalogo.agregarVideojuego(v);
    }

    void mostrarCatalogo() const
    {
        catalogo.mostrar();
    }

    void eliminarVideojuego(string t)
    {
        catalogo.eliminarVideojuego(t);
    }

    void registrarCliente(string n, string c)
    {
        clientes.agregarVideojuego(Cliente(n, siguienteId++, c));
    }

    void mostrarClientes() const
    {
        clientes.mostrar();
    }

    void registrarVenta(string titulo, int clienteId, string fecha)
    {
        Nodo<Videojuego>* videojuego = catalogo.buscarVideojuegoTitulo(titulo);
        Nodo<Cliente>* cliente = clientes.buscarVideojuegoId(clienteId);

        if (!videojuego || !cliente)
        {
            cout << "Error: cliente o videojuego no encontrado" << endl;
            return;
        }

        Venta venta(videojuego->dato, cliente->dato.id, fecha, videojuego->dato.precio);

        historial.agregarVideojuego(venta);
        devoluciones.push(venta);
        cliente->dato.compras++;

        cout << "Venta registrada correctamente" << endl;
    }

    void registrarDevolucion()
    {
        if (devoluciones.empty())
        {
            cout << "No hay devoluciones" << endl;
            return;
        }
        Venta v = devoluciones.pop();
        cout << "Devolución procesada del juego: " << v.videojuego.titulo << endl;
    }

    void mostrarHistorial() const
    {
        historial.mostrar();
    }

    void mostrarDevoluciones() const
    {
        devoluciones.mostrar();
    }
};