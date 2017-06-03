#include "Klient.h"

Klient::Klient(std::string imie,std::string nazwisko,std::string pesel,std::string nip)
	{
	this->Imie = imie;
	this->Nazwisko = nazwisko;
	this->Pesel = pesel;
	this->Nip = nip;
	}

Klient::~Klient() { }

std::string Klient::GetImie() { return this->Imie; }
std::string Klient::GetNazwisko() { return this->Nazwisko; }
std::string Klient::GetPesel() { return this->Pesel; }
std::string Klient::GetNip() { return this->Nip; }

bool Klient::EdytujImie(std::string imie)
	{
	this->Imie = imie;
	//HERE: wyswil zapytanie do DB
	return true;
	}


bool Klient::EdytujNazwisko(std::string nazwisko)
	{
	this->Nazwisko = nazwisko;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Klient::EdytujPesel(std::string pesel)
	{
	this->Pesel = pesel;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Klient::EdytujNip(std::string nip)
	{
	this->Nip = nip;
	//HERE: wyswil zapytanie do DB
	return true;
	}

Klient* Klient::Dodaj(std::string imie,std::string nazwisko,std::string pesel, std::string nip)
	{
	//Klient* s = new Klient();
	//HERE: query do DB
	return nullptr;
	}

bool Klient::Usun(Klient *)
	{
	return false;
	}
