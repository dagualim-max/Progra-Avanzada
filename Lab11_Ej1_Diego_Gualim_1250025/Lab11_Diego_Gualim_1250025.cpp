#include <iostream>
#include "ListaTareas.h"

using namespace std;

void menu();

int main()
{
	
}

void menu()
{

	ListaTareas lista;
	int opc;

	do
	{

		cout << "MENU" << endl;
		cout << "1. Agregar una tarea" << endl;
		cout << "2. Eliminar una tarea" << endl;
		cout << "3. Buscar una tarea" << endl;
		cout << "4. Mostrar todas las tareas" << endl;
		cout << "5. Mostrar tareas en orden inverso" << endl;
		cout << "6. Salir" << endl;

		switch (opc)
		{
		case 1:

			lista.agregarTarea();

			break;
		case 2:

			lista.eliminarTarea();

			break;
		case 3:

			lista.buscarTarea();

			break;
		case 4:

			lista.mostrarTodasTareas();

			break;
		case 5:

			lista.tareasEnInverso();

			break;
		case 6:

			cout << "Cerrando el programa";

			break;
		default:

			cout << "Opcion no valida";

			break;
		}

		system("pause");
		system("cls");

	} while (opc != 6);

}