#include "Mapa.h"

Mapa::Mapa() {
	for (int i = 0; i < MaxMapa; i++) {
		for (int j = 0; j < MaxMapa; j++) {
			mapa[i][j] = '-';
		}
	}
}

Mapa::Mapa(Cohete* cohetes) {
	for (int i = 0; i < MaxMapa; i++) {
		for (int j = 0; j < MaxMapa; j++) {
			mapa[i][j] = '-';
		}
	}
	for (int i = 0; i < MaxCohetes; i++) {
		mapa[cohetes[i].GetPos()[X]][cohetes[i].GetPos()[Y]] = '0';
	}
}

void Mapa::DibujarMapa() {
	for (int i = 0; i < MaxMapa; i++) {
		for (int j = 0; j < MaxMapa; j++) {
			std::cout << mapa[i][j];
		}
		std::cout << "\n";
	}
}

bool Mapa::ComprobarPos(Cohete* cohetes) {
	if (Distancia(cohetes[0].GetPos(), cohetes[1].GetPos()) == 1) {
		return true;
	}
	return false;
}

bool Mapa::Mover(MoveType move, Cohete* cohete) {
	int* posAnterior = cohete->GetPos();
	int coords[2] = {0,0};
	switch (move) {
	case UP:
		if (posAnterior[Y] + 1 > 10) {
			return false;
		}
		coords[Y] = 1;
		cohete->CambiarPos(coords);
		break;
	case DOWN:
		if (posAnterior[Y] - 1 < 0) {
			return false;
		}
		coords[Y] = -1;
		cohete->CambiarPos(coords);
		break;
	case LEFT:
		if (posAnterior[X] - 1 < 0) {
			return false;
		}
		coords[X] = -1;
		cohete->CambiarPos(coords);
		break;
	case RIGHT:
		if (posAnterior[X] + 1 > 10) {
			return false;
		}
		coords[X] = 1;
		cohete->CambiarPos(coords);
		break;
	}
	ActualizarMapa(posAnterior, cohete->GetPos());
	return true;
}

void Mapa::ActualizarMapa(int* posAnterior, int* posNueva) {
	mapa[posAnterior[X]][posAnterior[Y]] = '-';
	mapa[posNueva[X]][posNueva[Y]] = '0';
}

int Mapa::Distancia(int* p1, int* p2) {
	return std::sqrt(std::pow(p2[X]-p1[X], 2) + std::pow(p2[Y] - p1[Y], 2));
}


