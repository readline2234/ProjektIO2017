#include "Zasob.h"

Zasob::Zasob(int towarid, int dostawaid, int regalid, int ilosc)
	{
	this->TowarID = towarid;
	this->DostawaID = dostawaid;
	this->RegalID = regalid;
	this->Ilosc = ilosc;
	}

Zasob::~Zasob() { }

int Zasob::GetTowarID() { return this->TowarID; }
int Zasob::GetDostawaID() { return this->DostawaID; }
int Zasob::GetRegalID() { return this->RegalID; }
int Zasob::GetIlosc() { return this->Ilosc; }

bool Zasob::EdytujTowarID (int towarid)
	{
	this->TowarID = towarid;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool Zasob::EdytujDostawaID (int dostawaid)
	{
	this->DostawaID = dostawaid;
	//HERE: wyswil zapytanie do DB
	return true;	
	}
bool Zasob::EdytujRegalID (int regalid)
	{
	this->RegalID = regalid;
	//HERE: wyswil zapytanie do DB
	return true;	
	}
bool Zasob::EdytujIlosc (int ilosc)	
	{
	this->Ilosc = ilosc;
	//HERE: wyswil zapytanie do DB
	return true;	
	}
	
Zasob* Zasob::Dodaj(int towarid, int dostawaid, int regalid, int ilosc)
	{
	//Zasob* s = new Zasob();
	//HERE: query do DB
	return nullptr;
	}

bool Zasob::Usun(Zasob *)
	{
	return false;
	}
