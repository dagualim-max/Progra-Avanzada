#include "ListaTareas.h"

ListaTareas::ListaTareas()
{
    cabeza = nullptr;
    cola = nullptr;
}

void ListaTareas::agregarTarea()
{
   
    string nombre, descripcion, fecha;
    int prioridad;

    cout << "Ingrese el nombre de la tarea: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese la descripción: ";
    getline(cin, descripcion);

    cout << "Ingrese la fecha límite: ";
    getline(cin, fecha);

    cout << "Ingrese la prioridad (1=Alta, 2=Media, 3=Baja): ";
    cin >> prioridad;

    Tarea nuevaTarea(nombre, descripcion, fecha, prioridad);
    Nodo* nuevo_nodo = new Nodo(nuevaTarea);

    if (cabeza == nullptr)
    {
        cabeza = cola = nuevo_nodo;
        cout << "La tarea se ha agregado correctamente" << endl;
        return;
    }

    Nodo* actual = cabeza;
    while (actual != nullptr && actual->dato.prioridad <= prioridad)
    {
        actual = actual->siguiente;
    }

    if (actual == cabeza)
    {
        nuevo_nodo->siguiente = cabeza;
        cabeza->anterior = nuevo_nodo;
        cabeza = nuevo_nodo;
    }
    else if (actual == nullptr)
    {
        cola->siguiente = nuevo_nodo;
        nuevo_nodo->anterior = cola;
        cola = nuevo_nodo;
    }
    else 
    {
        nuevo_nodo->siguiente = actual;
        nuevo_nodo->anterior = actual->anterior;
        actual->anterior->siguiente = nuevo_nodo;
        actual->anterior = nuevo_nodo;
    }

    cout << "Tarea agregada correctamente.\n";

}

void ListaTareas::eliminarTarea()
{

    if (cabeza == nullptr)
    {
        cout << "La lista está vacía.\n";
        return;
    }

    string nombre;
    cout << "Ingrese el nombre de la tarea a eliminar: ";
    cin.ignore();
    getline(cin, nombre);

    Nodo* actual = cabeza;
    while (actual != nullptr && actual->dato.nombre != nombre)
    {
        actual = actual->siguiente;
    }

    if (actual == nullptr)
    {
        cout << "La tarea " << nombre << " no existe en la lista" << endl;
        return;
    }

    if (actual == cabeza)
    {
        cabeza = actual->siguiente;
    }
    
    if (actual == cola)
    {
        cola = actual->anterior;
    }

    if (actual->anterior != nullptr)
    {
        actual->anterior->siguiente = actual->siguiente;
    }
    if (actual->siguiente != nullptr)
    {
        actual->siguiente->anterior = actual->anterior;
    }

    delete actual;
    cout << "Tarea eliminada correctamente" << endl;
}

void ListaTareas::buscarTarea()
{

    if (cabeza == nullptr)
    {
        cout << "Aun no hay tareas en su lista de tareas" << endl;
        return;
    }

    string nombre;
    cout << "Ingrese el nombre de la tarea que desea buscar: ";
    cin.ignore();
    getline(cin, nombre);

    Nodo* actual = cabeza;
    while (actual != nullptr)
    {
        if (actual->dato.nombre == nombre) {
            cout << "Mostrando tarea:" << endl;
            actual->dato.mostrarTarea();
            return;
        }
        actual = actual->siguiente;
    }

    cout << "La tarea " << nombre << " no se encuentra en esta lista" << endl;

}

void ListaTareas::mostrarTodasTareas()
{

    if (cabeza == nullptr) {
        cout << "Aun no hay tareas en la lista" << endl;
        return;
    }

    Nodo* actual = cabeza;
    cout << "Lista de tareas en orden de prioridad alta a baja" << endl;
    
    while (actual != nullptr)
    {
        actual->dato.mostrarTarea();
        cout << endl;
        actual = actual->siguiente;
    }

}

void ListaTareas::tareasEnInverso()
{

    if (cola == nullptr)
    {
        cout << "Aun no hay tareas en la lista" << endl;
        return;
    }

    Nodo* actual = cola;
    cout << "Lista de tareas en orden de prioridad baja a alta" << endl;
    
    while (actual != nullptr)
    {
        actual->dato.mostrarTarea();
        cout << endl;
        actual = actual->anterior;
    }

}