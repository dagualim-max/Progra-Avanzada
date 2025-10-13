#include "RelojActividades.h"

RelojActividades::RelojActividades()
{
    cabeza = NULL;
    actual = NULL;
    horaActual = 0;
}

void RelojActividades::establecerHoraActual()
{
    cout << "Ingrese la hora actual (0-23): ";
    cin >> horaActual;
    
    if (horaActual < 0 || horaActual > 23)
    {
        horaActual = 0;
    }
    
    cout << "La hora actual fue establecida en: " << horaActual << ":00" << endl;
}

void RelojActividades::agregarActividad()
{
    string nombre, descripcion;
    int hora;

    cout << "Ingrese nombre de la actividad: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Ingrese descripción: ";
    getline(cin, descripcion);
    cout << "Ingrese la hora (0-23): ";
    cin >> hora;

    Actividad nuevaActividad(nombre, descripcion, hora);
    NodoCircular* nuevo_nodoCircular = new NodoCircular(nuevaActividad);

    if (cabeza == NULL)
    {    
        cabeza = nuevo_nodoCircular;
        cabeza->siguiente = cabeza;
        cabeza->anterior = cabeza;
        actual = cabeza;
        cout << "La actividad ha sido agragada correctamente" << endl;
        return;
    }

    NodoCircular* aux = cabeza;
    do
    {
        if (hora < aux->dato.hora)
            break;
        aux = aux->siguiente;
    } while (aux != cabeza);

    NodoCircular* anterior = aux->anterior;
    anterior->siguiente = nuevo_nodoCircular;
    nuevo_nodoCircular->anterior = anterior;
    nuevo_nodoCircular->siguiente = aux;
    aux->anterior = nuevo_nodoCircular;

    if (hora < cabeza->dato.hora)
    {
        cabeza = nuevo_nodoCircular;
    }

    cout << "La actividad ha sido agregada correctamente a la lista";
}

void RelojActividades::eliminarActividad()
{
    if (cabeza == NULL)
    {
        cout << "Aun no hay actividades en la lista";
        return;
    }

    int hora;
    cout << "Ingrese la hora de la actividad a eliminar: ";
    cin >> hora;

    NodoCircular* aux = cabeza;
    bool encontrada = false;

    do
    {
        if (aux->dato.hora == hora)
        {
            encontrada = true;
            break;
        }
        aux = aux->siguiente;
    } while (aux != cabeza);

    if (!encontrada)
    {
        cout << "No se encontraron actividades a esa hora";
        return;
    }

    if (aux->siguiente == aux)
    {
        delete aux;
        cabeza = NULL;
        actual = NULL;
    }
    else
    {
        aux->anterior->siguiente = aux->siguiente;
        aux->siguiente->anterior = aux->anterior;

        if (aux == cabeza)
        {
            cabeza = aux->siguiente;
        }
        if (aux == actual)
        {
            actual = aux->siguiente;
        }

        delete aux;
    }

    cout << "La actividad ha sido eliminada correctamente";
}

void RelojActividades::mostrarActividadActual()
{
    if (cabeza == NULL)
    {
        cout << "Aun no sehan regisstrado actividades";
        return;
    }

    NodoCircular* aux = cabeza;
    
    do
    {
        if (aux->dato.hora == horaActual)
        {
            cout << "Actividad actual (" << horaActual << ":00):" << endl;
            aux->dato.mostrar();
            actual = aux;
            return;
        }

        aux = aux->siguiente;
    } while (aux != cabeza);

    cout << "No hay ninguna actividad asignada a esta hora";
}

void RelojActividades::avanzarBloqueSiguiente()
{
    if (actual == NULL)
    {
        cout << "No hay actividades asignadas en esta hora";
        return;
    }

    actual = actual->siguiente;
    cout << "Siguiente actividad: " << endl;
    actual->dato.mostrar();
}

void RelojActividades::retrocederBloqueAnterior()
{
    if (actual == NULL)
    {
        cout << "No hay actividades asignadas a esta hora";
        return;
    }

    actual = actual->anterior;
    cout << "Actividad anterior: " << endl;
    actual->dato.mostrar();
}

void RelojActividades::recorrerEnBucle() {
    if (cabeza == NULL)
    {
        cout << "Aun no hay actividades para mostrar";
        return;
    }

    NodoCircular* aux = cabeza;
    cout << "Mostrando actividades del día en bucle" << endl;
    do
    {
        aux->dato.mostrar();
        cout << endl;
        cout << endl;
        aux = aux->siguiente;
    } while (aux != cabeza);
}