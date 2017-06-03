#pragma once

class Dostawa
{
private:
	int TowarID;
	int Ilosc;
	//date Data;
	int UzytkownikID;
	bool Rozmieszczona;
	int Kod;
	
public:
	Dostawa(int towarid, int ilosc, int uzytkownikid, bool rozmieszczona, int kod);
	~Dostawa();

	int GetTowarID();
	int GetIlosc();
	//
	int GetUzytkownikID();
	bool GetRozmieszczona();
	int GetKod();

	bool EdytujTowarID (int towarid);
	bool EdytujIlosc (int ilosc);
	//
	bool EdytujUzytkownikID (int uzytkownikid);
	bool EdytujRozmieszczona (int rozmieszczona);
	bool EdytujKod (int kod);	

	static Dostawa* Dodaj(int towarid, int ilosc, int uzytkownikid, bool rozmieszczona, int kod);
	static bool Usun(Dostawa *);
};

