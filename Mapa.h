#pragma once
#include <math.h>
#include "Cohete.h"

class Mapa
{
	public:
		const static int max_mapa = 10;
		const static int max_coords = 2;
		const static int max_cohetes = 2;
	
	private:
		char mapa[max_mapa][max_mapa];
		const static int ascii_offset = 48;
		

	public:
		Mapa();
		Mapa(Cohete* cohetes);

		void DibujarMapa();
		bool ComprobarPos(Cohete* cohetes);
		bool Mover(MoveType move, Cohete* cohete);
		void ActualizarMapa(int* posAnterior, int* posNueva);
		int Distancia(int* p1, int* p2);
};

