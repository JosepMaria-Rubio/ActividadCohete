#include "Cohete.h"

#include "Mapa.h"

Cohete::Cohete(){
	nombre = "Cohete";
	destino = "Luna";
	distancia = 500000;
	nCapsulas = 5;
	pos = new int[Mapa::max_coords];
	for (int i = 0; i < Mapa::max_coords; i++) {
		pos[i] = rand()/((RAND_MAX + 1u)/10);
	}
	for (int i = 0; i < max_capsulas; i++) {
		if (i < nCapsulas) {
			capsulas[i] = new Capsula();
		}
		else {
			capsulas[i] = nullptr;
		}
	}
}

Cohete::~Cohete() {
	delete[] capsulas;
	delete[] pos;
}

Cohete::Cohete(std::string nombre, std::string destino, int distancia, int nCapsulas){
	this->nombre = nombre;
	this->destino = destino;
	this->distancia = distancia;
	this->nCapsulas = nCapsulas;
	pos = new int[Mapa::max_coords];
	for (int i = 0; i < Mapa::max_coords; i++) {
		pos[i] = rand() / ((RAND_MAX + 1u) / 10);
	}
	for (int i = 0; i < max_capsulas; i++) {
		if (i < nCapsulas) {
			capsulas[i] = new Capsula();
		}
		else {
			capsulas[i] = nullptr;
		}
	}
}

bool Cohete::AgregarCap(Capsula* capsula){ 
	for (int i = 0; i < max_capsulas; i++) {
		if (capsulas[i] == nullptr) {
			capsulas[i] = capsula;
			nCapsulas++;
			return true;
		}
	}
	return false;
}

bool Cohete::EliminarCap(int pos){
	if (capsulas[pos] == nullptr) {
		return false;
	}
	for (int i = 0; i < max_capsulas; i++) {
		if (capsulas[pos]->isEmpty()) {
			DestruirCapsulas(pos);
			return true;
		}
		if (capsulas[i] != nullptr) {
			int carga = capsulas[i]->getNeededCharge();
			capsulas[pos]->ReparteCarga(carga);
			capsulas[i]->SumaCarga(carga);
		}
	}
	DestruirCapsulas(pos);
	return true;
}



bool Cohete::TransferirCap(int pos, Cohete* cohete){
	if (cohete->CapsulasFull()) {
		std::cout << "El cohete esta lleno\n";
		return false;
	}
	if (capsulas[pos] == nullptr) {
		std::cout << "No existe la capsula\n";
		return false;
	}
	cohete->AgregarCap(new Capsula(capsulas[pos]->getCarga()));
	EliminarCap(pos);
	return true;
}

void Cohete::Objetivo(std::string destino, int distancia){
	this->destino = destino;
	this->distancia = distancia;
}

void Cohete::ResetObjetivo() {
	this->destino = "";
	this->distancia = 0;
}

bool Cohete::ValidarViaje(int dist){
	int cargaAcumulada = 0;

	for (int i = 0; i < max_capsulas; i++) {
		if (capsulas[i] != nullptr) {
			cargaAcumulada += capsulas[i]->getCarga();
		}
	}

	if (dist > cargaAcumulada*10) {
		return false;
	}
	return true;
}


bool Cohete::Viajar(){
	if (!ValidarViaje(distancia)) {
		std::cout << "El viaje no se puede realizar\n";
		return false;
	}
	if(destino.empty()){
		std::cout << "El destino no existe\n";
		return false;
	}
	int cargaViaje = distancia / 10;
	int i = 0;
	while (cargaViaje > 0) {
		if (capsulas[i] != nullptr) {
			if (cargaViaje >= capsulas[i]->getCarga()) {
				cargaViaje -= capsulas[i]->getCarga();
				EliminarCap(i);
			}
			else {
				capsulas[i]->setCarga(capsulas[i]->getCarga() - cargaViaje);
				cargaViaje = 0;
			}
		}
		i++;
	}
	//CapsulasToString();
	ResetObjetivo();
	return true;
}



void Cohete::Cargar(int energia) {
	for (int i = 0; i < max_capsulas; i++) {
		if (capsulas[i] != nullptr) {
			if (energia + capsulas[i]->getCarga() > Capsula::max_carga) {
				capsulas[i]->setCarga(Capsula::max_carga);
			}
			else {
				capsulas[i]->setCarga(energia + capsulas[i]->getCarga());
			}
		}
	}
}



bool Cohete::CapsulasFull(){
	return nCapsulas == max_capsulas;
}

void Cohete::CapsulasToString() {
	for (int i = 0; i < max_capsulas; i++) {
		if (capsulas[i] != nullptr) {
			std::cout << "/" << capsulas[i]->getCarga() << "/";
		}
		else {
			std::cout << "-";
		}
	}
	std::cout << "\n";
}

std::string Cohete::GetNombre() {
	return nombre;
}


int* Cohete::GetPos() {
	return pos;
}

void Cohete::CambiarPos(int* pos) {
	this->pos[X] += pos[X];
	this->pos[Y] += pos[Y];
}

void Cohete::DestruirCapsulas(int pos) {
	delete capsulas[pos];
	capsulas[pos] = nullptr;
	nCapsulas--;
}
