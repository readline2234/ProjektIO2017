#pragma once
#include <string>
#include "Kategoria.h"

class Towar
{
private:
	std::string producent;
	std::string model;
	Kategoria * kategoria;
public:
	Towar(std::string producent,std::string model, Kategoria * kategoria);
	~Towar();

	std::string GetProducent();
	std::string GetModel();
	Kategoria * GetKategoria();

	bool EdytujProducent(std::string producent); 
	bool EdytujModel(std::string model);
	bool EdytujKategoria(Kategoria * kategoria);

	static Towar* Dodaj(std::string producent, std::string model, Kategoria * kategoria);
	static bool Usun(Towar *);
};

