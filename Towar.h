#pragma once
#include <string>
class Towar
{
private:
	std::string Producent;
	std::string Model;
	int KategoriaID;
public:
	Towar(std::string producent,std::string model, int kategoriaid);
	~Towar();

	std::string GetProducent();
	std::string GetModel();
	int GetKategoriaID();

	bool EdytujProducent(std::string producent); 
	bool EdytujModel(std::string model);
	bool EdytujKategoriaID(int kategoriaid);

	static Towar* Dodaj(std::string producent, std::string model, int kategoriaid);
	static bool Usun(Towar *);
};

