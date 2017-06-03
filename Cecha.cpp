#include "Cecha.h"

Cecha::Cecha(std::string nazwa, int kategoriaid)
	{
	this->Nazwa = nazwa;
	this->KategoriaID = kategoriaid;
	}

Cecha::~Cecha() { }

std::string Cecha::GetNazwa() { return this->Nazwa; }
int Cecha::GetKategoriaID() { return this->GetKategoriaID(); }

bool Cecha::EdytujNazwa(std::string nazwa)
	{
	this->Nazwa = nazwa;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Cecha::EdytujKategoriaID(int kategoriaid)
	{
	this->KategoriaID = kategoriaid;
	//HERE: wyswil zapytanie do DB
	return true;
	}


Cecha* Cecha::Dodaj(std::string nazwa, int kategoriaid)
	{
	//Cecha* s = new Cecha();
	//HERE: query do DB
	return nullptr;
	}

bool Cecha::Usun(Cecha *)
	{
	return false;
	}
