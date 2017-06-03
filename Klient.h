#pragma once
#include <string>
class Klient
{
private:
	std::string Imie;
	std::string Nazwisko;
	std::string Pesel;
	std::string Nip;
	
public:
	Klient(std::string imie,std::string nazwisko,std::string pesel,std::string nip);
	~Klient();

	std::string GetImie();
	std::string GetNazwisko();
	std::string GetPesel();
	std::string GetNip();
	
	bool EdytujImie(std::string imie);
	bool EdytujNazwisko(std::string nazwisko);
	bool EdytujPesel(std::string pesel); 
	bool EdytujNip(std::string nip);

	static Klient* Dodaj(std::string imie,std::string nazwisko,std::string pesel,std::string nip);
	static bool Usun(Klient *);
};

