#include "Cecha.h"

Cecha::Cecha(std::string nazwa, Kategoria * kategoria)
	{
	this->nazwa = nazwa;
	//this->Kategoria = kategoria;
	}

Cecha::~Cecha() { }

std::string Cecha::GetNazwa() { return this->nazwa; }
Kategoria * Cecha::GetKategoria() { return this->kategoria; }

bool Cecha::EdytujNazwa(std::string nazwa)
	{
	this->nazwa = nazwa;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Cecha::EdytujKategoria(Kategoria * kategoria)
	{
	//this->Kategoria = kategoria;
	//HERE: wyswil zapytanie do DB
	return true;
	}


Cecha* Cecha::Dodaj(std::string nazwa, Kategoria * kategoria)
	{
	//Cecha* s = new Cecha();
	//HERE: query do DB
	return nullptr;
	}

bool Cecha::Usun(Cecha *)
	{
	return false;
	}
