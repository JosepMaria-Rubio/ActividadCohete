#pragma once
#include "Cohete.h"
class Mapa
{
	private:
		char mapa[10][10];
		Cohete* cohete;

	public:
		Mapa();
		Mapa(Cohete* cohetes);


};

