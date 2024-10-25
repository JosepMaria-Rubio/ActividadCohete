#include "Mapa.h"

int main() {
	Cohete c;
	bool a = c.AgregarCap(new Capsula);
	bool correct = c.EliminarCap(1);
	std::cout << correct;
}