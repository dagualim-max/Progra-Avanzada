#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

class Gimnasio
{
protected:
    std::string nombre;
    std::string instructor;
    double precio;
    int cupo;

public:

    Gimnasio(std::string, std::string, double, int);
    virtual ~Gimnasio();

    std::string getNombre() const;
    double getPrecio() const;

    virtual void mostrarInfo() const;
};