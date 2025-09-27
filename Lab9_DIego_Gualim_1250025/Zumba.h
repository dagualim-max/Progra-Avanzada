#pragma once
#include <iostream>
#include "Gimnasio.h"

using namespace std;

class Zumba : public Gimnasio {
public:
    Zumba(string, double, int);
    void mostrarInfo() const override;
};