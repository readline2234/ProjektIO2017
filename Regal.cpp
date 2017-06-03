#include "Regal.h"

Regal::Regal(std::string kod,int pojemnosc, int strefaskladowaniaid)
	{
	this->Kod = kod;
	this->Pojemnosc = pojemnosc;
	this->StrefaSkladowaniaID = strefaskladowaniaid;
	}

Regal::~Regal() { }

std::string Regal::GetKod() { return this->Kod; }
int Regal::GetPojemnosc() { return this->Pojemnosc; }
int Regal::GetStrefaSkladowaniaID() { return this->GetStrefaSkladowaniaID(); }

bool Regal::EdytujKod(std::string kod)
	{
	this->Kod = kod;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Regal::EdytujPojemnosc(int pojemnosc)
	{
	this->Pojemnosc = pojemnosc;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Regal::EdytujStrefaSkladowaniaID(int strefaskladowaniaid)
	{
	this->StrefaSkladowaniaID = strefaskladowaniaid;
	//HERE: wyswil zapytanie do DB
	return true;
	}


Regal* Regal::Dodaj(std::string kod, int pojemnosc, int strefaskladowaniaid)
	{
	//Regal* s = new Regal();
	//HERE: query do DB
	return nullptr;
	}

bool Regal::Usun(Regal *)
	{
	return false;
	}
