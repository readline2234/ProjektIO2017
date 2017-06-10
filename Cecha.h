#pragma once
#include <string>
#include "Kategoria.h"

class Cecha
{
private:
	std::string nazwa;
	Kategoria * kategoria;
public:
	Cecha(std::string nazwa, Kategoria * kategoria);
	~Cecha();

	std::string GetNazwa();
	Kategoria * GetKategoria();

	bool EdytujNazwa(std::string nazwa);
	bool EdytujKategoria(Kategoria * kategoria);

	static Cecha* Dodaj(std::string nazwa, Kategoria * kategoria);
	static bool Usun(Cecha *);
};

