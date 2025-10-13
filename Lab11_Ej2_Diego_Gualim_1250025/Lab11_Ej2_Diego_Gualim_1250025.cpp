#include <iostream>
#include "RelojActividades.h"

using namespace std;

void menu();

int main()
{

    menu();
    return 0;

}

void menu()
{
    RelojActividades reloj;
    int opc;

    reloj.establecerHoraActual();

    system("pause");
    system("cls");

    do {
        cout << "MENU" << endl;
        cout << "1. Agregar actividad" << endl;
        cout << "2. Eliminar actividad" << endl;
        cout << "3. Mostrar actividad actual" << endl;
        cout << "4. Avanzar al siguiente bloque horario" << endl;
        cout << "5. Retroceder al bloque anterior" << endl;
        cout << "6. Recorrer actividades en bucle" << endl;
        cout << "7. Cambiar hora actual" << endl;
        cout << "8. Salir" << endl;
        cout << "Opción: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            reloj.agregarActividad();
            break;
        case 2:
            reloj.eliminarActividad();
            break;
        case 3:
            reloj.mostrarActividadActual();
            break;
        case 4:
            reloj.avanzarBloqueSiguiente();
            break;
        case 5:
            reloj.retrocederBloqueAnterior();
            break;
        case 6:
            reloj.recorrerEnBucle();
            break;
        case 7:
            reloj.establecerHoraActual();
            break;
        case 8:
            cout << "Saliendo del programa";
            break;
        default: 
            cout << "Opción no válida";
            break;
        }

        system("pause");
        system("cls");

    } while (opc != 8);
}