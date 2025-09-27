#pragma once
#include <iostream>
#include "Gimnasio.h"

using namespace std;

class Boxeo:public Gimnasio
{
	public:
		Boxeo(string, double, int);
		void mostrarInfo() const override;
};

