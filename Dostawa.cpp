#include "Dostawa.h"

Dostawa::Dostawa(int towarid, int ilosc, int uzytkownikid, bool rozmieszczona, int kod)
	{
	this->TowarID = towarid;
	this->Ilosc = ilosc;
	//
	this->UzytkownikID = uzytkownikid;
	this->Rozmieszczona = rozmieszczona;
	this->Kod = kod;
	}

Dostawa::~Dostawa() { }

int Dostawa::GetTowarID() { return this->TowarID; }
int Dostawa::GetIlosc() { return this->Ilosc; }
//
int Dostawa::GetUzytkownikID() { return this->UzytkownikID; }
bool Dostawa::GetRozmieszczona() { return this->Rozmieszczona; }
int Dostawa::GetKod() { return this->Kod; }

bool Dostawa::EdytujTowarID (int towarid)
	{
	this->TowarID = towarid;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Dostawa::EdytujIlosc (int ilosc)	
	{
	this->Ilosc = ilosc;
	//HERE: wyswil zapytanie do DB
	return true;	
	}

bool Dostawa::EdytujUzytkownikID (int uzytkownikid)
	{
	this->UzytkownikID = uzytkownikid;
	//HERE: wyswil zapytanie do DB
	return true;	
	}
		
bool Dostawa::EdytujRozmieszczona (int rozmieszczona)	
	{
	this->Rozmieszczona = rozmieszczona;
	//HERE: wyswil zapytanie do DB
	return true;	
	}

bool Dostawa::EdytujKod (int kod)	
	{
	this->Kod = kod;
	//HERE: wyswil zapytanie do DB
	return true;	
	}

	
Dostawa* Dostawa::Dodaj(int towarid, int ilosc, int uzytkownikid, bool rozmieszczona, int kod)
	{
	//Dostawa* s = new Dostawa();
	//HERE: query do DB
	return nullptr;
	}

bool Dostawa::Usun(Dostawa *)
	{
	return false;
	}
