#pragma once
#include "Cohete.h"
#include "Mapa.h"

class Controller {
	public:
		void Run();

	private:
		int MenuElegirCohete(Cohete* cohetes);
		int MenuAccionesCohete();
		int MenuMover();
		int MenuEliminar();
		int MenuTransferir();
		int MenuCargar();
		std::string MenuDestino();
		int MenuDistancia();
};

