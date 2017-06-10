#include "Zasob.h"

Zasob::Zasob(int ID, Towar * towar, Dostawa * dostawa, Regal * regal, int ilosc)
	{
	this->ID = ID;
	this->towar = towar;
	this->dostawa = dostawa;
	this->regal = regal;
	this->ilosc = ilosc;
	}

Zasob::~Zasob() { }

Towar * Zasob::GetTowar() { return this->towar; }
Dostawa * Zasob::GetDostawa() { return this->dostawa; }
Regal * Zasob::GetRegal() { return this->regal; }
int Zasob::GetIlosc() { return this->ilosc; }

int Zasob::GetID()
{
	return this->ID;
}

bool Zasob::EdytujTowar (Towar * towar)
	{
	this->towar = towar;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Zasob::EdytujDostawa (Dostawa * dostawa)
	{
	this->dostawa = dostawa;
	//HERE: wyswil zapytanie do DB
	return true;	
	}
bool Zasob::EdytujRegal (Regal * regal)
	{
	this->regal = regal;
	//HERE: wyswil zapytanie do DB
	return true;	
	}
bool Zasob::EdytujIlosc (int ilosc)	
	{
	this->ilosc = ilosc;
	//HERE: wyswil zapytanie do DB
	return true;	
	}
	
	bool Wydaj(int ilosc)
	{
	return true;
	}
	
	bool GenerujNaklejke()
	{
	return true;
	}
Zasob* Zasob::Dodaj(Towar * towar, Dostawa * dostawa, Regal * regal, int ilosc)
	{
	//Zasob* s = new Zasob();
	//HERE: query do DB
	return nullptr;
	}

bool Zasob::Usun(Zasob *)
	{
	return false;
	}
