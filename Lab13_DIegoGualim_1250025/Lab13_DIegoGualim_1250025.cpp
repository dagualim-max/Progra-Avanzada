#include <iostream>
#include "Tienda.h"
using namespace std;

int main() {
    Tienda tienda;
    tienda.agregarVideojuego(Videojuego("Hollow Knight", "Metroidvania", 59.99, 2022));
    tienda.agregarVideojuego(Videojuego("Hades", "RogueLike", 24.99, 2020));
    tienda.registrarCliente("Ines", "ine@gmail.com");

    int opc;
    do {
        cout << "1. Mostrar catálogo" << endl;
        cout << "2. Agregar videojuego" << endl;
        cout << "3. Registrar cliente" << endl;
        cout << "4. Registrar venta" << endl;
        cout << "5. Registrar devolución" << endl;
        cout << "6. Mostrar historial" << endl;
        cout << "7. Salir" << endl;
        cout << "Opción: ";
        cin >> opc;
        cin.ignore();

        if (opc == 1)
        {
            tienda.mostrarCatalogo();
        }
        else if (opc == 2)
        {
            string t, g;
            double p;
            int a;
            cout << "Título: ";
            getline(cin, t);
            cout << "Género: ";
            getline(cin, g);
            cout << "Precio: ";
            cin >> p;
            cout << "Año: ";
            cin >> a;
            cin.ignore();
            tienda.agregarVideojuego(Videojuego(t, g, p, a));
        }
        else if (opc == 3)
        {
            string n, c;
            cout << "Nombre: ";
            getline(cin, n);
            cout << "Correo: ";
            getline(cin, c);
            tienda.registrarCliente(n, c);
        }
        else if (opc == 4)
        {
            string t, f;
            int id;
            cout << "Título: ";
            getline(cin, t);
            cout << "ID cliente: ";
            cin >> id;
            cin.ignore();
            cout << "Fecha: ";
            getline(cin, f);
            tienda.registrarVenta(t, id, f);
        }
        else if (opc == 5)
        {
            tienda.registrarDevolucion();
        }
        else if (opc == 6)
        {
            tienda.mostrarHistorial();
        }
    } while (opc != 7);

    return 0;
}