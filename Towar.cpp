#include "Towar.h"

Towar::Towar(std::string producent,std::string model, Kategoria * kategoria)
	{
	this->producent = producent;
	this->model = model;
	this->kategoria = kategoria;
	}

Towar::~Towar() { }

std::string Towar::GetProducent() { return this->producent; }
std::string Towar::GetModel() { return this->model; }
Kategoria *  Towar::GetKategoria() { return this->kategoria; }

bool Towar::EdytujProducent(std::string producent)
	{
	this->producent = producent;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Towar::EdytujModel(std::string model)
	{
	this->model = model;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Towar::EdytujKategoria(Kategoria * kategoria)
	{
	this->kategoria = kategoria;
	//HERE: wyswil zapytanie do DB
	return true;
	}


Towar* Towar::Dodaj(std::string producent, std::string model, Kategoria * kategoria)
	{
	//Towar* s = new Towar();
	//HERE: query do DB
	return nullptr;
	}

bool Towar::Usun(Towar *)
	{
	return false;
	}
