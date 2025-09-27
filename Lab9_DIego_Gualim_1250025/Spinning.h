#pragma once
#include <iostream>
#include "Gimnasio.h"

using namespace std;

class Spinning : public Gimnasio 
{
public:
    Spinning(string, double, int);
    void mostrarInfo() const override;
};

