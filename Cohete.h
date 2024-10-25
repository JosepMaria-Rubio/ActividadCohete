#pragma once
#include <iostream>
#include "Capsula.h"
#include "Utils.h"

class Cohete
{
	private:
		std::string nombre;
		std::string destino;
		int distancia;
		Capsula* capsulas[MaxCapsulas];
		int nCapsulas;

	public:
		Cohete();
		Cohete(std::string nombre, std::string destino, int distancia, int nCapsulas);

		bool AgregarCap(Capsula* capsula);
		bool EliminarCap(int pos);
		bool TransferirCap(int pos, Cohete* cohete);
		bool ValidarViaje(int dist);
		void Objetivo(std::string destino, int distancia);
		bool Viajar();
		bool Cargar(int energia);
		bool CapsulasFull();
		void CapsulasToString();
};

