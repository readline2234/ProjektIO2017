#include "Wydanie.h"

Wydanie::Wydanie(int zasobid, int klientid, int ilosc, int uzytkownikid)
	{
	this->ZasobID = zasobid;
	this->KlientID = klientid;
	this->Ilosc = ilosc;
	//
	this->UzytkownikID = uzytkownikid;
	}

Wydanie::~Wydanie() { }

int Wydanie::GetZasobID() { return this->ZasobID; }
int Wydanie::GetKlientID() { return this->KlientID; }
int Wydanie::GetIlosc() { return this->Ilosc; }
//
int Wydanie::GetUzytkownikID() { return this->UzytkownikID; }

bool Wydanie::EdytujZasobID (int zasobid)
	{
	this->ZasobID = zasobid;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Wydanie::EdytujKlientID (int klientid)
	{
	this->KlientID = klientid;
	//HERE: wyswil zapytanie do DB
	return true;	
	}

bool Wydanie::EdytujIlosc (int ilosc)	
	{
	this->Ilosc = ilosc;
	//HERE: wyswil zapytanie do DB
	return true;	
	}

bool Wydanie::EdytujUzytkownikID (int uzytkownikid)
	{
	this->UzytkownikID = uzytkownikid;
	//HERE: wyswil zapytanie do DB
	return true;	
	}
	
Wydanie* Wydanie::Dodaj(int zasobid, int klientid, int ilosc, int uzytkownikid)
	{
	//Wydanie* s = new Wydanie();
	//HERE: query do DB
	return nullptr;
	}

bool Wydanie::Usun(Wydanie *)
	{
	return false;
	}
