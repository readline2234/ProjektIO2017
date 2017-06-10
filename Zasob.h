#pragma once
#include "Towar.h"
#include "Dostawa.h"
#include "Regal.h"

class Zasob
{
private:
	int ID;
	Towar * towar;
	Dostawa * dostawa;
	Regal * regal;
	int ilosc;
public:
	Zasob(int ID, Towar * towar, Dostawa * dostawa, Regal * regal, int ilosc);
	~Zasob();

	Towar * GetTowar();
	Dostawa * GetDostawa();
	Regal * GetRegal();
	int GetIlosc();
	int GetID();

	bool EdytujTowar(Towar * towar);
	bool EdytujDostawa(Dostawa * dostawa);
	bool EdytujRegal(Regal * regal);
	bool EdytujIlosc(int ilosc);

	bool Wydaj(int ilosc);
	bool GenerujNaklejke();

	static Zasob* Dodaj(Towar * towar, Dostawa * dostawa, Regal * regal, int ilosc);
	static bool Usun(Zasob *);
};

