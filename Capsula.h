#pragma once
#include "Utils.h"
class Capsula
{
	private:
		int carga;
	public:
		Capsula();
		Capsula(int carga);

		void SumaCarga(int carga);
		void ReparteCarga(int carga);
		void setCarga(int carga);
		int getCarga();
		int getNeededCharge();
		bool isEmpty();
};

