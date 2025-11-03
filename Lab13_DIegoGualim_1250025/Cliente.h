#pragma once
#include <iostream>
#include <string>

using namespace std;

class Cliente
{
public:
    string nombre;
    int id;
    string correo;
    int compras;

    Cliente();
    Cliente(string, int, string);
    void mostrar() const;
};