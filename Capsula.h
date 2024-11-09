#pragma once
class Capsula
{
	public:
		const static int max_carga = 10000;
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

