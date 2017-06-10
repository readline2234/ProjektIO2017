#pragma once
#include <string>
class Kategoria
{
private:
	std::string nazwa;
public:
	Kategoria(std::string nazwa);
	~Kategoria();

	std::string GetNazwa();

	bool EdytujNazwa(std::string nazwa);
	
	static Kategoria* Dodaj(std::string nazwa);
	static bool Usun(Kategoria *);
};

