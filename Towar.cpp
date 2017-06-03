#include "Towar.h"

Towar::Towar(std::string producent,std::string model, int kategoriaid)
	{
	this->Producent = producent;
	this->Model = model;
	this->KategoriaID = kategoriaid;
	}

Towar::~Towar() { }

std::string Towar::GetProducent() { return this->Producent; }
std::string Towar::GetModel() { return this->Model; }
int Towar::GetKategoriaID() { return this->GetKategoriaID(); }

bool Towar::EdytujProducent(std::string producent)
	{
	this->Producent = producent;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Towar::EdytujModel(std::string model)
	{
	this->Model = model;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Towar::EdytujKategoriaID(int kategoriaid)
	{
	this->KategoriaID = kategoriaid;
	//HERE: wyswil zapytanie do DB
	return true;
	}


Towar* Towar::Dodaj(std::string producent, std::string model, int kategoriaid)
	{
	//Towar* s = new Towar();
	//HERE: query do DB
	return nullptr;
	}

bool Towar::Usun(Towar *)
	{
	return false;
	}
