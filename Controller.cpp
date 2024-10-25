#include "Controller.h"


void Controller::Run() {
	Cohete cohetes[MaxCohetes];
	Mapa mapa(cohetes);
	bool salir = false;
	while (!salir) {
		int idCohete = MenuElegirCohete(cohetes);
		switch (MenuAccionesCohete()) {
		case ADD:
			if (cohetes[idCohete].AgregarCap(new Capsula)) {
				std::cout << "Capsula añadida correctamente\n";
			}
			else {
				std::cout <<  "El cohete esta lleno\n";
			}
			break;
		case DELETE:
			if (cohetes[idCohete].EliminarCap(MenuEliminar())) {
				std::cout << "Capsula eliminada correctamente\n";
			}
			else {
				std::cout << "La capsula seleccionada no existe\n";
			}
			break;
		case TRANSFER:
			if (mapa.ComprobarPos(cohetes)) {
				if (cohetes[idCohete].TransferirCap(MenuTransferir(), &cohetes[(idCohete + 1) % 2])) {
					std::cout << "Transferencia ejecutada correctamente\n";
				}
			}
			else {
				std::cout << "El cohete esta demasiado lejos\n";
			}
			break;
		case CHARGE:
			cohetes[idCohete].Cargar(MenuCargar());
			break;
		case OBJECTIVE:
			cohetes[idCohete].Objetivo(MenuDestino(), MenuDistancia());
			break;
		case LAUNCH:
			if (cohetes[idCohete].Viajar()) {
				std::cout << "Se ha relizado el viaje\n";
			}
			else {
				std::cout << "El viaje no se puede realizar\n";
			}
			break;
		case DRAW:
			mapa.DibujarMapa();
			break;
		case MOVE:
			mapa.Mover((MoveType)MenuMover(), &cohetes[idCohete]);
			break;
		case EXIT:
			salir = true;
			break;
		}
	}
}

int Controller::MenuElegirCohete(Cohete* cohetes) {
	int opcion;
	std::cout << "Cohetes a elegir\n" <<
		"1. " << cohetes[0].GetNombre() << "\n" <<
		"2. " << cohetes[1].GetNombre() << "\n" <<
		"Que cohete quieres usar?\n";
	std::cin >> opcion;
	return opcion-1;
}

int Controller::MenuAccionesCohete() {
	int opcion;
	std::cout << "Opciones a realizar\n" <<
		"1. Añadir capsula al cohete\n" <<
		"2. Eliminar capsula\n" <<
		"3. Transferir energia entre cohetes\n" <<
		"4. Cargar energia\n" <<
		"5. Determinar el objetivo\n" <<
		"6. Activar lanzamiento\n" <<
		"7. Dibujar el mapa\n" <<
		"8. Mover por el tablero\n" <<
		"9. Salir\n" <<
		"Que accion quieres realizar?\n";
	std::cin >> opcion;
	return opcion - 1;
}

int Controller::MenuMover() {
	int opcion;
	std::cout << "Direcciones para mover el cohete\n" <<
		"1. Arriba\n" <<
		"2. Abajo\n" <<
		"3. Izquierda\n" <<
		"4. Derecha\n" <<
		"En que direccion te quieres mover?\n";
	std::cin >> opcion;
	return opcion - 1;
}

int Controller::MenuEliminar() {
	int capsula;
	std::cout << "Que capsula quieres eliminar? (1-10)\n";
	std::cin >> capsula;
	return capsula -1;
}

int Controller::MenuTransferir() {
	int capsula;
	std::cout << "Que capsula quieres transferir? (1-10)\n";
	std::cin >> capsula;
	return capsula - 1;
}

int Controller::MenuCargar() {
	int carga;
	std::cout << "Cuanto quieres cargar cada capsula? (1-10000)\n";
	std::cin >> carga;
	return carga;
}

std::string Controller::MenuDestino() {
	std::string destino;
	std::cout << "Cual es el destino del viaje?\n";
	std::cin >> destino;
	return destino;
}

int Controller::MenuDistancia() {
	int distanica;
	std::cout << "Cual es la distancia al destino?\n";
	std::cin >> distanica;
	return distanica;
}
