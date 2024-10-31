#pragma once
#include <iostream>

#include "Capsula.h"
#include "Utils.h"

class Cohete{
	public:
		const static int max_capsulas = 10;
	
	private:
		std::string nombre;
		std::string destino;
		int distancia;
		Capsula* capsulas[max_capsulas];
		int nCapsulas;
		int* pos;

	public:

		
		Cohete();
		Cohete(std::string nombre, std::string destino, int distancia, int nCapsulas);

		bool AgregarCap(Capsula* capsula);
		bool EliminarCap(int pos);
		bool TransferirCap(int pos, Cohete* cohete);
		void Objetivo(std::string destino, int distancia);
		void ResetObjetivo();
		bool ValidarViaje(int dist);
		bool Viajar();
		void Cargar(int energia);
		bool CapsulasFull();
		void CapsulasToString();
		std::string GetNombre();
		int* GetPos();
		void CambiarPos(int* pos);
};

