#pragma once
#include <iostream>
#include "Gimnasio.h"

using namespace std;

class CrossFit : public Gimnasio {
public:
    CrossFit(string, double, int);
    void mostrarInfo() const override;
};