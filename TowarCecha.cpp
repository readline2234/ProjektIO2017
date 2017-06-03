#include "TowarCecha.h"

TowarCecha::TowarCecha(int towarid, int cechaid)
	{
	this->TowarID = towarid;
	this->CechaID = cechaid;
	}

TowarCecha::~TowarCecha() { }

int TowarCecha::GetTowarID() { return this->TowarID; }
int TowarCecha::GetCechaID() { return this->CechaID; }

bool TowarCecha::EdytujTowarID (int towarid)
	{
	this->TowarID = towarid;
	//HERE: wyswil zapytanie do DB
	return true;
	}

bool TowarCecha::EdytujCechaID (int cechaid)
	{
	this->CechaID = cechaid;
	//HERE: wyswil zapytanie do DB
	return true;	
	}
	
TowarCecha* TowarCecha::Dodaj(int towarid, int cechaid)
	{
	//TowarCecha* s = new TowarCecha();
	//HERE: query do DB
	return nullptr;
	}

bool TowarCecha::Usun(TowarCecha *)
	{
	return false;
	}
