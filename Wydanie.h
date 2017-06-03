#pragma once

class Wydanie
{
private:
	int ZasobID;
	int KlientID;
	int Ilosc;
	//date Data;
	int UzytkownikID;

public:
	Wydanie(int zasobid, int klientid, int ilosc, int uzytkownikid);
	~Wydanie();

	int GetZasobID();
	int GetKlientID();
	int GetIlosc();
	//
	int GetUzytkownikID();

	bool EdytujZasobID (int zasobid);
	bool EdytujKlientID (int klientid);
	bool EdytujIlosc (int ilosc);
	//
	bool EdytujUzytkownikID (int uzytkownikid);

	static Wydanie* Dodaj(int zasobid, int klientid, int ilosc, int uzytkownikid);
	static bool Usun(Wydanie *);
};

