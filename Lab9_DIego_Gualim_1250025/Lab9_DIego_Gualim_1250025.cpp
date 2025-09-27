#include <iostream>
#include <String>
#include <vector>
#include "Boxeo.h"
#include "CrossFit.h"
#include "Spinning.h"
#include "Yoga.h"
#include "Zumba.h"

using namespace std;

const int meses = 12;

int masConcurrida(const vector<vector<int>>& asistencias)
{
    int masConcurrido = 0, maxTotal = 0;
    for (int i = 0; i < asistencias.size(); i++)
    {
        int suma = 0;
        for (int j = 0; j < meses; j++) suma += asistencias[i][j];
        if (suma > maxTotal)
        {
            maxTotal = suma;
            masConcurrido = i;
        }
    }
    return masConcurrido;
}

int mesMasConcurrido(const vector<vector<int>>& asistencias)
{
    int masConcurrido = 0, maxTotal = 0;
    for (int j = 0; j < meses; j++)
    {
        int suma = 0;
        for (int i = 0; i < asistencias.size(); i++)
        {
            suma += asistencias[i][j];
        }

        if (suma > maxTotal)
        {
            maxTotal = suma;
            masConcurrido = j;
        }
    }
    return masConcurrido;
}

double ingresosTotales(const vector<Gimnasio*>& clases, const vector<vector<int>>& asistencias)
{
    double total = 0;
    for (int i = 0; i < clases.size(); i++)
    {
        for (int j = 0; j < meses; j++)
        {
            total += asistencias[i][j] * clases[i]->getPrecio();
        }
    }
    return total;
}

int main() {
    vector<Gimnasio*> clases;

    string instructor;
    double precio;
    int cupo;

    cout << "Registro de clases" << endl;
    cout << "Ingresar instructor de Boxeo: ";
    getline(cin, instructor);
    cout << "Ingresar precio: ";
    cin >> precio;
    cout << "Ingrear cupo: ";
    cin >> cupo; cin.ignore();
    clases.push_back(new Boxeo(instructor, precio, cupo));

    cout << "Ingresar instructor de Spinning: ";
    getline(cin, instructor);
    cout << "Ingresar precio: ";
    cin >> precio;
    cout << "ingresar cupo: ";
    cin >> cupo;
    cin.ignore();
    clases.push_back(new Spinning(instructor, precio, cupo));

    cout << "Ingresar instructor de CrossFit: ";
    getline(cin, instructor);
    cout << "ingresar precio: ";
    cin >> precio;
    cout << "Ingresar cupo: ";
    cin >> cupo;
    cin.ignore();
    clases.push_back(new CrossFit(instructor, precio, cupo));

    cout << "Ingresar instructor de Yoga: ";
    getline(cin, instructor);
    cout << "Ingresar precio: ";
    cin >> precio;
    cout << "ingrersar cupo: ";
    cin >> cupo;
    cin.ignore();
    clases.push_back(new Yoga(instructor, precio, cupo));

    cout << "Ingresar instructor de Zumba: ";
    getline(cin, instructor);
    cout << "Ingresar precio: ";
    cin >> precio;
    cout << "Ingresar cupo: ";
    cin >> cupo;
    cin.ignore();
    clases.push_back(new Zumba(instructor, precio, cupo));

    vector<vector<int>> asistencias(clases.size(), vector<int>(meses, 0));

    cout << "Registro de asistencias" << endl;
    for (int i = 0; i < clases.size(); i++)
    {
        cout << "Asistencias para " << clases[i]->getNombre() << ": " << endl;
        for (int j = 0; j < meses; j++) {
            cout << "Mes " << j + 1 << ": ";
            cin >> asistencias[i][j];
        }
    }

    cout << "Listado de Clases" << endl;
    for (auto c : clases) c->mostrarInfo();

    cout << "Tabla de Asistencias " << endl;
    cout << setw(15) << "Clase" << endl;
    for (int j = 0; j < meses; j++)
    {
        cout << setw(6) << j + 1;
        cout << endl;
    }
    for (int i = 0; i < clases.size(); i++)
    {
        cout << setw(15) << clases[i]->getNombre();
        for (int j = 0; j < meses; j++)
        {
            cout << setw(6) << asistencias[i][j];
            cout << endl;
        }
    }

    int msConcurrida = masConcurrida(asistencias);
    int mesMsConcurrido = mesMasConcurrido(asistencias);
    double totalIngresos = ingresosTotales(clases, asistencias);

    cout << "\n=== RESUMEN ===\n";
    cout << "Clase mas concurrida: " << clases[msConcurrida]->getNombre() << endl;
    cout << "Mes con mayor asistencia: " << mesMsConcurrido + 1 << endl;
    cout << "Ingresos totales del gimnasio: $" << fixed << setprecision(2) << totalIngresos << endl;

    for (auto c : clases) delete c;

    return 0;
}