#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

struct Titulo
{
    string codigo;
    string nombre;
    string genero;
    int añoLanzamiento;
    double calificacion;
    int copias;
};

void registrarTitulo(vector<Titulo>& catalogo)
 {
    Titulo titulo;
    cout << "Registrar nuevo titulo" << endl;
    cout << "Codigo: "; cin >> titulo.codigo;
    
    for (auto& i : catalogo)
    {
        if (i.codigo == titulo.codigo)
        {
            cout << "Codigo ya existente." << endl;
            return;
        }
    }
    cin.ignore();
    cout << "Nombre: ";
    getline(cin, titulo.nombre);
    cout << "Genero: ";
    getline(cin, titulo.genero);
    cout << "Anio de estreno: ";
    cin >> titulo.añoLanzamiento;
    cout << "Calificacion promedio (1-10): ";
    cin >> titulo.calificacion;
    cout << "Disponibilidad: ";
    cin >> titulo.copias;

    catalogo.push_back(titulo);
    cout << "El titulo ha sido registrado" << endl;
}

void mostrarTitulo(const Titulo& titulo)
{
    cout << "Codigo: " << titulo.codigo << endl;
    cout << "Nombre: " << titulo.nombre << endl;
    cout << "Año de Lanzamiento: " << titulo.añoLanzamiento << endl;
    cout << "Genero: " << titulo.genero << endl;
    cout << "Clasificacion" << titulo.calificacion << endl;
    cout << "Copias: " << titulo.copias << endl;
}

vector<Titulo> busquedaSecuencial(const vector<Titulo>& catalogo, string entrada, string valor)
{
    vector<Titulo> resultados;

    for (auto& i : catalogo)
    {
        if (entrada == "nombre")
        {
            if (i.nombre.find(valor) != string::npos || i.nombre.find(valor.substr(0, valor.size())) != string::npos)
            {
                resultados.push_back(i);
            }
        }
        else if (entrada == "codigo" && i.codigo == valor)
        {
            resultados.push_back(i);
        }
        else if (entrada == "genero" && i.genero == valor)
        {
            resultados.push_back(i);
        }
    }
    return resultados;
}

vector<Titulo> busquedaBinaria(vector<Titulo> catalogo, string entrada, string valor)
{
    vector<Titulo> resultados;
    if (entrada == "codigo")
    {
        sort(catalogo.begin(), catalogo.end(), [](const Titulo& a, const Titulo& b) {return a.codigo < b.codigo;});
        int izquierda = 0, derecha = catalogo.size() - 1;
        
        while (izquierda <= derecha)
        {
            int medio = (izquierda + derecha) / 2;

            if (catalogo[medio].codigo == valor)
            {
                resultados.push_back(catalogo[medio]);
                break;
            }
            else if (catalogo[medio].codigo < valor)
            {
                izquierda = medio + 1;
            }
            else
            {
                derecha = medio - 1;
            }
        }
    }
    else if (entrada == "año")
    {
        sort(catalogo.begin(), catalogo.end(), [](const Titulo& a, const Titulo& b) {return a.añoLanzamiento < b.añoLanzamiento;});
        int añoValor = stoi(valor);
        int izquierda = 0, derecha = catalogo.size() - 1;

        while (izquierda <= derecha)
        {
            int medio = (izquierda + derecha) / 2;

            if (catalogo[medio].añoLanzamiento == añoValor)
            {
                resultados.push_back(catalogo[medio]);
                break;
            }
            else if (catalogo[medio].añoLanzamiento < añoValor)
            {
                izquierda = medio + 1;
            }
            else
            {
                derecha = medio - 1;
            }
        }
    }
    return resultados;
}

void eliminarReducir(vector<Titulo>& catalogo) {
    string codigo;
    int cantidad;

    cout << "ingrese el codigo del titulo a modificar: ";
    cin >> codigo;

    for (auto i = catalogo.begin(); i != catalogo.end(); i++)
    {
        if (i->codigo == codigo)
        {
            cout << "ingrese la cantidad a eliminar: ";
            cin >> cantidad;

            if (cantidad > i->copias)
            {
                cout << "Ha ingresado un numero mayor a la cantidad de copias que hay de este titulo" << endl;
                return;
            }

            i->copias -= cantidad;

            if (i->copias == 0)
            {
                catalogo.erase(i);
                cout << "El titulo se ha eliminado del catalogo" << endl;
            }
            else
            {
                cout << "Nueva disponibilidad: " << i->copias << endl;
            }
            return;
        }
    }
    cout << "El titulo no se ha encontrado en la lista" << endl;
}

void compararTiempos(vector<Titulo>& catalogo) {
    string valor;
    cout << "Comparar tiempos de busqueda por codigo." << endl;
    cout << "Ingrese codigo a buscar: ";
    cin >> valor;

    auto inicio1 = high_resolution_clock::now();

    busquedaSecuencial(catalogo, "codigo", valor);
    
    auto fin1 = high_resolution_clock::now();
    auto tiempoSecuencial = duration_cast<microseconds>(fin1 - inicio1).count();

    auto inicio2 = high_resolution_clock::now();

    busquedaBinaria(catalogo, "codigo", valor);
    
    auto fin2 = high_resolution_clock::now();
    auto tiempoBinaria = duration_cast<microseconds>(fin2 - inicio2).count();

    cout << "Tiempo busqueda secuencial: " << tiempoSecuencial << " microsegundos" << endl;
    cout << "Tiempo busqueda binaria: " << tiempoBinaria << " microsegundos" << endl;

    if (tiempoBinaria < tiempoSecuencial)
    {
        cout << "La busqueda binaria fue mas eficiente" << endl;
    }
    else
    {
        cout << "La busqueda secuencial es mas eficiente en listas cortas" << endl;
    }
}

int main()
{
    vector<Titulo> catalogo;
    string entrada, valor;
    int opcion;

    do
    {
        cout << "PLATAFORMA DE STREAMING" << endl;
        cout << "1. Registrar titulo" << endl;
        cout << "2. Mostrar catalogo" << endl;
        cout << "3. Busqueda secuencial" << endl;
        cout << "4. Busqueda binaria" << endl;
        cout << "5. Eliminar o reducir disponibilidad" << endl;
        cout << "6. Comparar tiempos de busqueda" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        switch (opcion)
        {
            case 1:
                registrarTitulo(catalogo);
                break;
            case 2:
                cout << "Catalogo de Peliculas" << endl;
                for (auto& i : catalogo)
                {
                    mostrarTitulo(i);
                }

                break;
            case 3:
            {

                cout << "Entrada (nombre, codigo, genero): ";
                cin >> entrada;
                cin.ignore();

                cout << "Valor a buscar: ";
                getline(cin, valor);
                auto resultados = busquedaSecuencial(catalogo, entrada, valor);
                if (resultados.empty())
                {
                    cout << "No se encontraron resultados para los valores ingresados" << endl;
                }
                else
                {
                    for (auto& i : resultados)
                    {
                        mostrarTitulo(i);
                    }
                }
                break;
            }
            case 4:
            {
                cout << "Atributo (codigo/año): ";
                cin >> entrada;
                cout << "Valor a buscar: ";
                cin >> valor;
                auto resultados = busquedaBinaria(catalogo, entrada, valor);
                if (resultados.empty())
                {
                    cout << "No se encontraron resultados para los valores ingresados" << endl;
                }
                else
                {
                    for (auto& i : resultados)
                    {
                        mostrarTitulo(i);
                    }
                }
                break;
            }
            case 5:
                eliminarReducir(catalogo);
                break;
            case 6:
                compararTiempos(catalogo);
                break;
            case 7:
                cout << "Cerrando programa";
                break;
            default:
                cout << "Opcion invalida" << endl;
        }
    } while (opcion != 7);

    return 0;
}