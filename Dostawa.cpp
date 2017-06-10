#include "Dostawa.h"

Dostawa::Dostawa(Towar * towar, int ilosc, Uzytkownik * uzytkownik, bool rozmieszczona, int kod, std::string data)
	{
	this->towar = towar;
	this->ilosc = ilosc;
	this->Data = data;
	this->uzytkownik = uzytkownik;
	this->rozmieszczona = rozmieszczona;
	this->kod = kod;
	}

Dostawa::~Dostawa() { }

Towar * Dostawa::GetTowar() { return this->towar; }
int Dostawa::GetIlosc() { return this->ilosc; }
//
Uzytkownik * Dostawa::GetUzytkownik() { 
	return this->uzytkownik; 
}

bool Dostawa::GetRozmieszczona() { 
	return this->rozmieszczona; 
}
int Dostawa::GetKod() { 
	return this->kod; 
}

std::string Dostawa::GetData()
{
	return this->Data;
}

bool Dostawa::EdytujTowar (Towar * towar)
	{
	this->towar = towar;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Dostawa::EdytujIlosc (int ilosc)	
	{
	this->ilosc = ilosc;
	//HERE: wyswil zapytanie do DB
	return true;	
	}

bool Dostawa::EdytujUzytkownik (Uzytkownik * uzytkownik)
	{
	this->uzytkownik = uzytkownik;
	//HERE: wyswil zapytanie do DB
	return true;	
	}
		
bool Dostawa::EdytujRozmieszczona (int rozmieszczona)	
	{
	this->rozmieszczona = rozmieszczona;
	//HERE: wyswil zapytanie do DB
	return true;	
	}

bool Dostawa::EdytujKod (int kod)	
	{
	this->kod = kod;
	//HERE: wyswil zapytanie do DB
	return true;	
	}

	
Dostawa* Dostawa::Dodaj(Towar * towar, int ilosc, Uzytkownik * uzytkownik, bool rozmieszczona, int kod)
	{
	//Dostawa* s = new Dostawa();
	//HERE: query do DB
	return nullptr;
	}

bool Dostawa::Usun(Dostawa *)
	{
	return false;
	}
