#pragma once
#include "Towar.h"
#include "Uzytkownik.h"

class Dostawa
{
private:
	Towar * towar;
	int ilosc;
	std::string Data;
	Uzytkownik * uzytkownik;
	bool rozmieszczona;
	int kod;
	
public:
	Dostawa(Towar * towar, int ilosc, Uzytkownik * uzytkownik, bool rozmieszczona, int kod);
	~Dostawa();

	Towar * GetTowar();
	int GetIlosc();
	//
	Uzytkownik * GetUzytkownik();
	bool GetRozmieszczona();
	int GetKod();

	bool EdytujTowar (Towar * towar);
	bool EdytujIlosc (int ilosc);
	//
	bool EdytujUzytkownik (Uzytkownik * uzytkownik);
	bool EdytujRozmieszczona (int rozmieszczona);
	bool EdytujKod (int kod);	

	static Dostawa* Dodaj(Towar * towar, int ilosc, Uzytkownik * uzytkownik, bool rozmieszczona, int kod);
	static bool Usun(Dostawa *);
};

