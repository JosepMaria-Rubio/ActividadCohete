#pragma once
#include <math.h>
#include "Cohete.h"
class Mapa
{
	private:
		char mapa[MaxMapa][MaxMapa];
		

	public:
		Mapa();
		Mapa(Cohete* cohetes);

		void DibujarMapa();
		bool ComprobarPos(Cohete* cohetes);
		bool Mover(MoveType move, Cohete* cohete);
		void ActualizarMapa(int* posAnterior, int* posNueva);
		int Distancia(int* p1, int* p2);
};

