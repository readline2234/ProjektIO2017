#pragma once
#include <string>
class Cecha
{
private:
	std::string Nazwa;
	int KategoriaID;
public:
	Cecha(std::string nazwa, int kategoriaid);
	~Cecha();

	std::string GetNazwa();
	int GetKategoriaID();

	bool EdytujNazwa(std::string nazwa);
	bool EdytujKategoriaID(int kategoriaid);

	static Cecha* Dodaj(std::string nazwa, int kategoriaid);
	static bool Usun(Cecha *);
};

