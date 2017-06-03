#pragma once
#include <string>
class Uzytkownik
{
private:
	std::string Login;
	std::string Haslo;
	std::string Imie;
	std::string Nazwisko;

public:
	Uzytkownik(std::string login,std::string haslo,std::string imie,std::string nazwisko);
	~Uzytkownik();

	std::string GetLogin();
	std::string GetHaslo();
	std::string GetImie();
	std::string GetNazwisko();

	bool EdytujLogin(std::string login); 
	bool EdytujHaslo(std::string haslo);
	bool EdytujImie(std::string imie);
	bool EdytujNazwisko(std::string nazwisko);

	static Uzytkownik* Dodaj(std::string login,std::string haslo,std::string imie,std::string nazwisko);
	static bool Usun(Uzytkownik *);
};

