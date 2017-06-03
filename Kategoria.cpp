#include "Kategoria.h"

Kategoria::Kategoria(std::string nazwa)
{ 
	this->Nazwa = nazwa;
}

Kategoria::~Kategoria() { }

std::string Kategoria::GetNazwa() { return this->Nazwa;}

bool Kategoria::EdytujNazwa(std::string nazwa)
{
	this->Nazwa = nazwa;
	//HERE: wyswil zapytanie do DB
	return true;
}

Kategoria* Kategoria::Dodaj(std::string nazwa)
{
	//Kategoria* s = new Kategoria();
	//HERE: query do DB
	return nullptr;
}

bool Kategoria::Usun(Kategoria *)
{
	return false;
}
