#include "Mapa.h"

Mapa::Mapa() {
	for (int i = 0; i < max_mapa; i++) {
		for (int j = 0; j < max_mapa; j++) {
			mapa[i][j] = '-';
		}
	}
}

Mapa::Mapa(Cohete* cohetes) {
	for (int i = 0; i < max_mapa; i++) {
		for (int j = 0; j < max_mapa; j++) {
			mapa[i][j] = '-';
		}
	}
	for (int i = 0; i < max_cohetes; i++) {
		mapa[cohetes[i].GetPos()[Y]][cohetes[i].GetPos()[X]] = (char) i + ascii_offset + 1;
	}
}

void Mapa::DibujarMapa() {
	for (int i = 0; i < max_mapa; i++) {
		for (int j = 0; j < max_mapa; j++) {
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
	if(mapa[cohete->GetPos()[Y]][cohete->GetPos()[X]] != '-') {
		std::cout<<"Espacio ocupado\n";
		return false;
	}
	int posAnterior[max_mapa];
	posAnterior[X] = cohete->GetPos()[X];
	posAnterior[Y] = cohete->GetPos()[Y];
	
	int coords[2] = {0,0};
	switch (move) {
	case UP:
		if (posAnterior[Y] - 1 < 0) {
			return false;
		}
		coords[Y] = -1;
		cohete->CambiarPos(coords);
		break;
	case DOWN:
		if (posAnterior[Y] + 1 > 10) {
			return false;
		}
		coords[Y] = 1;
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
	mapa[posNueva[Y]][posNueva[X]] = mapa[posAnterior[Y]][posAnterior[X]];
	mapa[posAnterior[Y]][posAnterior[X]] = '-';
}

int Mapa::Distancia(int* p1, int* p2) {
	return std::sqrt(std::pow(p2[X]-p1[X], 2) + std::pow(p2[Y] - p1[Y], 2));
}