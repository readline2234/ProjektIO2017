#include "Uzytkownik.h"

Uzytkownik::Uzytkownik(std::string login,std::string haslo,std::string imie,std::string nazwisko)
	{
	this->Login = login;
	this->Haslo = haslo;
	this->Imie = imie;
	this->Nazwisko = nazwisko;
	}

Uzytkownik::~Uzytkownik() { }

std::string Uzytkownik::GetLogin() { return this->Login; }
std::string Uzytkownik::GetHaslo() { return this->Haslo; }
std::string Uzytkownik::GetImie() { return this->Imie; }
std::string Uzytkownik::GetNazwisko() { return this->Nazwisko; }

bool Uzytkownik::EdytujLogin(std::string login)
	{
	this->Login = login;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Uzytkownik::EdytujHaslo(std::string haslo)
	{
	this->Haslo = haslo;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Uzytkownik::EdytujImie(std::string imie)
	{
	this->Imie = imie;
	//HERE: wyswil zapytanie do DB
	return true;
	}


bool Uzytkownik::EdytujNazwisko(std::string nazwisko)
	{
	this->Nazwisko = nazwisko;
	//HERE: wyswil zapytanie do DB
	return true;
	}

Uzytkownik* Uzytkownik::Dodaj(std::string login, std::string haslo,std::string imie,std::string nazwisko)
	{
	//Uzytkownik* s = new Uzytkownik();
	//HERE: query do DB
	return nullptr;
	}

bool Uzytkownik::Usun(Uzytkownik *)
	{
	return false;
	}
