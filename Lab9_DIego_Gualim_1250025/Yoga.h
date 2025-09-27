#pragma once
#include <iostream>
#include "Gimnasio.h"

using namespace std;

class Yoga : public Gimnasio {
public:
    Yoga(string, double, int);
    void mostrarInfo() const override;
};