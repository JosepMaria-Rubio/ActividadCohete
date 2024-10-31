#include "Capsula.h"

Capsula::Capsula(){
	carga = 10000;
}

Capsula::Capsula(int carga){
	this->carga = carga;
}

void Capsula::SumaCarga(int carga){
	this->carga += carga;
}

void Capsula::ReparteCarga(int carga){
	this->carga -= carga;
}

void Capsula::setCarga(int carga){
	this->carga = carga;
}

int Capsula::getCarga(){
	return carga;
}

int Capsula::getNeededCharge()
{
	return max_carga - carga;
}

bool Capsula::isEmpty()
{
	return carga == 0;
}





